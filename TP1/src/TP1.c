/*
 ============================================================================
 Name        : TP1.c
 Author      : GAYAN ELIAS
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
 * Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
 1. Ingresar 1er operando (A=x)
 2. Ingresar 2do operando (B=y)
 3. Calcular todas las operaciones
 a) Calcular la suma (A+B)
 b) Calcular la resta (A-B)
 c) Calcular la division (A/B)
 d) Calcular la multiplicacion (A*B)
 e) Calcular el factorial (A!)
 4. Informar resultados
 a) “El resultado de A+B es: r”
 b) “El resultado de A-B es: r”
 c) “El resultado de A/B es: r” o “No es posible dividir por cero”
 d) “El resultado de A*B es: r”
 e) “El factorial de A es: r1 y El factorial de B es: r2”
 5. Salir
 • Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
 que contenga las funciones para realizar las cinco operaciones.
 • En el menú deberán aparecer los valores actuales cargados en los operandos A y B
 (donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
 • Deberán contemplarse los casos de error (división por cero, etc)
 • Documentar todas las funciones
 * */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(void)
{
	//DECLARACION DE VARIABLES
	int opcion;
	float operando1;
	float operando2;
	float resultadoSumar;
	float resultadoRestar;
	float resultadoDividir;
	float resultadoMultiplicar;
	unsigned long int resultadoFactorial;

	operando1 = 0;
	operando2 = 0;
	setbuf(stdout, NULL);
	do
	{	//MENU
		fflush(stdin);
		printf("BIENVENIDO A LA CALCULADORA!!!\n");
		printf("Seleccione una opcion:\n");
		printf("1- 1er OPERANDO:\n ");
		printf("2- 2do OPERANDO:\n ");
		printf("3- REALIZAR CALCULOS\n");
		printf("    -Sumar\n");
		printf("    -Restar\n");
		printf("    -Multiplicar\n");
		printf("    -Dividir\n");
		printf("    -Factorial\n");
		printf("4- MOSTRAR EL RESULTADO DE LOS CALCULOS\n");
		printf("5- SALIR DEL PROGRAMA\n\n");

		printf("OPCION: ");
		scanf("%d", &opcion);

		switch (opcion)
		{
		case 1: //1. Ingresar 1er operando (A=x)
			operando1 = PedirNumero();
			break;

		case 2: //2. Ingresar 2do operando (B=y)
			operando2 = PedirNumero();
			break;

		case 3: //3. Calcular todas las operaciones
			resultadoSumar = Sumar(operando1, operando2);
			resultadoMultiplicar = Multiplicar(operando1, operando2);
			resultadoDividir = Dividir(operando1, operando2);
			resultadoRestar = Restar(operando1, operando2);
			resultadoFactorial = Factorial(operando1);
			break;

		case 4: //4. Informar resultados
			printf("RESULTADO DE LA SUMA: %.2f\n", resultadoSumar);
			printf("RESULTADO DE LA RESTA: %.2f\n", resultadoRestar);
			printf("RESULTADO DE LA MULTIPLICACION: %.2f\n", resultadoMultiplicar);

			if (operando2 == 0)
				{
					printf("NO SE PUEDE DIVIDIR POR CERO!!!\n");
				}
				else
				{
					resultadoDividir = Dividir(operando1, operando2);
					printf("RESULTADO DE LA DIVISION: %.2f\n", resultadoDividir);
				}

			printf("RESULTADO DE FACTORIAL: %ld\n\n", resultadoFactorial);
			system("pause");
			break;


		case 5:
			printf("CERRANDO PROGRAMA\n");
			break;

		default:
			printf("NO SE HA HECHO NINGUNA OPERACION, REINTENTE NUEVAMENTE\n\n\n");
			break;

		}

	} while (opcion != 5);

	printf("FIN DE LA CALCULADORA BYEBYE\n\n");

	return EXIT_SUCCESS;
}
