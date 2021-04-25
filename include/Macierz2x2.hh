#ifndef MACIERZ2X2_HH
#define MACIERZ2X2_HH


#include <iostream>
#include <cmath>
#include "Wektor2D.hh"

#define ROZMIAR_MACIERZY 2

/**
 * Klasa modeluje macierz kwadratową o danym rozmiarze
 * 
 * Kody błędów:
 * 1-błąd podczas obliczania współczynnika macierzy (na przekątnej macierzy znalazła się wartość 0)
**/
class Macierz {
  double wartosc[ROZMIAR_MACIERZY][ROZMIAR_MACIERZY];                // Tablica przechowująca wartości macierzy [kolumna][wiersz]

  public:
    // Konstruktory
    Macierz();                                                       // Ustawia wartości przechowywane przez macierz na 0
    // Metody
    void generujMacierzObrotu(double katWStopniach);                 // Generuje macierz obrotu o zadany kąt w stopniach
    double obliczWyznacznik() const;                                 // Metoda zwracająca wartość wyznacznika macierzy
    // Przeciążenia operatorów
    Wektor  operator *  (const Wektor &wektor) const;                // Przeciążenie operatora mnożenia macierzy razy wektor
    Macierz operator *  (const Macierz &macierz) const;              // Przeciążenie operatora mnożenia macierzy razy macierz
    double  operator () (int wiersz, int kolumna) const;             // Przeciążenie operatora funkcyjnego do pobierania wartości macierzy
    double& operator () (int wiersz, int kolumna);                   // Przeciążenie operatora funkcyjnego do zmieniania wartości macierzy
    bool    operator == (const Macierz &macierz) const;              // Przeciążenie operatora porównywania dwóch macierzy
    bool    operator != (const Macierz &macierz) const;              // Przeciążenie operatora zanegowanego porównywania dwóch macierzy
};

std::ostream& operator << (std::ostream &Strm, const Macierz &Mac);  // Przeciążenie operatora wypisywania wartości macierzy

#endif
