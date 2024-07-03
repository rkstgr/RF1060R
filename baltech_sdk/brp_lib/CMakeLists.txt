cmake_minimum_required (VERSION 3.15)
cmake_policy(SET CMP0091 NEW)
project (brp_lib C)


#- BRPlib library --------------------------------------------------------------
if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    set(PLATFORM_SRC  src/platform_win.c)
else ()
    set(PLATFORM_SRC  src/platform_posix.c)
endif()
add_library(brp_lib SHARED
        src/brp_protocol.c
        src/commands.c
        src/composite_protocol.c
        src/frames.c
        src/pki_protocol.c
        src/security_protocol.c
        src/protocol.c
        src/tcpip_protocol.c
        src/usb_hid_protocol.c
        src/rs232_protocol.c
        src/monitor_protocol.c
        src/version.c
        src/base64.c
        src/mempool.c
        src/names.c
        ${PLATFORM_SRC})
target_include_directories(brp_lib PUBLIC
        inc)
target_include_directories(brp_lib PRIVATE
        ..)    # is needed to compile brp_lib even if release.h is not copied
target_compile_definitions(brp_lib PRIVATE
        _CRT_SECURE_NO_WARNINGS=)
target_link_libraries(brp_lib PRIVATE
        crypto-algorithms
        micro-ecc
        hidapi
        rs232)
set_target_properties(brp_lib PROPERTIES
        FOLDER "BRP Lib"
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    target_link_libraries(brp_lib PRIVATE ws2_32)
endif()
if (MSVC)
    target_compile_options(brp_lib PRIVATE "/WX")
else()
    target_compile_options(brp_lib PRIVATE "-Werror")
endif()


add_subdirectory(thirdparty)