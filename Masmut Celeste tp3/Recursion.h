#ifndef RECURSION_H_INCLUDED
#define RECURSION_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <strings.h>



int factorial (int n);
int potencia(int k,int expon);
int cargarArreglo(int a[]);
int cargarArregloRandom(int a[], int dim);
void mostrarArregloRecur(int a[],int validos,int i);
void mostrarArregloInversoRecursivo(int a[],int validos,int pos);
int arregloCapicuaRecur(int a[],int pri,int ult);
int sumaArregloRecursiva(int a[],int validos,int i);
int buscarMenorRecursiva(int a[],int validos,int i);

int carga();
void cargarArchivoEnteros();
int buscarMenorEnArchivo(FILE * origen);
void mostrarMenor();
int cantidad(FILE*origen);
void invertir (FILE*origen,int pospri,int posult);//paso las posiciones.
void invertirElementosArchivo();
void mostrar();
void mostrarElementos(FILE*origen);
void mostrarElementosInvertidos(FILE*origen);
void mostrarInvertido();

char ingresarCarcter();
void mostrarValoresInverso();
int cargarArregloChar(char a[]);
char elementoAbuscar();
int buscarElemento(char a[],int validos,char elemento,int pos);


#endif // RECURSION_H_INCLUDED
