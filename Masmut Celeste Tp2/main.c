#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct
{
    char nombre[30];
    char genero;
    int edad;
} persona;

const char datos[]="personas.bin";

persona cargar();
void cargarArchivoPersona();


typedef struct
{
    int valores[100];
    int posTope; //posición de nuevo tope, o sea, lugar en donde se almacenará el nuevo valor.
} Pila;


void apilar(Pila *p, int valor);
int desapilar(Pila *p);
int tope(Pila * p);
int pilavacia(Pila * p);
void mostrar(Pila p);
void inicpila(Pila *p);


int main()
{

    Pila primera;
    inicpila(&primera);

    apilar(&primera,5);
    apilar(&primera,8);
    apilar(&primera,3);
    apilar(&primera,9);
    printf("\nPila: ");
    mostrar(primera);

    printf("\n\n Se desapila...\n");
    desapilar(&primera);

    printf("\n El tope es: %d",tope(&primera));
    printf("\n\nPila vacia? 1=si / 0=no : %d\n\n",pilavacia(&primera));
    return 0;
}

persona cargar()
{
    persona aux;
    printf("Nombre:");
    fflush(stdin);
    gets(aux.nombre);
    printf("Edad:");
    scanf("%i",&aux.edad);
    printf("Sexo:");
    fflush(stdin);
    scanf("%c",&aux.genero);
    printf("\n-----------------\n");
    return aux;
}
void cargarArchivoPersona()
{
    persona aux;
    char control;
    FILE*archiP=fopen(datos,"a+b");
    if(archiP!=NULL)
    {
        do
        {
            aux=cargar();
            fwrite(&aux,sizeof(persona),1,archiP);
            printf("Desea cargar otro? s/n:");
            fflush(stdin);
            control=getch();
        }
        while(control!=27);
    }
    fclose(archiP);
}

int archivoArreglo(persona a[])
{
    int i=0;
    persona aux;
    FILE*archivP=fopen(datos,"rb");
    if(archivP==NULL)
    {
        printf("El archivo no existe");

    }
    else
    {
        while((fread(&aux,sizeof(persona),1,archivP)) > 0)
        {
            a[i]=aux;
            i++;
        }
    }
    fclose(archivP);
    return i;
}
char elegirGenero ()
{
    char genero;
    printf("\nIngrese f para Femenino o Ingrese m para masculino:");
    fflush(stdin);
    scanf("%c",&genero);
    return genero;
}

int contarMoV (persona a[],int validos,char genero)
{
    int i=0,cont=0;
    for(i=0; i<validos; i++)
    {
        if(genero==a[i].genero)
        {
            cont++;
        }
    }
    return cont;
}

void dimensionXsexo(persona * b, int cantidad)
{
    b=(persona*)malloc(sizeof(persona)*cantidad);
}

void pasarVoM(persona a[],int validos,char genero,persona b[])
{
    int i,j=0;
    for(i=0; i<validos; i++)
    {
        if(genero==a[i].genero)
        {
            b[j]=a[i];
            j++;
        }
    }

}

void mostrarArreglo(persona a[],int validos)
{
    int i;
    for(i=0; i<validos; i++)
    {
        printf("\nNombre:%s",a[i].nombre);
        printf("\nEdad:%i",a[i].edad);
        printf("\nSexo:%c",a[i].genero);
        printf("\n--------------------");
    }
}

int buscarposMenor(persona a[],int validos, int posi)
{
    int i;
    int menor=posi;
    int menorEdad= a[posi].edad;

    for(i=posi+1; i<validos; i++)
    {
        if(menorEdad > a[i].edad)
        {
            menorEdad= a[i].edad;
            menor=i;
        }
    }
    return menor;
}


void ordenXseleccion(persona a[],int validos)
{
    int i;
    persona aux;
    int posmenor;
    for(i=0; i<validos; i++)
    {
        posmenor=buscarposMenor(a,validos,i);
        aux=a[posmenor];
        a[posmenor]=a[i];
        a[i]=aux;
    }
}
void apilar(Pila* p,int valor)
{
    if(p->posTope < 100)
    {
        p->valores[p->posTope]=valor;
        p->posTope++;
    }
    else
    {
        printf(" \n Pila llena...");
    }

}

int desapilar(Pila*p)
{
    p->posTope--;
    return p->valores[p->posTope];

}
int tope(Pila*p)
{
    return p->valores[p->posTope-1];
}
int pilavacia(Pila* p)
{
    int i=0;
    if(p->posTope == 0)
    {
        i=1;
    }
    return i;
}
void mostrar(Pila p)
{
    int i;
    for(i=0; i<p.posTope; i++)
    {
        printf("-%i-",p.valores[i] );
    }
}
void inicpila(Pila*p)
{
    p->posTope=0;
}



void insertarDato(int a[],int ultpos,int dato)
{
    int i=ultpos;
    while(i>=0 && dato < a[i])
    {
        a[i+1]=a[i];
        i--;
    }
    a[i+1]=dato;
}

void ordenXinsercion(int a[],int validos)
{
    int i=0;
    while(i<validos-1)
    {
        insertarDato(a,i,a[i+1]);
        i++;
    }
}

//7. Función eliminar un elemento de un arreglo.
int elegirDato()
{
    int numero;
    printf("\nElija el dato que desee eliminar:");
    scanf("%i",&numero);
    return numero;
}
int buscarpos(int a[],int validos,int dato)
{
    int pos=0,i;
    for(i=0;i<validos;i++)
    {
        if( a[i]==dato )
        {
            pos=i;
        }
    }
    return pos;
}

int eliminarDato(int a[],int dimension,int pos)
{
    int i;
    for(i=0;i<dimension;i++)
    {
        if(pos<=i)
        {
            a[i]=a[i+1];
        }
    }
    dimension--;
    return dimension;
}
