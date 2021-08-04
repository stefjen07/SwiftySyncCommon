cmake_minimum_required(VERSION 3.19)
if (NOT TARGET SwiftySyncCommon)
    project(SwiftySyncCommon)

    set(CMAKE_CXX_STANDARD 14)

    include_directories(CodablePP)

    add_executable(test_common test.cpp)
endif()