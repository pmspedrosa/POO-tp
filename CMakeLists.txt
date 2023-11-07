cmake_minimum_required(VERSION 3.26)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp
        territorio.cpp
        territorio.h
        Mundo.cpp
        Mundo.h
        tecnologias.cpp
        tecnologias.h
        Continente.cpp
        Continente.h
        Ilha.cpp
        Ilha.h
        Imperio.cpp
        Imperio.h
        Interface.cpp
        Interface.h)
