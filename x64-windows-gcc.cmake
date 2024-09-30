set(TARGET_TRIPLET "i686-w64-mingw32-")

# do some windows specific logic
if(WIN32)
    set(TOOLCHAIN_EXT ".exe")
else()
    set(TOOLCHAIN_EXT "")
endif(WIN32)

find_program(COMPILER_ON_PATH "${TARGET_TRIPLET}gcc${TOOLCHAIN_EXT}")

if(DEFINED ENV{MINGW_W64_GCC_PATH}) 
    # use the environment variable first    
    file(TO_CMAKE_PATH $ENV{MINGW_W64_GCC_PATH} MINGW_W64_TOOLCHAIN_PATH)
    message(STATUS "Using ENV variable MINGW_W64_GCC_PATH = ${MINGW_W64_TOOLCHAIN_PATH}")
elseif(COMPILER_ON_PATH) 
    # then check on the current path
    get_filename_component(MINGW_W64_TOOLCHAIN_PATH ${COMPILER_ON_PATH} DIRECTORY)
    message(STATUS "Using ARM GCC from path = ${MINGW_W64_TOOLCHAIN_PATH}")
else()
    message(FATAL_ERROR "Unable to find ARM GCC. Either add to your PATH, or define MINGW_W64_GCC_PATH to the compiler location")
endif()

set(CMAKE_C_COMPILER    ${MINGW_W64_TOOLCHAIN_PATH}/${TARGET_TRIPLET}gcc${TOOLCHAIN_EXT} CACHE PATH "C compiler")
set(CMAKE_CXX_COMPILER  ${MINGW_W64_TOOLCHAIN_PATH}/${TARGET_TRIPLET}g++${TOOLCHAIN_EXT})
set(CMAKE_ASM_COMPILER  ${MINGW_W64_TOOLCHAIN_PATH}/${TARGET_TRIPLET}gcc${TOOLCHAIN_EXT})
set(CMAKE_LINKER        ${MINGW_W64_TOOLCHAIN_PATH}/${TARGET_TRIPLET}gcc${TOOLCHAIN_EXT})
set(CMAKE_SIZE_UTIL     ${MINGW_W64_TOOLCHAIN_PATH}/${TARGET_TRIPLET}size${TOOLCHAIN_EXT})
set(CMAKE_OBJCOPY       ${MINGW_W64_TOOLCHAIN_PATH}/${TARGET_TRIPLET}objcopy${TOOLCHAIN_EXT})
set(CMAKE_OBJDUMP       ${MINGW_W64_TOOLCHAIN_PATH}/${TARGET_TRIPLET}objdump${TOOLCHAIN_EXT})
set(CMAKE_NM_UTIL       ${MINGW_W64_TOOLCHAIN_PATH}/${TARGET_TRIPLET}gcc-nm${TOOLCHAIN_EXT})
set(CMAKE_AR            ${MINGW_W64_TOOLCHAIN_PATH}/${TARGET_TRIPLET}gcc-ar${TOOLCHAIN_EXT})
set(CMAKE_RANLIB        ${MINGW_W64_TOOLCHAIN_PATH}/${TARGET_TRIPLET}gcc-ranlib${TOOLCHAIN_EXT})

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

set(CMAKE_C_FLAGS_INIT      "${CPU_FLAGS} ${VFP_FLAGS} ${FLAGS_COMMON}"	                    CACHE	INTERNAL "Default C compiler flags.")
set(CMAKE_CXX_FLAGS_INIT	"${CPU_FLAGS} ${VFP_FLAGS} ${FLAGS_COMMON} ${FLAGS_COMMON_CPP}"	CACHE	INTERNAL "Default C++ compiler flags.")
set(CMAKE_ASM_FLAGS_INIT	"${CPU_FLAGS} ${FLAGS_ASM}"                                 	CACHE	INTERNAL "Default ASM compiler flags.")
set(CMAKE_EXE_LINKER_FLAGS_INIT	"${FLAGS_LINKER}"                         	                CACHE	INTERNAL "Default linker flags.")

SET(CMAKE_C_FLAGS_DEBUG    "${FLAGS_DEBUG}"    CACHE   INTERNAL "Default C compiler debug build flags.")
SET(CMAKE_CXX_FLAGS_DEBUG	"${FLAGS_DEBUG}"	CACHE	INTERNAL "Default C++ compiler debug build flags.")
SET(CMAKE_ASM_FLAGS_DEBUG	"${FLAGS_DEBUG}"	CACHE	INTERNAL "Default assembly compiler debug build flags")

### Release Flags
SET(CMAKE_C_FLAGS_RELEASE	 "${FLAGS_RELEASE}"	CACHE	INTERNAL "Default C compiler release build flags.")
SET(CMAKE_CXX_FLAGS_RELEASE	"${FLAGS_RELEASE}"	CACHE	INTERNAL "Default C++ compiler release build flags.")
SET(CMAKE_ASM_FLAGS_RELEASE	"${FLAGS_RELEASE}"	CACHE	INTERNAL "Default asm compiler release build flags.")
