#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "Traduction.h"

int nb_caractere(FILE* fichier)
{
    int x = 0;
    int Lettre;
    if (fichier != NULL) // test opening file
    {
        Lettre = fgetc(fichier);//Reading first letter
        while (Lettre != EOF)
        {
            x++;// repetition counter
            Lettre = fgetc(fichier);//Letter next
        }
        fclose(fichier);//closing file
        return x; // return number of repetition

    }
    else
    {
        // display error message
        printf("Impossible d'ouvrir le fichier test.txt");
        return 0;
    }
}

int ascii_to_binary(char car)
{
    int c = car;
    if (c == 0)
        return 0;
    if (c == 1)
        return 1;
    return ((c % 2) + 10 * ascii_to_binary(c / 2));
}

//Fonction permettant de traduire un fichier texte en code binaire (8 bits par caractere)
/*Parametre : un fichier input.txt contenant le texte à traduire et un fichier output.txt
 dans lequel la traduction de input.txt en code binaire sera écrit*/

void translate_binary(char* file_in, char* file_out){
    int car;
    FILE* input=fopen(file_in,"r");//on ouvre input.txt en mode lecture
    FILE* output=fopen(file_out,"w");//on ouvre input.txt en mode écriture

    if (input==NULL){ //problème d'ouverture du fichier
        fprintf(stderr, "-------------------ERREUR D'OUVERTURE-------------------");
    }

    if(output==NULL)//problème d'ouverture du fichier
    {
        fprintf(stderr, "-------------------ERREUR D'OUVERTURE-------------------");
    }

    while((car=fgetc(input)) != EOF){//Tant que nous ne sommes pas arrivés à la fin du fichier texte
        fprintf(output,"%08d",ascii_to_binary(car));//on écrit dans le fichier output.txt le code binaire du caractere courant.
    }
    fclose(input);//on ferme le fichier input.txt
    fclose(output);//on ferme le fichier output.txt
}



void storage_letter(FILE* dico,Node* mytree,char* path){
    char path_left[100];
    char path_right[100];
    char letter_code[100];

    strcpy(path_left,path);
    strcpy(path_right,path);

    if(mytree!=NULL){
        if(mytree->caractere== 0){//Noeud interm�diaire
            strcat(path_left,"0");
            storage_letter(dico,mytree->left,path_left);

            strcat(path_right,"1");
            storage_letter(dico,mytree->right,path_right);
        }
        else{//Noeud contenant une lettre
            if(path==NULL){//Il n'y a qu'un noeud dans l'arbre contenant une lettre donc un seul caractere dans le fichier texte,peu probable
                sprintf(letter_code, "%c:%s", mytree->caractere, "0");
                fprintf(dico,"%s\n",letter_code);
                printf("%s\n",letter_code);
            }
            else{
                sprintf(letter_code, "%c:%s", mytree->caractere, path);
                fprintf(dico,"%s\n",letter_code);
                printf("%s\n",letter_code);
            }
        }
    }
}

void Storage_Dictionary(Node* mytree,char* Dico_name){

    /** OPENING DICO FILE **/
    FILE* file_dico=fopen(Dico_name,"w");
    if (file_dico==NULL){ //probl�me d'ouverture du fichier
        fprintf(stderr, "-------------------ERREUR D'OUVERTURE DE DICO.TXT-------------------");
    }

    storage_letter(file_dico,mytree,"");
    fclose(file_dico);
}

code_car* create_elem_dic(){
    code_car* new_elem=(code_car*)malloc(sizeof(code_car));
    new_elem->caractere= 0;
    //new_elem->code="0";
    sprintf(new_elem->code,"%s","");
    new_elem->next=NULL;
    return new_elem;
}

