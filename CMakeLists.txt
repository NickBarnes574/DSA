cmake_minimum_required(VERSION 3.16)

project(
    DSA_Library
    LANGUAGES "C"
    DESCRIPTION "DSA Library v1.0"
)

include(dsa_main.cmake)

include_directories(0_Common/include)

if (EXISTS "${CMAKE_CURRENT_LIST_DIR}/0_Common/CMakeLists.txt")
    add_subdirectory(0_Common)
endif()

if (EXISTS "${CMAKE_CURRENT_LIST_DIR}/1_Data_Structures/CMakeLists.txt")
    add_subdirectory(1_Data_Structures)
endif()

# EOF
