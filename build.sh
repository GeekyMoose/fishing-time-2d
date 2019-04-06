#!/bin/bash


TARGET_EXE=raining-shark.out

rm $TARGET_EXE >> /dev/null 2>&1

gcc -g -Wall \
    -I./extern/glfw/include \
    -I./extern/glew/include \
    -lX11 -lXrandr -lXinerama -lXxf86vm -lXcursor \
    -lrt -lm -ldl \
    -lpthread \
    ./src/main.c \
    ./extern/glfw/bin/libglfw3.a \
    ./extern/glew/bin/libGLEW.a \
    -o $TARGET_EXE


