cmake_minimum_required (VERSION 3.15)
cmake_policy(SET CMP0091 NEW)
project (BrpDriver C)

add_library(BrpDriver SHARED
        src/wrapper.c
        src/drv_info.c
        src/ftob.c
        src/iso14443_3a.c
        src/iso14443_3b.c
        src/iso14443_4.c
        src/iso15693.c
        src/mifcmds.c
        src/syscmds.c
        src/vhl.c
        src/BrpDriver.def)
target_include_directories(BrpDriver PUBLIC
        inc)
target_include_directories(BrpDriver PRIVATE
        ..)    # is needed to compile brp_lib even if release.h is not copied
target_compile_definitions(BrpDriver PRIVATE
        _CRT_SECURE_NO_WARNINGS=""
        BRP_SDK_COMPATIBILITY="")
target_link_libraries(BrpDriver PUBLIC
        brp_lib)
set_target_properties(BrpDriver PROPERTIES
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>"
        FOLDER                  "Legacy Lib")
if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    set_target_properties(BrpDriver PROPERTIES
            BUILD_RPATH_USE_ORIGIN     "TRUE")
elseif (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set_target_properties(BrpDriver PROPERTIES
            INSTALL_RPATH              "@loader_path"
            BUILD_WITH_INSTALL_RPATH   "TRUE")
endif()
