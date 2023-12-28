set(SRC_FILES 
    typer.cpp    
    file.cpp
    display.cpp
    util.cpp
    error_handeling.cpp
)

add_library(Typer STATIC ${SRC_FILES})
target_link_libraries(Typer ncurses-lib cpr-lib simpleson-lib)
target_include_directories(Typer PUBLIC ./include)

add_subdirectory(test)