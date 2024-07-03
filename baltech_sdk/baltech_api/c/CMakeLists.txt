cmake_minimum_required (VERSION 3.0)
project (brp_lib C)


add_library(baltech_api STATIC baltech_api.c)
target_include_directories(baltech_api INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(baltech_api brp_lib)
set_target_properties(baltech_api PROPERTIES FOLDER "BRP Lib")
