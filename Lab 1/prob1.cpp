#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main() 
{
    FILE* fp;
    long suma = 0;
    if (fopen_s(&fp, "in.txt", "r") != 0)
    {
        printf("Eroare. Nu am putut deschide fisierul\n");
    }
    else
    {
        char s[100];
        while (fgets(s, 100, fp) != NULL)
        {
            int x = 0;
            printf("%s\n", s);
            for (int i = 0; i < strlen(s); i++)
            {
                if (s[i] != '\0')
                    x = x * 10 + (s[i] - '0');
            }
            suma += x;
        }
        printf("Suma numerelor este: %d", suma);
    }
    return 0;
}