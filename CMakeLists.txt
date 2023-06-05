cmake_minimum_required(VERSION 3.6)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Simple)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Injection REQUIRED)
add_executable(simple.a "simple-vnv.cpp")
link_vnv_file(simple.a SIMPLE cpp)

install(TARGETS simple.a DESTINATION ${CMAKE_INSTALL_PREFIX})
install(FILES vnv-input.json DESTINATION ${CMAKE_INSTALL_PREFIX})




