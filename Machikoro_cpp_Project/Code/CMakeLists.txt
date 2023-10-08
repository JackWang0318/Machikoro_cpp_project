cmake_minimum_required(VERSION 3.16)
project(cpp-project)

set(CMAKE_CXX_STANDARD 14)
set(DCMAKE_SH="CMAKE_SH-NOTFOUND")

add_executable(cpp-project main.cpp Constant.h Card_1.0.h Card_1.0.cpp Controler.h Player.h version.cpp version.h Player.cpp desk_1.0.cpp desk_1.0.h Controler.cpp Card_2.0.h Card_2.0.cpp desk_2.0.h desk_2.0.cpp)