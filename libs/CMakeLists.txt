ExternalProject_Add(cxxopts
    EXCLUDE_FROM_ALL TRUE
    INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/cxxopts
    GIT_REPOSITORY git@github.com:jarro2783/cxxopts.git
    CMAKE_ARGS
        -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
)

add_library(cxxopts-lib INTERFACE)
add_dependencies(cxxopts-lib cxxopts)
target_include_directories(cxxopts-lib INTERFACE "cxxopts/include")

ExternalProject_Add(ncurses-build
    EXCLUDE_FROM_ALL TRUE
    INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/ncurses
    GIT_REPOSITORY git@github.com:mirror/ncurses.git
    CONFIGURE_COMMAND <SOURCE_DIR>/configure --prefix <INSTALL_DIR>
    BUILD_COMMAND make -C <BINARY_DIR>
    INSTALL_COMMAND make -C <BINARY_DIR> install
)

add_library(ncurses-lib INTERFACE)
add_dependencies(ncurses-lib ncurses-build)
target_link_libraries(ncurses-lib INTERFACE -L${CMAKE_CURRENT_SOURCE_DIR}/ncurses/lib)
target_include_directories(ncurses-lib INTERFACE ncurses/include)
