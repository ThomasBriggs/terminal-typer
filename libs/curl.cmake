ExternalProject_Add(curl-extern
    EXCLUDE_FROM_ALL TRUE
    INSTALL_DIR ${CMAKE_SOURCE_DIR}/libs/curl
    GIT_REPOSITORY https://github.com/curl/curl.git
    GIT_TAG master
    UPDATE_COMMAND ""
    CMAKE_ARGS 
        -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
    BUILD_BYPRODUCTS <INSTALL_DIR>/lib/libcurl.so
)

add_library(curl-lib INTERFACE)
add_dependencies(curl-lib curl-extern)
target_link_libraries(curl-lib INTERFACE ${CMAKE_SOURCE_DIR}/libs/curl/lib/libcurl.so)
target_include_directories(ncurses-lib INTERFACE ${CMAKE_SOURCE_DIR}/libs/curl/include)