ExternalProject_Add(cxxopts
    EXCLUDE_FROM_ALL TRUE
    INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/
    GIT_REPOSITORY git@github.com:jarro2783/cxxopts.git
    CMAKE_ARGS
        -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>

)