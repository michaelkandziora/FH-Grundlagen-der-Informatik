//
// Created by Michael Kandziora on 2019-01-23.
//

#ifndef HASHFUNKTIONVERKETTETELISTE_HASHTABELLE_H
#define HASHFUNKTIONVERKETTETELISTE_HASHTABELLE_H

#include "VerketteteListe.h"

class HashTable{
public:
    HashTable();
    int hash(int key);
    node_t* new_node(int first_value);
    void insertItem(int key);
    bool deleteItem(int key);
    int numberOfItemsInIndex();
    int balkenDiagramm(int scale);
    void printTable();
    bool search(int key);


private:
    static const int TABLESIZE = 31;

    node_t* hashTable[TABLESIZE];
};


#endif //HASHFUNKTIONVERKETTETELISTE_HASHTABELLE_H
