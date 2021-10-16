/*
 * utn.c
 *
 *  Created on: 15 oct. 2021
 *      Author: Elias
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "input.h"

int Menu()
{
	int opcion;

	printf("INGRESE LA OPCION QUE DESEA: \n\n");
	printf("  1-DAR DE ALTA: \n");
	printf("  2-MODIFICAR: \n");
	printf("  3-DAR DE BAJA: \n");
	printf("  4-INFORMAR: \n");
	printf("  5-SALIR DEL PROGRAMA: \n");
	fflush(stdin);
	scanf("%d", &opcion);

	while(opcion > 5 || opcion < 1)
		{
			printf("¡¡OPCION INVALIDA!!, REINGRESE NUEVAMENTE: \n");
			fflush(stdin);
		    scanf("%d", &opcion);
		}

	return opcion;
}


/**
 *
 *@fn int AgregarEmpleado(Employee*, int, int)
 * @brief
 *
 * @param lista (recibe la estructura)
 * @param tamLista (recibe el tamaño de la lista)
 * @param id (recibe el id del empleado)
 * @return (retorna 0 en caso de que no se haya cargado el empleado o 1 en caso de que se haya cargado)
 */
int AgregarEmpleado(Employee* lista, int tamLista, int id)
{

	int rtn;
	rtn = 0;
	char nombre[30];
	char apellido[30];
	float salario;
	int sector;

	if(lista != NULL && tamLista > -1 && tamLista < 1001)
	{
		printf("ID: %d\n", id);

		printf("Ingrese su nombre: \n");
		fflush(stdin);
		scanf("%s", nombre);
		printf("Ingrese su apellido: \n");
		fflush(stdin);
		scanf("%s", apellido);
		printf("Ingrese su salario: \n");
		fflush(stdin);
		scanf("%f", &salario);
		printf("Ingrese su sector: \n");
		fflush(stdin);
		scanf("%d", &sector);
		if(addEmployee(lista, tamLista, id, nombre, apellido, sector, salario) == 0)
		{
			printf("Se creo exitosamente\n");
			rtn = 1;
		}


	}

	return rtn;
}



/**
 * @fn int EliminarEmpleado(Employee*, int)
 * @brief
 *
 * @param lista (recibe la estructura)
 * @param tamLista (recibe el tamaño de la lista)
 * @return (retorna 0 en caso de que no se haya eliminado el empleado y retorna 1 si se ha eliminado)
 */

int EliminarEmpleado(Employee* lista, int tamLista)
{
	int rtn;
	rtn = 0;
	int id;

	if(lista != NULL && tamLista > -1)
	{


		printf("Ingrese el ID del empleado que desea eliminar: \n");
		scanf("%d", &id);

		if(removeEmployee(lista, tamLista, id) == -1)
		{
			printf("El ID ingresado no existe\n");
		}
		else
		{
			printf("El ingresado ID se ha eliminado\n");
			rtn=1;
		}
	}

	return rtn;
}




int ModificarEmpleado(Employee* lista, int tamLista)
{
	Employee nuevoEmpleado;
	int id;
	int rtn;
	rtn = 0;
	int modificar;

	int i;
	i = -1;

	if(lista != NULL && tamLista > -1)
	{
		printEmployees(lista, tamLista);
		printf("Ingrese el ID del empleado a modificar: \n");
		fflush(stdin);
		scanf("%d", &id);

		i = findEmployeeById(lista, tamLista, id);

		if(i != -1)
		{
			nuevoEmpleado = lista[i];
			printf("Que desea modificar: 1-NOMBRE\n2-APELLIDO\n3-SALARIO\n4-SECTOR\n");
			fflush(stdin);
			scanf("%d", &modificar);


			while(modificar > 4 || modificar < 1)
			{
				printf("Error, intente nuevamente: 1-NOMBRE\n2-APELLIDO\n3-SALARIO\n4-SECTOR\n");
				fflush(stdin);
				scanf("%d", &modificar);
			}


			switch(modificar)
			{
			case 1:
				printf("Ingrese el nuevo nombre: \n");
				fflush(stdin);
				gets(nuevoEmpleado.name);
			break;
			case 2:
				printf("Ingrese el nuevo apellido: \n");
				fflush(stdin);
				gets(nuevoEmpleado.lastName);
				break;
			case 3:
				printf("Ingrese el nuevo salario: \n");
				fflush(stdin);
				scanf("%f", &nuevoEmpleado.salary);
			break;
			case 4:
				printf("Ingrese el nuevo sector: \n");
				fflush(stdin);
				scanf("%d", &nuevoEmpleado.sector);

			}
			lista[i] = nuevoEmpleado;
			rtn = 1;
			printf("La modificacion ha salido con éxito!!!\n");
		}
		else
		{
			printf("El ID no existe\n");
		}
	}

	return rtn;
}


int Informar(Employee* lista, int tamLista)
{
	int rtn = -1;
	float salarioTotal = 0;
	int superaPromedio = 0;
	float promedio = 0;
	int contadorEmpleados = 0;

	if(lista != NULL && tamLista > -1)
	{
		for(int i=0; i<tamLista; i++)
		{
			if(lista[i].isEmpty == 0)
			{
				salarioTotal += lista[i].salary;
				contadorEmpleados++;
			}
		}

		promedio = salarioTotal / contadorEmpleados;
		printf("El salario total es %.2f \n", salarioTotal);
		printf("EL salario promedio es: %.2f \n", promedio);

		for(int i=0; i < tamLista; i++)
		{
			if(lista[i].salary > promedio && lista[i].isEmpty == 0)
			{
				superaPromedio++;
			}
		}
		printf("La cantidad de empleados que superan el promedio: %d \n", superaPromedio);
		rtn = 0;
	}

	return rtn;
}

