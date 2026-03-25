cmake_minimum_required(VERSION 3.10)

project(Wireworld_Cell_DEVS VERSION 1.0 DESCRIPTION "Wireworld model using Cadmium v2")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

add_executable(wireworld src/main.cpp)

# Includes
target_include_directories(wireworld PRIVATE 
    ${CMAKE_SOURCE_DIR}/../include
    ${CMAKE_SOURCE_DIR}/../json/include
    ${CMAKE_SOURCE_DIR}/include
)

set_target_properties(wireworld PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
