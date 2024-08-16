cmake_minimum_required(VERSION 3.6)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

function(addExecutable name packageName)

  add_executable(${name} ${name}.cpp)
  link_vnv_executable(${name} ${packageName} cpp)

  target_include_directories(${name} PRIVATE ${MPI_CXX_INCLUDE_PATH})
  target_compile_options(${name} PRIVATE ${MPI_CXX_COMPILE_FLAGS})
  target_link_libraries(${name} PRIVATE ${MPI_CXX_LIBRARIES} ${MPI_CXX_LINK_FLAGS})
  target_compile_definitions(${name} PUBLIC -DWITH_MPI=1)

  install(TARGETS ${name} DESTINATION cpp)
  configure_file(${CMAKE_CURRENT_LIST_DIR}/inputfiles/${name}.json ${CMAKE_CURRENT_BINARY_DIR}/inputfiles/${name}.json COPYONLY)
  install(FILES ${CMAKE_CURRENT_LIST_DIR}/inputfiles/${name}.json DESTINATION cpp/inputfiles )
  
  vnv_register_build(${name} ${packageName} ${CMAKE_CURRENT_BINARY_DIR}/${name})
  vnv_register_install(${packageName} ${CMAKE_INSTALL_PREFIX}/cpp/${name} ${ARGN}) 

endfunction()


addexecutable(injectionPoint SampleExecutable A really simple example)
addexecutable(iterator SimpleExecutable A simple iterator example)
addexecutable(distributed Distributed A example showing mpi support)
addexecutable(live Live )
addexecutable(contour ContourExample)
addexecutable(line LineExample)
addexecutable(euler Euler)
addexecutable(vectors VectorsExample)

