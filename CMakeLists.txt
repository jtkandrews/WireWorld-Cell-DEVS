cmake_minimum_required(VERSION 3.16)

project(Wireworld_Cell_DEVS VERSION 1.0 DESCRIPTION "Wireworld model using Cadmium v2")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

if(DEFINED ENV{CADMIUM})
    set(CADMIUM_ROOT "$ENV{CADMIUM}/..")
    set(CADMIUM_PATHS "$ENV{CADMIUM}" "$ENV{CADMIUM}/include" "${CADMIUM_ROOT}/json/include")
else()
    set(CADMIUM_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../cadmium_v2")
    set(CADMIUM_PATHS "${CADMIUM_ROOT}/include" "${CADMIUM_ROOT}/json/include")
endif()

add_executable(wireworld src/main.cpp)

target_include_directories(wireworld PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CADMIUM_PATHS}
)

target_compile_options(wireworld PUBLIC -std=gnu++17)