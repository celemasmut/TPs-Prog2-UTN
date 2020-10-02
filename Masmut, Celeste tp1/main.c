#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int x=100;
const int y=200;
// 1
void inicializarArreglo(int a[], int dim);
int CargarArreglo(int a[], int dim);
int sumarValoresDeArreglo (int a[],int validos);
int CantidadValores(int a[],int validos);
int CalcularPromedio(int a[],int validos);
void mostrarArreglo(int a[],int dim);

//2
int cargarArregloChar(char a[],int dim);
void invertirArregloChar(char a[],int validos);
void mostrarArregloChar(char a[],int validos);

//4
int buscarPosiciondeMayor(int a[],int val);

//5
void cargarMatriz(int m[12][31]);
int elegirMes();
int buscarMaximaPrecipitacion(int m[12][31],int mes);
void CargarMaxPrecip(int ano[],int mes,int dia);
void CargarAnoPrecip(int ano[],int matriz[12][31]);
void mostrarMatriz(int m[12][31]);

//6
int cadenaCharCapicua(char c[],int validos);

//7
void intercambioDeVariable(int* a, int* b);

//8
int IntercalarArregloEntero(int A[],int validosA, int B[], int validosB, int Destino[]);

//9
int cargarNombreApellidoEdad(int edades[],char a[x][y]);
int buscarMayorEdad(int edades[],int dim);


int main()
{
    //punto 1
   /* int arreglo[30];
    inicializarArreglo(arreglo,30);
    int validos = CargarArreglo(arreglo,30);
    mostrarArreglo(arreglo,validos);
    // printf("\nEl promedio del arreglo es de :%d",CalcularPromedio(arreglo));*/

    //punto 2
    /*char arregloChar[20];
    int validos2=cargarArregloChar(arregloChar,20);
    invertirArregloChar(arregloChar,validos2);
    mostrarArregloChar(arregloChar,validos2);*/

    //punto 4
    /* int mayorpos=buscarPosiciondeMayor(arreglo,validos);
     mostrarArreglo;
     printf("\nLa posicion con el valor mayor es: %d",mayorpos);*/

    //punto5

    int matriz[12][31];
    cargarMatriz(matriz);
    mostrarMatriz(matriz);
    int mesElegido=elegirMes();
    int MaxPrecip=buscarMaximaPrecipitacion(matriz,mesElegido);
    printf("\nLa maxima Precipitacion del mes %d fue el dia : %d\n",mesElegido,MaxPrecip);
    int mesesPrecip[12];
    CargarAnoPrecip(mesesPrecip,matriz);
    printf("\n\n Los dias de maximas precipitaciones del año por mes \n");
    mostrarArreglo(mesesPrecip,12);

    //punto9
/*
    int edades[x];
    char A[x][y]; // x es la dimension e y es longitud del string
    int validos=cargarNombreApellidoEdad(edades,A);
    */

    return 0;
}

void inicializarArreglo(int a[], int dim)
{
    int i=0;
    for(i=0; i<dim; i++)
    {
        a[i]=-1;
    }
}

int CargarArreglo(int a[], int dim)
{
    int i=0;
    char control='s';
    printf("\nCargar Arreglo");
    while(i<dim && control=='s')
    {
        printf("\nIngrese un valor: ");
        scanf("%d",&a[i]);
        printf("\nDesea agregar mas valores? Si = s / No = n : ");
        fflush(stdin);
        scanf("%c",&control);
        i++;
    }
    return i;
}

int sumarValoresDeArreglo (int a[],int validos)
{
    int n=0;
    int i=0;
    while(i<validos)
    {
        n+=a[i];
        i++;
    }
    return n;
}

int CantidadValores(int a[],int validos)
{
    int i=0;
    while(i<validos)
    {
        i++;
    }
    return i;
}

int CalcularPromedio(int a[],int validos)
{
    int promedio;
    int cantidad;
    int suma;

    suma=sumarValoresDeArreglo(a,validos);
    cantidad=CantidadValores(a,validos);
    promedio=(suma/cantidad);
    return promedio;
}

void mostrarArreglo(int a[],int dim)
{
    int i;
    for(i=0; i<dim; i++)
    {
        printf("| %d",a[i]);
    }
}

int cargarArregloChar(char a[],int dim)
{
    int i=0;
    char control='s';
    while(i<dim && control=='s')
    {
        printf("\nIngrese caracter al arreglo: ");
        fflush(stdin);
        scanf("%c",&a[i]);
        printf("\nDesea agregar otro caracter? Si=s / No=n :");
        fflush(stdin);
        scanf("%c",&control);
        i++;
    }
    return i;
}

void invertirArregloChar(char a[],int validos)
{
    int i=0;
    int aux=0;
    int val=validos-1;
    while(i<val)
    {
        aux=a[i];
        a[i]=a[val];
        a[val]=aux;
        i++;
        val--;
    }
}

void mostrarArregloChar(char a[],int validos)
{
    int i=0;
    char control='s';
    while(i<validos && control=='s')
    {
        printf("| %c",a[i]);
        i++;
    }
}

