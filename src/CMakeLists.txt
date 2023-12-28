add_executable(main main.cpp)
target_link_libraries(main Typer cxxopts-lib)


set_target_properties(
    main
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)

add_subdirectory(typer)