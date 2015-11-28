#include "ArbolClientes.h"

void AClientes_inicializar(Clientes &ac)
{
    ac=NULL;
}

void AClientes_insertar(Clientes &ac, Cliente c)
{
    if(ac==NULL)
    {
        ac= new nodoa;
        ac->der= NULL;
        ac->izq= NULL;
        ac->c= c;
    }
    else
    {
        if(Cliente_getCedula(ac->c)> Cliente_getCedula(c))
            AClientes_insertar(ac->izq, c);
        else
            AClientes_insertar(ac->der, c);
    }
}

void AClientes_mostrarOrden(Clientes &ac)
{
    if(ac!=NULL)
    {
        AClientes_mostrarOrden(ac->izq);
        printf("\n\n");
        Cliente_mostrar(ac->c);
        AClientes_mostrarOrden(ac->der);
    }
}

bool AClientes_presente(Clientes &ac, long int ced) //@todo creo que anda, pero revisar igual
                                                  //@fixme pasarle la cedula directamente en vez de Cliente cl, como parametro.
{
    bool esta= false;
    if(ac!=NULL)
    {
        if(Cliente_getCedula(ac->c)== ced)
            esta=true;
        else
        {
            if(Cliente_getCedula(ac->c)> ced)
                esta= AClientes_presente(ac->izq, ced);
            else
                esta= AClientes_presente(ac->der, ced);
        }
    }
    return esta;
}

int AClientes_ClientEnCalle(Clientes &ac, String call)//@fixme esto esta mal, lo hice como si fuese lista, no esta recorriendo todo el arbol
{
    int suma=0;
    if(ac!=NULL)
    {
        suma= suma+ AClientes_ClientEnCalle(ac->izq, call);
        if(String_eq(Cliente_getCalle(ac->c), call))
            suma++;
        suma= suma+ AClientes_ClientEnCalle(ac->der, call);
    }
    return suma;
}

void AClientes_mostrarPCedula(Clientes &ac, long int ced)
{
    if(ac!=NULL)
    {
        if(Cliente_getCedula(ac->c)== ced)
            Cliente_mostrar(ac->c);
        else
            if(ced< Cliente_getCedula(ac->c))
                AClientes_mostrarPCedula(ac->izq, ced);
            else
                AClientes_mostrarPCedula(ac->der, ced);
    }
}


