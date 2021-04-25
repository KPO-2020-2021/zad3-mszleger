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

double Macierz::obliczWyznacznik() const
{
    Macierz kopia = *this;
    double wspolczynnik = 0;
    double wyznacznik = 1;

    // Tworzenie macierzy górno trójkątnej
    // Pętla zmieniająca element główny (elementy na przekątnej macierzy, o współrzędnych axa)
    for(int x = 0; x < ROZMIAR_MACIERZY; x++)
    {
        if(kopia.wartosc[x][x] == 0)
        {
            throw(1);
        }
        // Pętla przełączająca pomiędzy wierszami następującymi po aktualnym wierszu
        for(int y = x+1; y < ROZMIAR_MACIERZY; y++)
        {
            // Obliczanie współczynnika, z jakim musi zostać odjęty wiersz x od wiersza y
            wspolczynnik = kopia.wartosc[x][y] / kopia.wartosc[x][x];
            // Odjemowanie wiersza x pomnożonego o dany współczynnik od wiersza
            // Przewijanie pomiędzy kolumnami modyfikowanego wiersza
            for(int z = x; z < ROZMIAR_MACIERZY; z++)
            {
                kopia.wartosc[z][y] -= (kopia.wartosc[z][x] * wspolczynnik);
            }
        }
    }
    // Obliczanie wyznacznika
    for(int x = 0; x < ROZMIAR_MACIERZY; x++)
    {
        wyznacznik *= kopia.wartosc[x][x];
    }

    return wyznacznik;
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

Macierz Macierz::operator *  (const Macierz &macierz) const
{
    Macierz wynik;

    // Pętla przewijająca wiersze pierwszej macierzy
    for(int x = 0; x < ROZMIAR_MACIERZY; x++)
    {
        // Pętla przewijająca kolumny drugiej macierzy
        for(int y = 0; y < ROZMIAR_MACIERZY; y++)
        {
            // Pętla przewijająca pomiędzy poszczególnymi elementami w wierszu pierwszej macierzy i kolumnie drugiej macierzy
            for(int z = 0; z < ROZMIAR_MACIERZY; z++)
            {
                // Sumowanie poszczególnych iloczynów
                wynik.wartosc[y][x] += (this->wartosc[z][x] * macierz.wartosc[y][z]);
            }
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

bool Macierz::operator == (const Macierz &macierz) const
{
    for(int x = 0; x < ROZMIAR_MACIERZY; x++)
        for(int y = 0; y < ROZMIAR_MACIERZY; y++)
            if(this->wartosc[x][y] != macierz.wartosc[x][y])
                return false;
    return true;
}

bool Macierz::operator != (const Macierz &macierz) const
{
    return !(*this == macierz);
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