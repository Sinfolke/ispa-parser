@echo off
:: Script to prepare Boost with stacktrace support on Windows

:: Set Boost version and repository details
set BOOST_REPO=https://boostorg.jfrog.io/artifactory/main/release/1.87.0/source/boost_1_87_0.zip
set BOOST_DIR=boost_1_87_0

:: Clone Boost repository with submodules
@REM echo - Downloading boost source
@REM curl -L -o boost_1_87_0.zip https://boostorg.jfrog.io/artifactory/main/release/1.87.0/source/boost_1_87_0.zip
@REM echo - Extracting boost source
@REM tar -xf boost_1_87_0.zip
@REM IF %ERRORLEVEL% NEQ 0 (
@REM     echo Error: Failed to clone Boost repository or unzip the archive.
@REM     exit /b 1
@REM )
git clone --recursive https://github.com/boostorg/boost.git
:: Navigate to Boost directory
cd %BOOST_DIR%

:: Run bootstrap to prepare the build system
echo - Running bootstrap.bat
call ./bootstrap.bat
IF %ERRORLEVEL% NEQ 0 (
    echo Error: Failed to run bootstrap.bat.
    exit /b 1
)

:: Build Boost with stacktrace support
echo - Building Boost stacktrace
set PREFIX=%cd%
b2 --build-type=minimal --with-stacktrace --with-headers install --prefix=%PREFIX%
IF %ERRORLEVEL% NEQ 0 (
    echo Error: Failed to build Boost stacktrace
    exit /b 1
)
:: Completion message
echo - Boost has been successfully prepared
exit /b 0