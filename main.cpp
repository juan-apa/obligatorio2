#include <stdio.h>
#include "Reclamo.h"
#include "Cliente.h"
#include "ListaReclamos.h"
#include "ArbolClientes.h"
#include "Menu.h"

int main()
{
    bool fin= false;
    bool salir1= false, salir2= false, salir3= false;
    String saux;
    String_crear(saux);
    Clientes ac;
    Cliente c;
    Reclamo r, r2;
    LReclamos lr;
    Fecha f1, f2;
    AClientes_inicializar(ac);
    LReclamos_inicializar(lr);
    int i=0, op, opr, numaux, opl;

    long int cedAux;
    //int * punteroInt=new int;
    int cantMaxReclamos=0;

    while(!fin)
    {
        Menu_principal(op);
        switch(op){
    case 1:
        salir1= false;
        while(!salir1)
        {
            Menu_registros(opr);
            switch(opr){
        case 1:
            printf("\n\nA continuacion ingresara un nuevo cliente.\n\n");
            Cliente_cargar(c);
            if(AClientes_presente(ac, Cliente_getCedula(c))) //Verifica si el cliente se encuentra ya en el arbo, si se encuentra, vuelve al menu de ingresos
                printf("\nEl cliente ingresado ya existe.\n\n");
            else
                AClientes_insertar(ac, c);
            break; //Fin case 1: case 1: (ingresar un nuevo cliente)

        case 2:
            printf("\n\nA continuacion se ingresara un nuevo reclamo.\n\n");
            Reclamo_cargar(r);
            Fecha ultimaf;
            if(lr==NULL)
            {
                ultimaf.anio= 0;
                ultimaf.mes= 0;
                ultimaf.dia= 0;
            }
            else
                ultimaf= LReclamos_fechaPNum(lr, LReclamos_getMayorNum(lr));
            /*
            if(lr==NULL)
            {
                Reclamo_setNumero(r, LReclamos_getUltNum(lr)+1);
                LReclamos_agregar(lr, r);
            }
            */
            //else
           // {
                if(AClientes_presente(ac, Reclamo_getCedula(r)))
                {
                    if(Fecha_validacion(Reclamo_getFReal(r)))
                    {
                        if(Fecha_menorIgual(ultimaf ,Reclamo_getFReal(r)))
                        {
                            AClientes_sumarReclamo(ac, Reclamo_getCedula(r));

                            Reclamo_setNumero(r, LReclamos_getUltNum(lr)+1);
                            LReclamos_agregar(lr, r);
                        }
                        else
                            printf("\nLa fecha ingresada es inferior a la fecha del ultimo reclamo ingresado.\n");
                    }
                    else
                        printf("\nLa fecha ingresada es incorrecta.\n");
                }
                else
                    printf("\nNo hay ningun cliente registrado con cedula ingresada.\n");
            //} //@note acabo de hacer una mega chanchada, no probe ni una de las funciones que acabo de hacer. @fixme Si esto anda soy Jordano
            break; //Fin case 1: case 2: (Ingresar un nuevo reclamo)

        case 3:
            printf("\n\nIngrese un numero de reclamo: ");
            scanf("%d", &numaux);
            if(LReclamos_existeNum(lr, numaux))
            {
                LReclamos_MarcarSol(lr, numaux);
                printf("\nEl reclamo se ha marcado como solucionado correctamente.\n");
            }
            else
                printf("\nEl numero de reclamo ingresado es invalido.\n");
            break; //Fin case 1: case 3: (Marcar un reclamo como solucionado)

        case 4: //@fixme, tengo que agregarle al menu la opcion de salir
            salir1= true;
            break;
            }
        } //cierre llave while(!salir)
        break; //Break case 1:

    case 2:
        salir2= false;
        while(!salir2)
        {
            Menu_consultas(opl);
            switch(opl)
            {
            case 1://has
                if(lr==NULL)
                    printf("\nNo hay reclamos registtrados en el sistema.\n");
                else{
                    printf("\nLa cantidad de reclamos solucionados es: %d, de los no solucionados: %d\n ", LReclamos_cantRSol(lr), LReclamo_getCant(lr)-LReclamos_cantRSol(lr));
                }
                break; //Fin case 2: case 1: (Reclamos solucionados y no solucionados)

            case 2:
                if(ac==NULL)
                    printf("\nNo hay clientes ingresados en el sistema.\n");
                else{
                    printf("\nIngrese una calle: ");
                    fflush(stdin);
                    String_cargar(saux);
                    printf("\nLa cantidad de clientes que viven en la calle ");
                    String_mostrar(saux);
                    printf(" es %d.\n", AClientes_ClientEnCalle(ac, saux));
                }
                break; ///Fin case 2: case 1:(Clientes en la misma calle)

            case 3:
                if(lr==NULL)
                    printf("\nNo hay reclamos ingresados en el sistema.\n");
                else{
                    printf("\nIngrese la primer fecha: ");
                    fflush(stdin);
                    Fecha_cargar(f1);
                    printf("Ingrese la segunda fecha: ");
                    Fecha_cargar(f2);
                    if(Fecha_validacion(f1) && Fecha_validacion(f2))
                        if(Fecha_menorIgual(f1, f2)){
                            printf("\nLa cantidad de reclamos hecha entre el ");
                            Fecha_mostrar(f1);
                            printf(" y el ");
                            Fecha_mostrar(f2);
                            printf(" es: %d\n", LReclamos_cantRPIF(lr, f1, f2));
                        }
                        else
                            printf("\nLa primer fecha ingresada es mayor a la segunda.\n");
                    else
                        printf("\nUna o ambas de las fechas ingresadas son invalidas.\n");
                }
                break; //Fin case 2: case 1: (Reclamos realizados en un intervalo)

            case 4:
                AClientes_BuscarMaxReclamo(ac,cantMaxReclamos);
                printf("CANTIDAD MAXIMA DE :%d", cantMaxReclamos);
                Cliente_mostrar(AClientes_DevolverClienteMaxReclamo(ac,cantMaxReclamos));
                break; //Fin case 2: case1: (Cliente con mas reclamos)

            case 5:
                salir2= true;
                break; //Fin case 2: case 1: (atras)
            }
        }
        break;

    case 3:
        salir3= false;
        while(!salir3)
        {
            Menu_listados(opl);
            switch(opl)
            {
            case 1:
                if(ac==NULL)
                    printf("\nNo hay clientes ingresados en el sitema.\n");
                else
                {
                    printf("\nA continuacion se listaran los clientes ingresados en el sistema por orden de cedula.\n\n");
                    AClientes_mostrarOrden(ac);
                }
                break; //Fin case 3: case 1: (Listar clientes por orden de cedula)

            case 2: //@fixme
                if(lr==NULL)
                    printf("\nNo hay ningun reclamo ingresado en el sistema.\n");
                else{
                    printf("Ingrese una cedula: ");
                    scanf("%ld", &cedAux);
                    if(LReclamos_existeCed(lr, cedAux))
                    {
                       LReclamos_mostrarPCedula(lr, cedAux);
                       printf("\n");
                    }
                    else
                        printf("\nNo hay ningun cliente/reclamo ingresado en el sistema con la cedula ingresada.\n");
                }
                break; //Fin case 3: case 2: (Reclamos realizados por un cliente)

            case 3:
                if(lr==NULL)
                    printf("\nNo hay ningun reclamo ingresado en el sistema.\n");
                else
                {
                    printf("\nIngrese una fecha: ");
                    Fecha_cargar(f1);
                    if(Fecha_validacion(f1))
                    {
                        if(LReclamos_existeFecha(lr, f1)){
                            LReclamos_mostrarPFecha(lr, f1);
                        }
                        else
                            printf("No hay ningun reclamo con la fecha ingresada en el sistema.\n");
                    }
                    else
                        printf("La fecha ingresada es invalida.\n");
                }
                break; //Fin case 3: case 3: (Reclamos realizados en una fecha especifica)

            case 4:
                if(lr==NULL)
                    printf("\nNo hay ningun reclamo ingresado en el sistema.\n");
                else{
                    printf("\nIngrese un numero de reclamo.");
                    scanf("%d", &numaux);
                    if(LReclamos_existeNum(lr, numaux)){
                        Cliente_mostrar(AClientes_getCliente(ac, LReclamos_getCedPNum(lr, numaux)));
                        //@todo Hay que agregar el que me muestre si esta solucionado o no.
                    }
                }
                break; //Fin case 3: case 4: (Listar cliente que hizo un reclamo)

            case 5:
                salir3= true;
                break; //Fin case 3: case 5: (Atras)
            }

        }

        break; //Break case 3: (Menu listados)

    case 4:
        fin= true;
        break; //Fin case 4: (Salir del programa)
        }
    }
    //@todo Aca agregar la funcion que me baje los datos a un archivo.
    return 0;
}
