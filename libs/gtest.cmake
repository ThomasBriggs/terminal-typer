ExternalProject_Add(gtest-extern
    EXCLUDE_FROM_ALL TRUE
    INSTALL_DIR ${CMAKE_SOURCE_DIR}/libs/gtest
    GIT_REPOSITORY https://github.com/google/googletest
    GIT_TAG master
    UPDATE_COMMAND ""
    CMAKE_ARGS 
        -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
)