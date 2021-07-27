cmake_minimum_required(VERSION 3.19)
if (NOT TARGET SwiftySyncCommon)
    project(SwiftySyncCommon)

    set(CMAKE_CXX_STANDARD 14)

    add_subdirectory(CodablePP)
    include_directories(CodablePP)

    add_library(SwiftySyncCommon Data.h Data.cpp Request.h Request.cpp Functions.h Functions.cpp UUID.h UUID.cpp)
    target_link_libraries(SwiftySyncCommon Codable)

    add_executable(test_common test.cpp)
    target_link_libraries(test_common SwiftySyncCommon)

endif()