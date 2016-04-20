###
# MiniRPG
###

cmake_minimum_required(VERSION 3.5)

project(MiniRPG)

# Enable YCM autocomplete
set( CMAKE_EXPORT_COMPILE_COMMANDS 1 )

# Directory
set(SRC_DIR src)
set(LIB_DIR lib)
set(INC_DIR include)

# Flags
set(CMAKE_C_FLAGS "-Wall -Werror")
set(CMAKE_CXX_FLAGS "-Wall -Werror")

# Set Include Path
include_directories(${INC_DIR})

add_subdirectory(${LIB_DIR})
add_subdirectory(${INC_DIR})
add_subdirectory(${SRC_DIR})

