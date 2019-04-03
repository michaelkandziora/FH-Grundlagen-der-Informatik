#include <iostream>
#include "Hashtabelle.h"
#include "VerketteteListe.h"

int main() {
    long min_wert = RAND_MAX, max_wert = 0, rand_wert = 0;

    int n = 100000000;
    int m = 0;

    for(int alpha = 50 ; alpha < 301 ; alpha++){
        m = n / alpha;
        HashTable test(m);

        for (int i = 0; i < 100000; ++i) {
            rand_wert = rand();
            if(rand_wert > max_wert){
                max_wert = rand_wert;
            }
            if(rand_wert < min_wert){
                min_wert = rand_wert;
            }
            test.insertItem(rand_wert);
        }
    }


    std::cout << "Min: " << min_wert << std::endl;
    std::cout << "Max: " << max_wert << std::endl;
    std::cout << std::endl;
    // std::cout << test.search(342);

    test.balkenDiagramm(1);

    return 0;
}