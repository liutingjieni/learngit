#include<stdio.h>

 	int main()

  {    	

	 int array[] = { 6, 7, 8, 9, 10 }; 

    	int *p = array;    

	*(p++) += 123;    

	printf("%d,%d\n", *p, *(++p) ); 

	printf("%d,%d,%d,%d,%d\n", *p--,*p+20, *(p--), *p, *(++p) );  



	return 0;

   }
