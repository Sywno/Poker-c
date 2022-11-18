#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <vector>
#include <map>

enum Colors { COEUR=67, CARREAU=75, PIQUE=80, TREFLE=84 } ;
enum Values { UN=1, DEUX, TROIS, QUATRE, CINQ, SIX, SEPT, HUIT, NEUF, DIX, VALET, DAME, ROI, AS } ;

class Card
{
    public:
        static std::vector<std::string> StringValues ;
        static std::map<int, std::string> StringColors ;
    public:
        Card(int color, int value);
        virtual ~Card();
        Card(const Card& other);
        Card& operator=(const Card& other);

        friend std::ostream& operator<<(std::ostream& o, const Card& c) ;

        int Getm_value() const { return m_value; }
        int Getm_color() const { return m_color; }
        std::string& Getm_str() const { return (std::string&)m_str ; }

        bool operator==(const Card& other) const ;
        bool operator<(const Card& other) const ;
        bool operator>(const Card& other) const ;

    protected:
        void Setm_value(unsigned int value) ; // { m_value = val; }
        void Setm_color(unsigned int color) ; // { m_color = val; }
        void _make_string() ;

    private:
        int m_value;
        int m_color;
        std::string m_str ;

};

#else

extern std::vector<std::string> StringValues ;
extern std::map<int, std::string> StringColors ;

#endif // CARD_H
