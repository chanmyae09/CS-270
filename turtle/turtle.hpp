#ifndef TURTLE_CHARLES
#define TURTLE_CHARLES

#include <string>
#include <vector>
#include <cmath>


using vecf = std::vector<float>;
using matf = std::vector<vecf>;

namespace CS270 {

class Turtle {
    private:
        float x,y,heading;
        vecf pos;

    public:
        Turtle();
        void move_forward(const int& mag);
        void turn_left();
        void turn_right();
        void reverse();
        vecf get_position();
        void print_properties();

};
}

#endif