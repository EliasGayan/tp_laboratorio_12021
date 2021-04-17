/*
 * funciones.c
 *
 *  Created on: 11 abr. 2021
 *      Author: Elias
 */
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

float PedirNumero(void)
{
	float numero1;
	do{
		printf("INGRESAR OPERANDO: ");
		scanf("%f", &numero1);


	}while(numero1==0);
	puts("\n\n\n\n\n\n\n\n");
	return numero1;
}

float Sumar(float numero1, float numero2)
{
	float resultado;

	resultado = numero1 + numero2;
	return resultado;
}

float Dividir(float numero1, float numero2)
{
	float resultado;

	resultado = numero1 / numero2;
	if(numero2 == 0)
	{
		printf("NO SE PUEDE DIVIDIR POR CERO!!!\n");
	}

	return resultado;
}

float Multiplicar(float numero1, float numero2)
{
	float resultado;

	resultado = numero1 * numero2;
	return resultado;
}

float Restar(float numero1, float numero2)
{
	float resultado;

	resultado = numero1 - numero2;
	return resultado;
}

unsigned long int Factorial(int numero1)
{
	int fact=1;
	int i;

	for(i=numero1; i>0; i--)
	{
		fact=fact*i;
	}


	return fact;
}
