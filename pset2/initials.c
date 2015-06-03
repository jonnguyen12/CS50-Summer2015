#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string input = NULL;
    int count = 1; // for initials array
    
    //Get input from user
    do
    {
        input = GetString();
    }while(input == NULL);
    
    //Declare array of initials
    char initials[strlen(input)];
    
    //Get first initial
    initials[0] = toupper(input[0]);
    printf("%c", initials[0]);
    
    //Print the initials out
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (input[i] == ' ') 
        { 
            initials[count] = input[i+1];
            printf("%c", toupper(initials[count]));
            count++;
        }
    }
    printf("\n");
   
    return 0;
}
