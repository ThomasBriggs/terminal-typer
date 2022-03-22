
find_package(Curses REQUIRED)
link_libraries(${CURSES_LIBRARIES})
add_executable(main main.cpp file.cpp display.cpp util.cpp)
add_executable(test test.cpp file.cpp)