# CMakeList.txt : CMake project for tictactoeai, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

cmake_minimum_required(VERSION 3.12)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
    cmake_policy(SET CMP0141 NEW)
    set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project("tictactoeai")

# Add source to this project's shared library (DLL).
add_library(ai SHARED "main.cpp" "tictactoeai.cpp" "tictactoeai.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET ai PROPERTY CXX_STANDARD 20)
endif()

# Optional: Set the output directory for the DLL
set_target_properties(ai PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)

# TODO: Add tests and install targets if needed.
