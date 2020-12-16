cmake_minimum_required(VERSION 3.17)
project(Marmitaria C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Marmitaria
        main.c
        Marmitaria.c
        Marmitaria.h ArrayList.h ArrayList.c LocalStorage.h LocalStorage.c)
