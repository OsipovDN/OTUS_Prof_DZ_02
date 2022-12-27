cmake_minimum_required (VERSION 3.8)

project (lexicographically_sort)

add_executable (
    LexSort
    main.cpp
    #${CMAKE_CURRENT_SOURCE_DIR}/src
    src/FilePars.cpp
    )

target_include_directories(
    LexSort PRIVATE 
    ${CMAKE_CURRENT_BINARY_DIR}
)
target_include_directories(
    LexSort PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/header
)

set_target_properties(LexSort PROPERTIES
	CXX_STANDARD 11
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