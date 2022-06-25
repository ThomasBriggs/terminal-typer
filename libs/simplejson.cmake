ExternalProject_Add(simpleson-extern
    EXCLUDE_FROM_ALL TRUE
    INSTALL_DIR ${CMAKE_SOURCE_DIR}/libs/simpleson
    GIT_REPOSITORY https://github.com/gregjesl/simpleson.git
    GIT_TAG master
    UPDATE_COMMAND ""
    INSTALL_COMMAND
        mkdir -p <INSTALL_DIR>/include &&
        mkdir -p <INSTALL_DIR>/lib &&
        cp <SOURCE_DIR>/json.h <INSTALL_DIR>/include/. &&
        cp <BINARY_DIR>/libsimpleson.a <INSTALL_DIR>/lib/.
    BUILD_BYPRODUCTS <INSTALL_DIR>/include/json.h <INSTALL_DIR>/lib/libsimpleson.a
)

add_library(simpleson-lib INTERFACE)
add_dependencies(simpleson-lib simpleson-extern)
ExternalProject_Get_Property(simpleson-extern INSTALL_DIR)
target_link_libraries(simpleson-lib INTERFACE ${INSTALL_DIR}/lib/libsimpleson.a)
target_include_directories(simpleson-lib INTERFACE ${INSTALL_DIR}/include)