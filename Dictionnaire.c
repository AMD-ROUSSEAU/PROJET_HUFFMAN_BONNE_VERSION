#include "DICTIONNAIRE.H"

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
    if (file_dico==NULL){ //probl�me d'ouverture du fichier
        fprintf(stderr, "-------------------ERREUR D'OUVERTURE DE DICO.TXT-------------------");
    }

    storage_letter(file_dico,mytree,"");
    fclose(file_dico);
}
