ExternalProject_Add(gtest-extern
    EXCLUDE_FROM_ALL TRUE
    INSTALL_DIR ${CMAKE_SOURCE_DIR}/libs/gtest
    GIT_REPOSITORY https://github.com/google/googletest
    GIT_TAG main
    UPDATE_COMMAND ""
    CMAKE_ARGS 
        -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
    BUILD_BYPRODUCTS
        <INSTALL_DIR>/lib/libgmock.a
        <INSTALL_DIR>/lib/libgmock_main.a
        <INSTALL_DIR>/lib/libgtest.a
        <INSTALL_DIR>/lib/libgtest_main.a
)

add_library(gtest-lib INTERFACE)
find_package(GTest QUIET)

if(${FORCE_NON_LOCAL_LIBS} OR (NOT ${GTEST_FOUND}))
    message(STATUS "Using external GTest")
    add_dependencies(gtest-lib gtest-extern)
    ExternalProject_Get_Property(gtest-extern INSTALL_DIR)
    target_link_libraries(gtest-lib INTERFACE
        ${INSTALL_DIR}/lib/libgmock.a
        ${INSTALL_DIR}/lib/libgmock_main.a
        ${INSTALL_DIR}/lib/libgtest.a
        ${INSTALL_DIR}/lib/libgtest_main.a)
    target_include_directories(gtest-lib INTERFACE ${INSTALL_DIR}/include)
elseif(${GTEST_FOUND})
    message(STATUS "Using interal GTest")
    target_link_libraries(gtest-lib INTERFACE ${GTEST_LIBRARIES})
    target_include_directories(gtest-lib INTERFACE ${GTEST_INCLUDE_DIRS})
endif()

