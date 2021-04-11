#include "Prostokat.hh"


bool Prostokat::obroc(double kat)
{
    return this->obroc(kat, 1);
}

bool Prostokat::obroc(double kat, int ileRazy)
{
    if((static_cast <int> (kat) % 360) == 0)                         // Sprawdzanie czy podany kąt jest wielokrotnością kąta pełnego - zwracanie false jeśli tak
        return false;

    Macierz macierzObrotu;                                           // Tworzenie macierzy obrotu
    macierzObrotu.generujMacierzObrotu(kat);
    
    for(int y = 0; y < ileRazy; y++)                                 // Obracanie prostokąta daną ilość razy
        for(int x = 0; x < ILOSCWIERZCHOLKOW; x++)                   // Obracenie każdego wierzchołka względem środka układu współrzędnych
            wierzcholek[x] = macierzObrotu * wierzcholek[x];

    return true;
}

bool Prostokat::przesun(const Wektor &wektor)
{
    if(wektor.modul() == 0)
        return false;
    for(int x = 0; x < ILOSCWIERZCHOLKOW; x++)                       // Przesuwanie każdego wierzchołka o dany wektor
        wierzcholek[x] = wierzcholek[x] + wektor;
    return true;
}

void Prostokat::sprawdzBoki() const
{
    double dlugosc[ILOSCWIERZCHOLKOW];                               // Zmienna przechowująca długości poszczególnych boków
    // Obliczanie długości wierzchołków
    for(int x = 0; x < ILOSCWIERZCHOLKOW - 1; x++)
    {
        dlugosc[x] = (wierzcholek[x+1] - wierzcholek[x]).modul();
    }
    dlugosc[ILOSCWIERZCHOLKOW - 1] = (wierzcholek[0] - wierzcholek[ILOSCWIERZCHOLKOW - 1]).modul();

    // Sprawdzanie czy naprzeciwległe boki są sobie równe i wyświetlanie odpowiednich komunikatów
    if(dlugosc[0] < dlugosc[1])
    {
        // Boki 0 i 2 są krótsze, a boki 1 i 3 są dłuższe
        // Dłuższe boki
        if(dlugosc[1] == dlugosc[3])
            std::cout << ":) Dluzsze przeciwlegle boki sa sobie rowne." << std::endl;
        else
            std::cout << ":O Dluzsze przeciwlegle boki nie sa rowne!!!" << std::endl;
        // Wyswietlanie długości boków
        std::cout << "  Dlugosc pierwszego boku: " << std::fixed << std::setprecision(20) << dlugosc[1] << std::endl;
        std::cout << "    Dlugosc drugiego boku: " << std::fixed << std::setprecision(20) << dlugosc[3] << std::endl << std::endl;
        // Krótsze boki
        if(dlugosc[0] == dlugosc[2])
            std::cout << ":) Krotsze przeciwlegle boki sa sobie rowne." << std::endl;
        else
            std::cout << ":O Krotsze przeciwlegle boki nie sa rowne!!!" << std::endl;
        // Wyswietlanie długości boków
        std::cout << "  Dlugosc pierwszego boku: " << std::fixed << std::setprecision(20) << dlugosc[0] << std::endl;
        std::cout << "    Dlugosc drugiego boku: " << std::fixed << std::setprecision(20) << dlugosc[2] << std::endl << std::endl;
    }else{
        // Boki 1 i 3 są krótsze, a boki 0 i 2 są dłuższe
        // Dłuższe boki
        if(dlugosc[0] == dlugosc[2])
            std::cout << ":) Dluzsze przeciwlegle boki sa sobie rowne." << std::endl;
        else
            std::cout << ":O Dluzsze przeciwlegle boki nie sa rowne!!!" << std::endl;
        // Wyswietlanie długości boków
        std::cout << "  Dlugosc pierwszego boku: " << std::fixed << std::setprecision(20) << dlugosc[0] << std::endl;
        std::cout << "    Dlugosc drugiego boku: " << std::fixed << std::setprecision(20) << dlugosc[2] << std::endl << std::endl;
        // Krótsze boki
        if(dlugosc[1] == dlugosc[3])
            std::cout << ":) Krotsze przeciwlegle boki sa sobie rowne." << std::endl;
        else
            std::cout << ":O Krotsze przeciwlegle boki nie sa rowne!!!" << std::endl;
        // Wyswietlanie długości boków
        std::cout << "  Dlugosc pierwszego boku: " << std::fixed << std::setprecision(20) << dlugosc[1] << std::endl;
        std::cout << "    Dlugosc drugiego boku: " << std::fixed << std::setprecision(20) << dlugosc[3] << std::endl << std::endl;
    }
}

bool Prostokat::wczytaj(const std::string &nazwaPliku)
{
    std::fstream plik;
    Wektor ostatniPunkt;
    plik.open(nazwaPliku);                                           // Otwieranie pliku
    if(plik.is_open() == false)                                      // Sprawdzanie czy udało się otworzyć plik - zwracanie false jeśli nie
        return false;
    for(int x = 0; x < ILOSCWIERZCHOLKOW; x++)
    {
        plik >> wierzcholek[x];
        if(plik.fail())                                              // Sprawdzanie czy wystąpił błąd podczas próby odczyt
        {
            plik.close();                                            // Zamykanie pliku
            return false;
        }
    }
    // Pobieranie ostatniej wartości (powtórzonych współrzędnych pierwszego wierzchołka) i sprawdzanie czy są takie same jak pierwszy wierzchołek
    plik >> ostatniPunkt;
    if(plik.fail() || (wierzcholek[0] != ostatniPunkt))              // Sprawdzanie czy wystąpił błąd podczas próby odczyt lub punkty nie są równe
    {
        plik.close();                                                // Zamykanie pliku
        return false;
    }
    plik.close();                                                    // Zamykanie pliku
    return true;
}

bool Prostokat::zapisz(const std::string &nazwaPliku) const
{
    std::fstream plik;
    plik.open(nazwaPliku, std::fstream::out);                        // Otwieranie pliku
    if(plik.is_open() == false)                                      // Sprawdzanie czy udało się otworzyć plik - zwracanie false jeśli nie
        return false;
    plik << *this;                                                   // Zapisywanie współrzędnych prostokąta
    plik << this->wierzcholek[0];
    if(plik.fail())                                                  // Sprawdzanie czy wystąpił błąd podczas zapisywania
    {
        plik.close();                                                // Zamykanie pliku
        return false;
    }
    plik.close();                                                    // Zamykanie pliku
    return true;
}

std::ostream& operator << (std::ostream &Strm, const Prostokat &Pr)
{
    for(int x = 0; x < ILOSCWIERZCHOLKOW; x++)                       // Wyświetlanie współrzędnych współrzędnych każdego wierzchołka
        Strm << Pr.wierzcholek[x] << std::endl;
    return Strm;
}
