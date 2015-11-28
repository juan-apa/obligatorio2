#ifndef STRDIN_H_INCLUDED
#define STRDIN_H_INCLUDED
#include "booleano.h"

const int MAX = 80;
typedef char *String;

void strDin_crear(String &s); //CREA UN STRING CON SOLO UNA POSICION, QUE ES UN \0

void strDin_dest(String &s); //DESTRUYE EL STRING

int strDin_lar(String s);//DEVUELVE EL LARGO DEL STRING

void strDin_cop(String &s1, String s2);//COPIA EL  STRING S2 EN S1

void strDin_cargar(String &s);//ASUMO QUE EL STRING YA VIENE CREADO.!

void strDin_mostrar(String s);//IMPRIME EL STRING

void strDin_con(String &s1, String s2);//PONE S2 AL FINAL DE S1. S2 NO SE DESTRUYE.

void strDin_swp(String &s1, String &s2);//SWAPEA LOS STRINGS

bool strDin_men(String s1, String s2);//DEVUELVE TRUE SI EL PRIMERO ES MENOR ALFABETICAMENTE, FALSE DE LO CONTRARIO

bool strDin_eq(String s1, String s2);//DEVUELVE TRUE SI LOS STRINGS SON IGUALES


#endif // STRDIN_H_INCLUDED
