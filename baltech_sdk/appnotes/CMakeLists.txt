cmake_minimum_required (VERSION 3.12)
project(appnotes C)



# App Note USB/HID -------------------------------------------------------------
add_executable(appnote_usb_hid usb_hid/appnote_usb_hid.c)
target_link_libraries(appnote_usb_hid baltech_api)
set_target_properties(appnote_usb_hid PROPERTIES FOLDER "Application Notes")


# App Note USB/CDC -------------------------------------------------------------
add_executable(appnote_usb_cdc usb_cdc/appnote_usb_cdc.c)
target_link_libraries(appnote_usb_cdc baltech_api)
set_target_properties(appnote_usb_cdc PROPERTIES FOLDER "Application Notes")


# App Note VHL -----------------------------------------------------------------
add_executable(appnote_vhl vhl/appnote_vhl.c)
target_link_libraries(appnote_vhl baltech_api)
set_target_properties(appnote_vhl PROPERTIES FOLDER "Application Notes")


# App Note Secure Communication ------------------------------------------------
add_executable(appnote_secure_communication secure_communication/appnote_secure_communication.c)
target_link_libraries(appnote_secure_communication baltech_api)
set_target_properties(appnote_secure_communication PROPERTIES FOLDER "Application Notes")


#- Appnote Reader Update -------------------------------------------------------
add_executable(appnote_reader_update reader_update/appnote_reader_update.c)
target_link_libraries(appnote_reader_update baltech_api)
set_target_properties(appnote_reader_update PROPERTIES FOLDER "Application Notes")


# App Note TCP Client ----------------------------------------------------------
add_executable(appnote_tcp_client tcp_client/appnote_tcp_client.c)
target_link_libraries(appnote_tcp_client baltech_api)
if(WIN32)
    target_link_libraries(appnote_tcp_client ws2_32)
endif(WIN32)
file(RELATIVE_PATH REL_SRC_DIR ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} ${CMAKE_CURRENT_SOURCE_DIR}/tcp_client)
target_compile_definitions(appnote_tcp_client PUBLIC
    "SRC_DIR=\"${REL_SRC_DIR}\""
    _CRT_SECURE_NO_WARNINGS=)
set_target_properties(appnote_tcp_client PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
set_target_properties(appnote_tcp_client PROPERTIES FOLDER "Application Notes")


# App Note TCP Server ----------------------------------------------------------
add_executable(appnote_tcp_server tcp_server/appnote_tcp_server.c)
target_link_libraries(appnote_tcp_server baltech_api)
if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    target_link_libraries(appnote_tcp_server ws2_32)
endif()
if (${CMAKE_SYSTEM_NAME} MATCHES "Windows" OR ${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    file(RELATIVE_PATH REL_SRC_DIR ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Release ${CMAKE_CURRENT_SOURCE_DIR}/tcp_server)
else()
    file(RELATIVE_PATH REL_SRC_DIR ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} ${CMAKE_CURRENT_SOURCE_DIR}/tcp_server)
    message(${REL_SRC_DIR})
endif()
target_compile_definitions(appnote_tcp_server PUBLIC
    "SRC_DIR=\"${REL_SRC_DIR}\""
    _CRT_SECURE_NO_WARNINGS=)
set_target_properties(appnote_tcp_server PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
set_target_properties(appnote_tcp_server PROPERTIES FOLDER "Application Notes")


# App Note UDP Introspection ---------------------------------------------------
add_executable(appnote_udp_introspection udp_introspection/appnote_udp_introspection.c)
if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    target_link_libraries(appnote_udp_introspection ws2_32)
endif()
set_target_properties(appnote_udp_introspection PROPERTIES FOLDER "Application Notes")


# App Note BrpDriver -----------------------------------------------------------
add_executable(appnote_brpdriver brpdriver/appnote_BrpDriver.c)
target_link_libraries(appnote_brpdriver BrpDriver)
set_target_properties(appnote_brpdriver PROPERTIES FOLDER "Application Notes")


# App Note CSharp --------------------------------------------------------------
if(${CMAKE_GENERATOR} MATCHES "Visual Studio ([^89]|[89][0-9])")
    cmake_minimum_required (VERSION 3.8)    # C# support was added in CMake 3.8
    enable_language(CSharp)
    add_executable(appnote_c_sharp c_sharp/appnote_c_sharp.cs)
    target_link_libraries(appnote_c_sharp brp_lib)
    set_property(TARGET appnote_c_sharp PROPERTY WIN32_EXECUTABLE FALSE)
    set_target_properties(appnote_c_sharp PROPERTIES FOLDER "Application Notes")
endif()


# App Note MemPool -------------------------------------------------------------
add_executable(appnote_mempool mempool/appnote_mempool.c)
target_link_libraries(appnote_mempool baltech_api)
set_target_properties(appnote_mempool PROPERTIES FOLDER "Application Notes")
