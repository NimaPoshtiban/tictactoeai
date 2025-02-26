cmake_minimum_required(VERSION 3.12)

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

# Set output directories for the C++ library
set_target_properties(ai PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)

# --- SBCL Compilation for Lisp ---

# Find SBCL executable
find_program(SBCL_EXECUTABLE sbcl)
if(NOT SBCL_EXECUTABLE)
    message(FATAL_ERROR "SBCL not found. Please install SBCL and ensure 'sbcl' is in your PATH.")
endif()

# Define the Lisp source file and output FASL file
set(LISP_SOURCE "${CMAKE_SOURCE_DIR}/minmax.lisp")
set(LISP_FASL "${CMAKE_BINARY_DIR}/minmax.fasl")

# Custom command to compile the Lisp file to FASL
add_custom_command(
    OUTPUT ${LISP_FASL}
    COMMAND ${SBCL_EXECUTABLE} --noinform --eval "(compile-file \"${LISP_SOURCE}\")" --eval "(quit)"
    DEPENDS ${LISP_SOURCE}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Compiling minmax.lisp to minmax.fasl"
)

# Custom target to ensure the FASL is built
add_custom_target(lisp_fasl ALL DEPENDS ${LISP_FASL})

# Optional: Create a standalone executable from the Lisp file
set(LISP_EXE "${CMAKE_BINARY_DIR}/bin/minmax${CMAKE_EXECUTABLE_SUFFIX}")
add_custom_command(
    OUTPUT ${LISP_EXE}
    COMMAND ${SBCL_EXECUTABLE} --noinform --load "${LISP_SOURCE}" --eval "(sb-ext:save-lisp-and-die \"${LISP_EXE}\" :toplevel (lambda () (format t \"Minmax running~%\") (finish-output) 0) :executable t)"
    DEPENDS ${LISP_SOURCE}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Building standalone Lisp executable: minmax"
)

# Custom target for the executable
add_custom_target(lisp_exe ALL DEPENDS ${LISP_EXE})

# Ensure the C++ library is built before the Lisp targets (if they need to interact)
add_dependencies(lisp_fasl ai)
add_dependencies(lisp_exe ai)