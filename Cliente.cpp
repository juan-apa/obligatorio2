#include "Cliente.h"

String Cliente_getNombre(Cliente c)
{
    return c.nombre;
}

String Cliente_getApellido(Cliente c)
{
    return c.apellido;
}

String Cliente_getCalle(Cliente c)
{
    return c.calle;
}

int Cliente_getNumPuerta(Cliente c)
{
    return c.numPuerta;
}

long int Cliente_getTelefono(Cliente c)
{
    return c.telefono;
}

long int Cliente_getCedula(Cliente c)
{
    return c.cedula;
}

int Cliente_getCantReclamos (Cliente c)
{
    return c.cantReclamos;
}

void Cliente_SetNombre(Cliente &c, String s)
{
    c.nombre= s;
}

void Cliente_setApellido(Cliente &c, String s)
{
    c.apellido= s;
}

void Cliente_setCalle(Cliente &c, String s)
{
    c.calle= s;
}

void Cliente_setNumPuerta(Cliente &c, int n)
{
    c.numPuerta= n;
}

void Cliente_setTelefono(Cliente &c, long int n)
{
    c.telefono= n;
}

void Cliente_setCedula(Cliente &c, long int n)
{
    c.cedula= n;
}

void Cliente_setCantReclamos(Cliente &c){
    c.cantReclamos++;
}

void Cliente_cargar(Cliente &c)
{
    String nom;
    String ape;
    String calle;
    int aux;
    long int liaux;
    String_crear(nom);
    String_crear(ape);
    String_crear(calle);
    c.cantReclamos=0;
    printf("Nombre: ");
    fflush(stdin);
    String_cargar(nom);
    Cliente_SetNombre(c, nom);
    printf("Apellido: ");
    fflush(stdin);
    String_cargar(ape);
    Cliente_setApellido(c, ape);
    printf("Cedula: ");
    scanf("%ld", &liaux);
    Cliente_setCedula(c, liaux);
    printf("Calle: ");
    fflush(stdin);
    String_cargar(calle);
    Cliente_setCalle(c, calle);
    printf("Numero de puerta: ");
    scanf("%d", &aux);
    Cliente_setNumPuerta(c, aux);
    printf("Telefono: ");
    scanf("%ld", &liaux);
    Cliente_setTelefono(c, liaux);
}

void Cliente_mostrar(Cliente c)
{
    String_mostrar(Cliente_getApellido(c));
    printf(", ");
    String_mostrar(Cliente_getNombre(c));
    printf("; Cedula: %ld", Cliente_getCedula(c));
    printf("; Direccion: ");
    String_mostrar(Cliente_getCalle(c));
    printf(" ");
    printf("%d", Cliente_getNumPuerta(c));
    printf("; Telefono: %ld", Cliente_getTelefono(c));
}
