#ifndef _CIRCLEBASE_HPP
#define _CIRCLEBASE_HPP

#include <string>

class CircleBase {
    public:
        // methodes
                // CTOR / DTOR
                CircleBase(float ray) ;
                CircleBase(const CircleBase& c) ;
                ~CircleBase() ;
                // OPTOR
                CircleBase& operator=(const CircleBase& c) ;

                // ACSOR
                float get_rayon() const { return this->rayon ; }

        // Methodes fonctionnelles
        virtual std::string& get_classname() const ;
        virtual bool operator==(const CircleBase& other) const ;

        // working methode
        virtual float ComputeSurface() const ;
        virtual float ComputePerimetre() const ;

        // Attributs
    private:
        float       rayon ;
} ;

#else
    #pragma message(__FILE__ " _CIRCLEBASE_HPP ALREADY INCLUDED")
#endif