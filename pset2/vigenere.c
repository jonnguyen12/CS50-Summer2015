#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    //Check key in command line argument
   if(argc < 2 || argc > 2)
   {
        printf("Usage: must include a key\n");
        return 1;
   }
   
   //Get the key
   string k = argv[1];
   
   //Check the key
   if ( k == NULL)
   {
    printf("Key must be provided\n");
    return 1;
   }
   
   //Check if the key contains digits
   for (int i = 0, n = strlen(k); i < n; i++) 
   {
        if(isdigit(k[i]))
        {
            puts("Key cannot contain digits.");
            return 1;
        }
   
   }
   
   //Declare some variables
   string input = NULL;
   string uppercaseAlpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   string lowercaseAlpha = "abcdefghijklmnopqrstuvwxyz";
   
   //Ask user for plain text
   do
   {
    input = GetString();
   }while(input == NULL);
   
   //To keep track of key index
   int index = 0;
   
   //Print out the cipher text
    for (int i = 0, n = strlen(input); i < n; i++)
       {
           //recycle the key index
           if(index > strlen(k) - 1)
           {
                index = 0;
           }
           
           //Check the character in plain text is alpha
            if(!isalpha(input[i])) continue;
            
            char ci = input[i];
            
            if(isupper(ci) && islower(k[index]))
            {
                int offset = ci + k[index] -'a' - 'A';
                offset = offset % 26;
                ci = uppercaseAlpha[offset];
                input[i] = ci;
            }
               
            else if (islower(ci) && islower(k[index]))
            {
                int offset = ci + k[index] - 'a' - 'a';
                offset = offset % 26;
                ci = lowercaseAlpha[offset];
                input[i] = ci;
            }
            
            else if (islower(ci) && isupper(k[index]))
            {
                int offset = ci + k[index] - 'a' - 'A' ;
                offset = offset % 26;
                ci = lowercaseAlpha[offset];
                input[i] = ci;
            }
            
            else if (isupper(ci) && isupper(k[index]))
            {
                int offset = ci + k[index] - 'A' - 'A';
                offset = offset % 26;
                ci = uppercaseAlpha[offset];
                input[i] = ci;
            }
            
             index++;
        
       }

   
   printf("%s\n", input);
    return 0;
}
