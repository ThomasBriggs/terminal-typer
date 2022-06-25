include(cxxopts.cmake)
include(ncurses.cmake)
include(cpr.cmake)
include(simplejson.cmake)

add_custom_target(clean-libs
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMAND rm -rf cxxopts
    COMMAND rm -rf ncurses
    COMMAND rm -rf cpr
)