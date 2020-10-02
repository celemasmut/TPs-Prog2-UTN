#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char apellido [30];
    char nombre[30];
    char dni [10];
} stPersona;

typedef struct
{
    int id;
    stPersona persona;
    char cuit [15];
    char email[90];
    char domicilioParticular[50];
    char domicilioComercial[50];
    char TelefonoFijo[15];
    char TelefonoCel[15];
    int cargo;
} stCliente;

typedef struct
{
    int id;
    stPersona persona;
    char cuit [15];
    char email[90];
    char domicilioComercial[50];
    char TelefonoFijo[15];
    char TelefonoCel[15];
} stProveedor;

typedef struct
{
    int id;
    stPersona persona;
    char cuil [15];
    char email[90];
    char domicilioParticular[50];
    char TelefonoFijo[15];
    char TelefonoCel[15];
    int idTipo;
    int sueldo;
} stEmpleado;

stPersona Persona ();
int verificarDNI(char dni[]);
stEmpleado empleado();
int id(char archivo1[]);
void ingresaEmpleadoArchivo();
void guardaEmpleadoArchivo(char archivoEmpleados[], stEmpleado aux);
void mostrarEmpleado(stEmpleado aux);
void mostrarArchivoEmpleado();
int ingresaEmpleadosArray(stEmpleado e[], int v, int dim);
void mostrarArregloEmpleados(stEmpleado e[], int v);
int archivoEmpleados2arreglo(char archivo[], stEmpleado e[], int v, int dim);
int archivoCompletoEmpleados2arreglo(char archivo[], stEmpleado e[], int dim,int v);
int cuentaRegistros(char file[], int dataSize);



#endif // EMPLEADO_H_INCLUDED
