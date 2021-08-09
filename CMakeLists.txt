cmake_minimum_required(VERSION 3.0)
if (NOT TARGET SwiftySyncCommon)
    project(SwiftySyncCommon)

    set(CMAKE_CXX_STANDARD 14)

    add_subdirectory(CodablePP)

    add_library(SwiftySyncCommon Data.hpp Data.cpp Request.hpp Request.cpp Functions.hpp UUID.hpp UUID.cpp)
    target_link_libraries(SwiftySyncCommon Codable)
    target_include_directories(SwiftySyncCommon PUBLIC CodablePP)

    #add_executable(test_common test.cpp)
    #target_link_libraries(test_common SwiftySyncCommon)
endif()