//
// Created by Aidan on 10/5/2020.
//

#pragma once

#include <string>

#include <nlohmann/json.hpp>

#include "alias.hh"

namespace discordpp {
struct Call {
    Call() {}

    Call(sptr<const std::string> requestType, sptr<const std::string> targetUrl,
         sptr<const json> body, sptr<const handleWrite> onWrite,
         sptr<const handleRead> onRead)
        : requestType_(std::move(requestType)), targetURL_(std::move(targetUrl)),
          body_(std::move(body)), onWrite_(std::move(onWrite)),
          onRead_(std::move(onRead)) {}

    /*Call(sptr<const std::string> requestType, sptr<const std::string> targetUrl,
         sptr<const handleWrite> onWrite, sptr<const handleRead> onRead)
        : requestType(std::move(requestType)), targetURL(std::move(targetUrl)),
          onWrite(std::move(onWrite)), onRead(std::move(onRead)) {}

    Call(sptr<const std::string> requestType, sptr<const std::string> targetUrl,
         sptr<const json> body, sptr<const handleRead> onRead)
        : requestType(std::move(requestType)), targetURL(std::move(targetUrl)),
          body(std::move(body)), onRead(std::move(onRead)) {}

    Call(sptr<const std::string> requestType, sptr<const std::string> targetUrl,
         sptr<const json> body, sptr<const handleWrite> onWrite)
        : requestType(std::move(requestType)), targetURL(std::move(targetUrl)),
          body(std::move(body)), onWrite(std::move(onWrite)) {}

    Call(sptr<const std::string> requestType, sptr<const std::string> targetUrl,
         sptr<const json> body)
        : requestType(std::move(requestType)), targetURL(std::move(targetUrl)),
          body(std::move(body)) {}

    Call(sptr<const std::string> requestType, sptr<const std::string> targetUrl,
         sptr<const handleWrite> onWrite)
        : requestType(std::move(requestType)), targetURL(std::move(targetUrl)),
          onWrite(std::move(onWrite)) {}

    Call(sptr<const std::string> requestType, sptr<const std::string> targetUrl,
         sptr<const handleRead> onRead)
        : requestType(std::move(requestType)), targetURL(std::move(targetUrl)),
          onRead(std::move(onRead)) {}

    Call(sptr<const std::string> requestType, sptr<const std::string> targetUrl)
        : requestType(std::move(requestType)), targetURL(std::move(targetUrl)) {
    }*/

    sptr<const std::string> requestType_ = nullptr;
    sptr<const std::string> targetURL_ = nullptr;
    sptr<const json> body_ = nullptr;
    sptr<const handleWrite> onWrite_ = nullptr;
    sptr<const handleRead> onRead_ = nullptr;
};
} // namespace discordpp
