#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "SWektor.hh"
#include <iostream>
#include <cmath>
#include <iomanip>

template <typename STyp, int SWymiar>
class Macierz {
  
    Wektor<STyp,SWymiar> kolumny[SWymiar];
    
  public:
 
    STyp operator () (unsigned int kol, unsigned int wier) const {
        return kolumny[kol][wier]; }
    
    STyp & operator () (unsigned int kol, unsigned int wier) {
        return kolumny[kol][wier]; }
    
    Wektor<STyp,SWymiar> operator * (Wektor<STyp,SWymiar>);
    Macierz<STyp,SWymiar> macTryg(double beta);
};

/******************************************************************************************/

template <typename STyp, int SWymiar>
Wektor<STyp,SWymiar> Macierz<STyp,SWymiar>::operator * (Wektor<STyp,SWymiar> wek){
    Wektor<STyp,SWymiar> wynik;
    Macierz<STyp,SWymiar> mac = *this;
    wynik[0] = wek[0] * mac(0,0) + wek[1] * mac(0,1);
    wynik[1] = wek[0] * mac(1,0) + wek[1] * mac(1,1);
    return wynik;
}

/******************************************************************************************/

template <typename STyp, int SWymiar>
std::istream& operator >> (std::istream &Strm, Macierz<STyp,SWymiar> &mac){
    unsigned int i, j;
    int szerPola = 9;
    for( i = 0 ; i < SWymiar ; i++)
        for( j = 0 ; j < SWymiar ; j++) {
            Strm.width(szerPola);
            Strm >> mac(i, j); }
    return Strm;
}

/******************************************************************************************/

template <typename STyp, int SWymiar>
std::ostream& operator << (std::ostream &Strm, const Macierz<STyp,SWymiar> &mac){
    unsigned int i, j;
    for( i = 0 ; i < SWymiar ; i++){
        for( j = 0 ; j < SWymiar ; j++)
            Strm << "\t" << mac(i, j) ;
        Strm << std::endl; }
    return Strm;
}

/******************************************************************************************/

template <typename STyp, int SWymiar>
Macierz<STyp,SWymiar> Macierz<STyp,SWymiar>::macTryg(double beta){
    Macierz<STyp,SWymiar> mac = *this;
    beta = beta / 180 * M_PI;
    mac(0,0) = cos( beta );
    mac(0,1) = - sin( beta );
    mac(1,0) = sin( beta );
    mac(1,1) = cos( beta );
    return mac;
}

#endif
