#include <iostream>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/event.h>
#include <sys/unistd.h>
#include <fcntl.h>
#include "EventLoop.h"

int main(){
    //std::thread::id thread;
    //thread = std::this_thread::get_id();
    //std::cout << "主线程ID: " << thread << "\n";
    EventLoop loop;
    loop.loop();
    return 0;
}