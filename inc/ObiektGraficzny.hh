#ifndef OBIEKTGRAFICZNY_HH
#define OBIEKTGRAFICZNY_HH

#include <iostream>
#include "Wektor2D.hh"
#include "zbiorWierzcholkow.hh"



class ObiektGraficzny {
public:
    zbiorWierzcholkow wierzcholkiGlob;
    Wektor2D polozenieGlob;
    double katObrotuGlob;
    int rozmiar;
};


#endif
