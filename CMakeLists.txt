﻿cmake_minimum_required(VERSION 3.12)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
    cmake_policy(SET CMP0141 NEW)
    set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project("tictactoeai")

# Add source to this project's shared library (DLL or .so for Unix-like systems).
if (WIN32)
    add_library(ai SHARED "main.cpp" "tictactoeai.cpp" "tictactoeai.h")
else()
    add_library(ai SHARED "tictactoeai.cpp" "tictactoeai.h")
endif()

if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET ai PROPERTY CXX_STANDARD 20)
endif()

# Optional: Set the output directory for the DLL or shared library
set_target_properties(ai PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)

# TODO: Add tests and install targets if needed.
