ExternalProject_Add(ncurses-extern
    EXCLUDE_FROM_ALL TRUE
    INSTALL_DIR ${CMAKE_SOURCE_DIR}/libs/ncurses
    GIT_REPOSITORY https://github.com/mirror/ncurses.git
    GIT_TAG deb0d07
    UPDATE_COMMAND ""
    CONFIGURE_COMMAND <SOURCE_DIR>/configure --prefix <INSTALL_DIR> --with-shared --without-debug --without-manpages --includedir <INSTALL_DIR>/include
    BUILD_COMMAND make -C <BINARY_DIR>
    INSTALL_COMMAND make -C <BINARY_DIR> install
    BUILD_BYPRODUCTS <INSTALL_DIR>/lib/libncurses.so <INSTALL_DIR>/include/ncurses/ncurses.h
)

add_library(ncurses-lib INTERFACE)
add_dependencies(ncurses-lib ncurses-extern)
target_link_libraries(ncurses-lib INTERFACE ${CMAKE_SOURCE_DIR}/libs/ncurses/lib/libncurses.so)
target_include_directories(ncurses-lib INTERFACE ${CMAKE_SOURCE_DIR}/libs/ncurses/include/ncurses)