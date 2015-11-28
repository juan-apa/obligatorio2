#include "Reclamo.h"

Fecha Reclamo_getFReal(Reclamo r)
{
    return r.fReal;
}

String Reclamo_getDescripcion(Reclamo r)
{
    return r.descripcion;
}

long int Reclamo_getCedula(Reclamo r)
{
    return r.cedula;
}

bool Reclamo_getSolucionado(Reclamo r)
{
    return r.solucionado;
}

int Reclamo_getNumero(Reclamo r)
{
    return r.numero;
}

void Reclamo_setFReal(Reclamo &r, Fecha f)
{
    r.fReal= f;
}

void Reclamo_setDescripcion(Reclamo &r, String s)
{
    r.descripcion= s;
}

void Reclamo_SetCedula(Reclamo &r, long int n)
{
    r.cedula= n;
}

void Reclamo_SetSolucionado(Reclamo &r, bool b)
{
    r.solucionado= b;
}

void Reclamo_setNumero(Reclamo &r, int n)
{
    r.numero= n;
}


void Reclamo_mostrar(Reclamo r)
{
    printf("Fecha realizado: ");
    Fecha_mostrar(Reclamo_getFReal(r));
    printf("; Descripcion: ");
    String_mostrar(Reclamo_getDescripcion(r));
    printf("; Cedula: %ld", Reclamo_getCedula(r));
    printf("; Solucionado: ");
    if(Reclamo_getSolucionado(r))
        printf("Si");
    else
        printf("No");
    printf("; Numero: %d\n", Reclamo_getNumero(r));
}

void Reclamo_cargar(Reclamo &rec) //@todo HAY QUE PONERLE QUE LA FECHA SEA CORRECTA, OSEA QUE EL ANTERIOR TENGA UNA FECHA MENOR O IGUAL
{
    Fecha f;
    String saux;
    String_crear(saux);
    long int caux;
    printf("Fecha: ");
    Fecha_cargar(f);
    Reclamo_setFReal(rec, f);
    printf("Descripcion: ");
    String_cargar(saux);
    Reclamo_setDescripcion(rec, saux);
    printf("Cedula: ");
    scanf("%ld", &caux);
    Reclamo_SetCedula(rec, caux);
    Reclamo_SetSolucionado(rec, false);
    Reclamo_setNumero(rec,0 /* LReclamos_getUltNum(rec)+1*/); //@todo poner una funcion que tome el num del anterior
}
