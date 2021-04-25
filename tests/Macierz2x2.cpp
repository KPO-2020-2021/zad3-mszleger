#include "./doctest/doctest.h"
#include "../include/Macierz2x2.hh"

TEST_CASE("test Macierz Porównanie 1"){
    Macierz x, z;

    x(0, 0) = 1;
    x(1, 0) = 2;
    x(0, 1) = 3;
    x(1, 1) = 4;

    z(0, 0) = 1;
    z(1, 0) = 2;
    z(0, 1) = 3;
    z(1, 1) = 4;

    CHECK(x == z);
}

TEST_CASE("test Macierz Porównanie 2"){
    Macierz x, z;

    x(0, 0) = 1;
    x(1, 0) = 2;
    x(0, 1) = 3;
    x(1, 1) = 4;

    z(0, 0) = 5;
    z(1, 0) = 2;
    z(0, 1) = 3;
    z(1, 1) = 4;

    CHECK_FALSE(x == z);
}

TEST_CASE("test Macierz Porównanie 3"){
    Macierz x, z;

    x(0, 0) = 1;
    x(1, 0) = 2;
    x(0, 1) = 3;
    x(1, 1) = 4;

    z(0, 0) = 1;
    z(1, 0) = 5;
    z(0, 1) = 3;
    z(1, 1) = 4;

    CHECK_FALSE(x == z);
}

TEST_CASE("test Macierz Porównanie 4"){
    Macierz x, z;

    x(0, 0) = 1;
    x(1, 0) = 2;
    x(0, 1) = 3;
    x(1, 1) = 4;

    z(0, 0) = 1;
    z(1, 0) = 2;
    z(0, 1) = 5;
    z(1, 1) = 4;

    CHECK_FALSE(x == z);
}

TEST_CASE("test Macierz Porównanie 5"){
    Macierz x, z;

    x(0, 0) = 1;
    x(1, 0) = 2;
    x(0, 1) = 3;
    x(1, 1) = 4;

    z(0, 0) = 1;
    z(1, 0) = 2;
    z(0, 1) = 3;
    z(1, 1) = 5;

    CHECK_FALSE(x == z);
}

TEST_CASE("test Macierz Porównanie 6"){
    Macierz x, z;

    x(0, 0) = 1;
    x(1, 0) = 2;
    x(0, 1) = 3;
    x(1, 1) = 4;

    z(0, 0) = 1;
    z(1, 0) = 2;
    z(0, 1) = 3;
    z(1, 1) = 4;

    CHECK_FALSE(x != z);
}
/*
TEST_CASE("test Macierz Macierz_obrotu 1"){
    Macierz x, z;

    x.generujMacierzObrotu(180);

    z(0, 0) = -1;
    z(1, 0) =  0;
    z(0, 1) =  0;
    z(1, 1) = -1;

    CHECK(x == z);
}

TEST_CASE("test Macierz Macierz_obrotu 2"){
    Macierz x, z;

    x.generujMacierzObrotu(90);

    z(0, 0) =  0;
    z(1, 0) = -1;
    z(0, 1) =  1;
    z(1, 1) =  0;

    CHECK(x == z);
}
*/
TEST_CASE("test Macierz Mnożenie razy wektor 1"){
    Wektor x, z;
    Macierz y;

    x[0] = 5;
    x[1] = 6;

    y(0, 0) = 1;
    y(1, 0) = 2;
    y(0, 1) = 3;
    y(1, 1) = 4;

    z[0] = 17;
    z[1] = 39;

    CHECK((y * x) == z);
}

TEST_CASE("test Macierz Mnożenie razy macierz 1"){
    Macierz A, B, C;

    A(0, 0) = 1;
    A(1, 0) = 2;
    A(0, 1) = 3;
    A(1, 1) = 4;

    B(0, 0) = 5;
    B(1, 0) = 6;
    B(0, 1) = 7;
    B(1, 1) = 8;

    C(0, 0) = 19;
    C(1, 0) = 22;
    C(0, 1) = 43;
    C(1, 1) = 50;

    CHECK((A * B) == C);
}

TEST_CASE("test Macierz Obliczanie wyznacznika 1"){
    Macierz A;
    double wyznacznik = -2;

    A(0, 0) = 1;
    A(1, 0) = 2;
    A(0, 1) = 3;
    A(1, 1) = 4;

    CHECK(A.obliczWyznacznik() == wyznacznik);
}