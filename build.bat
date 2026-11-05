@echo off

gcc -std=c17 -Wall -Wextra -Wpedantic -pedantic-errors src/main.c -o build/main.exe

if errorlevel 1 exit /b 1

echo Build Successful!