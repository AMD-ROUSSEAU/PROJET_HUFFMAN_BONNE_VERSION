#ifndef COMPRESSION_H_INCLUDED
#define COMPRESSION_H_INCLUDED
#include "Traduction.h"

#define length_code 100

typedef struct code_car{
  char caractere;
  char* code[length_code];
  struct code_car* next;
}code_car;

void storage_letter(FILE* dico,Node* mytree,char* path);
void Storage_Dictionary(Node* mytree,char* Dico_name);
code_car* read_dico(char* dico);
char* find_code(code_car* dico_list,char car);
void compression_file(char* file_text,char* compressed, code_car* memory_dico);

#endif // COMPRESSION_H_INCLUDED
