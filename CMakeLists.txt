cmake_minimum_required (VERSION 3.8)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project (lexicographically_sort VERSION ${PROJECT_VESRION})
find_package(GTest)
configure_file(version.h.in version.h)

add_executable (
    LexSort
    main.cpp
    src/FilePars.cpp
    src/LexSort.cpp
)
add_executable(lex_sort_gtest test/lex_sort_gtest.cpp)

target_include_directories(
    LexSort PRIVATE 
    ${CMAKE_CURRENT_BINARY_DIR}
)
target_include_directories(
    LexSort PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/header
)

target_include_directories(
    lex_sort_gtest PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/test
)
target_include_directories(
    lex_sort_gtest PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
)

target_include_directories(
    lex_sort_gtest PRIVATE
    ${GTEST_INCLUDE_DIRS}
)

target_link_libraries(
    lex_sort_gtest PRIVATE
    ${GTEST_BOTH_LIBRARIES}
)
set_target_properties(LexSort PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
    CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(LexSort PRIVATE 
        -g
        -Wall
        -Wextra
        -Werror
        -pedantic
    )

elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(LexSort PRIVATE
        /EHsc
        /W4
        /WX
    )

endif()

install(TARGETS LexSort RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

enable_testing()

add_test(lex_sort_gtest lex_sort_gtest)
