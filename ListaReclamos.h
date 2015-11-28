#ifndef LISTARECLAMOS_H_INCLUDED
#define LISTARECLAMOS_H_INCLUDED
#include "Reclamo.h"

typedef struct nodo_L{
    nodo_L* sig;
    Reclamo r;
}nodol;

typedef nodol* LReclamos;

void LReclamos_inicializar(LReclamos &lr); //Inicializa el listado de reclamos, apuntandolo a NULL

void LReclamos_agregar(LReclamos &lr, Reclamo rec); //Agrega un nuevo reclamo al listado

void LReclamos_mostrar(LReclamos lr);

int LReclamos_getUltNum(LReclamos lr);

bool LReclamos_existeNum(LReclamos lr, int num); //Devuelve true si el numero de reclamo existe.

void LReclamos_MarcarSol(LReclamos &lr, int num); //Asumo que ya verifique que el reclamo existe.

int LReclamos_cantSolucionados(LReclamos lr);

void LReclamos_mostrarPCedula(LReclamos lr, long int ced);

Fecha LReclamos_fechaPNum(LReclamos lr, int num); //EL NUMERO TIENE QUE ESTAR PRESENTE EN EL ARREGLO, SINO CRASH

int LReclamos_getMayorNum(LReclamos lr);

void LReclamos_setRSolPNum(LReclamos &lr, int num); //El numero tiene que existir

int LReclamos_cantRSol(LReclamos lr);

int LReclamo_getCant(LReclamos lr);

int LReclamos_cantRPIF(LReclamos lr, Fecha f1, Fecha f2);

bool LReclamos_existeCed(LReclamos lr, long int ced);

#endif // LISTARECLAMOS_H_INCLUDED
