
#include <stdio.h>
#include <stdlib.h> //library that is required to read the file

int main()
{
    char *ch[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int num[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    int resultHelper[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    int i = 0;

    int initial;

    FILE *fptr; // file pointer

    fptr = fopen("test.txt", "r"); // open file in read mode

    while (fscanf(fptr, "%d", &initial) != EOF) // read file until end of file
    {
        printf("%d: " , initial);
        
        if (initial > 3889) //reuired condition, mentioned in the question
        {
            printf("ERROR the number is too big");
        }

        i = 0;
        while (i < 13) //loopto find the number of times each part of the number is repeated
        {
            resultHelper[i] = initial / num[i];
            initial = initial - resultHelper[i] * num[i];
            i++;
        }

        i = 0;
        for (int j = 0; j < 13; j++) //loop to print the result
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