#include "Scena.hh"


using namespace std;

int main() {
    char znak;
    double ile;
    Wektor2D wsp;
    Scena scena;
    do{
        cout<<"r - stworz robota"<<endl<<"p - dodaj przeszkode"<<endl<<"j - jedz robotem"<<endl<<"o - obroc robota"<<endl<<"k - zrob okrag"<<endl<<"d - jazda do celu"<<endl<<"z - zmien robota"<<endl<<"q - wyjscie"<<endl;
        cin>>znak;
        switch(znak){
            case 'r': scena.dodajRobota(); scena.Rysuj(); break;
            case 'p': scena.dodajPrzeszkode(); scena.Rysuj(); break;
            case 'o': cout<<"Podaj kat obrotu w stopniach"<<endl; cin>>ile; scena.obrot(ile); break;
            case 'j': cout<<"Podaj odleglosc do pokonania"<<endl; cin>>ile; scena.jedz(ile); break;
            case 'k': scena.okrag(); break;
            case 'z': scena.zmienRobota(); break;
            case 'd': cout<<"Podaj wspolrzedne celu"; cin>>wsp; scena.jedzDoCelu(wsp); break;
            case 'q': break;
            default:
                cout<<"Robot nie obsluguje takiej funkcji"<<endl; break;
        
        }
    }while(znak != 'q');
}
