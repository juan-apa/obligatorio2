#include "fecha.h"

void Fecha_cargar(Fecha &f)
{
    //printf("Ingrese la fecha: ");
    scanf("%d %d %d", &f.dia, &f.mes, &f.anio);
    fflush(stdin);
    while(f.dia>31&&f.dia<1)
    {
        printf("El dia Ingresado es incorrecto, vuelva a intentar.\nIngrese el dia: ");
        scanf("%d", &f.dia);
    }
    //printf("Ingrese el mes: ");
    //scanf("%d", &f.mes);
    while(f.mes>12 && f.mes<1)
    {
        printf("El mes Ingresado es incorrecto, vuelva a intentar.\nIngrese el mes: ");
        scanf("%d", &f.mes);
    }
    //printf("Ingrese el anio: ");
    //scanf("%d", &f.anio);
}
void Fecha_mostrar(Fecha f)
{
    printf("%d/%d/%d", f.dia, f.mes, f.anio);
}
int Fecha_getDia(Fecha f)
{
    return f.dia;
}
int Fecha_getMes(Fecha f)
{
    return f.mes;
}
int Fecha_getAnio(Fecha f)
{
    return f.anio;
}
bool Fecha_validacion(Fecha f)
{
    bool correcto=false;
    if(f.anio%4==0)
    {
        if(f.mes==2 && f.dia<30 && f.dia>0) correcto= true;
        if((f.mes==1 || f.mes==3 || f.mes==5 || f.mes==7 ||f.mes==8 || f.mes==10 || f.mes==12) && (f.dia<32 && f.dia>0))
        {
            correcto= true;
        }
        if((f.mes==4 || f.mes==6 || f.mes==9 || f.mes==11) && (f.dia<31 && f.dia>0))
        {
            correcto=true;
        }

    }
    else
    {
        if(f.mes==2 && f.dia<29 && f.dia>0) correcto= true;
        if((f.mes==1 || f.mes==3 || f.mes==5 || f.mes==7 ||f.mes==8 || f.mes==10 || f.mes==12) && (f.dia<32 && f.dia>0))
        {
            correcto= true;
        }
        if((f.mes==4 || f.mes==6 || f.mes==9 || f.mes==11) && (f.dia<31 && f.dia>0))
        {
            correcto= true;
        }

    }
    return correcto;
}
/*
bool Fecha_menorIgual(Fecha f1, Fecha f2)
{
    bool menor= false;
    if(Fecha_getAnio(f1)<=Fecha_getAnio(f2))
        menor= true;
    else
    {

    }
}*/
bool Fecha_menorIgual(Fecha f1, Fecha f2)
{
    bool menor= false;
    if(Fecha_getAnio(f1)==Fecha_getAnio(f2) && Fecha_getMes(f1)==Fecha_getMes(f2) && Fecha_getDia(f1)==Fecha_getDia(f2))
        menor= true;
    else{
        if(Fecha_getAnio(f1)<Fecha_getAnio(f2))
        {
            menor=true;
        }
        else
        {
            if(Fecha_getAnio(f1)==Fecha_getAnio(f2) && Fecha_getMes(f1)==Fecha_getMes(f2))
            {
                if(Fecha_getDia(f1)<=Fecha_getDia(f2))
                    menor=true;
            }
            else{
                if(Fecha_getAnio(f1)==Fecha_getAnio(f2))
                    if(Fecha_getMes(f1)<Fecha_getMes(f2))
                        menor= true;
                    else
                        if(Fecha_getMes(f1)==Fecha_getMes(f2))
                            if(Fecha_getDia(f1)<Fecha_getDia(f2))
                                menor= true;
            }
        }

    }
}
