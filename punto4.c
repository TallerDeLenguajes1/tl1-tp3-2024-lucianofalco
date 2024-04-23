/*
4) Considere la siguiente situación: En una distribuidora necesita implementar la carga de
productos de sus preventistas, los cuales recolectan los productos que sus clientes van
necesitando. El sistema que se utiliza en la empresa es desarrollado por equipos de
programadores donde cada equipo se encarga de una tarea específica. Usted forma parte del
equipo de programación que se encargará de hacer el módulo para los preventistas:
Tareas:
Cada preventista puede visitar hasta 5 clientes, los cuales por cuestiones operativas solo
puede pedir hasta 10 productos
Las estructuras de datos necesarias son las siguientes:


i) Desarrollar una interfaz por consola donde se solicite al usuario la cantidad de
clientes.
ii) Solicitar al usuario la carga de los clientes creados dinámicamente en el paso anterior.
iii) A medida que se dé de alta cada cliente, Generar aleatoriamente la cantidad de
productos asociados al cliente y sus características.
Ej: producto cargado nro. 2
Producto {
ProductoID=2
Cantidad = 1;
*TipoProducto = “Snack”;
PrecioUnitario = 100;
}
iv) Implemente una función que calcule el costo total de un producto. Esta función debe
recibir como parámetro el producto y devolver el resultado de calcular la Cantidad por
el PrecioUnitario.
v) Mostrar por pantalla todo lo cargado. Incluyendo un total a pagar por cliente
(sumatoria del costo de todos los productos)

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

struct Producto {
int ProductoID; //Numerado en ciclo iterativo
int Cantidad; // entre 1 y 10
char *TipoProducto; // Algún valor del arreglo TiposProductos
float PrecioUnitario; // entre 10 - 100
};

struct Cliente {
int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
struct Producto *Productos //El tamaño de este arreglo depende de la variable
// “CantidadProductosAPedir”
};

// i) Desarrollar una interfaz por consola donde se solicite al usuario la cantidad de
// clientes.

// ii) Solicitar al usuario la carga de los clientes creados dinámicamente en el paso anterior.

int SolicitarCantidad();
struct Cliente * ReservarClientes();
struct Cliente *cargarCliente();
void MostrarClientes(struct Cliente*);
void MostrarProducto(struct Producto*);

int main()
{
    struct Cliente *Clientes;
    Clientes = ReservarClientes();
    MostrarClientes(Clientes);

    return 0;
}

void MostrarProducto(struct Producto *c){
    for (int i = 0; i < c->Cantidad; i++)
    {
        printf("\n\t Producto #%i" , i+1);
        printf("\n\tID: %i" , c->ProductoID );
        printf("\n\t Cantidad: %i" , c->Cantidad);
        printf("\n\t Precio unitario: %i" , c->PrecioUnitario);
        printf("\n\t Tipo: %s" , c->TipoProducto);

    }
    
}
void MostrarClientes(struct Cliente *clientes){
    for (int i = 0; i < clientes->CantidadProductosAPedir; i++)
    {
        printf("Cliente #%i :\n", i+1 );
        printf("ID:\n" , clientes[i].ClienteID);
        printf("Nombre: %s\n" , clientes[i].NombreCliente);
        MostrarProducto(clientes[i].Productos);
    }
    
}

int SolicitarCantidad(){
    int cantidad;
    printf("\n Ingrese la cantidad de clientes\n");
    scanf("%d" , &cantidad);
    return cantidad;
}

struct Cliente * ReservarClientes()
{
    int cantidad;
    struct Cliente ** cliente;
    cantidad = SolicitarCantidad();

    cliente = (struct Cliente **)malloc(cantidad * sizeof(struct Cliente *));
    
    for (int i = 0; i < cantidad; i++)
    {
        cliente[i] = cargarCliente();
        cliente[i]->ClienteID = i ;
    }   

    return *cliente ; 
}

struct Cliente* cargarCliente(){
    struct Cliente *cliente;
    cliente = (struct cliente*)malloc(sizeof(struct Cliente));
    cliente->Productos = (struct Producto *) malloc(sizeof(struct Producto));
    char *buff = (char*)malloc(sizeof(char)*100);;
    

    printf("\nIngrese el nombre del cliente\n");
    fflush(stdin);
    gets(buff);
    cliente->NombreCliente = (char*)malloc(strlen((buff)+1)*sizeof(sizeof(char)));

    
    printf("\nIngrese la cantidad de productos que pedira\n");
    scanf("%d",&cliente->CantidadProductosAPedir);
    
    printf("\nIngrese el producto\n");

    printf("\nIngrese la cantidad de productos \n");
    scanf("%d",&cliente->Productos->Cantidad);

    printf("\nIngrese el precio unitario del producto \n");
    scanf("%f",&cliente->Productos->PrecioUnitario);

    int tamanio = sizeof(TiposProductos)/sizeof(TiposProductos[0]);
    int indice = rand()%tamanio;
    cliente->Productos->TipoProducto = TiposProductos[indice];


    return cliente ;
}
