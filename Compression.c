#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "Compression.h"

/*Creation du dictionnaire*/

void storage_letter(FILE* dico,Node* mytree,char* path){
    char path_left[100];
    char path_right[100];
    char letter_code[100];

    strcpy(path_left,path);
    strcpy(path_right,path);

    if(mytree!=NULL){
        if(mytree->caractere==NULL){//Noeud interm�diaire
            strcat(path_left,"0");
            storage_letter(dico,mytree->left,path_left);

            strcat(path_right,"1");
            storage_letter(dico,mytree->right,path_right);
        }
        else{//Noeud contenant une lettre
            if(path==NULL){//Il n'y a qu'un noeud dans l'arbre contenant une lettre donc un seul caractere dans le fichier texte,peu probable
                sprintf(letter_code, "%c:%s", mytree->caractere, "0");
                printf("Lettre code 1 = %s\n",letter_code);
                fprintf(dico,"%s\n",letter_code);
            }
            else{
                sprintf(letter_code, "%c:%s", mytree->caractere, path);
                printf("Lettre code 2 = %s\n",letter_code);
                fprintf(dico,"%s\n",letter_code);
            }
        }
    }
}

void Storage_Dictionary(Node* mytree,char* Dico_name){

    /** OPENING DICO FILE **/
    FILE* file_dico=fopen(Dico_name,"w");
    if (file_dico==NULL){ //probleme d'ouverture du fichier
        fprintf(stderr, "-------------------ERREUR D'OUVERTURE DE DICO.TXT-------------------");
    }

    storage_letter(file_dico,mytree,"");
    fclose(file_dico);
}

/*=====================================================================================================*/

/*Chargement du dictionnaire en memoire*/

code_car* create_elem_dic(){
    code_car* new_elem=(code_car*)malloc(sizeof(code_car));
    new_elem->caractere=(char)NULL;
    sprintf(new_elem->code,"%s","");
    new_elem->next=NULL;
    return new_elem;
}

code_car* read_dico(char* dico){
    char* read;
    int i,length_line;
    code_car* first_code=NULL;
    code_car* current_code=NULL;
    code_car* previous_code=NULL;
    char line[length_code];

    FILE* file_dico=fopen(dico,"r");

    read=fgets(line,length_code,file_dico);//length_code : taille max de la ligne qu'on veut lire (car comme on a defini une taille pour line, cela evite un depassement), dico : fichier qu'on veut lire, line : variable temporaire de stockaged'une ligne du fichier dico)
    while(read!=0){
        length_line=strlen(line);
        if(length_line>0)
        {
            length_line=length_line-1;

            current_code = create_elem_dic();
            current_code->caractere=line[0];
            for (i=2;i<length_line;i++){ //on copie le code dans current_code
                sprintf(current_code->code,"%s%c",current_code->code,line[i]);
            }

            if(previous_code==NULL){//on est sur le premier caractere
                first_code=current_code;
                previous_code=current_code;
            }
            else{
                previous_code->next=current_code;
                previous_code=current_code;
            }
            read=fgets(line,length_code,file_dico);
        }
    }
    fclose(file_dico);
    return first_code;
}

/*=====================================================================================================*/

/*Encodage*/

char* find_code(code_car* dico_list,char car){
    code_car* current_dico_list=dico_list;
    if(current_dico_list!=NULL){
        while(current_dico_list->next!=NULL){
            if(current_dico_list->caractere==car){
                return current_dico_list->code;
            }
            else current_dico_list=current_dico_list->next;
        }
    }
    return NULL;
}

//file_text : fichier a compresser
void compression_file(char* file_text,char* compressed, code_car* memory_dico){
    printf("Entree dans compression_file");
    code_car* dictionary=memory_dico;
    code_car* dictionary_temp=memory_dico;
    char car;
    char* code[100];
    code_car* car_code;

    FILE* text_read=fopen(file_text,"r");
    FILE* comp_file=fopen(compressed,"w");

    while((car=fgetc(text_read)) != EOF){
         while(dictionary_temp!=NULL){
            if(dictionary_temp->caractere==car){
                fprintf(comp_file,"%s",dictionary_temp->code);
            }
            dictionary_temp=dictionary_temp->next;
         }
         dictionary_temp = dictionary;
    }
    fclose(text_read);
    fclose(comp_file);
}
