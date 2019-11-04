cmake_minimum_required(VERSION 3.13)
project(Mywebserver)

set(CMAKE_CXX_STANDARD 14)

add_executable(Mywebserver main.cpp
        EventLoop.cpp EventLoop.h
        Channel.cpp Channel.h CallBack.h
        Acceptor.h Acceptor.cpp
        TcpServer.h TcpServer.cpp
        WebServer.h WebServer.cpp)