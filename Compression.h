#ifndef COMPRESSION_H_INCLUDED
#define COMPRESSION_H_INCLUDED
#include "Dictionnaire.h"

#define length_code 100

typedef struct code_car{
  char caractere;
  char* code[length_code];
  struct code_car* next;
}code_car;

code_car* read_dico(char* dico);
code_car* create_elem_dic();
char* find_code(code_car* dico_list,char car);
void compression_file(char* file_text,char* compressed, code_car* memory_dico);

#endif // COMPRESSION_H_INCLUDED
