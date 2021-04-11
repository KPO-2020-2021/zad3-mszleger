#ifndef WEKTOR2D_HH
#define WEKTOR2D_HH

#include <iostream>
#include <iomanip>
#include <cmath>

#define ROZMIAR_WEKTORA 2

/**
 * Klasa modelująca wektor w danej przestrzeni (zależy od wartości stałej symbolicznej ROZMIAR_WEKTORA)
**/
class Wektor {
  double wartosc[ROZMIAR_WEKTORA];                                   // Tablica przechowująca współrzędne wektora - [0]-oś OX, [1]-oś OY
  
  public:
    // Konstruktory
    Wektor();                                                        // Konstruktor inicjujący współrzędne wektora wartościami 0
    // Metody
    double modul() const;                                            // Metoda zwracająca długość wektora
    // Przeciążenia operatorów
    double  operator [] (int indeks) const;                          // Przeciążenie operatora indeksującego do odczytu wartości wektora
    double& operator [] (int indeks);                                // Przeciążenie operatora indeksującego do zapisu wartości wektora
    Wektor  operator +  (const Wektor &wektor2) const;               // Przeciążenie operatora dodawania dwóch wektorów
    Wektor  operator -  (const Wektor &wektor2) const;               // Przeciążenie operatora odejmowania dwóch wektorów
    bool    operator == (const Wektor &wektor2) const;               // Przeciążenie operatora porównywania dwóch wektorów
    bool    operator != (const Wektor &wektor2) const;               // Przeciążenie operatora zanegowanego porównywania dwóch wektorów
};

std::istream& operator >> (std::istream &Strm, Wektor &Wek);         // Przeciążenie operatora wczytywania współrzędnych wektora

std::ostream& operator << (std::ostream &Strm, const Wektor &Wek);   // Przeciążenie operatora wypisywania współrzędnych wektora

#endif
