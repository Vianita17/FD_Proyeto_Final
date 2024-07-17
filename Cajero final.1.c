#include <stdio.h>
#include<stdlib.h>
#include<windows.h>
typedef struct Tienda{
	char Nombre_producto[25];
	int codigo_barras;
	int cantidad;
	float precio;
}Producto;

int Pedir_cantidad();
Producto Agregar_producto();
void Mostrar_productos(Producto *productos,int Num_productos);
void Mostrar_producto(Producto *productos, int posicion);
int Busqueda(Producto *productos,int Codigo,int contador);
int venta_para(Producto *productos,int Codigo,int contador);
void gotoxy(int, int);
int main(int argc, char *argv[]) {
	system("mode con: cols=80 lines=25");
	system("COLOR F9");
	int Num_productos,eleccion=0,contador_productos=0;
	int cd,cl,cp,td,tf,tp,vu;
	char iva={'%'};
	float i;
	float vp;
	float precio;
	tf = 0;
	td = 0;
	cl = 123;
	Num_productos=Pedir_cantidad();
	Producto productos[Num_productos];
	system("cls");
	while(eleccion!=6){
		
		gotoxy(35,1);printf("MENU\n");
		printf("\nQUE DESEA REALIZAR:\n");
		printf("\n");
		printf("\t1)AGREGAR UN PRODUCTO\n");
		printf("\t2)BUSCAR UN PRODUCTO\n");
		printf("\t3)MOSTRAR PRODUCTOS\n");
		printf("\t4)VENDER PRODUCTOS\n");
		printf("\t5)VER TOTAL DEL DIA\n");
		printf("\t6)SALIR DEL MENU\n");
		printf("\tINSERTE DEL NUMERO DE OPCION: ");
		scanf("%d",&eleccion);
		system("cls");
		switch(eleccion){
		case 1: {
			if(contador_productos==Num_productos){
				printf("\nNo es posible agregar más productos");
			}else{
				productos[contador_productos]=Agregar_producto();
				contador_productos++;
			}
			system("cls");
			break;
		}
		case 2:{
			int buscado,Codigo;
			printf("\nESCRIBA EL CODIGO DE BARRAS PARA BUSCAR EL PRODUCTO: ");
			scanf("%d",&Codigo);
			buscado=Busqueda(productos,Codigo,contador_productos);
			if(buscado==-1){
				printf("\nProducto no encontrado");
			}else{
				Mostrar_producto(productos,buscado);
			}
			system("pause");
			system("cls");
			break;
		
		}
		case 3:{
				Mostrar_productos(productos,contador_productos);
				system("pause");
				system("cls");
				break;
			}
		case 4:{
				int Codigo;
				printf("\n"); 
				printf("INGRESE LA CANTIDAD DE PRODUCTOS QUE SE VENDERA: \n");
				scanf("%i",&cp);
				for (i=1;i<=cp;i+=1) {
					printf("\nESCRIBA EL CODIGO DE BARRAS DEL PRODUCTO: ");
					scanf("%d",&Codigo);
					printf("\n");
					precio= venta_para(productos,Codigo,contador_productos);
					printf("INGRESE LA CANTIDAD A VENDER DEL PRODUCTO %.0f: \n",i);
					scanf("%f",&vp);
					tp = vp*precio;
					tf = tf+tp;
				}
				system("cls");
				printf("DIGITE LA CLAVE DE LA CAJA REGISTRADORA:\n");
				scanf("%i",&cl);
				if ((cl==123)) {
					printf("ESCRIBA EL DINERO ENTREGADO:\n");
					scanf("%i",&cd);
					vu = cd-tf;
					system("pause");
					system("cls");
					printf("\n");
					printf("\n            **TICKET DE COMPRA**\n\n");
					printf("CANTIDAD DE PRODUCTOS COMPRADOS:   %i\n",cp);
					printf("TOTAL DE COMPRA:		  $%i\n",tf);
					printf("DINERO INGRESADO:		 $%i\n",cd);
					printf("IVA:				   0%c\n",iva);
					printf("VUELTO:				  $%i\n",vu);
					td = td+tf;
					tf = 0;
				} else {
					printf("¡CLAVE INVALIDA!\n");
				}
				system("pause");
				system("cls");
				break;	
			}
		case 5:{
					printf("TOTAL DE VENTAS DEL DIA: %i\n",td);
					system("pause");
					break;
			}
		case 6:{
					gotoxy(32,12);printf("¡SEE YOU LATER :D!");
					break;
				}
		}
	}
	return 0;
}

int Pedir_cantidad(){
	int cantidad;
	gotoxy(35,8); printf("HOLA:)\n");
	gotoxy(20,10); printf("SEA BIENVENIDO A NUESTRO PROGRAMA \"ABARROTEX\"\n");
	gotoxy(2,12); printf("UN SISTEMA DE CAJERO EFICAZ PARA LA ADIMISTRACION DE TU TIENDA DE ABARROTES\n");
	gotoxy(35,14); printf("COMENCEMOS...\n");
	system("pause");
	system("cls");
	printf("INSERTE EL TOTAL DE PRODUCTOS EN LA TIENDA: ");
	scanf("%d",&cantidad);
	return cantidad;
}
Producto Agregar_producto(){
	Producto articulo;
	printf("\nESCRIBA EL NOMBRE DEL PRODUCTO: ");
	scanf("%s",&articulo.Nombre_producto);
	printf("\nESCRIBA EL PRECIO DEL PRODUCTO : ");
	scanf("%f",&articulo.precio);
	printf("\nESCRIBA LA CANTIDAD DISPONIBLE DEL PRODUCTO: ");
	scanf("%d",&articulo.cantidad);
	printf("\nESCRIBA EL CODIGO DE BARRAS(NUMEROS): ");
	scanf("%d",&articulo.codigo_barras);
	return articulo;	
}

void Mostrar_productos(Producto *productos,int Num_productos){
	for(int i=0;i<Num_productos;i++){
		printf("\nProducto: %s",productos[i].Nombre_producto);
		printf("\nPrecio: %.2f",productos[i].precio);
		printf("\nCantidad disponible: %d",productos[i].cantidad);
		printf("\nCodigo de barras: %d",productos[i].codigo_barras);
		printf("\n");
	}
}
				
void Mostrar_producto(Producto *productos, int posicion){
	printf("\nProducto: %s",productos[posicion].Nombre_producto);
	printf("\nPrecio: %.2f",productos[posicion].precio);
	printf("\nCantidad disponible: %d",productos[posicion].cantidad);
	printf("\nCodigo de barras: %d",productos[posicion].codigo_barras);
	printf("\n");
}

int Busqueda(Producto *productos,int Codigo,int contador){
	int i=0;
	for(i;i<contador;i++){
		if(productos[i].codigo_barras==Codigo){
			return i;
		}
	}
	return -1;
}

int venta_para(Producto *productos,int Codigo,int contador){
	int i=0;
	float precio_para;
	for(i;i<contador;i++){
		if(productos[i].codigo_barras==Codigo){
			precio_para=productos[i].precio;
		}
	}
	return precio_para;
}
void gotoxy(int x, int y){
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y= y;
	SetConsoleCursorPosition(hcon,dwPos);
}
stdin(fflush)
