ExternalProject_Add(cxxopts-extern
    EXCLUDE_FROM_ALL TRUE
    INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/cxxopts
    GIT_REPOSITORY https://github.com/jarro2783/cxxopts.git
    GIT_TAG 8185e6b
    UPDATE_COMMAND ""
    CMAKE_ARGS
        -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
)

add_library(cxxopts-lib INTERFACE)
add_dependencies(cxxopts-lib cxxopts-extern)
target_include_directories(cxxopts-lib INTERFACE "cxxopts/include")

ExternalProject_Add(ncurses-extern
    EXCLUDE_FROM_ALL TRUE
    INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/ncurses
    GIT_REPOSITORY https://github.com/mirror/ncurses.git
    GIT_TAG 64eb5fa
    UPDATE_COMMAND ""
    CONFIGURE_COMMAND <SOURCE_DIR>/configure --prefix <INSTALL_DIR> --with-shared --without-debug --without-manpages --includedir <INSTALL_DIR>/include
    BUILD_COMMAND make -C <BINARY_DIR>
    INSTALL_COMMAND make -C <BINARY_DIR> install
)

add_library(ncurses-lib INTERFACE)
find_package(Curses QUIET)
if ((NOT ${CURSES_FOUND}) OR ${FORCE_NON_LOCAL_LIBS})
    add_dependencies(ncurses-lib ncurses-extern)
    target_link_libraries(ncurses-lib INTERFACE -L${CMAKE_CURRENT_SOURCE_DIR}/ncurses/lib -lncurses)
    target_include_directories(ncurses-lib INTERFACE ncurses/include/ncurses ncurses/include)
else ()
    target_link_libraries(ncurses-lib INTERFACE ${CURSES_LIBRARIES})
    target_include_directories(ncurses-lib INTERFACE ${CURSES_INCLUDE_DIRS})
    message(STATUS NCURSESPATH:${CURSES_LIBRARIES})
endif()

list(APPEND CMAKE_BUILD_RPATH /home/thomas/Documents/terminal-typer/libs/ncurses/lib)
set(CMAKE_BUILD_RPATH ${CMAKE_BUILD_RPATH} PARENT_SCOPE)

ExternalProject_Add(libcurl-extern
    EXCLUDE_FROM_ALL TRUE
    INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libcurl
    GIT_REPOSITORY https://github.com/curl/curl.git
    GIT_TAG 64db5c5
    UPDATE_COMMAND ""
    CMAKE_ARGS
        -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
        -DBUILD_CURL_EXE:BOOL=FALSE
        -DBUILD_SHARED_LIBS:BOOL=FALSE

)

add_library(libcurl-lib INTERFACE)
find_package(CURL QUIET)
if ((NOT ${CURL_FOUND}) OR ${FORCE_NON_LOCAL_LIBS})
    add_dependencies(libcurl-lib libcurl-extern)
    target_link_libraries(libcurl-lib INTERFACE -L${CMAKE_CURRENT_SOURCE_DIR}/libcurl/lib -lcurl -lssl -lcrypto)
    target_include_directories(libcurl-lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/libcurl/include)
else ()
    target_link_libraries(libcurl-lib INTERFACE CURL::libcurl)
    message(STATUS CURLPATH:${CURL_LIBRARIES})
endif()


add_custom_target(clean-libs
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMAND rm -rf cxxopts
    COMMAND rm -rf ncurses
    COMMAND rm -rf libcurl
)