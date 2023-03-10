/**
* About: Bank_DataBase.c
* Author: Azza Saeed
* Created: 2/3/2023
**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Bank_DataBase.h"

extern int counter; /* to count number of customers */
extern customer_t client[2];
	int id_check;
	int i;
	void Create_vNewCustomer(void)
	{
		if(counter<=2)
		{
	         for(i=0;i<2;i++)
			 {
				  printf("Name of new cusomer number %i:",i+1);
			      fflush(stdin);
			      gets((client[i].name));
				  printf("\n");
				  printf("id of new customer number %i:",i+1);
				  fflush(stdin);
				  scanf("%d",&(client[i].id));
				  printf("\n");
				L1:  printf("cash for new customer number %i:",i+1);
				  fflush(stdin);
				  scanf("%lf",&(client[i].cash));
				  if(client[i].cash<0)
				  {
					printf("Please cash must be positive cash:");
					goto L1;
                  }
				  printf("\n");
				  printf("type of cash number %i:",i+1);
				  fflush(stdin);
				  gets(&(client[i].type));
				  printf("\n");
				  counter++;
			 }

	    }
	}
	void Edit_vDataOfCustomer(int id)
	{
		for(i=0;i<counter;i++)
		{
			if(id==client[i].id)
			{
				  printf(" New name of cusomer number %i:",counter+i);
			      fflush(stdin);
			      gets(&(client[i].name));
				  printf("\n");
				  printf("New id of customer number %i:",counter+i);
				  scanf("%i",&client[i].id);
				  printf("\n");
				  printf("New cash for customer number %i:",counter+i);
				  fflush(stdin);
				  scanf("%lf",&client[i].cash);
				  printf("\n");
				  printf("New type of cash number %i:",counter+i);
				  fflush(stdin);
				  gets((client[i].type));
				  printf("\n");
			}
		}
	}
	void Print_vDataOfCustomer(int id)
	{
		for(i=0;i<counter;i++)
		{
			if(id==client[i].id)
			{
				printf(" Name of customer number %i is:%s",i+1,client[i].name);
				printf("\n");
				printf(" Id of customer number %i is:%i",i+1,client[i].id);
				printf("\n");
				printf(" cash of customer number %i is:%0.2lf",i+1,client[i].cash);
				printf("\n");
				printf(" type of cash of customer number %i is:%s",i+1,client[i].type);
				printf("\n");
                break;
			}
		}
	}
    void Delete_vDataOfCustomer(int id)
	{
		int index;
		for(i=0;i<=counter-1;i++)
			{
				if(client[i].id==id)
				{
					index=i;
					for(i=index;i<=counter-1;i++)
					{
						client[i]=client[i+1];
					}
				}
			}
        client[counter].cash=-1; // -1 indicate this is empty place for new customer
        client[counter].id=-1 ;  // -1 indicate this is empty place for new customer
        strcpy(client[counter].name,"-1"); // -1 indicate this is empty place for new customer
        strcpy(client[counter].type,"-1"); // -1 indicate this is empty place for new customer
        counter--;

	}



