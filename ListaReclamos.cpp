#include "ListaReclamos.h"

void LReclamos_inicializar(LReclamos &lr)
{
    lr= NULL;
}

void LReclamos_agregar(LReclamos &lr, Reclamo rec)
{
    if(lr==NULL)
    {
        //@TODO preguntar si puedo poner aca la funcion de agregarle al numero al reclamo;
        /*Reclamo_setNumero(rec, LReclamos_getUltNum(lr)+1);*/ //@fixme Entra siempre en null, porque es recursico, pasarlo a iterativo y averiguar el numero antes de la iteracion
        lr= new nodol;
        lr->r= rec;
        lr->sig= NULL;
    }
    else
        LReclamos_agregar(lr->sig, rec);
        //@fixme pasarlo a while, para meter la funcion que averigua el numero de reclamo.
}

void LReclamos_mostrar(LReclamos lr) //@fixme, poner que ponga los nodos en orden por fecha, el dia 26 puedo agregar un reclamo del dia 24
{
    if(lr!=NULL)
    {
        printf("\n\nReclamo N%d\n", Reclamo_getNumero(lr->r));
        Reclamo_mostrar(lr->r);
        LReclamos_mostrar(lr->sig);
    }
}

int LReclamos_getUltNum(LReclamos lr)
{
    if(lr==NULL) //Caso de que la lista de Reclamos venga vacia
        return 0;
    else
    {
        if(lr->sig== NULL) //Si en el que estoy parado apunta a NULL, devuelvo el numero del reclamo en el que estoy
            return Reclamo_getNumero(lr->r);
        else
            return LReclamos_getUltNum(lr->sig); //De lo contrario me muevo hacia adelante en la lista
    }
}

void LReclamos_MarcarSol(LReclamos &lr, int num) //Asumo que ya verifique si el reclamo existe
{
    if(lr!=NULL)
    {
        if(Reclamo_getNumero(lr->r)== num)
            Reclamo_SetSolucionado(lr->r, true);
        else
            LReclamos_MarcarSol(lr->sig, num);
    }
}

bool LReclamos_existeNum(LReclamos lr, int num)
{
    bool esta= false;
    if(lr!=NULL)
    {
        if(Reclamo_getNumero(lr->r)==num)
            esta= true;
        else
            esta= LReclamos_existeNum(lr->sig, num);
    }
    return esta;
}

int LReclamos_cantSolucionados(LReclamos lr)
{
    if(lr!=NULL)
    {
        if(Reclamo_getSolucionado(lr->r))
            return 1+LReclamos_cantSolucionados(lr->sig);
        else
            return LReclamos_cantSolucionados(lr->sig);
    }
    else
        return 0;
}

void LReclamos_mostrarPCedula(LReclamos lr, long int ced)
{
    if(lr!=NULL)
    {
        if(Reclamo_getCedula(lr->r)== ced)
            Reclamo_mostrar(lr->r);
        LReclamos_mostrarPCedula(lr->sig, ced);
    }
}

Fecha LReclamos_fechaPNum(LReclamos lr, int num)
{
    Fecha fec;
    if(lr!=NULL)
    {
        if(Reclamo_getNumero(lr->r)== num)
            fec= Reclamo_getFReal(lr->r);
        else
            fec= LReclamos_fechaPNum(lr->sig, num);
    }
    return fec;
}

int LReclamos_getMayorNum(LReclamos lr)
{
    if(lr==NULL)
        return 0;
    else
    {
        LReclamos lraux= lr;
        int aux= Reclamo_getNumero(lr->r);
        while(lr!=NULL)
        {
            if(Reclamo_getNumero(lr->r) > aux){
                aux= Reclamo_getNumero(lr->r);
            }
            lr= lr->sig;
        }
        lr= lraux;
        return aux;
    }
}

void LReclamos_setRSolPNum(LReclamos &lr, int num)
{
    LReclamos lraux= lr;
    bool fin= false;
    while(lr!=NULL && !fin)
    {
        if(Reclamo_getNumero(lr->r)== num)
            Reclamo_SetSolucionado(lr->r, true);
        else
            lr= lr->sig;
    }
    lr= lraux;
}

int LReclamos_cantRSol(LReclamos lr)
{
    if(lr==NULL)
        return 0;
   else{
        if(Reclamo_getSolucionado(lr->r))
            return 1+ LReclamos_cantSolucionados(lr->sig);
        else
            return LReclamos_cantSolucionados(lr->sig);
   }
}

int LReclamo_getCant(LReclamos lr)
{
    if(lr==NULL)
        return 0;
    else
        return 1+ LReclamo_getCant(lr->sig);
}

int LReclamos_cantRPIF(LReclamos lr, Fecha f1, Fecha f2)
{
    if(lr==NULL)
        return 0;
    else
    {
        if(Fecha_menorIgual(f1, Reclamo_getFReal(lr->r)) && Fecha_menorIgual(Reclamo_getFReal(lr->r), f2))
            return 1+ LReclamos_cantRPIF(lr->sig, f1, f2);
        else
            return LReclamos_cantRPIF(lr->sig, f1, f2);
    }
}

