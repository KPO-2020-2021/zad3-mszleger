#ifndef PROSTOKAT_HH
#define PROSTOKAT_HH

#include <iostream>
#include <fstream>
#include "Wektor2D.hh"
#include "Macierz2x2.hh"

#define ILOSCWIERZCHOLKOW 4

/**
 * Klasa modelująca prostokąt
**/
class Prostokat {
  Wektor wierzcholek[ILOSCWIERZCHOLKOW];                             // Tablica przechowująca współrzędne wierzchołków prostokąta (w kolejności w jakiej sąsiadują)
  // Zaprzyjaźnione funkcje
  friend std::ostream& operator << (std::ostream &Strm, const Prostokat &Pr); // Przeciążenie operatora wypisywania współrzędnych prostokąta
  public:
    // Konstruktory

    // Metody
    bool obroc(double kat);                                          // Metoda obracająca prostokąt o dany kąt - zwraca true jeśli obrócono
    bool obroc(double kat, int ileRazy);                             // Metoda obracająca prostokąt o dany kąt, daną ilość razy - zwraca true jeśli obrócono
    bool przesun(const Wektor &wektor);                              // Metoda przesówająca prostokąt o dany wektor - zwraca true jeśli przesunięto
    void sprawdzBoki() const;                                        // Metoda sprawdzająca, czy długości naprzeciwległych boków są takie same (wyświetla komunikaty)
    bool wczytaj(const std::string &nazwaPliku);                     // Metoda wczytująca wierzchołki prostokąta z danego pliku - zwraca true jeśli udało się wczytać
    bool zapisz(const std::string &nazwaPliku) const;                // Metoda zapisująca wierzchołki prostokąta w danym pliku - zwraca true jeśli udało się zapisać
    // Przeciążenia operatorów
 
};

std::ostream& operator << (std::ostream &Strm, const Prostokat &Pr); // Przeciążenie operatora wypisywania współrzędnych prostokąta

#endif
