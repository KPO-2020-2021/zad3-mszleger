#include "./doctest/doctest.h"
#include "../include/Wektor2D.hh"

TEST_CASE("test Wektor Porównanie 1"){
    Wektor x, y;

    x[0] = 1;
    x[1] = 2;

    y[0] = 1;
    y[1] = 2;

    CHECK(x == y);
}

TEST_CASE("test Wektor Porównanie 2"){
    Wektor x, y;

    x[0] = 3;
    x[1] = 2;

    y[0] = 1;
    y[1] = 2;

    CHECK_FALSE(x == y);
}

TEST_CASE("test Wektor Porównanie 3"){
    Wektor x, y;

    x[0] = 1;
    x[1] = 3;

    y[0] = 1;
    y[1] = 2;

    CHECK_FALSE(x == y);
}

TEST_CASE("test Wektor Porównanie 4"){
    Wektor x, y;

    x[0] = 1;
    x[1] = 2;

    y[0] = 1;
    y[1] = 2;

    CHECK_FALSE(x != y);
}

TEST_CASE("test Wektor Porównanie 5"){
    Wektor x, y;

    x[0] = 3;
    x[1] = 2;

    y[0] = 1;
    y[1] = 2;

    CHECK(x != y);
}

TEST_CASE("test Wektor Porównanie 6"){
    Wektor x, y;

    x[0] = 1;
    x[1] = 3;

    y[0] = 1;
    y[1] = 2;

    CHECK(x != y);
}

TEST_CASE("test Wektor Dodawanie 1"){
    Wektor x, y, z;

    x[0] = 3;
    x[1] = 5;

    y[0] = 1;
    y[1] = 2;

    z[0] = 4;
    z[1] = 7;

    CHECK((x + y) == z);
}

TEST_CASE("test Wektor Odejmowanie 1"){
    Wektor x, y, z;

    x[0] = 3;
    x[1] = 5;

    y[0] = 1;
    y[1] = 2;

    z[0] = 2;
    z[1] = 3;

    CHECK((x - y) == z);
}

TEST_CASE("test Wektor Modul 1"){
    Wektor x;
    double z;

    x[0] = 3;
    x[1] = 4;

    z = 5;

    CHECK(x.modul() == z);
}