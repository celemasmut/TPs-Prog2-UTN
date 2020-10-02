#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Empleado.h"


#define archivo1 "employers.dat"
#define dimEmpl 150


void Menu();
void switchMenu();

int main()
{
    Menu();
    switchMenu();
    return 0;
}

void Menu()
{
    printf("\n\t [--->  Menu Principal  <---]\n\n");
    printf("\n 1 - Carga archivo de Empleados");
    printf("\n 2 - Muestra archivo de Empleados");
    printf("\n 3 - Pasa archivo a arreglo de Empleados");
    printf("\n 4 - Carga arreglo de Empleados");
    printf("\n 5 - Muestra arreglo de Empleados");
    printf("\n\n ---------> ESC para salir....\n");
}
void switchMenu()
{
    char opcion;
    fflush(stdin);
    opcion=getch();
    while(opcion!=27)
    {
        stEmpleado empleados[dimEmpl];
        int vEmp=0;

        switch(opcion)
        {
        case 49:
            system("cls");
            ingresaEmpleadoArchivo();
            break;
        case 50:
            system("cls");
            mostrarArchivoEmpleado(archivo1);
            system("pause");
            break;
        case 51:
            vEmp=archivoCompletoEmpleados2arreglo(archivo1,empleados,dimEmpl,vEmp);
            break;
        case 52:
            vEmp=ingresaEmpleadosArray(empleados,vEmp,dimEmpl);
            system("cls");
            break;
        case 53:
            system("cls");
            printf("validos: %i",vEmp);
            mostrarArregloEmpleados(empleados,vEmp);
            break;
        default:
            break;

        }
        Menu();
        fflush(stdin);
        opcion=getch();
        //system("cls");

    }

}
