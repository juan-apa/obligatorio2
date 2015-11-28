#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
#include <stdio.h>

const int MAX = 80;
typedef char *String;

void String_crear(String &s); //CREA UN STRING CON SOLO UNA POSICION, QUE ES UN \0

void String_dest(String &s); //DESTRUYE EL STRING

int String_lar(String s);//DEVUELVE EL LARGO DEL STRING

void String_cop(String &s1, String s2);//COPIA EL  STRING S2 EN S1

void String_cargar(String &s);//ASUMO QUE EL STRING YA VIENE CREADO.!

void String_mostrar(String s);//IMPRIME EL STRING

void String_con(String &s1, String s2);//PONE S2 AL FINAL DE S1. S2 NO SE DESTRUYE.

void String_swp(String &s1, String &s2);//SWAPEA LOS STRINGS

bool String_men(String s1, String s2);//DEVUELVE TRUE SI EL PRIMERO ES MENOR ALFABETICAMENTE, FALSE DE LO CONTRARIO

bool String_eq(String s1, String s2);//DEVUELVE TRUE SI LOS STRINGS SON IGUALES

#endif // STRING_H_INCLUDED
