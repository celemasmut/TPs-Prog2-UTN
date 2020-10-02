#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Recursion.h"

#define enteros "archivo.bin"
#define x 30


void switchMenu();
void Menu();



int main()
{
    Menu();
    switchMenu();

    return 0;
}

void Menu()
{
    printf("\n\t [--->  Menu Principal de tp Recursividad  <---]\n\n");
    printf("\n 1 - Calcular Factorial de un numero ");
    printf("\n 2 - Calcular la potencia de un numero");
    printf("\n 3 - Recorrer Arreglo y mostrar");
    printf("\n 4 - Mostrar arreglo invertido");
    printf("\n 5 - Determinar si el arreglo es capicua");
    printf("\n 6 - Sumar los elementos y retornar suma");
    printf("\n 7 - Buscar el menor elemento de un arreglo");
    printf("\n 8 - Buscar menor elemento de un archivo de numeros enteros");
    printf("\n 9 - Invertir los elementos de un archivo de numeros enteros");
    printf("\n a - Recorrer archivo y mostrar");
    printf("\n b - Ingresar valores a una variable y mostrar");
    printf("\n c - Determinar si un arreglo tiene determinado elemento");
    printf("\n\n ---------> ESC para salir....\n");
}
void switchMenu()
{
    char opcion;
    int num1,num2;
    int arreglo[x];
    char caracteres[x];
    int cantidad;
    int posicion=0;
    int rta;
    int suma;
    char caracter;
    int menor;
    fflush(stdin);
    opcion=getch();


    while(opcion!=27)
    {

        switch(opcion)
        {
        case 49:
            system("cls");

            num1=factorial(9);
            printf("El fatorial de 9 es:%i\n",num1);
            system("pause");

            break;
        case 50:
            system("cls");
            num2=potencia(4,7);
            printf("\nLa potencia de 4 a la 7 es de:%i\n",num2);

            system("pause");
            break;
        case 51:
            system("cls");

            cantidad=cargarArregloRandom(arreglo,x);
            printf("---- Muestro Arreglo recursivo ----");
            mostrarArregloRecur(arreglo,cantidad,posicion);
            printf("\n");
            system("pause");

            break;
        case 52:
            system("cls");

            mostrarArregloInversoRecursivo(arreglo,cantidad-1,posicion);

            system("pause");
            break;
        case 53:
            system("cls");

            rta=arregloCapicuaRecur(arreglo,posicion,cantidad-1);
            if(rta==1)
            {
                printf("\n\nEl arreglo es capicua\n");
            }
            else
            {
                printf("\n\nEl arreglo no es capicua.\n");
            }
            system("pause");

            break;
        case 54:
            system("cls");

            suma=sumaArregloRecursiva(arreglo,x,posicion);
            printf("\nLa suma es de:%i\n",suma);
            system("pause");
            break;
        case 55:
            system("cls");

            menor=buscarMenorRecursiva(arreglo,x,posicion);
            printf("\n\nEl menor elemento es:%i\n",menor);
            system("pause");

            break;
        case 56:
            system("cls");
            printf("-------> Ingrese entero o  ESC para salir..... ");
            cargarArchivoEnteros();
            printf("\nPUNTO 8:\n");
            mostrarMenor();
            system("pause");
            break;
        case 57:
            system("cls");

            printf("PUNTO 9: INVERTIR LOS ELEMENTOS\n");
            printf("\nArchivo sin invertir:\n");
            mostrar();
            invertirElementosArchivo();
            printf("\nArchivo invertido:\n");
            mostrar();
            printf("\n");
            system("pause");
            break;
        case 97:
            system("cls");

            printf("MOSTRAR LOS ELEMENTOS DE FORMA INVERTIDA.\n");
            mostrarInvertido();
            system("pause");

            break;
        case 98:
            system("cls");

            printf("PUNTO 11:\n");
            printf("Ingrese valor o caracter. Ingrese - ESC - para finalizar:\n");
            mostrarValoresInverso();
            printf("\n");
            system("pause");
            break;
        case 99:
            system("cls");

            printf("PUNTO 12:\n");
            cantidad=cargarArregloChar(caracteres);
            system("pause");
            caracter=elementoAbuscar();
            rta=buscarElemento(caracteres,cantidad,caracter,0);
            if(rta==1)
            {
                printf("\nEl elemento %c SE encuentra en el arreglo\n",caracter);
            }
            else
            {
                printf("\nEl elemento %c NO se encuentra en el arreglo\n",caracter);
            }
            system("pause");

            break;
        default:
            break;

        }
        system("cls");

        Menu();
        fflush(stdin);
        opcion=getch();
        //system("cls");

    }

}
