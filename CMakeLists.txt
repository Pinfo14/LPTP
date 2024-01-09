cmake_minimum_required(VERSION 3.27)
project(LPTP C)

set(CMAKE_C_STANDARD 11)

add_executable(LPTP main.c
        company.h
        company.c
        input.h
        input.c
        menu.h
        menu.c
        businessLines.h
        businessLines.c
)
