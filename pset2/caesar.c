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
   int k = atoi(argv[1]);
   
   //Check the key
   if ( k < 0)
   {
    printf("Key must be non-negative\n");
    return 1;
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
   
   //Print out the cipher text
   for (int i = 0, n = strlen(input); i < n; i++)
   {
        if(!isalpha(input[i])) continue;
        
        char ci = input[i];
        
        if(isupper(ci))
        {
            int offset = ci + k - 'A';
            offset = offset % 26;
            ci = uppercaseAlpha[offset];
            input[i] = ci;
        }
           
        else if (islower(ci))
        {
            int offset = ci + k - 'a';
            offset = offset % 26;
            ci = lowercaseAlpha[offset];
            input[i] = ci;
        }
   }
   
   printf("%s\n", input);
    return 0;
}
