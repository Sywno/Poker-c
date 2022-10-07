#include <iostream>

#include "circle_base.h"


CircleBase::CircleBase(float ray) {
    std::cout << "CTOR1" << std::endl ;
    this->rayon = ray ;
}

CircleBase::CircleBase(const CircleBase& c) {
    std::cout << "CTOR2" << std::endl ;

    this->rayon = c.get_rayon() ;
}

CircleBase::~CircleBase(){

    std::cout << "DTOR" << std::endl ;
}

CircleBase& CircleBase::operator=(const CircleBase& c) {
    std::cout << "OP =" << std::endl ;
    if(this == &c){
        return *this ;
    }

    this->rayon = c.get_rayon() ;
    return *this ;
}

static std::string s("CircleBase") ;
std::string& CircleBase::get_classname() const {
    return s ;
}

bool CircleBase::operator==(const CircleBase& other) const {
    std::cout << "OP ==" << std::endl ;
    return 1 ;
}

// working methode
float CircleBase::ComputeSurface() const {
    return 0.0 ;
}

float CircleBase::ComputePerimetre() const {
    return 0.0 ;
}