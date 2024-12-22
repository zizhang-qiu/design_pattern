cmake_minimum_required(VERSION 3.30)
project(design_pattern)

set(CMAKE_CXX_STANDARD 17)

add_executable(design_pattern main.cpp)
add_executable(factory factory.cc)
add_executable(abstract_factory abstract_factory.cc)
add_executable(builder builder.cc)
add_executable(prototype prorotype.cc)
add_executable(singleton singleton.cc)
add_executable(adapter adapter.cc)
add_executable(bridge bridge.cc)
