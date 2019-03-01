#include "Menu.h"

void Menu_principal(int &op)
{
    printf("---------------------------------\n");
    printf("|        ¿Que desea hacer?      |\n");
    printf("|  1. Registros.                |\n");
    printf("|  2. Consultas.                |\n");
    printf("|  3. Listados.                 |\n");
    printf("|  4. Salir.                    |\n");
    printf("---------------------------------\n");
    printf("\n>Opcion: ");
    scanf("%d", &op);
    while(op<1 || op>4)
    {
        printf("\nLa opcion ingresada es incorrecta, vuelva a intentar.");
        printf("\n>Opcion: ");
        scanf("%d", &op);
    }
}

void Menu_registros(int &op)
{
    printf("---------------------------------\n");
    printf("|  1. Nuevo Cliente.            |\n");
    printf("|  2. Nuevo Reclamo.            |\n");
    printf("|  3. Marcar como solucionado.  |\n");
    printf("|  4. Atras.                    |\n");
    printf("---------------------------------\n");
    printf("\n>Opcion: ");
    scanf("%d", &op);
    while(op<1 || op>4)
    {
        printf("\nLa opcion ingresada es incorrecta, vuelva a intentar.");
        printf("\n>Opcion: ");
        scanf("%d", &op);
    }
}

void Menu_consultas(int &op)
{
    printf("---------------------------------------------------------\n");
    printf("|  1. Total de reclamos sulcionados y no solucionados.  |\n");
    printf("|  2. Clientes en la misma calle.                       |\n");
    printf("|  3. Reclamos realizados en un intervalo de tiempo.    |\n");
    printf("|  4. Obtener el cliente con mas reclamos.              |\n");
    printf("|  5. Atras.                                            |\n");
    printf("---------------------------------------------------------\n");
    printf("\n>Opcion: ");
    scanf("%d", &op);
    while(op<1 || op>5)
    {
        printf("\nLa opcion ingresada es incorrecta, vuelva a intentar.");
        printf("\n>Opcion: ");
        scanf("%d", &op);
    }
}

void Menu_listados(int &op) //@todo, falta hacer el 3 menu.
{
    printf("-----------------------------------------------------\n");
    printf("|  1. Listar clientes por orden de cedula.          |\n");
    printf("|  2. Reclamos realizados por un cliente.           |\n");
    printf("|  3. Reclamos realizados en una fecha especifica.  |\n");
    printf("|  4. Listar cliente que hizo un reclamo.           |\n");
    printf("|  5. Atras.                                        |\n");
    printf("-----------------------------------------------------\n");
    printf("\n>Opcion: ");
    scanf("%d", &op);
    while(op<1 || op>5)
    {
        printf("\nLa opcion ingresada es incorrecta, vuelva a intentar.");
        printf("\n>Opcion: ");
        scanf("%d", &op);
    }
}
