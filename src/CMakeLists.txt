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

set_target_properties(
    main
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)

add_executable(curl curltest.cpp)
target_link_libraries(curl libcurl-lib)
