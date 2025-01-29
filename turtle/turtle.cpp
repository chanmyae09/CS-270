#include "turtle.hpp"
#include <iostream>
CS270::Turtle::Turtle()
{   x=0;
    y = 0;
    heading = 0;
    pos = vecf(2);
    pos = {x, y};
}
void CS270:: Turtle ::turn_left(){
    heading+=90%360;
}

void CS270:: Turtle ::turn_right(){
    heading+=-90%360;
}

vecf CS270:: Turtle :: get_position(){
    return pos;
}

void CS270:: Turtle :: move_forward(const int& mag){
    x += mag*std::cosf(heading*M_PI/180);
    y += mag*std::sinf(heading*M_PI/180);
}

void CS270::Turtle:: reverse(){
    heading+=-90%360;
}
void CS270::Turtle::print_properties(){
    std::cout<<"x: "<<x<<std::endl;
    std::cout<<"y: "<<y<<std::endl;
    std::cout<<"heading: "<<heading<<std::endl;
}




