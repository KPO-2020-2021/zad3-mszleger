#include "Wektor2D.hh"


Wektor::Wektor()
{
    for(int x = 0; x < ROZMIAR_WEKTORA; x++)
        wartosc[x] = 0;
}

double Wektor::modul() const
{
    double modul2 = 0;

    for(int x = 0; x < ROZMIAR_WEKTORA; x++)
        modul2 += this->wartosc[x] * this->wartosc[x];

    return sqrt(modul2);
}

double  Wektor::operator [] (int indeks) const
{
    return wartosc[indeks];
}

double& Wektor::operator [] (int indeks)
{
    return wartosc[indeks];
}

Wektor Wektor::operator + (const Wektor &wektor2) const
{
    Wektor wynik;

    for(int x = 0; x < ROZMIAR_WEKTORA; x++)
        wynik[x] = this->wartosc[x] + wektor2[x];

    return wynik;
}

Wektor Wektor::operator - (const Wektor &wektor2) const
{
    Wektor wynik;

    for(int x = 0; x < ROZMIAR_WEKTORA; x++)
        wynik[x] = this->wartosc[x] - wektor2[x];

    return wynik;
}

bool Wektor::operator == (const Wektor &wektor2) const
{
    for(int x = 0; x < ROZMIAR_WEKTORA; x++)
    {
        if(this->wartosc[x] != wektor2.wartosc[x])
            return false;
    }
    return true;
}

bool Wektor::operator != (const Wektor &wektor2) const
{
    return !(*this == wektor2);
}

std::istream& operator >> (std::istream &Strm, Wektor &Wek)
{
    for(int x = 0; x < ROZMIAR_WEKTORA; x++)
        Strm >> Wek[x];
    
    // Zabezpieczanie się przed ustawieniem wartości -0
    for(int x = 0; x < ROZMIAR_WEKTORA; x++)
        if(Wek[x] == 0)
            Wek[x] = 0;

    return Strm;
}

std::ostream& operator << (std::ostream &Strm, const Wektor &Wek)
{
    for(int x = 0; x < ROZMIAR_WEKTORA; x++)
        Strm << " " << std::setw(15) << std::fixed << std::setprecision(10) << Wek[x];

    return Strm;
}
