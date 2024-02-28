
/*

Proyecto Parcial 1
Nombre: Daniel Alberto Reyna López
Fecha: 28/2/2024

*/


//Uso de librerias nuestro codigo
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <iomanip>

using namespace std;

//Definicion de valores
#define NUMERO_EQUIPOS 5
#define NUMERO_MATERIAS 5
#define NUMERO_ANIOS 4
#define MAX_CALIFICACION 50
#define MIN_CALIFICACION 0
#define MAXIMA_LONGITUD_CADENA 50

//Declaracion de funciones
void llamaCiclo();
int busquedaAleatorios(int minimo, int maximo);
void llenarMatriz(float matriz[NUMERO_EQUIPOS][NUMERO_ANIOS + 1]);
void imprimirMatrizLinea();
float imprimirMatriz(float matriz[NUMERO_EQUIPOS][NUMERO_ANIOS + 1], char equipos[NUMERO_EQUIPOS][MAXIMA_LONGITUD_CADENA], string nombreFacultad);

//Programa empieza con la lectura del programa
int main()
{
    srand(getpid());
    llamaCiclo();
    return 0;
}
//Proceso de citar una funcion
void llamaCiclo()
{
    float matriz_Liga_Nacional[NUMERO_EQUIPOS][NUMERO_ANIOS + 1];
    float matriz_Liga_de_Ascenso[NUMERO_EQUIPOS][NUMERO_ANIOS + 1];
    float matriz_Liga_Metropolitana[NUMERO_EQUIPOS][NUMERO_ANIOS + 1];
    char opcion;
    bool repetir = true;

    float promedio_Liga_Nacional;
    float promedio_Liga_de_Ascenso;
    float promedio_Liga_Metropolitana;

    char equipos[NUMERO_EQUIPOS][MAXIMA_LONGITUD_CADENA] = {"Equipo1","Equipo2","Equipo3","Equipo4","Equipo5"};
    do
    {
        system("cls");
        promedio_Liga_Nacional=0;
        promedio_Liga_de_Ascenso=0;
        promedio_Liga_Metropolitana=0;
        cout << "*** Comparativo de Ligas ***" << endl << endl;
        llenarMatriz(matriz_Liga_Nacional);
        promedio_Liga_Nacional = imprimirMatriz(matriz_Liga_Nacional, equipos, "Liga_Nacional");
        llenarMatriz(matriz_Liga_de_Ascenso);
        promedio_Liga_Nacional = imprimirMatriz(matriz_Liga_de_Ascenso, equipos, "Liga_de_Ascenso");
        llenarMatriz(matriz_Liga_Metropolitana);
        promedio_Liga_Metropolitana = imprimirMatriz(matriz_Liga_Metropolitana, equipos, "Liga_Metropolitana");
        //impresion de los valores solicitados
        if (promedio_Liga_Nacional > promedio_Liga_de_Ascenso && promedio_Liga_Nacional > promedio_Liga_Metropolitana)
        {
            cout << " La Liga con el mejor promedio es : " << "Liga_Nacional" << " Promedio: " << promedio_Liga_Nacional << endl;
        } else
        if (promedio_Liga_Nacional > promedio_Liga_Nacional && promedio_Liga_de_Ascenso > promedio_Liga_Metropolitana)
        {
            cout << " La Liga con el mejor promedio es : " << "Liga_de_Ascenso" << " Promedio: " << promedio_Liga_de_Ascenso << endl;
        } else
        if (promedio_Liga_Metropolitana > promedio_Liga_de_Ascenso && promedio_Liga_Metropolitana > promedio_Liga_Nacional)
        {
            cout << " La Liga con el mejor promedio es : " << "Liga_Metropolitana" << " Promedio: " << promedio_Liga_Metropolitana << endl;
        } else
        {
            cout << " Algunas Ligas tienen el mismo promedio " << endl << endl;
        }
        cout << "Desea otro calculo (s/n)? ";
        cin >> opcion;
        if (opcion == 'n')
        {
            repetir=false;
        }
    } while (repetir);
}
int busquedaAleatorios(int minimo, int maximo)
{
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

void llenarMatriz(float matriz[NUMERO_EQUIPOS][NUMERO_ANIOS + 1])
{
    int y, x;
    for (y = 0; y < NUMERO_EQUIPOS; y++)
    {
        float suma = 0;
        int calificacion = 0;
        for (x = 0; x < NUMERO_ANIOS; x++)
        {
            if (x == 0 || x == 3)  //Primer año
            {
                calificacion = busquedaAleatorios(MIN_CALIFICACION, 20);
            } else if (x == 1)  //segundo año
            {
                calificacion = busquedaAleatorios(MIN_CALIFICACION, 25);
            } else if (x == 2)  //tercer año
            {
                calificacion = busquedaAleatorios(MIN_CALIFICACION, 35);
            }
            suma += (float)calificacion;
            matriz[y][x] = calificacion;
            calificacion=0;
        }
        // Agregar promedio

        matriz[y][NUMERO_ANIOS] = suma;
    }
}

void imprimirMatrizLinea()
{
    int x;

    cout << "+--------";
    for (x = 0; x < NUMERO_ANIOS + 1; x++)
    {
        cout << "+---------";
    }
    cout << "+\n";
}
float imprimirMatriz(float matriz[NUMERO_EQUIPOS][NUMERO_ANIOS + 1], char equipos[NUMERO_EQUIPOS][MAXIMA_LONGITUD_CADENA], string nombreFacultad)
{
    //Imprecion de la matriz junto con los calculos del programa
    int y, x;

    float promedioMayor = matriz[0][NUMERO_ANIOS];
    float promedioMenor = matriz[0][NUMERO_ANIOS];
    float totalGeneral = 0;
    float promedioGeneral = 0;
    char alumnoPromedioMayor[MAXIMA_LONGITUD_CADENA];
    char alumnoPromedioMenor[MAXIMA_LONGITUD_CADENA];
    memcpy(alumnoPromedioMayor, equipos[0], MAXIMA_LONGITUD_CADENA);
    memcpy(alumnoPromedioMenor, equipos[0], MAXIMA_LONGITUD_CADENA);
    cout << nombreFacultad << endl;
    cout << "(anio1)=>2010  (anio2)=>2011 (anio3)=>2012 (anio4)=>2014" << endl;
    imprimirMatrizLinea();
    cout << setw(9) << "Equipos";
    for (x = 0; x < NUMERO_ANIOS; x++)
    {
        cout << setw(9) << "Anio" << x + 1; //El programa no lee el caracter "Ñ" por lo que lo cambie por el termino "anio"
    }
    cout << setw(8) << "Tot" << endl;
    imprimirMatrizLinea();
    for (y = 0; y < NUMERO_EQUIPOS; y++)
    {
        cout << "!" << setw(8) << equipos[y] << "!";
        float suma = 0;
        for (x = 0; x < NUMERO_ANIOS; x++)
        {
            int calificacion = matriz[y][x];
            cout << setw(9) << calificacion << "!";
        }
        float promedio = matriz[y][NUMERO_ANIOS];
        totalGeneral += matriz[y][NUMERO_ANIOS];
        if (promedio > promedioMayor)
        {
            promedioMayor = promedio;
            memcpy(alumnoPromedioMayor, equipos[y], MAXIMA_LONGITUD_CADENA);
        }
        if (promedio < promedioMenor)
        {
            promedioMenor = promedio;
            memcpy(alumnoPromedioMenor, equipos[y], MAXIMA_LONGITUD_CADENA);
        }
        cout << setw(9) << fixed << setprecision(2) << promedio << "!" << endl;
        imprimirMatrizLinea();
    }
    promedioGeneral = totalGeneral / NUMERO_EQUIPOS;
    cout << "Nota mayor: " << setw(10) << alumnoPromedioMayor <<  setw(10) << promedioMayor << endl;
    cout << "Nota menor: " << setw(10) << alumnoPromedioMenor <<  setw(10) << promedioMenor << endl;
    cout << "Nota prom : " << setw(10) <<  promedioGeneral << endl << endl;
    return promedioGeneral;
}
