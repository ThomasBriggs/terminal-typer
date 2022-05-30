ExternalProject_Add(cpr-extern
    EXCLUDE_FROM_ALL TRUE
    INSTALL_DIR ${CMAKE_SOURCE_DIR}/libs/cpr
    GIT_REPOSITORY https://github.com/libcpr/cpr.git
    GIT_TAG master
    UPDATE_COMMAND ""
    CMAKE_ARGS 
        -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
    BUILD_BYPRODUCTS <INSTALL_DIR>/lib/libcpr.so <INSTALL_DIR>/include/cpr/cpr.h
)

add_library(cpr-lib INTERFACE)
add_dependencies(cpr-lib cpr-extern)
target_link_libraries(cpr-lib INTERFACE ${CMAKE_SOURCE_DIR}/libs/cpr/lib/libcpr.so)
target_include_directories(cpr-lib INTERFACE ${CMAKE_SOURCE_DIR}/libs/cpr/include)