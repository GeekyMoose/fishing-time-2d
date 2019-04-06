#!/bin/bash


TARGET_EXE=raining-shark.out

rm $TARGET_EXE >> /dev/null 2>&1

gcc -g -Wall \
    -I./extern/glfw/include \
    -I./extern/glew/include \
    ./src/main.c \
    ./extern/glfw/bin/libglfw3.a \
    ./extern/glew/bin/libGLEW.a \
    -o $TARGET_EXE


