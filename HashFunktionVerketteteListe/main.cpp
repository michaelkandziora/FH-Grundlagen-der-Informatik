#include <iostream>
#include "Hashtabelle.h"
#include "VerketteteListe.h"

int main() {

    HashTable test;

    for (int i = 0; i < 100000000; ++i) {
        test.insertItem(rand());
    }

    // std::cout << test.search(342);

    test.balkenDiagramm(25);

    return 0;
}