//
// Created by Michael Kandziora on 2019-01-23.
//

#ifndef HASHFUNKTIONVERKETTETELISTE_HASHTABELLE_H
#define HASHFUNKTIONVERKETTETELISTE_HASHTABELLE_H

#include "VerketteteListe.h"

class HashTable{
public:
    HashTable(int slots = 10000);
    ~HashTable();
    int hash(int key);
    node_t* new_node(int first_value);
    void insertItem(int key);
    bool deleteItem(int key);
    int numberOfItemsInIndex();
    int balkenDiagramm(int scale);
    void printTable();
    bool search(int key);

private:
    //  m = tablesize
    int m;
    //  n = 100 Mio
    int n;

    node_t** hashTable;


};
#endif //HASHFUNKTIONVERKETTETELISTE_HASHTABELLE_H
