#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Decompression.h"

int find_ascii(char* code_lettre, code_car* dico)
{
    while(dico!=NULL){
        if(strcmp(dico->code,code_lettre)==0)
        {
            return dico->caractere;
        }
        dico=dico->next;
    }
    return -1;
}

void decompress_file(char *f_decomp,char* f_comp,code_car* dico)
{
    char car;
    int asci;
    char* code[100];

    FILE* file_decomp=fopen(f_decomp,"w");
    FILE* file_comp=fopen(f_comp,"r");
    memset(code,'\0',100);

    while((car=fgetc(file_comp)) != EOF){
        sprintf(code,"%s%c",code,car);
        asci=find_ascii(code,dico);
        if(asci>0)
        {
            fprintf(file_decomp,"%c",asci);
            memset(code,'\0',100);
        }
    }
    fclose(file_decomp);
    fclose(file_comp);
}
