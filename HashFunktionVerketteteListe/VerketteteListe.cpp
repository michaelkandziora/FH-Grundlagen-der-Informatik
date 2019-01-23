//
// Created by Michael Kandziora on 2019-01-23.
//

/****************************************************/
/*					BIBLIOTHEKEN					*/
/****************************************************/

#include <iostream>
#include "VerketteteListe.h"


/****************************************************/
/*				     FUNKTIONEN 					*/
/****************************************************/
//----------------------------------------------------
/**                   NEW NODE                     **/
/*
    ZWECK:          |
    PARAMETER:      |
    RUECKGABE:      |
    BUGS:           |
*/
node_t* new_node(int first_value){
    node_t* first_element = (node_t*) malloc(sizeof(node_t));
    if(first_element == NULL){
        printf("Speicher konnte nicht beschafft werden.");
        exit(54);
    }
    first_element->data = first_value;
    first_element->prev = NULL;
    first_element->next = NULL;

    return first_element;
}

//----------------------------------------------------
/**                   ADD NODE                     **/
/*
    ZWECK:          |
    PARAMETER:      |
    RUECKGABE:      |
    BUGS:           |
*/
void add_node(node_t* head, int new_value){
    if(head == NULL){
        printf("ERROR LEERE LISTE");
    }

    node_t* curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }

    node_t* next_node = (node_t*) new_node(new_value);
    curr->next = next_node;
    next_node->prev = curr;
    next_node->next = NULL;
}

//----------------------------------------------------
/**               ADD NODE SORTED                  **/
/*
    ZWECK:          |
    PARAMETER:      |
    RUECKGABE:      |
    BUGS:           |
*/
void insert_node_sort(node_t* head, int new_value){
    node_t* curr = head;
    node_t* last = NULL;

    if(head == NULL){
        printf("ERROR LEERE LISTE");
    }

    while(curr->data < new_value){
        last = curr;
        curr = curr->next;
    }

    node_t* next_node = (node_t*) new_node(new_value);
    last->next = next_node;
    curr->prev = next_node;
    next_node->prev = last;
    next_node->next = curr;

}

//----------------------------------------------------
/**                   DELETE NODE                  **/
/*
    ZWECK:          |
    PARAMETER:      |
    RUECKGABE:      |
    BUGS:           |
*/
void delete_node(node_t* head, int delete_val){
    node_t* curr = head;
    node_t* prev = NULL;
    node_t* next = NULL;

    if(head == NULL){
        printf("ERROR LEERE LISTE");
    }

    while(curr->data != delete_val){
        prev = curr;
        curr = curr->next;
        next = curr->next;

        printf("\nWert %d erfolgreich geloescht!\n",delete_val);
    }

    if(curr->data == delete_val){
        prev->next = next;
        next->prev = prev;

        free(curr);

    }else{
        printf("Wert nicht gefunden!");
    }

}

//----------------------------------------------------
/**                   DELETE ALL (BUGGY)           **/
/*
    ZWECK:          |
    PARAMETER:      |
    RUECKGABE:      |
    BUGS:           |
*/
void delete_all(node_t** head){
    node_t* curr = *head;
    node_t *next = NULL;

    if(head == NULL){
        printf("ERROR LEERE LISTE");
    }

    while(curr != NULL){
        next = curr->next;
        curr->data = 0;
        curr->next =NULL;
        curr->prev = NULL;
        free(curr);
        curr = next;
    }
    *head = NULL;

}

//----------------------------------------------------
/**                   PRINT NODES                  **/
/*
    ZWECK:          |
    PARAMETER:      |
    RUECKGABE:      |
    BUGS:           |
*/
void print_nodes(node_t* head, bool reverse){
    node_t* curr = head;

    if(head == NULL){
        printf("KEINE LISTE VORHANDEN!");
    }else{
        if(reverse == false){
            while(curr->next != NULL){
                printf("Element:\tVAL: %d\tNEXT: %p\tLAST: %p\tCURR: %p\n",curr->data,curr->next,curr->prev,curr);
                curr = curr->next;
            }
            printf("Element:\tVAL: %d\tNEXT: %p\tLAST: %p\tCURR: %p\n",curr->data,curr->next,curr->prev,curr);
        }else{
            while(curr->next != NULL){
                curr = curr->next;
            }
            while(curr->prev != NULL){
                printf("Element:\tVAL: %d\tNEXT: %p\tLAST: %p\tCURR: %p\n",curr->data,curr->next,curr->prev,curr);
                curr = curr->prev;
            }
            printf("Element:\tVAL: %d\tNEXT: %p\tLAST: %p\tCURR: %p\n",curr->data,curr->next,curr->prev,curr);
        }
    }
}