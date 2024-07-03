cmake_minimum_required (VERSION 3.15)
cmake_policy(SET CMP0091 NEW)
project (baltech_sdk C)

# output all runtime (.exe/.dll) files into the same directory, as otherwise
# the appnote*.exe files will not find the brp_lib.dll
math(EXPR PLATFORM_WORDSIZE "8*${CMAKE_SIZEOF_VOID_P}")
if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    if (MINGW)
        set (PLATFORM_NAME mingw-win)
    else()
        set (PLATFORM_NAME win)
    endif()
elseif (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    set (PLATFORM_NAME linux)
elseif (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set (PLATFORM_NAME mac)
else()
    message(FATAL_ERROR "This Platform is not supported")
endif()
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/binaries/${PLATFORM_NAME}${PLATFORM_WORDSIZE})
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/static-libs)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

set_property(GLOBAL PROPERTY USE_FOLDERS ON)


# sub projects of this SDK
add_subdirectory(brp_lib)
add_subdirectory(baltech_api/c)
add_subdirectory(appnotes)
add_subdirectory(legacy_wrapper)



# This is only required for unit-testing
if (EXISTS "${PROJECT_SOURCE_DIR}/.pytest-headlock/CMakeLists.txt")
    if(MINGW)
        add_subdirectory(.pytest-headlock  unittests)
    endif()
endif()


# if building without use of tasks.py run necessary parts of tasks.py
# implicitly at least once.
if (NOT EXISTS "${PROJECT_SOURCE_DIR}/brp_lib/src/release.h")
    execute_process(COMMAND tox copy-release-h)
endif()
if (NOT EXISTS "${PROJECT_SOURCE_DIR}/brp_lib/src/namelists.h")
    execute_process(COMMAND tox gen-namelists)
endif()
if (NOT EXISTS "${PROJECT_SOURCE_DIR}/baltech_api/c/baltech_api.c")
    execute_process(COMMAND tox c-wrapper)
endif()
