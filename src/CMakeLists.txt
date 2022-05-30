set(SRC_FILES 
    main.cpp
    typer.cpp    
    file.cpp
    display.cpp
    util.cpp
    error_handeling.cpp
)

add_executable(main ${SRC_FILES})
target_link_libraries(main ncurses-lib cxxopts-lib)

add_executable(curl curl.cpp)
target_link_libraries(curl cpr-lib)

set_target_properties(
    main
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)