#ifndef zbiorWierzcholkow_hh
#define zbiorWierzcholkow_hh

#include <vector>
#include "Wektor2D.hh"
#include <iostream>

/*!
 * \file
 * \brief Zawiera definicję klasy zbiorWierzcholkow
 *
 *  Plik zawiera definicję klasy zbiorWierzcholkow
 *  Zawiera metody pozwalajce na dodawanie, usuwanie, zmienianie danych w kontenerze danych
 */

class zbiorWierzcholkow{
    /*!
     * \brief Pole zawiera kontener danych o nazwie wierzcholki
     */
    std::vector<Wektor2D> wierzcholki;
public:
    /*!
     * \brief Metoda pozwala na dodanie wierzcholka w formacie x y do kontenera danych
     */
    void DodajWierzcholek(Wektor2D wek){wierzcholki.push_back(wek);};
    /*!
     * \brief Metoda pozwala na dodanie wektora do kontenera danych
     */
    void DodajWierzcholek(float x, float y){Wektor2D Wek(x, y); wierzcholki.push_back(Wek);};
    /*!
     * \brief Metoda uwuwa wysztkie elementy z kontenera
     */
    void UsunWszystkie(){ wierzcholki.clear(); };
    /*!
     * \brief Metoda pozwala na zmiane ostatniego elementu w kontenerze danych
     */
    void ZmienOstatni(Wektor2D Wek){wierzcholki.at(wierzcholki.size()-1)=Wek;};
    /*!
     * \brief Metoda zwraca rozmiar kontenera danych
     */
    int rozmiar() const {return wierzcholki.size();};
    /*!
     * \brief Metoda zwaraca wybrany element kontenera
     */
    Wektor2D &zwrocWierz(int x) {return wierzcholki.at(x);};
    /*!
     * \brief Metoda zwaraca wybrany element kontenera
     */
    Wektor2D zwrocWierz(int x) const {return wierzcholki.at(x);};
};


#endif
