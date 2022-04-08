set(SRC_FILES 
    main.cpp
    typer.cpp    
    file.cpp
    display.cpp
    util.cpp
    error_handeling.cpp
)

message(${SRC_FILES})

add_executable(main ${SRC_FILES})

set_target_properties(
    main
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)

target_link_libraries(main ncurses-lib cxxopts-lib)