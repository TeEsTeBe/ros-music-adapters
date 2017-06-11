#include "ROSInPort.h"


void
ROSInPort::init(MUSIC::Setup* setup, char* port_name)
{

    this->port_name = port_name;

}

void
ROSInPort::initROS(int argc, char** argv)
{
    ros::init(argc, argv, port_name);
    ros::start();
}

template<class M, class T>
void
ROSInPort::subscribe(std::string topic, void(T::*fp)(M)){
    ros_node.subscribe(topic, 1000, fp, this);
}


