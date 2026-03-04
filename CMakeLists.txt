cmake_minimum_required(VERSION 3.16)

project(juicer)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(juicer
    src/juicer.c
    src/lib/compression/rle/rle.c
    src/lib/utils/config.c
)

target_include_directories(juicer PRIVATE
    ${PROJECT_SOURCE_DIR}/src
)