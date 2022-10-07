#include <iostream> // cout
#include <iomanip> // setw

// #include "circle.h"
// #include "circle.h"
#include "../include/circle_base.h"

void test_circle_base() {

const std::string name = "hello" ;

    CircleBase c = CircleBase(10) ;
    printf("%p -> %f\n", &c, c.get_rayon()) ;
}

// void test_circle() {

// const std::string name = "hello" ;

//     Circle c = Circle(10, name) ;
//     printf("%p -> %f / %s / %s\n", &c, c.get_rayon(), c.get_name().c_str(), c.get_data()) ;
// }

void test_stdstring(const std::string& s)
{
    std::cout << '-' << std::setw(20) << s << '-' << std::endl ;

}
int main(int argc, char *argv[])
{
std::string s = "hello" ;

	std::cout << "Hello world!" << std::endl << std::endl ;
    test_circle_base() ;
    test_stdstring(s) ;
}