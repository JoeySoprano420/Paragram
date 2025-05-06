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
link out.obj /SUBSYSTEM:CONSOLE /ENTRY:mainCRTStartup /OUT:paragram.exe kernel32.lib user32.lib msvcrt.lib legacy_stdio_definitions.lib
if errorlevel 1 (
    echo Error during LINK step.
    exit /b 1
)

echo [CMAKE.BAT] Done! Built: paragram.exe
endlocal
