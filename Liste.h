#ifndef LISTE_H_INCLUDED
#define LISTE_H_INCLUDED


//Définition de la structure Node
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define length_code 100/*++++++++AJOUT+++++++++++*/

typedef struct Node{
    int caractere;
    int occurrence;
    struct Node* next_elem;
    struct Node* left;
    struct Node* right;
}Node;

Node* create_elem(int car,int occ);/*++++++++MODIF++++++++++*/
Node* increment_elem(Node* list_huffman,int caractere);
Node* create_list_char(char* file_in);/*++++++++MODIF NOM+++++++++++*/
void print_list(Node* mylist);
int nb_element_list(Node* mylist);

#endif // LISTE_H_INCLUDED
