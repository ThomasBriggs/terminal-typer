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
    BUILD_COMMAND make -C <SOURCE_DIR>  -j 4
    INSTALL_COMMAND make -C <SOURCE_DIR> install
)

add_library(ncurses-lib INTERFACE)
add_dependencies(ncurses-lib ncurses-build)
