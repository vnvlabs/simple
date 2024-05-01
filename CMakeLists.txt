cmake_minimum_required(VERSION 3.6)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Simple)
find_package(MPI REQUIRED)
find_package(Injection REQUIRED)
set(WITH_MPI ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(basic)
add_subdirectory(c)
add_subdirectory(cpp)
add_subdirectory(fortran)
add_subdirectory(library)
add_subdirectory(plugin)





