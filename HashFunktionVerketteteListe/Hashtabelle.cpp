//
// Created by Michael Kandziora on 2019-01-23.
//

#include <iostream>
#include <iomanip>
#include "Hashtabelle.h"

HashTable::HashTable() {
    for (int i = 0; i < TABLESIZE; ++i) {
        hashTable[i] = new node_t;
        hashTable[i]->data = -1;
        hashTable[i]->prev = nullptr;
        hashTable[i]->next = nullptr;
    }
}

int HashTable::hash(int key) {

    int index = 0;

    index = key%TABLESIZE;
    return index;
}

node_t* HashTable::new_node(int first_value){
    node_t* first_element = new node_t;
    if(first_element == NULL){
        std::cout << "Speicher konnte nicht beschafft werden." ;
        exit(54);
    }
    first_element->data = first_value;
    first_element->prev = NULL;
    first_element->next = NULL;

    return first_element;
}

void HashTable::insertItem(int key) {
    int index = hash(key);

    node_t* curr = hashTable[index];
    while(curr->next != NULL){
        curr = curr->next;
    }

    node_t* next_node = (node_t*) new_node(key);
    curr->next = next_node;
    next_node->prev = curr;
    next_node->next = NULL;
}

bool HashTable::deleteItem(int key){
    int index = hash(key);

    node_t* curr = hashTable[index];
    node_t* prev = NULL;
    node_t* next = NULL;

    if(curr == NULL){
        printf("ERROR LEERE LISTE");
    }

    while(curr->data != key){
        curr = curr->next;

        if(curr == NULL){
            printf("Wert nicht gefunden!");
            return false;
        }
    }

    prev->next = next;
    next->prev = prev;

    free(curr);
    return true;
}

bool HashTable::search(int key){
    int index = hash(key);

    node_t* curr = hashTable[index];

    if(curr == NULL){
        printf("ERROR LEERE LISTE");
    }

    while(curr->data != key){
        curr = curr->next;

        if(curr == NULL){
            return false;
        }
    }

    return true;

}

int HashTable::numberOfItemsInIndex() {

    for(int i = 0; i < TABLESIZE; ++i) {
        node_t* curr = hashTable[i];
        int count = 0;

        while(curr != nullptr){
            curr = curr->next;
            count++;
        }

        std::cout << "Bucket: " << i << " hat " << count-1 << " Einträge" << std::endl;
    }
}

int HashTable::balkenDiagramm(int scale) {
    int arr[TABLESIZE] = {0};

    for(int i = 0; i < TABLESIZE; ++i) {
        node_t* curr = hashTable[i];
        int count = 0;

        while(curr != nullptr){
            curr = curr->next;
            count++;
        }

        std::cout << "Bucket: " << std::setw(3) << i << " hat " << count-1 << " Einträge " ;

        for (int j = 1; j < count/scale; ++j) {
            std::cout << "#";
        }

        std::cout << std::endl;

        arr[i] = count;
    }

    std::cout << std::endl;

    for (int k = 0; k < TABLESIZE; ++k) {
        int count = 0;
        for (int l = 0; l < TABLESIZE; ++l) {
            if(arr[k] == arr[l]) count++;
        }
        std::cout << "Wert " << arr[k] << "kommt " << count << " Mal vor." << std::endl;
    }
}