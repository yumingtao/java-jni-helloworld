## Introduction
1. Directory structure
   - cpp: directory contains .h, .cpp and .jnilib
   - src: java packages and files
   - BuildJniLib.sh: script to build jnilib
2. Develop a Java class include native method declaration
3. Use "javac" compile the java class

    ```
    javac HelloWorld.java
    ```
4. Use "javah -jni" generate .h file, cd to src directory run command

    ```
    javah -d ../cpp -jni com.ymt.HelloWorld
    ```
5. New a HelloWorldImpl.cpp in 'cpp' directory and implement it via C++
6. New a MyFunctions.h and MyFunctions.cpp in 'cpp' directory, implement a method 'sayHello' via C++
7. cd to 'cpp' directory
    ```
    gcc -lstdc++ -dynamiclib -I /Library/Java/JavaVirtualMachines/jdk1.8.0_131.jdk/Contents/Home/include/ *.cpp -o libhelloworld.jnilib
    ```
   if has "'jni_md.h' file not found" error, run below command
   ```
   sudo cp /Library/Java/JavaVirtualMachines/jdk1.8.0_131.jdk/Contents/Home/include/darwin/jni_md.h /Library/Java/JavaVirtualMachines/jdk1.8.0_131.jdk/Contents/Home/include
   ```
   Notes: 
    - The '-lstdc++' means use C++ standard library
    - Or run ```./BuildJniLib.sh``` directly
    - The jni lib name should not contain '_'
8. Copy the jnilib to one of the 'java.library.path', eg. '/Library/Java/Extensions'
    ```
    sudo cp libhelloworld.jnilib /Library/Java/Extensions
    ```
   Notes: 
   - It is ineffective to set 'java.library.path' dynamically in Java code, please refer to below links to get more details.
        - https://blog.csdn.net/sinianliushui/article/details/68061035
        - https://bugs.java.com/bugdatabase/view_bug.do?bug_id=4280189
9. cd to src dirctory, run
   ```
    java com/ymt/HelloWorld yumingtao
   ```
   Or run 'Main' in IDE.
   Notes: ensure that HelloWorld.class is till in com/ymt directory
10. The test result
    ```
    sayHello, yumingtao
    sayHello2, yumingtao
    Java_com_ymt_HelloWorld_sayHello...
    Java_com_ymt_HelloWorld_sayHello2...
    ```