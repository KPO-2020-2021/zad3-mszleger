#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "../include/Macierz2x2.hh"

TEST_CASE("test Macierz Mnożenie 1"){
    Wektor x, z;
    Macierz y;

    x[0] = 5;
    x[1] = 6;

    y(0, 0) = 1;
    y(1, 0) = 2;
    y(0, 1) = 3;
    y(1, 1) = 4;

    x[0] = 17;
    x[1] = 39;

    CHECK((y * x) == z);
}