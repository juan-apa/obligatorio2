#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include <stdio.h>
#include "String.h"

typedef struct {
    String nombre;
    String apellido;
    String calle;
    int numPuerta;
    long int telefono;
    long int cedula;
    int cantReclamos;
}Cliente;

//SELECTORAS
String Cliente_getNombre(Cliente c); //Devuelve el nombre del cliente c

String Cliente_getApellido(Cliente c); //Devuelve el apellido del cliente c

String Cliente_getCalle(Cliente c); //Devuelve la calle del cliente c

int Cliente_getNumPuerta(Cliente c); //Devuelve el numero de puerta del cliente c

long int Cliente_getTelefono(Cliente c); //Devuelve el numero de telefono del cliente c

long int Cliente_getCedula(Cliente c); //Devuelve la cedula del cliente c

void Cliente_SetNombre(Cliente &c, String s); //Le pone el nombre s al cliente c

void Cliente_setApellido(Cliente &c, String s); //Le pone el apellido s al cliente c

void Cliente_setCalle(Cliente &c, String s); //Le pone la calle s al cliente c

void Cliente_setNumPuerta(Cliente &c, int n); //Le pone el numero de puerta n al cliente c

void Cliente_setTelefono(Cliente &c, long int n); //Le pone el numero de telefono n al cliente c

void Cliente_setCedula(Cliente &c, long int n); //Le pone la cedula n al cliente c

void Cliente_setCantReclamos (Cliente &c);

void Cliente_cargar(Cliente &c); //carga el cliente c por pantalla

void Cliente_mostrar(Cliente c); //Muestra el cliente c por pantalla

int Cliente_getCantReclamos (Cliente c);

#endif // CLIENTE_H_INCLUDED
