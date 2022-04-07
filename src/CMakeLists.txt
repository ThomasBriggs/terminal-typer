
find_package(Curses REQUIRED)

link_libraries(${CURSES_LIBRARIES})

add_library(terminal-typer
    typer.cpp    
    file.cpp
    display.cpp
    util.cpp
    error_handeling.cpp
)


add_executable(main main.cpp)
add_executable(quote quote.cpp)

set_target_properties(
    main quote
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)

target_link_libraries(main terminal-typer cxxopts-lib ncurses-lib)
target_link_libraries(quote terminal-typer)