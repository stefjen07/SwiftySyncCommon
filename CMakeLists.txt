cmake_minimum_required(VERSION 3.0)
if (NOT TARGET SwiftySyncCommon)
    project(SwiftySyncCommon)

    set(CMAKE_CXX_STANDARD 14)

    add_subdirectory(CodablePP)

    include_directories(include)

    add_library(SwiftySyncCommon include/Data.hpp src/Data.cpp include/Request.hpp src/Request.cpp include/Functions.hpp include/UUID.hpp src/UUID.cpp)
    target_link_libraries(SwiftySyncCommon Codable)
    target_include_directories(SwiftySyncCommon PUBLIC CodablePP/include)

    #add_executable(test_common test/test.cpp)
    #target_link_libraries(test_common SwiftySyncCommon)
endif()