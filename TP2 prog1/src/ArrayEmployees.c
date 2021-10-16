/*
 * ArrayEmployees.c
 *
 *  Created on: 13 oct. 2021
 *      Author: Elias
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "input.h"


int initEmployees(Employee* list, int len)
{
	int rtn;
	rtn = -1;

	if(list != NULL && len > 0 && len < 1001)
	{
		for(int i=0; i<len; i++)
		{
			list[i].isEmpty = 1;
		}
		rtn = 0;
	}
	return rtn;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	int rtn;
	rtn = -1;

	if(list != NULL && len > 0 && len < 1001 && name != NULL && lastName != NULL && salary > 0 && id > -1)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].isEmpty == 1)
			{
				list[i].isEmpty = 0;
				strcpy(list[i].name, name);
				strcpy(list[i].lastName, lastName);
				list[i].salary = salary;
				list[i].id = id;
				list[i].sector = sector;

				rtn=0;
				break;
			}
		}
	}

	return rtn;
}


int findEmployeeById(Employee* list, int len,int id)
{
	int rtn;
	rtn = -1;

	if(list != NULL && len > 0 && len < 1001 && id > -1)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].id == id && list[i].isEmpty == 0)
			{
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}


int removeEmployee(Employee* list, int len, int id)
{
	int rtn;
	int index;
	rtn = -1;

	index = findEmployeeById(list, len, id);

	if(index != -1)
	{
		list[index].isEmpty = 1;
		rtn = 0;
	}

	return rtn;
}


int sortEmployees(Employee* list, int len, int order)
{
    int rtn;
    int i;
    int j;
    Employee aux;
    rtn = -1;

    if(list != NULL && len > -1 && len < 1001 && order > -1 && order < 2)
    {
       switch(order)
       {

       case 0:
        for( i = 0; i < len - 1; i++)
        {
            for( j = i +1; j < len; j++)
            {
               if(list[i].isEmpty == 0 && list[j].isEmpty == 0)
               {
                    if(strcmp(list[i].lastName, list[j].lastName) < 0 || (strcmp(list[i].lastName, list[j].lastName) == 0 && list[i].sector > list[j].sector))
                    {
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }
               }
            }
        }
        rtn = 0;
        break;

       case 1:
        for(i = 0; i < len - 1; i++)
        {
            for(j = i +1; j < len; j++)
            {
                    if(strcmp(list[i].lastName, list[j].lastName) > 0  || (strcmp(list[i].lastName, list[j].lastName) == 0 && list[i].sector < list[j].sector ))
                    {
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }
            }
        }

        rtn = 0;
        break;
       }
    }

    return rtn;
}

int printEmployees(Employee* list, int length)
{
	printf("ID ------ Name ------ LastName ------ Sector ------ Salary\n");

	for(int i=0; i < length; i++)
	{
		if(list[i].isEmpty == 0)
		{
			printf("%4d ------ %10s ------ %10s ------ %15d ------ %6.2f\n",  list[i].id,
																			list[i].name,
																			list[i].lastName,
																			list[i].sector,
																			list[i].salary);
		}
	}

	return 0;
}











