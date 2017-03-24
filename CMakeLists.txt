cmake_minimum_required( VERSION 2.8 )
set(CMAKE_BUILD_TYPE Release)
project (BatailleNavale)

include_directories(lib)

file(GLOB SOURCES "src/*.cpp")

include_directories(/usr/include)
link_directories(/usr/include/allegro)

add_executable(BN ${SOURCES} lib/myhelpers.h src/myhelper.cpp)
