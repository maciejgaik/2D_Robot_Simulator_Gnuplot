/*!
 * \file
 * \brief Zawiera definicje metod klasy Przeszkoda
 *
 * Zawiera definicje metod klasy Przeszkoda
 * wraz z ich opisem.
 */

#include "Przeszkoda.hh"

void Przeszkoda::korpus(){
    roz = 3 * jakiRozmiar();
    ustalPolozenie();
    wierzcholkiLok.DodajWierzcholek(-roz,-roz);
    wierzcholkiLok.DodajWierzcholek(roz,-roz);
    wierzcholkiLok.DodajWierzcholek(roz,roz);
    wierzcholkiLok.DodajWierzcholek(-roz,roz);
    wierzcholkiLok.DodajWierzcholek(-roz,-roz);
    
    for( int i = 0; i < wierzcholkiLok.rozmiar(); i++){
        wierzcholkiGlob.DodajWierzcholek(wierzcholkiLok.zwrocWierz(i) + polozeniePoczatkowe); }
}

int Przeszkoda::jakiRozmiar(){
    int roz;
    std::cout << "Podaj rozmiar przeszkody w zakresie 1-10" << std::endl;
    std::cin >> roz;
    if(roz > 10 || roz < 1){ std::cout << "Poza dozwolonym zakresem. Ustawiono rozmiar domyslny = 5" << std::endl; return 10;}
    roz *= 3;
    rozmiar = roz;
    return roz;
}


void Przeszkoda::ustalPolozenie(){
    std::cout << "Podaj wspolrzedna x, y polozenia poczatkowego oddzielone spacja" << std::endl;
    std::cin >> polozeniePoczatkowe; std::cout << std::endl;
    polozenieGlob[0] = polozeniePoczatkowe[0]; polozenieGlob[1] = polozeniePoczatkowe[1];
}

