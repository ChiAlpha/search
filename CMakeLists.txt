cmake_minimum_required(VERSION 3.5)

project (chch)

set (source_dir "${CMAKE_SOURCE_DIR}/src/")

file (GLOB sources "${source_dir}/*.cpp")

add_executable(chch ${sources})
