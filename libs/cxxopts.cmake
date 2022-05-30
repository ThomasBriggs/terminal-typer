ExternalProject_Add(cxxopts-extern
    EXCLUDE_FROM_ALL TRUE
    INSTALL_DIR ${CMAKE_SOURCE_DIR}/libs/cxxopts
    GIT_REPOSITORY https://github.com/jarro2783/cxxopts.git
    GIT_TAG 8185e6b
    UPDATE_COMMAND ""
    CMAKE_ARGS
        -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
    BUILD_BYPRODUCTS <INSTALL_DIR>/include/cxxopts.hpp
)

add_library(cxxopts-lib INTERFACE)
add_dependencies(cxxopts-lib cxxopts-extern)
target_include_directories(cxxopts-lib INTERFACE ${CMAKE_SOURCE_DIR}/libs/cxxopts/include)