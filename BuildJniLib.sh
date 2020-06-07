#!/bin/bash
echo "start to compile...."

gcc -lstdc++ -dynamiclib -I /Library/Java/JavaVirtualMachines/jdk1.8.0_131.jdk/Contents/Home/include/ cpp/*.cpp -o cpp/libhelloworld.jnilib

echo "complete."