include(cxxopts.cmake)
include(ncurses.cmake)
include(cpr.cmake)
include(simplejson.cmake)
include(gtest.cmake)

add_custom_target(clean-libs
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMAND rm -rf cxxopts
    COMMAND rm -rf ncurses
    COMMAND rm -rf cpr
    COMMAND rm -rf simpleson
    COMMAND rm -rf gtest
)

set(ADDITIONAL_CLEAN_FILES
    <CMAKE_CURRENT_SOURCE_DIR>/cxxopts
    <CMAKE_CURRENT_SOURCE_DIR>/ncurses
    <CMAKE_CURRENT_SOURCE_DIR>/cpr
    <CMAKE_CURRENT_SOURCE_DIR>/simpleson
    <CMAKE_CURRENT_SOURCE_DIR>/gtest
)