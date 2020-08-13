#!/bin/bash

build(){
    rm -rf build/
    mkdir build
    cd build
    cmake ..
    make -j4
}

plots(){
    rm -rf plots
    mkdir plots
} 

if [[ $1 == "--build" ]]; then
    build
elif [[ $1 == "--run" ]]; then
    plots
    ./build/ACC | python3 ./tests/main.py
else
    build
    ./ACC
fi
