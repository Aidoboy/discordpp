# Discord++ <sup>(it's cool)</sup>
A Modularized C++ Library for the Discord API

***This library is not a hacked Discord mobile app that will give you free Nitro. Free Nitro does not exist, and any YouTube video saying otherwise is attempting either to get you to install malware or to collect ad revenue off of you.***

[![GitHub stars](https://img.shields.io/github/stars/DiscordPP/discordpp?style=for-the-badge)](https://github.com/DiscordPP/discordpp/stargazers)[![Discord](https://img.shields.io/discord/164234463247597568?color=%237289DA&label=Discord&style=for-the-badge)](https://discord.gg/VHAyrvspCx)

## Links
* [Discord Server](https://discord.gg/VHAyrvspCx)
* [Echo: Example / Template Bot](https://github.com/DiscordPP/echo-bot)

## Dependencies

### Required
* [Boost](http://www.boost.org/)
* A Discord++ REST module
   * [REST: Beast](https://github.com/DiscordPP/rest-beast/)
      * Requires [OpenSSL](https://www.openssl.org/)
* A Discord++ WebSocket module
   * [WebSocket: Beast](https://github.com/DiscordPP/websocket-beast)
      * Currently out of date
   * [WebSocket: Simple-WebSocket-Server](https://github.com/DiscordPP/websocket-simpleweb)

### Included <sup>(Git submodules)</sup>
* [nlohmann::json](https://github.com/nlohmann/json)

### Recommended Plugins
* [Plugin: RateLimit](https://github.com/DiscordPP/plugin-ratelimit) handes rate limiting
   * Without this plugin, Discord++ exits when encountering a rate limit for your safety
* [Plugin: Overload](https://github.com/DiscordPP/plugin-overload) provides overloads for the websocket and REST `call` and `send` functions to create `std::shared_ptr`s for you and provides some sane defaults when you don't need all their arguments.
* [Plugin: Responder](https://github.com/DiscordPP/plugin-responder) provides a simple interface for detecting commands in the form of a character and a string, e.g. `!help`
* You can find more plugins on the [#discordpp-plugin](https://github.com/topics/discordpp-plugin) tag

## Usage

See [the Wiki](https://github.com/DiscordPP/discordpp/wiki) for setup and configuration
