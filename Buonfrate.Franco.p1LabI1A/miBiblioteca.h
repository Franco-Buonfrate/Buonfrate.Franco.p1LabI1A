#ifndef MIBIBLIOTECA_H_INCLUDED
#define MIBIBLIOTECA_H_INCLUDED

int menu();

int ingresarIntPos(char texto[],int* campo,int minimo,int limite);
int ingresarStr(char texto[],char* campo,int tam);
int ingresarFloatPos(char texto[],float* campo,int minimo,int limite);
int ingresarChar(char texto[], char* campo,char parametroUno, char parametroDos);


#endif // MIBIBLIOTECA_H_INCLUDED
