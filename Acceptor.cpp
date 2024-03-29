//
// Created by Jialu  Hu on 2019-8-3.
//
#include "Acceptor.h"
Acceptor::Acceptor(EventLoop *loop,
        InetAddr &addr)
        :loop_(loop),
        addr_(addr),
        AcceptorChannle_(new Channel(loop,socket_.sockfd())),
        socket_(SocketOpt::socket())
        {
    std::cout << "Acceptor is build$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
    addr_.Init();
    SocketOpt::setnonblocking(socket_.sockfd());
    SocketOpt::bind(socket_.sockfd(),addr_.inetaddr());
    AcceptorChannle_->setReadCallback([this]{ this->handleAccept();});
}

Acceptor::~Acceptor() {
    std::cout << "~Acceptor\n";

}

void Acceptor::listen() {
    //开启监听套接字
    SocketOpt::listen(socket_.sockfd());
    std::cout << "socket_sockfd():" << socket_.sockfd() << std::endl;
    //向channel中注册可读事件,进行accept
    AcceptorChannle_->enableReading();
}

void Acceptor::handleAccept() {
    int connfd = SocketOpt::accept(socket_.sockfd());
    SocketOpt::setnonblocking(connfd);
    if(connfd > 0){
        std::cout << "连接成功\n";
        if(_newConnectionCb){
            _newConnectionCb(connfd,addr_);
        }else{
            ::close(connfd);
        }
    }
}