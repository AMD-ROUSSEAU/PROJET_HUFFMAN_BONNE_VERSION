#ifndef DICTIONNAIRE_H_INCLUDED
#define DICTIONNAIRE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "ARBRE.H"

void storage_letter(FILE* dico,Node* mytree,char* path);
void Storage_Dictionary(Node* mytree,char* Dico_name);

#endif
