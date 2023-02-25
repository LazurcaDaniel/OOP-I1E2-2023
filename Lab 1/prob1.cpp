#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
void add_big_numbers(char s1[], char s2[], char rez[])
{
    char n1[100], n2[100];
    strcpy(n1, s1);
    strcpy(n2, s2);
    int l1 = strlen(n1);
    int l2 = strlen(n2);
    int nr_cifre = 0;
    int carry = 0;
    if (l1 < l2)
    {
        for (int i = l2 - 1; i >= l2 - l1; i--)
            n1[i] = n1[i - (l2 - l1)];
        for (int i = 0; i < l2 - l1; i++)
            n1[i] = '0';
        l1 = l2;
        n1[l1] = '\0';
    }
    else if (l2 < l1)
    {
        for (int i = l1 - 1; i >= l1 - l2; i--)
            n2[i] = n2[i - (l1 - l2)];
        for (int i = 0; i < l1 - l2; i++)
            n2[i] = '0';
        l2 = l1;
        n2[l2] = '\0';
    }
    while (l1 > 0 && l2 > 0)
    {
        int nr = (n1[l1 - 1] - '0') + (n2[l2 - 1] - '0') + carry;
        rez[nr_cifre] = (nr % 10) + '0';
        carry = nr / 10;
        nr_cifre++;
        l1--;
        l2--;
    }
    if (carry)
        rez[nr_cifre++] = '1';
    rez[nr_cifre] = '\0';
    for (int i = 0; i < nr_cifre / 2; i++)
        swap(rez[i], rez[nr_cifre - i - 1]);

}
int main()
{
    FILE* fp;
    if (fopen_s(&fp, "ini.txt", "r") != 0)
    {
        printf("Eroare. Nu am putut deschide fisierul\n");
    }
    else
    {

        char s1[100], s2[100], buffer[1];
        fgets(s1, 100, fp);
        strcpy(s1 + strlen(s1) - 1, s1 + strlen(s1));
        while (fgets(s2, 100, fp) != nullptr)
        {
            char rez[100];
            strcpy(s2 + strlen(s2) - 1, s2 + strlen(s2));
            add_big_numbers(s1, s2, rez);
            //cout << rez << '\n' << '\n';
            strcpy(s1, rez);
        }
        printf("Suma numerelor este: %s", s1);
    }
    return 0;
}