#ifndef ARBRE_H_INCLUDED
#define ARBRE_H_INCLUDED

#include "Liste.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define length_code 100/*++++++++AJOUT+++++++++++*/



Node* smaller_element(Node* mylist);
Node* delete_smaller(Node* list, Node* smaller);/*++++++++AJOUT+++++++++++*/
Node* create_tree_huffman(Node* list_node);/*++++++++AJOUT+++++++++++*/
void print_tree(Node* tree);/*++++++++AJOUT+++++++++++*/


#endif // ARBRE_H_INCLUDED
