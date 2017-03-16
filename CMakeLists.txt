cmake_minimum_required( VERSION 2.8 )
set(CMAKE_BUILD_TYPE Release)
project (BatailleNavale)

include_directories(lib)

file(GLOB SOURCES "src/*.cpp")
add_executable(BN ${SOURCES})
