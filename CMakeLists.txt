cmake_minimum_required(VERSION 3.15)
project(ParagramCompiler)

set(CMAKE_CXX_STANDARD 17)

# Compiler source
add_executable(parac src/compiler.cpp)

# NASM
enable_language(ASM_NASM)

# Path to NASM-compiled output
add_custom_command(
    OUTPUT output.asm
    COMMAND parac ${CMAKE_SOURCE_DIR}/src/main.para > output.asm
    DEPENDS parac
    COMMENT "Transpiling .para to .asm"
)

add_custom_command(
    OUTPUT output.exe
    COMMAND nasm -f win64 output.asm -o output.obj
    COMMAND link output.obj /OUT:output.exe
    DEPENDS output.asm
    COMMENT "Assembling with NASM and Linking"
)

add_custom_target(build_paragram ALL
    DEPENDS output.exe
    COMMENT "Full Paragram Build"
)
