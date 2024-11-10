#pragma once
#include <iostream>
#include "Stocznia.hpp" // Zak�adamy, �e wszystkie pliki s� zaimportowane w odpowiednim porz�dku

unsigned int transportujFlota(unsigned int towar)
{
    if (towar == 0)
        return 0; // Nie tworzymy statk�w, je�li nie ma towaru

    Stocznia     stocznia;               // Tworzymy obiekt stoczni
    unsigned int przetransportowany = 0; // Ca�kowita ilo�� przetransportowanego towaru

    CountThis< Zaglowiec >::reset();

    // P�tla dop�ki nie przetransportujemy wystarczaj�cej ilo�ci towaru
    while (przetransportowany < towar) {

        Statek* statek = stocznia();

        // Transportujemy towar
        przetransportowany += statek->transportuj();

        delete statek;
    }

    // Zwracamy liczb� �aglowc�w u�ytych do transportu
    return CountThis< Zaglowiec >::get();
}
