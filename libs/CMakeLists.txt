ExternalProject_Add(cxxopts
    EXCLUDE_FROM_ALL TRUE
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/cxxopts
    BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/cxxopts/build
    GIT_REPOSITORY git@github.com:jarro2783/cxxopts.git
    INSTALL_COMMAND cmake -E echo "Skipping install step."
)