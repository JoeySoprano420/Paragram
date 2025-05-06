@echo off
cmake -S . -B build
cmake --build build
cd build
output.exe
