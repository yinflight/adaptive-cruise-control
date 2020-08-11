#!/bin/bash

build(){
    rm -rf build/
    mkdir build
    cd build
    cmake ..
    make -j4
}

if [[ $1 == "--build" ]]; then
    build
elif [[ $1 == "--run" ]]; then
    ./build/ACC | python3 ./tests/plot.py
else
    build
    ./ACC | python3 ../tests/plot.py
fi
