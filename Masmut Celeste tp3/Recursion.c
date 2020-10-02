#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "Recursion.h"

const char enteros[]="archivo.bin";


int factorial (int n)
{
    int rta;
    if(n==0)
    {
        rta=1;
    }
    else
    {
        rta=n*factorial(n-1);
    }
    return rta;
}

//2. Calcular la potencia de un número en forma recursiva.
int potencia(int k,int expon)
{
    int rta;
    if(expon==0)
    {
        rta=1;
    }
    else
    {
        rta=k*potencia(k,expon-1);
    }
    return rta;
}

int cargarArreglo(int a[])
{
    int i=0;
    char control='s';
    while(control=='s')
    {
        printf("ingrese numero al arreglo:");
        scanf("%i",&a[i]);
        i++;
        printf("Desea continuar? s/n:");
        fflush(stdin);
        scanf("%c",&control);
    }
    return i;
}
int cargarArregloRandom(int a[], int dim)
{
    int i;
    for(i=0; i<dim; i++)
    {
        a[i]=rand()%10;
    }
    return i;//mis validos
}

//3. Recorrer un arreglo y mostrar sus elementos en forma recursiva.

void mostrarArregloRecur(int a[],int validos,int i)
{
    if(i<validos)
    {
        printf("%c %i ",(i%10==0)?'\n':'-',a[i]);
        mostrarArregloRecur(a,validos,i+1);
    }
}

//4. Recorrer un arreglo comenzando desde la posición 0 y mostrar sus elementos en forma invertida (recursivo).
void mostrarArregloInversoRecursivo(int a[],int validos,int pos)
{
    if(pos<=validos)
    {

        mostrarArregloInversoRecursivo(a,validos,pos+1);
        printf(" %c %i",(pos%10==0)?'\n':'-',a[pos]);
    }
}

//5. Determinar en forma recursiva si un arreglo es capicúa.

int arregloCapicuaRecur(int a[],int pri,int ult)
{
    int i;
    if(pri<=ult)
    {
        if(a[pri] == a[ult])
        {
            i=arregloCapicuaRecur(a,pri+1,ult-1);
        }
        else
        {
            i=0;
        }
    }
    else
    {
        i=1;
    }
    return i;
}

//6. Sumar en forma recursiva los elementos de un arreglo de enteros.

int sumaArregloRecursiva(int a[],int validos,int i)
{
    int suma=0;
    if(i < validos)
    {
        suma=a[i]+sumaArregloRecursiva(a,validos,i+1);
    }

    return suma;
}


//7. Buscar el menor elemento de un arreglo en forma recursiva.

int buscarMenorRecursiva(int a[],int validos,int i)
{
    int menor=a[validos-1];
    if(i<validos)
    {
        menor=buscarMenorRecursiva(a,validos,i+1);
        if(menor> a[i])
        {
            menor=a[i];
        }
    }

    return menor;
}


//8. Buscar el menor elemento de un archivo números de enteros.
int carga()
{
    int i;
    printf("Ingrese numero:");
    scanf("%i",&i);
    return i;
}

void cargarArchivoEnteros()
{
    int num;
    char opcion;
    FILE*origen=fopen(enteros,"ab");
    if(origen != NULL)
    {
        do
        {
            num=carga();
            fwrite(&num,sizeof(int),1,origen);
            fflush(stdin);
            opcion=getch();
        }
        while(opcion!=27);
        fclose(origen);
    }
}

int buscarMenorEnArchivo(FILE * origen)
{
    int numero,menor;
    if(fread(&menor,sizeof(int),1,origen)==0)//necesito llegar al final para la vuelta de la recursion y poder comparar.
    {
        fseek(origen,sizeof(int)*-1,SEEK_END);//me dirijo antes del final
        fread(&menor,sizeof(int),1,origen);//asigno el ultimo valor
    }
    else
    {
        numero=buscarMenorEnArchivo(origen);
        if(numero<menor)
        {
            menor=numero;
        }

    }
    return menor;
}
void mostrarMenor()
{
    int menor=0;
    FILE * origen=fopen(enteros,"rb");
    if(origen != NULL)
    {
        menor=buscarMenorEnArchivo(origen);
        printf("El elemento menor es el:%d\n\n",menor);
        fclose(origen);
    }
}

