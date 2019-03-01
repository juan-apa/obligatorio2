#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include <stdio.h>

typedef struct{
    int dia;
    int mes;
    int anio;
}Fecha;

void Fecha_cargar(Fecha &f); //Carga una fecha

void Fecha_mostrar(Fecha f); //Muestra una fecha

int Fecha_getDia(Fecha f); //Devuelve el dia

int Fecha_getMes(Fecha f);//Devuelve el mes

int Fecha_getAnio(Fecha f);//Devuelve el anio

bool Fecha_validacion(Fecha f); //Me dice si la fecha es correcta o no.

bool Fecha_menorIgual(Fecha f1, Fecha f2); //Devuelve true si la f1 es MENOR O IGUAL a f2, de lo contrario false.

bool Fecha_igual(Fecha f1, Fecha f2);

//bool Fecha_menor(Fecha f1, Fecha f2); //Devuelve true si la f1 es MENOR a f2, de lo contrario false.
//@note, tuve que hacer 2 funciones la de menor igual y la de menor, porque en el intervalo de las fechas, me lo pide incluyendo las fechas ingresadas.


#endif // FECHA_H_INCLUDED
