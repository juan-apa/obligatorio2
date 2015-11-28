#ifndef ARBOLCLIENTES_H_INCLUDED
#define ARBOLCLIENTES_H_INCLUDED
#include "Cliente.h"

typedef struct nodo_A{
    nodo_A* izq;
    nodo_A* der;
    Cliente c;
}nodoa;

typedef nodoa* Clientes;

void AClientes_inicializar(Clientes &ac);

void AClientes_insertar(Clientes &ac, Cliente c);

void AClientes_mostrarOrden(Clientes &ac);

bool AClientes_presente(Clientes &ac, long int ced);

int AClientes_ClientEnCalle(Clientes &ac, String call); //Devuelve la cantidad de clientes que viven en la misma calle

void AClientes_mostrarPCedula(Clientes &ac, long int ced);

Cliente AClientes_getCliente(Clientes &ac, long int ced);

void AClientes_sumarReclamo(Clientes &ac, long int ced);

void alfa(int valor, int punt);

void AClientes_BuscarMaxReclamo(Clientes ac, int &punt);

#endif // ARBOLCLIENTES_H_INCLUDED
