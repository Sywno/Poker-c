#include <stdexcept> // invalid_argument
#include "Card.h"

Card::Card(int color, int value)
{
    Setm_color(color) ;
    Setm_value(value) ;
    _make_string() ;
}

Card::~Card()
{
    //dtor
}

Card::Card(const Card& other)
{
    //copy ctor
    Setm_color(other.Getm_color()) ;
    Setm_value(other.Getm_value()) ;
    _make_string() ;
}

Card& Card::operator=(const Card& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    Setm_color(rhs.Getm_color()) ;
    Setm_value(rhs.Getm_value()) ;
    _make_string() ;
    return *this;
}

void Card::Setm_value(unsigned int value)
{
    //ctor
    if( value < UN || value > AS)
    {
        throw std::invalid_argument("Value is a bad argument ") ;
    }

    m_value = value;
}

void Card::Setm_color(unsigned int color)
{
    if( color != PIQUE && color != TREFLE && color != COEUR && color != CARREAU)
    {
        throw std::invalid_argument("Color is a bad argument ") ;
    }

    m_color = color;
}

bool Card::operator==(const Card& other) const
{
   return Getm_value() == other.Getm_value() ;
}
bool Card::operator<(const Card& other) const
{
   return Getm_value() < other.Getm_value() ;
}

bool Card::operator>(const Card& other) const
{
   return Getm_value() > other.Getm_value() ;
}

std::ostream& operator<<(std::ostream& o, const Card& c)
{
    o << "(" << (char)c.Getm_color() << ", " << c.Getm_value()<< ")" ;
    return o ;
}

void Card::_make_string()
{
    m_str = '(' + Card::StringColors[Getm_color()] + ", " + Card::StringValues[Getm_value()] + ')' ;
}

std::vector<std::string> Card::StringValues = { "None", "1", "2", "3", "4", "5", "6", "7", "8", "9","10", "VALET", "DAME", "ROI", "AS" } ;
std::map<int, std::string> Card::StringColors =  { { CARREAU, "CARREAU" }, {COEUR, "COEUR"} , {TREFLE, "TREFLE"}, {PIQUE, "PIQUE"} } ;
