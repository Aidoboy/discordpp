//
// Created by aidan on 11/7/15.
//

#ifndef DISCORDPP_DISCORDPP_HH
#define DISCORDPP_DISCORDPP_HH

#include <vector>
#include <string>

#include <nlohmann/json.hpp>

#include "botStruct.hh"

#include "colors.hh"

namespace discordpp {
    using json = nlohmann::json;
    using snowflake = uint64_t;

    class Bot : virtual BotStruct {
        std::unique_ptr<boost::asio::steady_timer> pacemaker_;
        std::unique_ptr<std::chrono::milliseconds> heartrate_;
        int sequence_ = -1;
        bool gotACK = true;
    public:
        std::multimap<std::string, std::function<void(json)>> handlers;

        Bot() {
            needInit["Bot"] = true;
        }

        void initBot(unsigned int apiVersionIn, const std::string &tokenIn, std::shared_ptr<asio::io_context> aiocIn) {
            apiVersion = apiVersionIn;
            token = tokenIn;
            aioc = aiocIn;
            needInit["Bot"] = false;
        }

    protected:
        void sendHeartbeat() {
            if(!gotACK){
                std::cerr << clr(Red) << "Discord Servers did not respond to heartbeat. Reconnect not implemented.\n" << clr(Reset);
                exit(1);
            }
            gotACK = false;
            std::cout << clr(Bold) << "Sending heartbeat...\n" << clr(Reset);
            pacemaker_ = std::make_unique<boost::asio::steady_timer>(
                    *aioc,
                    std::chrono::steady_clock::now() + *heartrate_
            );
            pacemaker_->async_wait(
                    [this](const boost::system::error_code) {
                        sendHeartbeat();
                    }
            );
            if(sequence_ >= 0) {
                send(1, sequence_);
            }else{
                send(1, {});
            }
        }

        void recievePayload(json payload) override {
            //std::cerr << "Recieved Payload: " << payload.dump(4) << '\n';

            switch (payload["op"].get<int>()) {
                case 0:  // Dispatch:           dispatches an event
                    sequence_ = payload["s"].get<int>();
                    if(handlers.find(payload["t"]) == handlers.end()){
                        std::cerr << clr(Yellow) << "No handlers defined for " << payload["t"] << clr(Reset) << "\n";
                    }else{
                        for(auto handler = handlers.lower_bound(payload["t"]); handler != handlers.upper_bound(payload["t"]); handler++){
                            handler->second(payload["d"]);
                        }
                    }
                    break;
                case 1:  // Heartbeat:          used for ping checking
                    std::cerr << clr(Red) << "Discord Servers requested a heartbeat, which is not implemented.\n" << clr(Reset);
                    break;
                case 7:  // Reconnect:          used to tell clients to reconnect to the gateway
                    std::cerr << clr(Red) << "Discord Servers requested a reconnect. Reconnect not implemented." << clr(Reset);
                    exit(1);
                case 9:  // Invalid Session:	used to notify client they have an invalid session id
                    std::cerr << clr(Red) << "Discord Servers notified of an invalid session ID. Reconnect not implemented." << clr(Red);
                    exit(1);
                case 10: // Hello:              sent immediately after connecting, contains heartbeat and server debug information
                    heartrate_ = std::make_unique<std::chrono::milliseconds>(payload["d"]["heartbeat_interval"]);
                    sendHeartbeat();
                    send(2, {
                            {"token",      token},
                            {"properties", {
                                                   {"$os", "linux"},
                                                   {"$browser", "discordpp"},
                                                   {"$device", "discordpp"},
                                           }
                            }
                    });
                    break;
                case 11: // Heartbeat ACK:      sent immediately following a client heartbeat that was received
                    gotACK = true;
                    std::cout << clr(Green) << "Heartbeat Successful.\n" << clr(Reset);
                    break;
                default:
                    std::cerr << clr(Red) << "Unexpected opcode " << payload["op"] << "! Message:\n"
                              << payload.dump(4) << '\n' << clr(Reset);
            }
        }
    };
}

#endif //DISCORDPP_DISCORDPP_HH
