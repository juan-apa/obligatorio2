#ifndef RECLAMO_H_INCLUDED
#define RECLAMO_H_INCLUDED
#include <stdio.h>
#include "String.h"
#include "Fecha.h"

//#include "ListaReclamos.h"

typedef struct{
    Fecha fReal;
    String descripcion;
    long int cedula;
    bool solucionado;
    int numero;
}Reclamo;

//Selectoras
Fecha Reclamo_getFReal(Reclamo r); //Devuelve la fecha de realizacion del reclamo r

String Reclamo_getDescripcion(Reclamo r); //Devuelve la descripcion del reclamo r

long int Reclamo_getCedula(Reclamo r); //Devuelve la cedula del reclamo r

bool Reclamo_getSolucionado(Reclamo r); //Devuelve true si el reclamo r esta solucionado, de lo contrario false

int Reclamo_getNumero(Reclamo r); //Devuelve el numero del reclamo r

void Reclamo_setFReal(Reclamo &r, Fecha f); //Le pone la fecha f al reclamo r

void Reclamo_setDescripcion(Reclamo &r, String s); //Le pone la descripcion s al reclamo r

void Reclamo_SetCedula(Reclamo &r, long int n); //Le pone la cedula n al reclamo r

void Reclamo_SetSolucionado(Reclamo &r, bool b); //Le pone el valor de b a la solucion del reclamo r

void Reclamo_setNumero(Reclamo &r, int n); //Le pone el numero n al reclamo r


void Reclamo_mostrar(Reclamo r); //Muestra por pantalla el reclamo r

void Reclamo_cargar(Reclamo &r); //Carga el reclamo r con las instrucciones por pantalla.

#endif // RECLAMO_H_INCLUDED
