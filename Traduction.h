#ifndef TRADUCTION_H_INCLUDED
#define TRADUCTION_H_INCLUDED
#include "Liste.h"

#define length_code 100/*++++++++AJOUT+++++++++++*/

typedef struct code_car{/*++++++++AJOUT+++++++++++*/
  char caractere;
  char* code[length_code];
  struct code_car* next;
}code_car;


int ascii_to_binary(char car);
void translate_binary(char* file_in, char* file_out);
int nb_caractere(FILE* fichier);
void storage_letter(FILE* dico,Node* mytree,char* path);/*++++++++AJOUT+++++++++++*/
void Storage_Dictionary(Node* mytree,char* Dico_name);/*++++++++AJOUT+++++++++++*/
code_car* create_elem_dic();

#endif // TRADUCTION_H_INCLUDED
