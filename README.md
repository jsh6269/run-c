# How to run C++

## g++ (Windows)

```
mkdir build-gpp
cp *.cpp *.h build-gpp/
cd build-gpp
g++ main.cpp helper.cpp -o main
./main
```

## gcc (Windows)

g++을 놔두고 왜 gcc를 찾나 싶지만 옵션을 설정하면 gcc도 가능하다.

```
mkdir build-gcc
cp *.cpp *.h build-gpp/
cd build-gcc
gcc main.cpp helper.cpp -o main -lstdc++ -std=c++17
./main
```

## clang (Mac)

```
mkdir build-clang
cp *.cpp *.h build-clang/
cd build-clang
clang++ main.cpp helper.cpp -o main
./main
```

## mingw32-make: Makefile

Makefile이 존재하는지 확인

```
mkdir build-make
cp *.cpp *.h Makefile build-make/
cd build-make
mingw32-make clean
mingw32-make
./main
```

## CMake

CMakeLists.txt가 존재하는지 확인  
깔끔한 작업을 위해 build 폴더에서 진행

### MinGW

```
mkdir build-mingw
cd build-mingw
cmake -G "MinGW Makefiles" ..
mingw32-make
./main
```

## Ninja

```
mkdir build-ninja
cd build-ninja
cmake -G "Ninja" ..
ninja
./main
```

### Visual Studio: vcxproj

```
mkdir build-vs
cd build-vs

# cmake --help로 사용 가능한 generator를 확인
# The following generators are available on this platform ~ 문구 확인
cmake -G "Visual Studio 17 2022" ..
cmake --build .
./Debug/main
```

### Unix

WSL (Windows Subsystem for Linux) 설정  
wsl terminal 열기

```
sudo apt update
sudo apt install build-essential cmake
cmake --version
mkdir build-unix
cd build-unix
cmake -G "Unix Makefiles" ..
make
./main
```

## CMake Preset

```
cmake --preset mingw
cd build-mingw-preset
mingw32-make
./main

cd ..
cmake --preset ninja
cd build-ninja-preset
ninja
./main
```

## meson

meson 설치 후 환경변수 설정 필요

```
pip install meson ninja
meson --version
meson setup build-meson
meson compile -C build-meson
./build-meson/main
```

## Docker

```
docker build -t my-cpp-app .
docker run --rm my-cpp-app
```
