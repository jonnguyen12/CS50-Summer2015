#include <stdio.h>
#include <cs50.h>
#include <ctype.h>

int main(void)
{

    int height = 0;
    do
    {
        printf("Height: ");
        height = GetInt();
    }while(height < 0 || height > 23);
    
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < height - i - 1; k++)
        {
            printf(" ");
        }
        
        for (int j = 0; j < i + 2; j++)
        {
            printf("#");
        }
        
        printf("\n");
    }
    
    return 0;

}
