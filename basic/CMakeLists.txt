add_executable(simple.a "simple-vnv.cpp")
link_vnv_file(simple.a SIMPLE cpp)
install(TARGETS simple.a DESTINATION ${CMAKE_INSTALL_PREFIX})
install(FILES vnv-input.json DESTINATION ${CMAKE_INSTALL_PREFIX})




