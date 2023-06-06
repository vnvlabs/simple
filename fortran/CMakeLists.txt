
enable_language (Fortran)
set(CMAKE_Fortran_MODULE_DIRECTORY ${CMAKE_BINARY_DIR}/modules)

add_executable(hello_fortran helloworld.f90 hellovnv.cpp)

link_vnv_file_fortran(hello_fortran fortran cpp true)
configure_file(${CMAKE_CURRENT_LIST_DIR}/vnv.json ${CMAKE_CURRENT_BINARY_DIR}/vnv.json COPYONLY)
install(TARGETS hello_fortran DESTINATION fortran)
install(FILES ${CMAKE_CURRENT_LIST_DIR}/vnv.json DESTINATION fortran )
