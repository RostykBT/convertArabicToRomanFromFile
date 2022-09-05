
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    int resultHelper[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    char *ch[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int i = 0;
    int initial;

    FILE *fptr;

    fptr = fopen("test.txt", "r");

    while (fscanf(fptr, "%d", &initial) != EOF)
    {
        printf("%d: " , initial);
        
        if (initial > 3889)
        {
            printf("ERROR the number is too big");
        }
        i = 0;
        while (i < 13)
        {
            resultHelper[i] = initial / num[i];
            initial = initial - resultHelper[i] * num[i];
            i++;
        }

        i = 0;
        for (int j = 0; j < 13; j++)
        {
            for (int k = 0; k < resultHelper[j]; k++)
            {
                printf("%s", ch[j]);
            }

        }
        printf("\n");
    }
    return 0;
}