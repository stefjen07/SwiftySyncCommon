cmake_minimum_required(VERSION 3.19)
project(SwiftyData)
project(SwiftyRequest)
project(SwiftyFunctions)
project(SwiftyUUID)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(CodablePP)
include_directories(CodablePP)

add_library(SwiftyData Data.h Data.cpp)
target_link_libraries(SwiftyData PUBLIC CodablePP/Codable.lib PUBLIC CodablePP/JSON.lib)

add_library(SwiftyRequest Request.h Request.cpp)
target_link_libraries(SwiftyRequest PUBLIC CodablePP/Codable.lib PUBLIC CodablePP/JSON.lib)

add_library(SwiftyFunctions Functions.h Functions.cpp)

add_library(SwiftyUUID UUID.h UUID.cpp)