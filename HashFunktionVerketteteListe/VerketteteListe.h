//
// Created by Michael Kandziora on 2019-01-23.
//

#ifndef HASHFUNKTIONVERKETTETELISTE_VERKETTETELISTE_H
#define HASHFUNKTIONVERKETTETELISTE_VERKETTETELISTE_H

/****************************************************/
/*					    STRUCT  					*/
/****************************************************/

typedef struct list_element {
    int data;
    struct list_element* prev;
    struct list_element* next;
}node_t;


#endif //HASHFUNKTIONVERKETTETELISTE_VERKETTETELISTE_H
