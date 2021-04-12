#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "../include/Prostokat.hh"

TEST_CASE("test Wektor Porównanie 1"){
    Prostokat x, y;

    x[0][0] = 1;
    x[0][1] = 2;
    x[1][0] = 3;
    x[1][1] = 4;
    x[2][0] = 5;
    x[2][1] = 6;
    x[3][0] = 7;
    x[3][1] = 8;

    y[0][0] = 1;
    y[0][1] = 2;
    y[1][0] = 3;
    y[1][1] = 4;
    y[2][0] = 5;
    y[2][1] = 6;
    y[3][0] = 7;
    y[3][1] = 8;

    CHECK(x == y);
}

TEST_CASE("test Wektor Porównanie 2"){
    Prostokat x, y;

    x[0][0] = 9;
    x[0][1] = 2;
    x[1][0] = 3;
    x[1][1] = 4;
    x[2][0] = 5;
    x[2][1] = 6;
    x[3][0] = 7;
    x[3][1] = 8;

    y[0][0] = 1;
    y[0][1] = 2;
    y[1][0] = 3;
    y[1][1] = 4;
    y[2][0] = 5;
    y[2][1] = 6;
    y[3][0] = 7;
    y[3][1] = 8;

    CHECK_FALSE(x == y);
}

TEST_CASE("test Wektor Porównanie 3"){
    Prostokat x, y;

    x[0][0] = 1;
    x[0][1] = 9;
    x[1][0] = 3;
    x[1][1] = 4;
    x[2][0] = 5;
    x[2][1] = 6;
    x[3][0] = 7;
    x[3][1] = 8;

    y[0][0] = 1;
    y[0][1] = 2;
    y[1][0] = 3;
    y[1][1] = 4;
    y[2][0] = 5;
    y[2][1] = 6;
    y[3][0] = 7;
    y[3][1] = 8;

    CHECK_FALSE(x == y);
}

TEST_CASE("test Wektor Porównanie 4"){
    Prostokat x, y;

    x[0][0] = 1;
    x[0][1] = 2;
    x[1][0] = 9;
    x[1][1] = 4;
    x[2][0] = 5;
    x[2][1] = 6;
    x[3][0] = 7;
    x[3][1] = 8;

    y[0][0] = 1;
    y[0][1] = 2;
    y[1][0] = 3;
    y[1][1] = 4;
    y[2][0] = 5;
    y[2][1] = 6;
    y[3][0] = 7;
    y[3][1] = 8;

    CHECK_FALSE(x == y);
}

TEST_CASE("test Wektor Porównanie 5"){
    Prostokat x, y;

    x[0][0] = 1;
    x[0][1] = 2;
    x[1][0] = 3;
    x[1][1] = 9;
    x[2][0] = 5;
    x[2][1] = 6;
    x[3][0] = 7;
    x[3][1] = 8;

    y[0][0] = 1;
    y[0][1] = 2;
    y[1][0] = 3;
    y[1][1] = 4;
    y[2][0] = 5;
    y[2][1] = 6;
    y[3][0] = 7;
    y[3][1] = 8;

    CHECK_FALSE(x == y);
}

TEST_CASE("test Wektor Porównanie 6"){
    Prostokat x, y;

    x[0][0] = 1;
    x[0][1] = 2;
    x[1][0] = 3;
    x[1][1] = 4;
    x[2][0] = 9;
    x[2][1] = 6;
    x[3][0] = 7;
    x[3][1] = 8;

    y[0][0] = 1;
    y[0][1] = 2;
    y[1][0] = 3;
    y[1][1] = 4;
    y[2][0] = 5;
    y[2][1] = 6;
    y[3][0] = 7;
    y[3][1] = 8;

    CHECK_FALSE(x == y);
}

TEST_CASE("test Wektor Porównanie 7"){
    Prostokat x, y;

    x[0][0] = 1;
    x[0][1] = 2;
    x[1][0] = 3;
    x[1][1] = 4;
    x[2][0] = 5;
    x[2][1] = 9;
    x[3][0] = 7;
    x[3][1] = 8;

    y[0][0] = 1;
    y[0][1] = 2;
    y[1][0] = 3;
    y[1][1] = 4;
    y[2][0] = 5;
    y[2][1] = 6;
    y[3][0] = 7;
    y[3][1] = 8;

    CHECK_FALSE(x == y);
}

TEST_CASE("test Wektor Porównanie 8"){
    Prostokat x, y;

    x[0][0] = 1;
    x[0][1] = 2;
    x[1][0] = 3;
    x[1][1] = 4;
    x[2][0] = 5;
    x[2][1] = 6;
    x[3][0] = 9;
    x[3][1] = 8;

    y[0][0] = 1;
    y[0][1] = 2;
    y[1][0] = 3;
    y[1][1] = 4;
    y[2][0] = 5;
    y[2][1] = 6;
    y[3][0] = 7;
    y[3][1] = 8;

    CHECK_FALSE(x == y);
}

TEST_CASE("test Wektor Porównanie 9"){
    Prostokat x, y;

    x[0][0] = 1;
    x[0][1] = 2;
    x[1][0] = 3;
    x[1][1] = 4;
    x[2][0] = 5;
    x[2][1] = 6;
    x[3][0] = 7;
    x[3][1] = 9;

    y[0][0] = 1;
    y[0][1] = 2;
    y[1][0] = 3;
    y[1][1] = 4;
    y[2][0] = 5;
    y[2][1] = 6;
    y[3][0] = 7;
    y[3][1] = 8;

    CHECK_FALSE(x == y);
}

TEST_CASE("test Wektor Porównanie 1"){
    Prostokat x, y;

    x[0][0] = 1;
    x[0][1] = 2;
    x[1][0] = 3;
    x[1][1] = 4;
    x[2][0] = 5;
    x[2][1] = 6;
    x[3][0] = 7;
    x[3][1] = 8;

    y[0][0] = 1;
    y[0][1] = 2;
    y[1][0] = 3;
    y[1][1] = 4;
    y[2][0] = 5;
    y[2][1] = 6;
    y[3][0] = 7;
    y[3][1] = 8;

    CHECK_FALSE(x != y);
}

TEST_CASE("test Wektor Przesuwanie 1"){
    Prostokat x, y;
    Wektor z;

    x[0][0] = 1;
    x[0][1] = 2;
    x[1][0] = 3;
    x[1][1] = 4;
    x[2][0] = 5;
    x[2][1] = 6;
    x[3][0] = 7;
    x[3][1] = 8;

    z[0] = 1;
    z[1] = 2;

    y[0][0] = 2;
    y[0][1] = 4;
    y[1][0] = 4;
    y[1][1] = 6;
    y[2][0] = 6;
    y[2][1] = 8;
    y[3][0] = 8;
    y[3][1] = 10;

    x.przesun(z);

    CHECK(x == y);
}

TEST_CASE("test Wektor Obrót 1"){
    Prostokat x, y;
    double z = 90;

    x[0][0] = 1;
    x[0][1] = 2;
    x[1][0] = 3;
    x[1][1] = 4;
    x[2][0] = 5;
    x[2][1] = 6;
    x[3][0] = 7;
    x[3][1] = 8;

    y[0][0] = -2;
    y[0][1] =  1;
    y[1][0] = -4;
    y[1][1] =  3;
    y[2][0] = -6;
    y[2][1] =  5;
    y[3][0] = -8;
    y[3][1] =  7;

    x.obroc(z);

    CHECK(x == y);
}