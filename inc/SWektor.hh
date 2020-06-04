#ifndef WEKTOR_HH
#define WEKTOR_HH


#include <iostream>
#include <cmath>
#include <iomanip>

template <typename STyp, int SWymiar>
class Wektor {
  
    STyp elem[SWymiar];
    
  public:
  
    STyp operator [] (unsigned int index) const { return elem[index]; }
    STyp & operator [] (unsigned int index) { return elem[index]; }
    Wektor<STyp,SWymiar> operator + ( const Wektor<STyp,SWymiar> m2) const;
    Wektor<STyp,SWymiar> operator + ( STyp liczba ) const;
    Wektor<STyp,SWymiar> operator - ( const Wektor<STyp,SWymiar> m2) const;
    Wektor<STyp,SWymiar> operator * ( STyp liczba ) const;
    bool operator >= ( const Wektor<STyp,SWymiar> m2) const;
    Wektor<STyp,SWymiar>(STyp const& x, STyp const& y){ elem[0] = x; elem[1] = y; };
    Wektor<STyp,SWymiar>(){ elem[0]=0; elem[1]=0; };
    float operator * (Wektor<STyp,SWymiar> m2);
    STyp dlugoscWek();
    
};

/******************************************************************************************/

template <typename STyp, int SWymiar>
Wektor<STyp,SWymiar> Wektor<STyp,SWymiar>::operator + ( const Wektor<STyp,SWymiar> m2) const{
    unsigned int i;
    Wektor<STyp,SWymiar> wynik;
    for( i = 0 ; i < SWymiar ; i++ ){
        wynik.elem[i] = elem[i] + m2.elem[i]; }
    
    return wynik;
}

/******************************************************************************************/

template <typename STyp, int SWymiar>
Wektor<STyp,SWymiar> Wektor<STyp,SWymiar>::operator + ( STyp liczba) const{
    unsigned int i;
    Wektor<STyp,SWymiar> wynik;
    for( i = 0 ; i < SWymiar ; i++ ){
        wynik.elem[i] = elem[i] + 5; }
    
    return wynik;
}

/******************************************************************************************/

template <typename STyp, int SWymiar>
Wektor<STyp,SWymiar> Wektor<STyp,SWymiar>::operator - ( const Wektor<STyp,SWymiar> m2) const{
    unsigned int i;
    Wektor<STyp,SWymiar> wynik;
    for( i = 0 ; i < SWymiar ; i++ )
        wynik.elem[i] = this->elem[i] - m2.elem[i];
    return wynik;
}

/******************************************************************************************/

template <typename STyp, int SWymiar>
Wektor<STyp,SWymiar> Wektor<STyp,SWymiar>::operator * (STyp liczba) const{
    unsigned int i;
    Wektor<STyp,SWymiar> wynik;
    for( i = 0 ; i < SWymiar ; i++ )
        wynik.elem[i] = this->elem[i] * liczba;
    return wynik;
}

/******************************************************************************************/


template <typename STyp, int SWymiar>
std::istream& operator >> (std::istream &strm, Wektor<STyp,SWymiar> &wek){
    unsigned int i;
    for( i = 0 ; i < SWymiar ; i++ )
        strm >> wek[i];
    return strm;
}

/******************************************************************************************/

template <typename STyp, int SWymiar>
std::ostream& operator << (std::ostream &strm, const Wektor<STyp,SWymiar> &wek){
    unsigned int i;
    for( i = 0 ; i < SWymiar ; i++ )
        strm << " " << wek[i];
    return strm;
}

/******************************************************************************************/

template <typename STyp, int SWymiar>
STyp Wektor<STyp,SWymiar>::dlugoscWek(){
    STyp dlugosc;
    int i;
    dlugosc = 0;
    for( i = 0 ; i < SWymiar ; i++)
        dlugosc = dlugosc + ( elem[i] * elem[i] );
    dlugosc = sqrt(dlugosc);
    return dlugosc;
}

/******************************************************************************************/

template <typename STyp, int SWymiar>
bool Wektor<STyp,SWymiar>::operator >= ( const Wektor<STyp,SWymiar> m2) const{
    if( elem[0] >= m2.elem[0] ) return true;
    if( elem[1] >= m2.elem[1] ) return true;
    return false;
}

template <typename STyp, int SWymiar>
float Wektor<STyp,SWymiar>::operator * (Wektor<STyp,SWymiar> m2){
    unsigned int i;
    float wynik = 0.0;
    for( i = 0 ; i < SWymiar ; i++ )
        wynik += this->elem[i] * m2.elem[i];
    return wynik;
}



#endif
