// "Copyright 2023 Gabriel Amorim Soares e Silva"

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "./catch.hpp"
#include "./romanos.hpp"

TEST_CASE("Numeros romanos - algarismos únicos", "[romanos]") {
    REQUIRE(romanos_para_decimal("I") == 1);

    REQUIRE(romanos_para_decimal("V") == 5);

    REQUIRE(romanos_para_decimal("X") == 10);

    REQUIRE(romanos_para_decimal("X") == 10);

    REQUIRE(romanos_para_decimal("L") == 50);


    REQUIRE(romanos_para_decimal("C") == 100);

    REQUIRE(romanos_para_decimal("D") == 500);

    REQUIRE(romanos_para_decimal("M") == 1000);
}

TEST_CASE("Numeros romanos - combinação de algarismos", "[romanos]") {
    REQUIRE(romanos_para_decimal("II") == 2);

    REQUIRE(romanos_para_decimal("VIII") == 8);

    REQUIRE(romanos_para_decimal("IX") == 9);

    REQUIRE(romanos_para_decimal("XII") == 12);

    REQUIRE(romanos_para_decimal("XL") == 40);

    REQUIRE(romanos_para_decimal("LXX") == 70);

    REQUIRE(romanos_para_decimal("CD") == 400);

    REQUIRE(romanos_para_decimal("DLXX") == 570);

    REQUIRE(romanos_para_decimal("MDXL") == 1540);

    REQUIRE(romanos_para_decimal("MMCCCLX") == 2360);

    REQUIRE(romanos_para_decimal("MMDCCCXC") == 2890);
}

TEST_CASE("Numeros romanos - algarismos inválidos", "[romanos]") {
    REQUIRE(romanos_para_decimal("G") == -1);

    REQUIRE(romanos_para_decimal("i") == -1);

    REQUIRE(romanos_para_decimal("N") == -1);

    REQUIRE(romanos_para_decimal("o") == -1);

    REQUIRE(romanos_para_decimal("q") == -1);

    REQUIRE(romanos_para_decimal("Q") == -1);

    REQUIRE(romanos_para_decimal("E") == -1);

    REQUIRE(romanos_para_decimal("W") == -1);

    REQUIRE(romanos_para_decimal("w") == -1);

    REQUIRE(romanos_para_decimal("l") == -1);

    REQUIRE(romanos_para_decimal("K") == -1);

    REQUIRE(romanos_para_decimal("XXC") == -1);

    REQUIRE(romanos_para_decimal("VV") == -1);

    REQUIRE(romanos_para_decimal("VX") == -1);
}
