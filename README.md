# Thrift implementation with C++ and Java

Implementation of apache thrift for calling C++ method from Java client

Please make sure to install apache thrift on your machine from https://thrift.apache.org/ before exeuting this code

Run the C++ server from /src/main/cpp using `./ReverseStringHandler`

Run the java client located at /src/main/java/ReversedStringClient.java

The basic functionality of this code is to take a string in the java client which would be reversed and returned by the C++ code. The string before reversal and after getting reversed is printed to the console by the java application. This is an example of remotely calling a C++ method from within a java application.