/*!
 * \file
 * \brief Zawiera definicje metod klasy Scena
 *
 * Zawiera definicje metod klasy Scena
 * wraz z ich opisem.
 */

#include "Scena.hh"

using namespace std;

bool Scena::ZapiszDoStrumienia(std::ostream& StrmWy) const {
    int i=0, j=0;
    for( j = 0 ; j < obiekty.size() ; j++){
        for ( i = 0; i < obiekty.at(j)->wierzcholkiGlob.rozmiar(); i++ ) {
        StrmWy << obiekty.at(j)->wierzcholkiGlob.zwrocWierz(i) << endl;
        }
        StrmWy << "#\n\n\n";
    }
    i=0; j=0;
    for( j = 0 ; j < roboty.size() ; j++){
        for( i  = 0 ; i < roboty.at(j)->sciezkaRob.sciezka.rozmiar() ; i++)
            StrmWy << roboty.at(j)->sciezkaRob.sciezka.zwrocWierz(i) << endl;
        StrmWy << "#\n\n\n";
    }
    return !StrmWy.fail();
}

/**************************************************************************************************************/

bool Scena::ZapiszDoPliku(const char* sNazwaPliku) const {
    ofstream   StrmWy(sNazwaPliku);
    if (!StrmWy.is_open()) {
        cerr << endl << "Blad: Otwarcie do zapisu pliku '" << sNazwaPliku << "' nie powiodlo sie." << endl << endl;
        return false;
    }
    return ZapiszDoStrumienia(StrmWy);
}

/**************************************************************************************************************/

void Scena::ZmienPolozenie(float x, float y) {
    Wektor2D starePolozenie = roboty.at(ktory)->polozenieGlob;
    Wektor2D nowePolozenie(x, y);
    for ( int i = 0; i < roboty.at(ktory)->wierzcholkiGlob.rozmiar(); i++ ) {
        roboty.at(ktory)->wierzcholkiGlob.zwrocWierz(i) = roboty.at(ktory)->wierzcholkiGlob.zwrocWierz(i) + nowePolozenie - starePolozenie; }
    roboty.at(ktory)->polozenieGlob = nowePolozenie;
}

/**************************************************************************************************************/

void Scena::ruszOWektor(Wektor2D wek) {
    for ( int i = 0; i < roboty.at(ktory)->wierzcholkiGlob.rozmiar(); i++ ) {
        roboty.at(ktory)->wierzcholkiGlob.zwrocWierz(i) = roboty.at(ktory)->wierzcholkiLok.zwrocWierz(i) + roboty.at(ktory)->polozenieGlob + wek; }
    roboty.at(ktory)->polozenieGlob = roboty.at(ktory)->polozenieGlob + wek;
}

/**************************************************************************************************************/

void Scena::obrot(double beta){
    int jednostkaObrotu = 1;
    if(beta < 0) jednostkaObrotu = -2;
    Macierz<float,2> macierzObrotu;
    for(double j = 0 ; abs(j) <= abs(beta) ; j += jednostkaObrotu){
        macierzObrotu = macierzObrotu.macTryg(j);
        for( int i = 0 ; i < roboty.at(ktory)->wierzcholkiGlob.rozmiar() ; i++){
            roboty.at(ktory)->wierzcholkiGlob.zwrocWierz(i) = macierzObrotu * roboty.at(ktory)->wierzcholkiLok.zwrocWierz(i) + roboty.at(ktory)->polozenieGlob; }
        Rysuj();
        usleep(roboty.at(ktory)->predkoscObrotu);
    }
    for( int i = 0 ; i < roboty.at(ktory)->wierzcholkiGlob.rozmiar() ; i++)
        roboty.at(ktory)->wierzcholkiLok.zwrocWierz(i) = macierzObrotu * roboty.at(ktory)->wierzcholkiLok.zwrocWierz(i);
    roboty.at(ktory)->katObrotuGlob += beta;
}

/**************************************************************************************************************/

void Scena::jedz(double odleglosc){
    double i=0.5;
    Wektor2D starePolozenie = roboty.at(ktory)->polozenieGlob;
    double przejechane = 0.0;
    Wektor2D jednostkaRuchu(i*cos(roboty.at(ktory)->katObrotuGlob*M_PI/180), i*sin(roboty.at(ktory)->katObrotuGlob*M_PI/180));
    int j = 1;
    while(!(przejechane >= odleglosc)){
        //j++;
        //if( j%4 != 0 ){
        //if(czyKolizja()){ cout << endl << "Wykryto kolizje!" << endl << endl; break;}}
        Wektor2D przebytaDroga = roboty.at(ktory)->polozenieGlob - starePolozenie;
        przejechane = przebytaDroga.dlugoscWek();
        ruszOWektor(jednostkaRuchu);
        roboty.at(ktory)->sciezkaRob.sciezka.DodajWierzcholek(roboty.at(ktory)->wierzcholkiGlob.zwrocWierz(0));
        Rysuj();
        usleep(roboty.at(ktory)->predkoscRuchu);
    }
    Rysuj();
}

void Scena::okrag(){
    for( int i = 0 ; i <= 360 ; i++ ){
        jedz(1/M_PI);
        obrot(1);
    }
}

/**************************************************************************************************************/

void Scena::jedzDoCelu(Wektor2D gdzie){
    Wektor2D droga;
    double katNachylenia;
    droga = gdzie - roboty.at(ktory)->polozenieGlob;
    double dlugoscDrogi = droga.dlugoscWek();
    katNachylenia = atan(droga[0] / droga[1]) * 180 / M_PI;
    obrot(katNachylenia);
    jedz(dlugoscDrogi);
}

/**************************************************************************************************************/

void Scena::dodajRobota(){
    shared_ptr<Robot> rob(new Robot);
    rob->korpus();
    roboty.push_back(rob);
    obiekty.push_back(rob);
}

/**************************************************************************************************************/

bool Scena::czyKolizja(){
    Macierz<float,2> macierzObrotu;
    for( int i = 0 ; i < obiekty.size() ; i++ ){
        if( i == ktory && obiekty.size() > 1 ) i++;
        macierzObrotu = macierzObrotu.macTryg(roboty.at(ktory)->katObrotuGlob);
        Wektor2D r = roboty.at(ktory)->polozenieGlob - obiekty.at(i)->polozenieGlob;
        Wektor2D V(400,0);
        V = macierzObrotu * V;
        float dlugosc1 = abs ((r * V) / V.dlugoscWek());
        float dlugosc2 = (roboty.at(ktory)->rozmiar + obiekty.at(i)->rozmiar) * sqrt(2);
        if (dlugosc1 > dlugosc2)
            return false;
        
        return true;}
}

/**************************************************************************************************************/

void Scena::dodajPrzeszkode(){
    shared_ptr<Przeszkoda> przeszkoda(new Przeszkoda);
    przeszkoda->korpus();
    obiekty.push_back(przeszkoda);
}

/**************************************************************************************************************/

void Scena::zmienRobota(){
    cout << "Wykryto nastepujace roboty: " << endl << endl;
    for(int i = 0 ; i < roboty.size() ; i++){
        cout << "\t" << i+1 << ". o wspolrzednych " << roboty.at(i)->polozenieGlob << endl;
    }
    cout << endl << "Wprowadz numer pozadanego robota: ";
    cin >> ktory;
    cout << "Wybrano robota nr " << ktory << " o wsporzednych " << roboty.at(ktory-1)->polozenieGlob << endl;
    ktory-=1;
}
