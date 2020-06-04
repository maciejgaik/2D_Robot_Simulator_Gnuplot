#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH

#include <iostream>
#include "Macierz.hh"
#include "zbiorWierzcholkow.hh"
#include "ObiektGraficzny.hh"
#include "Sciezka.hh"

class Przeszkoda : public ObiektGraficzny {
public:
    /*!
     * \brief Pole zawiera wierzcholki globalne przeszkody
     */
    zbiorWierzcholkow wierzcholkiLok;
    /*!
     * \brief Pole zawiera polozenie poczatkowe przeszkody
     */
    Wektor2D polozeniePoczatkowe;
    /*!
     * \brief Metoda inicjalizuje rozmiar przeszkody
     */
    int roz;
    /*!
     * \brief Metoda inicjalizuje korpus przeszkody
     */
    void korpus();
    /*!
     * \brief Metoda inizalizuje rozmiar obiektu
     */
    int jakiRozmiar();
    /*!
     * \brief Metoda inicjalizuje polozenie poczatkowe obiektu
     */
    void ustalPolozenie();
};

#endif

