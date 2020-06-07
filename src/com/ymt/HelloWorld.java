package com.ymt;

/**
 * @author yumingtao
 */
public class HelloWorld {
    public native String sayHello(String name);
    public native String sayHello2(String name);

    static {
        /**
         * It is ineffective to set it dynamically,
         * refer to https://bugs.java.com/bugdatabase/view_bug.do?bug_id=4280189
         */
        //System.setProperty("java.library.path", ".");
        System.loadLibrary("helloworld");
    }

    public static void main(String[] args) {
        HelloWorld helloWorld = new HelloWorld();
        String helloString = helloWorld.sayHello(args[0]);
        System.out.println(helloString);

        helloString = helloWorld.sayHello2(args[0]);
        System.out.println(helloString);
    }
}
