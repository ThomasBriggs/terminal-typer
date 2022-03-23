
find_package(Curses REQUIRED)
link_libraries(${CURSES_LIBRARIES})

add_library(terminal-typer
    typer.cpp    
    file.cpp
    display.cpp
    util.cpp
)

add_executable(main 
    main.cpp
)
target_link_libraries(main terminal-typer)

add_executable(test test.cpp file.cpp)