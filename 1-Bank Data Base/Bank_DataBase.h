/**
* About: Bank_DataBase.h
* Author: Azza Saeed
* Created: 2/3/2023
**/

#ifndef BANK_DATABASE_H
#define BANK_DATABASE_H
typedef struct customer
{
	char name[20]; /* name of customer */
	int id; /* id of customer */
	double cash; /* cash of customer */
	char type[7]; /* credit or debit */
}customer_t;
void Create_vNewCustomer(void); /* to create new customer */
void Edit_vDataOfCustomer(int id); /* to edit the data of customer */
void Delete_vDataOfCustomer(int id); /* to delete data of a customer */
void Print_vDataOfCustomer(int id); /* to print data of cusomer */
#endif
