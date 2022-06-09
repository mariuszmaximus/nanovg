cd /d %~dp0
cd ..
mkdir build

set PATH=C:\Windows\System32;C:\bin\cmake-3.23.1-windows-x86_64\bin;C:\bin\Conan\conan;C:\msys64\mingw64\bin

cd build

conan install .. --build missing
pause

cmake ..
pause

cmake --build .
pause