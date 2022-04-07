
add_library(terminal-typer
    typer.cpp    
    file.cpp
    display.cpp
    util.cpp
    error_handeling.cpp
)

target_link_libraries(terminal-typer ncurses-lib)

add_executable(main main.cpp)
add_executable(quote quote.cpp)

set_target_properties(
    main quote
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)

target_link_libraries(main terminal-typer cxxopts-lib)
target_link_libraries(quote terminal-typer)