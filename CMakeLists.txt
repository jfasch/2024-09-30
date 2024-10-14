cmake_minimum_required(VERSION 3.20)
project(2024-09-30 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)

# compiler options. (we only check for gcc)
if (${CMAKE_C_COMPILER_ID} STREQUAL GNU)
   string(APPEND CMAKE_C_FLAGS   " -Wall -Werror")
   string(APPEND CMAKE_CXX_FLAGS " -Wall -Werror")
   string(APPEND CMAKE_CXX_FLAGS " -fno-rtti")
   string(APPEND CMAKE_CXX_FLAGS " -fno-exceptions")
   if ("${CMAKE_BUILD_TYPE}" STREQUAL Debug)
     string(APPEND CMAKE_C_FLAGS   " -O0 -g3")
     string(APPEND CMAKE_CXX_FLAGS " -O0 -g3")
   endif()
endif()

add_subdirectory(programs)
add_subdirectory(toolcase)
add_subdirectory(tests)

add_subdirectory(livehacking)

add_subdirectory(googletest)



add_subdirectory(embedded-nonvirtual-polymorphic-objects)
add_subdirectory(embedded-nonvirtual-polymorphic-pointers)
