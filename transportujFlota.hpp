#pragma once
#include <iostream>
#include "Stocznia.hpp" // Zak³adamy, ¿e wszystkie pliki s¹ zaimportowane w odpowiednim porz¹dku

unsigned int transportujFlota(unsigned int towar)
{
    if (towar == 0)
        return 0; // Nie tworzymy statków, jeœli nie ma towaru

    Stocznia     stocznia;               // Tworzymy obiekt stoczni
    unsigned int przetransportowany = 0; // Ca³kowita iloœæ przetransportowanego towaru

    CountThis< Zaglowiec >::reset();

    // Pêtla dopóki nie przetransportujemy wystarczaj¹cej iloœci towaru
    while (przetransportowany < towar) {

        Statek* statek = stocznia();

        // Transportujemy towar
        przetransportowany += statek->transportuj();

        delete statek;
    }

    // Zwracamy liczbê ¿aglowców u¿ytych do transportu
    return CountThis< Zaglowiec >::get();
}
