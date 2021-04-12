#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
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