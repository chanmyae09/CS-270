#include "turtle.hpp"
using namespace CS270;
#include <iostream>

int main(){
    Turtle turtle = Turtle();
    std::cout << turtle.get_position()[0] << turtle.get_position()[1];
    turtle.move_forward(5);
    turtle.turn_left();
    turtle.print_properties();
    return 0;
}