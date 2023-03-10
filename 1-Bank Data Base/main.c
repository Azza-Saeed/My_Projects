#include <stdio.h>
#include <stdlib.h>
#include "Bank_DataBase.h"
int counter ;
customer_t client[2] ;

int main()
{  char choice ;
   int id_check ;

   while(1)
   {
	   printf("please select one of this options:\n1-Create new customer<press 1 to select this option> \n2-print data of cusomer<press 2 to select this option>\n3-delete data of customer<prss 3 to select this option>\n4-Edit information of customer<press 4 to select this option>\n6-To exit <press enter 6 to select this option >\n\nEnter your choice:");
	   fflush(stdin);
	   scanf("%c",&choice);
	   printf("          <^^>         \n");

	   switch(choice)
	   {
		   case '1':
		     if(counter>=2)
		     {
			   printf("Maximum number of customer is 3 then you can not add any customer\n");
			   break;
		     }
		     Create_vNewCustomer();
		       break;
		   case '2':
		     printf("please enter the id of customer:");
		     fflush(stdin);
		     scanf("%d",&id_check);
		     printf("\n");
		     Print_vDataOfCustomer(id_check);
		       break;
		   case '3':
		     printf("please enter the id of customer:");
		     scanf("%d",&id_check);
		     Delete_vDataOfCustomer(id_check);
		       break;
		   case '4':
		     printf("please enter the id of customer:");
		     fflush(stdin);
		     scanf("%d",&id_check);
		     Edit_vDataOfCustomer(id_check);
		       break;
		   case '6':
		     exit(0);
			 break;
		   default:
		      printf("wrong choice\n\n");
		       break;
	   }
   }
   return 0;
}
