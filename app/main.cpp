#include <iostream>
#include <limits>
#include "../include/Wektor2D.hh"
#include "../include/Macierz2x2.hh"
#include "../include/Prostokat.hh"
#include "../include/lacze_do_gnuplota.hh"

#define NAZWAPLIKU "../datasets/prostokat.dat"

// Wyświtla opcje obsługiwane przez menu
void wyswietlMenu()
{
    std::cout << "o - obrot prostokata o zadany kat" << std::endl;
    std::cout << "p - przesuniecie prostokata o zadany wektor" << std::endl;
    std::cout << "w - wyswietlenie wspolrzednych wierzcholkow" << std::endl;
    std::cout << "m - wyswietl menu" << std::endl;
    std::cout << "k - koniec dzialania programu" << std::endl;
    std::cout << std::endl;
}

int main()
{
    Prostokat             Pr;                      // Klasa przechowująca właściwości prostokąta
    PzG::LaczeDoGNUPlota  Lacze;                   // Klasa przechowująca właściwości łącza
    Wektor wektor;
    double kat = 0;
    int ilosc = 0;
    char znak;

    if(Pr.wczytaj(NAZWAPLIKU) == false)            // Wczytywanie wierzchołków prostokąta
    {
        std::cerr << "Nie znaleziono pliku z współrzędnymi wierzchołków prostokąta!" << std::endl;
        return 1;
    }

    //-------------------------------------------------------
    //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
    //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
    //  na dwa sposoby:
    //   1. Rysowane jako linia ciagl o grubosci 2 piksele
    //
    Lacze.DodajNazwePliku(NAZWAPLIKU,PzG::RR_Ciagly,2);
    //
    //   2. Rysowane jako zbior punktow reprezentowanych przez kwadraty,
    //      których połowa długości boku wynosi 2.
    //
    Lacze.DodajNazwePliku(NAZWAPLIKU,PzG::RR_Punktowy,2);
    //
    //  Ustawienie trybu rysowania 2D, tzn. rysowany zbiór punktów
    //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
    //  jako wspolrzedne punktow podajemy tylko x,y.
    //
    Lacze.ZmienTrybRys(PzG::TR_2D);

    // Wyświetlanie informacji początkowych
    std::cout << std::endl;
    Pr.sprawdzBoki();
    wyswietlMenu();                              // Wyświetlanie menu
    Lacze.Rysuj();

    // Główna pętla programu
    while(true)
    {
        std::cout << "Twoj wybor? (m - menu) > ";
        std::cin >> znak;
        if(std::cin.fail())
        {
            std::cin.clear();
            znak = 'i';                          // Ustawianie znaku na nieobsługiwany
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');     // Kasowanie pozostałych znaków w buforze
        switch (znak)
        {
        case 'o':            // Obrót prostokąta o zadany kąt
            std::cout << "Podaj wartosc kata obrotu w stopniach" << std::endl;
            std::cin >> kat;
            if(std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');     // Kasowanie pozostałych znaków w buforze
                std::cerr << "Podano kąt w niewłaściwym formacie!" << std::endl;
            }else{
                std::cout << "Ile razy operacja obrotu ma byc powtorzona?" << std::endl;
                std::cin >> ilosc;
                if(std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');     // Kasowanie pozostałych znaków w buforze
                    std::cerr << "Podano ilość powtórzeń w niepoprawnym formacie!" << std::endl;
                }else{
                    std::cout << std::endl;
                    Pr.obroc(kat, ilosc);
                    Pr.zapisz(NAZWAPLIKU);
                    Lacze.Rysuj();
                    Pr.sprawdzBoki();
                }
            }


            break;
        case 'p':            // Przesunięcie prostokąta o zadany wektor
            std::cout << "Wprowadz wspolrzedne wektora translacji w postaci dwoch liczb tzn. wspolrzednej x oraz wspolrzednej y." << std::endl;
            std::cin >> wektor;
            if(std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');     // Kasowanie pozostałych znaków w buforze
                std::cerr << "Podano współrzedne wektora w niepoprawnym formacie!" << std::endl;
            }else{
                Pr.przesun(wektor);
                Pr.zapisz(NAZWAPLIKU);
                Lacze.Rysuj();
            }
            break;
        case 'w':            // Wyświetlenie współrzędnych wierzchołków
            std::cout << std::endl;
            std::cout << Pr << std::endl;
            break;
        case 'm':            // Wyświetlenie menu
            std::cout << std::endl;
            wyswietlMenu();
            break;
        case 'k':            // Koniec działania programu
            std::cout << std::endl << "Koniec dzialania programu" << std::endl << std::endl;
            return 0;
            break;
        default:
            std::cout << std::endl << "Wprowadzono nieprawidłowe oznaczenie funkcji" << std::endl << std::endl;
            break;
        }
    }
}
