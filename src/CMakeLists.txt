# find_package(Curses REQUIRED)


add_library(terminal-typer
    typer.cpp    
    file.cpp
    display.cpp
    util.cpp
    error_handeling.cpp
)

# target_link_libraries(terminal-typer ${CURSES_LIBRARIES})
target_link_libraries(terminal-typer ncurses-lib)

add_executable(main main.cpp)

set_target_properties(
    main
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)

target_link_libraries(main terminal-typer cxxopts-lib)