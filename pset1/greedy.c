#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //Variables declaration
   float input = 0;
   printf("O hai! ");
   
   //Ask user for input
   do
   {
      printf("How much change is owned?\n");
      input = GetFloat();
   }while (input < 0);
   
   
   //Process input
   int count = 0; //to count how many coins
   
   //Process dollars
   input = input * 100;
   int cinput = (int) round(input);
   
   // Process cents
   do
   {
        if (cinput >= 25) cinput -= 25;
        else if (cinput < 25 && cinput >= 10) cinput -= 10;
        else if(cinput < 10 && cinput >= 5) cinput -= 5;
        else if (cinput < 5 && cinput > 0) { cinput -= 1; };
        count++;
       
   }while(cinput > 0);
   
   // Print number of coins
   printf("%d\n", count);
}
