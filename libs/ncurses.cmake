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
set(CURSES_NEED_NCURSES TRUE)
find_package(Curses QUIET)

if(${FORCE_NON_LOCAL_LIBS} OR !${CURSES_FOUND})
    message(STATUS "Using external NCURSES")
    add_dependencies(ncurses-lib ncurses-extern)
    ExternalProject_Get_Property(ncurses-extern INSTALL_DIR)
    target_link_libraries(ncurses-lib INTERFACE ${INSTALL_DIR}/lib/libncurses.so)
    target_include_directories(ncurses-lib INTERFACE ${INSTALL_DIR}/include)
    target_include_directories(ncurses-lib INTERFACE ${INSTALL_DIR}/include/ncurses)
elseif(${CURSES_FOUND})
    message(STATUS "Using interal NCURSES")
    target_link_libraries(ncurses-lib INTERFACE ${CURSES_LIBRARIES})
    target_include_directories(ncurses-lib INTERFACE ${CURSES_INCLUDE_DIRS})
endif()

