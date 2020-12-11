#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Arbre.h"

Node* smaller_element(Node* mylist)
{
    Node* smaller = mylist;

    //printf("Entree dans smaller_element\n");
    while(mylist->next_elem != NULL)
    {
        if(mylist->next_elem->occurrence <= smaller->occurrence)
        {
            smaller=mylist->next_elem;
            mylist = mylist->next_elem;
        }
        else
        {
            mylist = mylist->next_elem;
        }
    }

    return smaller;
}

/*+++++++++++++++++AJOUT++++++++++++++++++*/
//Fonction qui supprime l'�l�ment smaller de la liste et qui retourne la nouvelle liste
Node* delete_smaller(Node* list, Node* smaller){
    Node* mylist=list;
    Node* first_elem=mylist;
    Node* previous = NULL; //Noeud pr�c�dent

    //printf("Entree dans delete_smaller\n");
    while(mylist != NULL){
        if (mylist==smaller){
            if(previous==NULL)//Cas o� smaller est le premier �l�ment de la liste
            {
                return mylist->next_elem;
            }
            else // smaller n'est pas le premier �l�ment
            {
                if((mylist->next_elem)==NULL){//smaller est le dernier �l�ment de la liste
                    previous->next_elem = NULL;
                    return first_elem;
                }
                else //smaller n'est ni le premier ni le dernier �l�ment de la liste
                {
                    (previous->next_elem) = (smaller->next_elem);
                    return first_elem;
                }
            }
        }
        previous=mylist;
        mylist=mylist->next_elem;
    }
}

/*+++++++++++++++++AJOUT++++++++++++++++++*/

Node* create_tree_huffman(Node* list_node){
    Node* mylist=list_node;
    Node* small_elem_1;
    Node* small_elem_2;
    Node* new_node;

    while(mylist->next_elem != NULL){
        small_elem_1 = smaller_element(mylist);//on trouve le premier plus petit �l�ment et on le stocke dans small_elem_1
        mylist=delete_smaller(mylist,small_elem_1);//on supprime le premier plus petit �l�ment de mylist
        small_elem_1->next_elem = NULL;//l'�l�ment n'est plus dans la liste

        small_elem_2 = smaller_element(mylist);//on trouve le deuxi�me plus petit �l�ment et on le stocke dans small_elem_2
        mylist=delete_smaller(mylist,small_elem_2);//on supprime le deuxi�me plus petit �l�ment de mylist
        small_elem_2->next_elem = NULL;//l'�l�ment n'est plus dans la liste

        new_node=create_elem(NULL,(small_elem_1->occurrence)+(small_elem_2->occurrence));
        new_node->left=small_elem_1;
        new_node->right=small_elem_2;

        new_node->next_elem = mylist;//on rajoute le nouveau noeud en debut de liste
        mylist = new_node;
    }
    return mylist;
}

//Fonction qui affiche les noeuds d'un arbre avec un parcours prefixe.
void print_tree(Node* tree){
    if(tree!=NULL){
        //printf("Entree dans print_tree\n");
        printf("[%c]|[%d] ->\n",tree->caractere,tree->occurrence);/*!!!!!!!!!!Modif!!!!!!!!!!!*/
        print_tree(tree->left);
        print_tree(tree->right);

    }
}
