#include <stdio.h>
#include <string.h>
#include "deq.h"
#include "wrappers.h"

struct deq *deq_create(void){
    // create new, empty deq, returns pointer
    struct deq *d;

    d = (struct deq *) malloc_or_exit(sizeof(struct deq));
    d->count = 0;
    d->leftmost = NULL;
    d->rightmost = NULL;
    return d;
}

struct deq_elem *deq_elem_create(char *str){
    // create new deq element given a string, returns pointer

    struct deq_elem *d_elem = (struct deq_elem *) malloc_or_exit(sizeof(struct deq_elem));
    char * my_str = strdup_or_exit(str);
    d_elem -> str = my_str;
    return d_elem;
}

struct deq_elem *deq_append(struct deq *deque, char *s){
    // append element on the right end, return new elem
    struct deq_elem *d_elem = deq_elem_create(s);
    
    // Si es el primer elemento, pasa a ser el de más a la derecha y el de más a la izquierda
    if (deque->count ==0){
        deque ->leftmost = d_elem;
        deque ->rightmost = d_elem;
    }
    // Si no es el primero, pasa a ser el de mas a la derecha, y forma con el de mas a la derecha anterior
    // una pareja prev, next
    else {
        deque->rightmost->next = d_elem;
        d_elem->prev = deque->rightmost;
        deque->rightmost = d_elem;
    }
    deque->count++;
    return d_elem;
}

struct deq_elem *deq_append_left(struct deq *deque, char *s){
    // append element on the left end, return new elem
    struct deq_elem *d_elem = deq_elem_create(s);
    
    // Si es el primer elemento, pasa a ser el de más a la derecha y el de más a la izquierda
    if (deque->count ==0){
        deque ->leftmost = d_elem;
        deque ->rightmost = d_elem;
    }
    // Si no es el primero, pasa a ser el de mas a la izquierda, y forma con el de mas a la izquierda anterior
    // una pareja prev, next
    else {
        deque->leftmost->prev = d_elem;
        d_elem->next = deque->leftmost;
        deque->leftmost = d_elem;
    }
    deque->count++;
    return d_elem;
}

struct deq_elem *deq_pop(struct deq *deque){
    // pop element of the right end, return element (NULL if empty deque), caller must free if necessary
    if (deque->count == 0){
        return NULL;
    }
    struct deq_elem *eliminado = deque->rightmost; 

    if (deque->count == 1){
        deque->leftmost = NULL;
        deque->rightmost = NULL;
    }
    else{
        eliminado->prev->next = NULL;
        deque->rightmost = eliminado->prev;
        eliminado->prev = NULL;
    }
    deque->count --;
    return eliminado;
}

struct deq_elem *deq_pop_left(struct deq *deque){
    // pop element of the left end, return element (NULL if empty deque), caller must free if necessary
    
    if (deque->count == 0){
        return NULL;
    }
    
    struct deq_elem *eliminado = deque->leftmost; 

    if (deque->count == 1){
        deque->leftmost = NULL;
        deque->rightmost = NULL;
    }
    else{
        eliminado->next->prev = NULL;
        deque->leftmost = eliminado->next;
        eliminado->next = NULL;
    }
    deque->count --;
    return eliminado;
}


void deq_print(struct deq *deque, int cant_print){
    // printf all str from elements from deque, left to right


    if (!(deque ->count==0)){
        struct deq_elem * e = deque->rightmost;

        for (int i = 0; i < deque->count && cant_print>0; i++){
            fprintf(stderr,"%s\n", e->str);
            e = e->prev;
            cant_print--;
        }
    }
}



void deq_print_ordered(struct deq *deque, int cant_print){

    if (deque ->count==0) {
        return;
    }

    int quantity = cant_print;
    struct deq_elem * e = deque->rightmost;

    for (; e->prev != NULL && cant_print > 0; cant_print--) {
        e = e->prev;
    }
    e = e->next;
    quantity = quantity - cant_print - 1;

    for (; e != NULL && quantity >= 0; e = e->next) {
        fprintf(stderr,"%i: %s\n", quantity, e->str);
        quantity--;
    }
    
}