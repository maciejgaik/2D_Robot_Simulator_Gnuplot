/*!
 * \file
 * \brief Zawiera definicje metod klasy Robot
 *
 * Zawiera definicje metod klasy Robot
 * wraz z ich opisem.
 */



#include "Robot.hh"

void Robot::korpus() {
        int roz = jakiRozmiar();
        ustalPolozenie();
        ustalPredkosc();
        wierzcholkiLok.DodajWierzcholek(0,0);
        wierzcholkiLok.DodajWierzcholek(roz,0);
        wierzcholkiLok.DodajWierzcholek(0,-roz);
        wierzcholkiLok.DodajWierzcholek(-roz,-roz);
        wierzcholkiLok.DodajWierzcholek(-roz,roz);
        wierzcholkiLok.DodajWierzcholek(0,roz);
        wierzcholkiLok.DodajWierzcholek(roz,0);

    for( int i = 0; i < wierzcholkiLok.rozmiar(); i++){
        wierzcholkiGlob.DodajWierzcholek(wierzcholkiLok.zwrocWierz(i) + polozeniePoczatkowe); }
    
}

void Robot::ustalPredkosc(){
    int v;
    std::cout << "Podaj predkosc robota w zakresie 1-10" << std::endl;
    std::cin >> v;
    if(v > 10 || v < 1){ std::cout << "Poza dozwolonym zakresem. Ustawiono predkosc domyslna = 5" << std::endl; v=5;}
    predkoscRuchu = 50000/v; predkoscObrotu = 125000/v ;
}

int Robot::jakiRozmiar(){
    int roz;
    std::cout << "Podaj rozmiar robota w zakresie 1-10" << std::endl;
    std::cin >> roz;
    if(roz > 10 || roz < 1){ std::cout << "Poza dozwolonym zakresem. Ustawiono rozmiar domyslny = 5" << std::endl; return 10;}
    roz *= 2;
    rozmiar = roz;
    return roz;
}


void Robot::ustalPolozenie(){
    Wektor2D tmp;
    std::cout << "Podaj wspolrzedna x, y polozenia poczatkowego oddzielone spacja" << std::endl;
    std::cin >> tmp; std::cout << std::endl;
    polozeniePoczatkowe[0] = tmp[0]; polozeniePoczatkowe[1] = tmp[1];
    polozenieGlob[0] = polozeniePoczatkowe[0]; polozenieGlob[1] = polozeniePoczatkowe[1];
    sciezkaRob.sciezka.DodajWierzcholek(polozeniePoczatkowe);
}

