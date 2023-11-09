cmake_minimum_required(VERSION 3.12)

# Set the project name and version
project(cy_daily VERSION 1.0)

# Define build options
option(BUILD_HASH "Build hash cpp" ON)
option(BUILD_DEBUG "Enable gcc -g option" ON)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Compiler option
add_compile_options(-Wall -Wextra -Wpedantic)

# Create a separate build directory
set(BUILD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build)

# Make sure the build directory exists
file(MAKE_DIRECTORY ${BUILD_DIR})

# Move to the build directory
execute_process(
    COMMAND ${CMAKE_COMMAND} -E chdir ${BUILD_DIR}
)

# Macro to build all source file
macro(add_executables_from_subdirectory subdir)
    file(MAKE_DIRECTORY ${BUILD_DIR}/${subdir})
    file(GLOB SOURCES "${subdir}/*.cpp")

    foreach(SOURCE ${SOURCES})
            get_filename_component(EXEC_NAME ${SOURCE} NAME_WE)
            add_executable(${EXEC_NAME} ${SOURCE})
            set_target_properties(${EXEC_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BUILD_DIR}/${subdir})
    endforeach()
endmacro()

# Build with debug
if(BUILD_DEBUG)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Optionally, build tests based on the BUILD_TESTS option
if(BUILD_HASH)
    add_executables_from_subdirectory(hash)
    message(STATUS "Build hash test")
endif()

