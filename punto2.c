/*2) Una empresa necesita simular la producción de los próximos 5 años para tal fin necesita
generar una matriz (estática) de 5x12 donde cada fila corresponde a un año y cada columna
es un mes. Ud. debe realizar las siguientes tareas:
a. Cargue dicha matriz con valores aleatorios entre 10000 y 50000.
b. Muestre por pantalla los valores cargados
c. Saque el promedio de ganancia por año y muestrelos por pantalla
d. Obtenga el valor*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define filas 5
#define columnas 12

int generarNumeroAleatorio(int min, int max);
void CargarMatriz(int matriz[filas][columnas]);
void MostrarValoresCargados(int matriz[filas][columnas]);
void PromedioGanancias(int matriz[filas][columnas]);

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int mt[filas][columnas];
    CargarMatriz(mt);
    MostrarValoresCargados(mt);
    PromedioGanancias(mt);
    return 0;
}

int generarNumeroAleatorio(int min, int max) {
    return (rand() % (max - min + 1) + min);
}

void CargarMatriz(int matriz[filas][columnas]){
    int i , j ;
    for ( i = 0; i < filas; i++)
    {
        for ( j = 0; j < columnas; j++)
        {
            matriz[i][j] = generarNumeroAleatorio(10000 , 50000);
        }
    }
}

void MostrarValoresCargados(int matriz[filas][columnas]){
    int i , j ;
    for ( i = 0; i < filas; i++)
    {
        for ( j = 0; j < columnas; j++)
        {
            printf("%i ", matriz[i][j]);
        }
        printf("\n");
    }  
}

void PromedioGanancias(int matriz[filas][columnas]){
    float promedioPorAnio;
    float vectorGanancias[columnas];
    float suma = 0;
    int i , j ;
    for ( i = 0; i < filas; i++)
    {
        for ( j = 0; j < columnas; j++)
        {
            suma = suma + matriz[i][j];
        }
        promedioPorAnio = suma/columnas;
        vectorGanancias[i] = promedioPorAnio;
    }

    printf("\n\n Promedio de ganancias por anio: \n");
    for ( i = 0; i < filas; i++)
    {
        printf("#Promedio hace %i anios = [%f] \n" , filas-(i+1) , vectorGanancias[i]);
    }
    
}
