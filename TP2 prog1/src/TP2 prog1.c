/*
 ============================================================================
 Name        : TP2.c
 Author      : Elias
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "input.h"
#define TAM 2 //CAMBIAR A 1000


int main(void)
{
	setbuf(stdout, NULL);
	Employee arrayEmployees[TAM];
	int opcion;
	int contadorEmpleados;
	int id;
	int orden=0;
	id=0;
	contadorEmpleados = 0;

	initEmployees(arrayEmployees, TAM);

	do
	{
		opcion = Menu();

		switch(opcion)
		{
		case 1:
			if(contadorEmpleados < TAM)
			{
				if(AgregarEmpleado(arrayEmployees, TAM, id))
				{
					id++;
					contadorEmpleados++;
				}
				else
				{
					printf("Se encontro un error, no se creo el empleado\n");
				}

			}
			else
			{
				printf("No se encuentra lugar de almacenamiento\n");
			}
		break;
		case 2:
			if(contadorEmpleados > 0)
			{
				ModificarEmpleado(arrayEmployees, TAM);
			}
			else
			{
				printf("No se encuentran empleados para modificar\n");
			}
		break;
		case 3:
			if(contadorEmpleados > 0)
			{
				printEmployees(arrayEmployees, TAM);

				if(EliminarEmpleado(arrayEmployees, TAM) == 1)
				{
					contadorEmpleados--;
				}
			}
			else
			{
				printf("No se encuentran empleados para dar de baja\n");
			}
		break;
		case 4:
			if(contadorEmpleados > 0)
			{
				printf("Ingrese 1 para mostrar Apellido y sector en forma ascendente o 0 para descendente\n");
				fflush(stdin);
				scanf("%d", &orden);

				while(orden != 1 && orden != 0)
				{
					printf("ERROR, Reingrese una opcion valida: 1 o 0\n");
					fflush(stdin);
					scanf("%d", &orden);
				}

				sortEmployees(arrayEmployees, TAM, orden);
				printEmployees(arrayEmployees, TAM);

				Informar(arrayEmployees, TAM);
			}
			else
			{
				printf("No se encuentran empleados para Informar\n");
			}

			break;
		}

	}while(opcion != 5);

	return EXIT_SUCCESS;
}





