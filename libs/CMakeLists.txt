ExternalProject_Add(cxxopts-extern
    EXCLUDE_FROM_ALL TRUE
    INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/cxxopts
    GIT_REPOSITORY https://github.com/jarro2783/cxxopts.git
    GIT_TAG 8185e6b
    UPDATE_COMMAND ""
    CMAKE_ARGS
        -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
)

add_library(cxxopts-lib INTERFACE)
add_dependencies(cxxopts-lib cxxopts-extern)
target_include_directories(cxxopts-lib INTERFACE "cxxopts/include")

ExternalProject_Add(ncurses-extern
    EXCLUDE_FROM_ALL TRUE
    INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/ncurses
    GIT_REPOSITORY https://github.com/mirror/ncurses.git
    GIT_TAG 64eb5fa
    UPDATE_COMMAND ""
    CONFIGURE_COMMAND <SOURCE_DIR>/configure --prefix <INSTALL_DIR> --with-shared --without-debug --without-manpages --includedir <INSTALL_DIR>/include
    BUILD_COMMAND make -C <BINARY_DIR>
    INSTALL_COMMAND make -C <BINARY_DIR> install
)

add_library(ncurses-lib INTERFACE)
find_package(Curses QUIET)
if ((NOT ${CURSES_FOUND}) OR ${FORCE_NON_LOCAL_LIBS})
    add_dependencies(ncurses-lib ncurses-extern)
    target_link_libraries(ncurses-lib INTERFACE -L${CMAKE_CURRENT_SOURCE_DIR}/ncurses/lib -lncurses)
    target_include_directories(ncurses-lib INTERFACE ncurses/include/ncurses ncurses/include)
else ()
    target_link_libraries(ncurses-lib INTERFACE ${CURSES_LIBRARIES})
    target_include_directories(ncurses-lib INTERFACE ${CURSES_INCLUDE_DIRS})
endif()

add_custom_target(clean-libs
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMAND rm -rf cxxopts
    COMMAND rm -rf ncurses
)

list(APPEND CMAKE_BUILD_RPATH /home/thomas/Documents/terminal-typer/libs/ncurses/lib)
message(STATUS ${CURSES_LIBRARIES})
set(CMAKE_BUILD_RPATH ${CMAKE_BUILD_RPATH} PARENT_SCOPE)