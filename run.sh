#!/bin/bash

RED=$(printf '\033[31m')
RESET=$(printf '\033[m')

while getopts "t:" flag; do
    case "${flag}" in
        t)
            runtype=${OPTARG};;
    esac
done
shift $((OPTIND - 1))

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

main(){
    if [[ $runtype == "build" ]]; then
        build
    elif [[ $runtype == "run" ]]; then
        plots
        ./build/ACC | python3 ./tests/main.py
    elif [[ $runtype == "all" ]]; then
        build
        ./ACC | python3 ../tests/main.py
    fi
}

main
