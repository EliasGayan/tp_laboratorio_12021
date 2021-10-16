/*
 * utn.h
 *
 *  Created on: 15 oct. 2021
 *      Author: Elias
 */

#ifndef UTN_H_
#define UTN_H_

int Menu();
int AgregarEmpleado(Employee* lista, int tamLista, int id);
int ModificarEmpleado(Employee* lista, int tamLista);
int EliminarEmpleado(Employee* lista, int tamLista);
int Informar(Employee* lista, int tamLista);

#endif /* UTN_H_ */

