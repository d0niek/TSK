#!/bin/bash

rm -rf obj bin

wx_flags=$(wx-config --cxxflags)
wx_libs=$(wx-config --libs)

cpp_files=$(find . -type f -name "*.cpp")
for file in $cpp_files
do
    dir_name=$(dirname $file)
    file_name=$(basename $file .cpp)
    if [ ! -d obj/$dir_name ]; then
        mkdir -p obj/$dir_name
    fi

    echo "Compile file: $dir_name/$file_name.cpp"

    g++ $wx_flags -Wall -g -c $file -o obj/$dir_name/$file_name.o
done

o_files=$(find obj/ -type f -name "*.o")

mkdir bin
g++ -o bin/app $o_files $wx_libs
