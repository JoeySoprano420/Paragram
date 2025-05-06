@echo off
setlocal

REM -- Path setup: ensure VS Developer Command Prompt is used
REM -- Assumes nasm.exe is in PATH

echo [CMAKE.BAT] Assembling out.asm to out.obj...
nasm -f win64 out.asm -o out.obj
if errorlevel 1 (
    echo Error during NASM assembly.
    exit /b 1
)

echo [CMAKE.BAT] Linking with MSVC LINK.exe...
ld -o paragram out.o -lc -dynamic-linker /lib64/ld-linux-x86-64.so.2 -e _start
if errorlevel 1 (
    echo Error during LINK step.
    exit /b 1
)

echo [CMAKE.BAT] Done! Built: paragram.exe
endlocal
