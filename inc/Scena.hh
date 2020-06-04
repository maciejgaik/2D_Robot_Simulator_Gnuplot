#ifndef scena_hh
#define scena_hh

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <memory>
#include <unistd.h>

#include "lacze_do_gnuplota.hh"
#include "ObiektGraficzny.hh"
#include "Macierz.hh"
#include "Robot.hh"
#include "Przeszkoda.hh"
#include "Wektor2D.hh"


/*!
 * \file
 * \brief Zawiera definicję klasy Scena
 *
 *  Plik zawiera definicję klasy Scena
 *  Inicjalizuje lacze do GNUPlota i Robota
 */
class Scena{
public:
    PzG::LaczeDoGNUPlota  Lacze;
    int ktory = 0;
    std::vector<std::shared_ptr<Robot>> roboty;
    std::vector<std::shared_ptr<ObiektGraficzny>> obiekty;

    /*!
     * \brief Metoda zapisuje do plikow wierzcholki globalne robota i jego sciezke
     */
    void Rysuj(){ ZapiszDoPliku("figury/scena.dat"); Lacze.Rysuj();};
    /*!
     * \brief kontruktor bezparametryczny inizalizuje odpowiednie ustawienia GNUPlota
     */
    Scena(){
        Lacze.DodajNazwePliku("figury/scena.dat",PzG::RR_Ciagly,2);
        Lacze.ZmienTrybRys(PzG::TR_2D); };
    /*!
     * \brief Metoda zapisuje do pliku
     */
    bool ZapiszDoPliku(const char* sNazwaPliku) const;
    /*!
     * \brief Metoda sprawdza strumien wyjsciowy zapisu
     */
    bool ZapiszDoStrumienia(std::ostream& StrmWy) const;
    /*!
     * \brief Metoda realizuje obrot robota
     */
    void obrot(double beta);
    /*!
     * \brief Metoda zmienia polozenie robota na podane wsporzednne
     */
    void ZmienPolozenie(float x, float y);
    /*!
     * \brief Metoda przesuwa robota o podany wektor
     */
    void ruszOWektor(Wektor2D wek);
    /*!
     * \brief Metoda realizuje ruch robota
     */
    void jedz(double odleglosc);
    /*!
     * \brief Metoda porusza robotem tworzac okrag
     */
    void okrag();
    /*!
     * \brief Metoda porusza robotem az dotrze do wyznaczonego celu
     */
    void jedzDoCelu(Wektor2D gdzie);
    /*!
     * \brief Metoda pozwala na dodanie robota
     */
    void dodajRobota();
    /*!
     * \brief Metoda sprawdza czy wystepuje kolizja z innymi obiektami
     */
    bool czyKolizja();
    /*!
     * \brief Metoda pozwla dodac nowa przeszkode
     */
    void dodajPrzeszkode();
    /*!
     * \brief Metoda pozwala zmienic obecnie uzywany robot na inny
     */
    void zmienRobota();
  
};

#endif 
