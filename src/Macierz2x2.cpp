#include "Macierz2x2.hh"


Macierz::Macierz()
{
    for(int x = 0; x < ROZMIAR_MACIERZY; x++)
        for(int y = 0; y < ROZMIAR_MACIERZY; y++)
            this->wartosc[x][y] = 0;
}

void Macierz::generujMacierzObrotu(double katWStopniach)
{
    #if (ROZMIAR_MACIERZY != 2)
        #error Metoda dostosowana do generowania macierzy obrotu w 2D
    #endif

    double katWRadianach = katWStopniach * M_PI / 180;

    wartosc[0][0] =  cos(katWRadianach);
    wartosc[1][0] = -sin(katWRadianach);
    wartosc[0][1] =  sin(katWRadianach);
    wartosc[1][1] =  cos(katWRadianach);
}

Wektor  Macierz::operator *  (const Wektor &wektor) const
{
    #if (ROZMIAR_MACIERZY != ROZMIAR_WEKTORA)
        #error Rozmiary macierzy i wektora nie są kompatykilne do mnożenia!
    #endif

    Wektor wynik;

    for(int x = 0; x < ROZMIAR_MACIERZY; x++)
    {
        for(int y = 0; y < ROZMIAR_MACIERZY; y++)
        {
            wynik[x] += wektor[y] * wartosc[y][x];
        }
    }
    
    return wynik;
}

double  Macierz::operator () (int wiersz, int kolumna) const
{
    return this->wartosc[wiersz][kolumna];
}

double& Macierz::operator () (int wiersz, int kolumna)
{
    return this->wartosc[wiersz][kolumna];
}

std::ostream& operator << (std::ostream &Strm, const Macierz &Mac)
{
    for(int x = 0; x < ROZMIAR_MACIERZY; x++)
    {
        for(int y = 0; y < ROZMIAR_MACIERZY; y++)
        {
            Strm << " " << std::setw(15) << std::fixed << std::setprecision(10) << Mac(x, y);
        }
        Strm << std::endl;
    }
    return Strm;
}