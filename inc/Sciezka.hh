#ifndef Sciezka_hh
#define Sciezka_hh

#include <iostream>
#include "zbiorWierzcholkow.hh"
#include <fstream>
#include "ObiektGraficzny.hh"
#include "Wektor2D.hh"

/*!
 * \file
 * \brief Zawiera definicję klasy Sciezka
 *
 *  Plik zawiera definicję klasy Sciezka
 *  Zawiera punkty sciezki robota
 */

class Sciezka : public ObiektGraficzny{
public:
    /*!
     * \brief Pole zawiera kolejne punkty sciezki robota
     */
    zbiorWierzcholkow sciezka;


};

#endif 
