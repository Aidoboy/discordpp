cmake_minimum_required(VERSION 3.6)
project(discordpp)

set(CMAKE_CXX_STANDARD 17)

###################

include(FetchContent)

FetchContent_Declare(json
        GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent
        GIT_TAG v3.9.1)

FetchContent_GetProperties(json)
if(NOT json_POPULATED)
    FetchContent_Populate(json)
    add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Boost 1.71.0 REQUIRED system date_time)
find_package(Threads REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(FMT REQUIRED)

###################

add_library(${PROJECT_NAME} INTERFACE)

INCLUDE_DIRECTORIES(
        ${discordpp_SOURCE_DIR}
        ${Boost_INCLUDE_DIRS}
        ${OPENSSL_INCLUDE_DIR}
)
TARGET_LINK_LIBRARIES(
        ${PROJECT_NAME} INTERFACE
        ${Boost_LIBRARIES}
        Threads::Threads
        ${OPENSSL_LIBRARIES}
        nlohmann_json::nlohmann_json
        fmt::fmt
)