int buscarPosiciondeMayor(int a[],int val)
{
    int i;
    int mayor=0;
    int pos;
    for(i=0; i<val; i++)
    {
        if(mayor<a[i])
        {
            mayor=a[i];
            pos=i;
        }
    }
    return pos+1;
}

void cargarMatriz(int m[12][31]) // funcion de cargar matriz random
{
    int x; //meses
    int y; //dias
    for(x=0; x<12; x++)
    {
        for(y=0; y<31; y++)
        {
            m[x][y]=(rand()%100)+1;
        }
    }
}
int elegirMes()// elijo mes por usuario
{
    int i=0;
    printf("\nElija el mes numerico que desea: ");
    scanf("%d",&i);
    return i;
}

int buscarMaximaPrecipitacion(int m[12][31], int mes) // recorro matriz para buscar el dia de la max precip. del mes elegido por usuario
{
    int MaxPreci=0;
    int DiaMax=0;
    int y=0;

    if(mes>0 && mes<=12)
    {
        for(y=0; y<31; y++)
        {
            if(m[mes-1][y] > MaxPreci)
            {
                MaxPreci=m[mes-1][y];
                DiaMax=y+1;
            }
        }
    }
    return DiaMax;
}
void CargarMaxPrecip(int ano[],int mes,int dia) // ingreso el dia con mayor precip. al arreglo
{
    if(mes>=0 && mes<=12)
    {
        ano[mes]=dia;
    }
}
void CargarAnoPrecip(int ano[],int matriz[12][31]) //funcion que carga el arreglo con los dias de mayor precip en el año
{
    int i=0;
    int diaMax;
    while(i>=0 && i<12)
    {
        diaMax=buscarMaximaPrecipitacion(matriz,i+1);
        CargarMaxPrecip(ano,i,diaMax);
        i++;
    }

}
void mostrarMatriz(int m[12][31])// muestra matriz
{
    int x;
    int y;
    printf("\n------- Matriz de Precipitaciones -------\n");

    for(x=0;x<12;x++)
    {
        printf("                              Mes: %d \n",x+1);
        for(y=0;y<31;y++)
        {
            printf("-%d",m[x][y]);
        }
        printf("\n\n");
    }
}

int cadenaCharCapicua(char c[],int validos)
{
    int i=0;
    int j=validos-1;
    int flag=1;
    while (i<j && flag==1)
    {
        if(c[i]==c[j])
        {
            i++;
            j--;
        }else{
        flag=0;
        }
    }
    return flag;
}

void intercambioDeVariable(int* a, int* b)
{
    int aux;
    aux=*a;
    *a=*b;
    *b=aux;
}

int IntercalarArregloEntero(int A[],int validosA, int B[], int validosB, int Destino[])
{
    int iA=0;
    int iB=0;
    int iDest=0;
    while(iA<validosA && iB<validosB)
    {
        if(A[iA]<B[iB])
        {
            Destino[iDest]=A[iA];
            iA++;
            iDest++;
        }
        else{
            Destino[iDest]=B[iB];
            iB++;
            iDest++;
        }
    }
    while(iA<validosA)
    {
        Destino[iDest]=A[iA];
        iA++;
        iDest++;
    }
    while(iB<validosB)
    {
        Destino[iDest]=B[iB];
        iB++;
        iDest++;
    }
    return iDest;
}

int cargarNombreApellidoEdad(int edades[],char a[x][y])
{
    int i=0;
    char control = 's';
    while (i<x && control == 's')
    {
        printf("\n\nIngrese Apellido: ");
        fflush(stdin);
        scanf("%s",&a[i]);
        printf("\nEdad: ");
        scanf("%d",&edades[i]);
        printf("------Desea Agregar mas?   Si= s / No= n  -------");
        fflush(stdin);
        scanf("%c",&control);
        i++;
    }
    return i;
}
int buscarMayorEdad(int edades[],int dim)
{
    int i;
    int edadMayor=edades[0];
    int posicion=0;
    for(i=0;i<dim;i++)
    {
        if(edadMayor<edades[i])
        {
            edadMayor=edades[i];
            posicion=i;
        }
    }
    return posicion;
}
void mostrarPersonaMayor(char apellido[][y],int pos, int edades[])
{
    printf("La persona con mayor edad es : %c con %d años.",apellido[pos],edades[pos]);
}
int buscarMinimoArreglo(int A[], int validos)
{
    int i;
    int menor=A[0];
    int pos=0;
    for(i=0;i<validos;i++)
    {
        if(menor>A[i])
        {
            menor=A[i];
            pos=i;
        }
    }
    return pos;
}
void retornoPorParametros(int A[],int validos,int *maxino, int *minimo, float *promedio)
{
    int posMax=buscarPosiciondeMayor(A,validos);
    int posMin=buscarMinimoArreglo(A,validos);
    *maxino=A[posMax];
    *minimo=A[posMin];
    *promedio=CalcularPromedio(A,validos);
}
