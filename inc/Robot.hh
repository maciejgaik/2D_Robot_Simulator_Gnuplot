#ifndef Robot_hh
#define Robot_hh

#include <iostream>
#include "Macierz.hh"
#include "zbiorWierzcholkow.hh"
#include "ObiektGraficzny.hh"
#include "Sciezka.hh"
#include "Wektor2D.hh"

/*!
 * \file
 * \brief Zawiera definicję klasy Robot
 *
 *  Plik zawiera definicję klasy Robot
 *  Inicjalizuje jego ksztalt i rozmiar
 */


class Robot : public ObiektGraficzny{
public:
    /*!
     * \brief Pole zawiera wierzcholki globalne robot
     */
    zbiorWierzcholkow wierzcholkiLok;
    /*!
     * \brief Pole zawiera sciezke robot
     */
    Sciezka sciezkaRob;
    /*!
     * \brief Pole zawiera polozenie poczatkowe robot
     */
    Wektor2D polozeniePoczatkowe;
    /*!
     * \brief Metoda inizalizuje korpus robota
     */
    void korpus();
    /*!
     * \brief Pole zawiera predkosc ruchu robota
     */
    int predkoscRuchu = 10000;
    /*!
     * \brief Pole zawiera predkosc obrotu robota
     */
    int predkoscObrotu = 25000;
    /*!
     * \brief Metoda inizalizuje predkosc robota
     */
    void ustalPredkosc();
    /*!
     * \brief Metoda inizalizuje rozmiar robota
     */
    int jakiRozmiar();
    /*!
     * \brief Metoda inizalizuje polozenie poczatkowe robota
     */
    void ustalPolozenie();
    
    
};

#endif
