@echo off

set VC_DIR=D:\Program Files (x86)\Microsoft Visual Studio 12.0\VC
set MSDK_DIR=C:\Program Files (x86)\Microsoft SDKs\Windows\v7.1A
set QT_DIR=D:\Qt\Qt5.4.2\5.4\msvc2013_opengl
set INCLUDE=%VC_DIR%\include;%MSDK_DIR%\Include
set LIB=%MSDK_DIR%\Lib;%VC_DIR%\lib
set SRC_DIR=%cd%
set BUILD_DIR=%cd%\QPoisson
set PATH=%VC_DIR%\bin;%MSDK_DIR%\Bin;%QT_DIR%\bin

if not exist %QT_DIR% exit
if not exist %SRC_DIR% exit
if not exist %BUILD_DIR% md %BUILD_DIR%

cd QPoisson

%QT_DIR%\bin\qmake.exe %SRC_DIR%\QPoisson.pro -spec win32-msvc2013  "CONFIG+=debug" "CONFIG+=console"
if exist %BUILD_DIR%\Debug\QPoisson.exe del %BUILD_DIR%\Debug\QPoisson.exe
nmake Debug
if not exist %BUILD_DIR%\Debug\Qt5Cored.dll (
  %QT_DIR%\bin\windeployqt.exe %BUILD_DIR%\Debug\QPoisson.exe
)