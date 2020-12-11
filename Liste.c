#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Liste.h"

//Fonction qui cree un noeud
Node* create_elem(int car,int occ)
{
    Node* new_node=(Node*)malloc(sizeof(Node));
    new_node->caractere = car;
    new_node->occurrence=occ;
    new_node->next_elem=NULL;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}

//Fonction qui permet d'incrementer l'occurrence d'un noeud existant dans la liste
//Retourne l'addresse du noeud s'il est present
//Retourne NULL si le noeud n'est pas present
Node* increment_elem(Node* list_huffman,int caractere){
    while(list_huffman != NULL){
        if ((list_huffman->caractere)==caractere){
            list_huffman->occurrence++;
            return list_huffman;
        }
        list_huffman=list_huffman->next_elem;
    }
    return NULL;
}

//Fonction qui cree une liste contenant les caracteres presents dans un fichier texte et leurs occurrences
//Si le caractere courant n'est pas dans la liste : creation d'un noeud contenant le caractere et ajout de ce noeud dans la liste
//Si le caractere courant est dans la liste : incrementation de son occurrence
Node* create_list_char(char* file_in){
    Node* mylist=NULL;
    Node* temp=NULL;//liste temporaire
    int car;
    FILE* file=fopen(file_in,"r");

    if (file==NULL){ //probleme d'ouverture du fichier
        fprintf(stderr, "-------------------ERREUR D'OUVERTURE-------------------");
    }

    while((car=fgetc(file)) != EOF){//Tant que nous ne sommes pas arrives a la fin du fichier texte
        if (mylist==NULL){//Si la liste est vide
            mylist=create_elem(car,1);
            temp=mylist;
        }
        else{
            if (increment_elem(mylist,car) == NULL){
                temp->next_elem=create_elem(car,1);
                temp=temp->next_elem;
            }
        }
    }
    fclose(file);
    return mylist;
}

void print_list(Node* mylist)
{
    if(mylist==NULL)
    {
        return;
    }
    else
    {
        while(mylist!=NULL){
            printf("[%d][%d] -> \n",mylist->caractere, mylist->occurrence);
            mylist=mylist->next_elem;
        }
    }
}

int nb_element_list(Node* mylist)
{
    if (mylist == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + nb_element_list(mylist->next_elem);
    }
}