//9. Invertir los elementos de un archivo de números enteros.
int cantidad(FILE*origen)
{
    int cant;
    fseek(origen, 0, SEEK_END);
    cant=ftell(origen)/sizeof(int);
    return cant;
}

void invertir (FILE*origen,int pospri,int posult)//paso las posiciones.
{
    int a,b;

    if(pospri<posult)
    {
        fseek(origen,sizeof(int)*pospri,SEEK_SET);
        fread(&a,sizeof(int),1,origen);//quiero asignarle el primer valor
        fseek(origen,sizeof(int)*posult,SEEK_SET);
        fread(&b,sizeof(int),1,origen);//asigno el ultimo valor

        fseek(origen,sizeof(int)*posult,SEEK_SET);//ubico el cursor al final
        fwrite(&a,sizeof(int),1,origen);//grabo el primer elemento al ultimo lugar.
        fseek(origen,sizeof(int)*pospri,SEEK_SET);
        fwrite(&b,sizeof(int),1,origen);//grabo el ultimo elemento al primer lugar.
        invertir(origen,pospri+1,posult-1);
    }
}

void invertirElementosArchivo()
{
    int canti;
    FILE*origen=fopen(enteros,"r+b");
    if(origen!=NULL)
    {
        canti=cantidad(origen);//la cantidad de posiciones.
        invertir(origen,0,canti-1);//paso las posiciones, le resto uno a canti para que me posicione al principio del ultimo.
        fclose(origen);
    }
}
void mostrar()
{
    FILE*orige=fopen(enteros,"rb");
    if(orige!=NULL)
    {
        mostrarElementos(orige);
        fclose(orige);
    }
}
void mostrarElementos(FILE*origen)
{
    int elemento;
    if(fread(&elemento,sizeof(int),1,origen) > 0)
    {
        printf("- %i ",elemento);
        mostrarElementos(origen);
    }

}

//10. Recorrer un archivo y mostrar sus elementos en forma invertida.
void mostrarElementosInvertidos(FILE*origen)
{
    int elemento;
    if(fread(&elemento,sizeof(int),1,origen) > 0)
    {
        mostrarElementosInvertidos(origen);
        printf("- %i",elemento);
    }

}
void mostrarInvertido()
{
    FILE*origen=fopen(enteros,"rb");
    if(origen != NULL)
    {
        mostrarElementosInvertidos(origen);
        fclose(origen);
    }
}

//11. Ingresar valores a una variable (por teclado) y mostrarlo en el orden inverso (hasta ingresar un ‘*’). NO usar arreglos.
char ingresarCarcter()
{
    char n;
    scanf("%c",&n);//tira warning y no lo entiendo-
    return n;
}
void mostrarValoresInverso()
{
    char valor;
    valor=ingresarCarcter();
    if(valor!='*')
    {
        mostrarValoresInverso();
        printf("- %c",valor);
    }
}


//12. Determinar si un arreglo contiene un determinado elemento.
int cargarArregloChar(char a[])
{
    int i=0;
    char opcion;
    printf("ingrese caracter al arreglo:");

    printf("\n---> ESC para salir....\n");

    do
    {
        printf("Caracter: ");
        scanf("%c",&a[i]);
        i++;
        fflush(stdin);
        opcion=getch();
    }
    while(opcion!=27);
    return i;
}
char elementoAbuscar()
{
    char i;
    printf("Ingrese el caracter que desea buscar en el arreglo:");
    fflush(stdin);
    scanf("%c",&i);
    return i;
}

int buscarElemento(char a[],int validos,char elemento,int pos)//validos ya esta restado 1 desde el llamado
{
    int i=0;
    if(pos<=validos)//corte
    {
        if(a[pos] == elemento )//
        {
            i=1;
        }
        else
        {
            i=buscarElemento(a,validos,elemento,pos+1);
        }
    }
    return i;
}

int  menorPersonas(nodo * lista, int edad )
{
    edad=100;
    if(lista)
    {
        edad=menorPersonas(lista->siguiente,edad);
        if(lista->dato.edad <= edad)
        {
            edad = lista->dato.edad;

        }

    }
    return edad;
}
