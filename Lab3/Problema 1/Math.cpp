#include "Math.h"
#include <iostream>
#include <stdarg.h>
#include <cstring>
#include <string>
#define _CRT_SECURE_NO_WARNINGS
int Math::Add(int x1, int x2)
{
    return x1 + x2;
}
int Math::Add(int x1, int x2, int x3)
{
    return x1 + x2 + x3;
}
double Math::Add(double x1, double x2)
{
    return x1 + x2;
}
double Math::Add(double x1, double x2, double x3)
{
    return x1 + x2 + x3;
}
int Math::Mul(int x1, int x2)
{
    return x1 * x2;
}
int Math::Mul(int x1, int x2, int x3)
{
    return x1 * x2 * x3;
}
double Math::Mul(double x1, double x2)
{
    return x1 * x2;
}
double Math::Mul(double x1, double x2, double x3)
{
    return x1 * x2 * x3;
}

int Math::Add(int count, ...)
{
    int val = 0;
    va_list ap;
    int i;

    va_start(ap, count);
    for (i = 0; i < count; i++)
        val += va_arg(ap, int);
    va_end(ap);

    return val;
}

char* Math::Add(const char* p1, const char* p2)
{
    if (p1 == nullptr || p2 == nullptr)
        return nullptr;
    int l1 = strlen(p1);
    int l2 = strlen(p2);
    char* n1, * n2, * rez;
    if (l1 < l2) {
        rez = (char*)malloc(sizeof(char) * (l2 + 1));
        n1 = (char*)malloc(sizeof(char) * l2);
        n2 = (char*)malloc(sizeof(char) * l2);
        memset(rez, '0', l2 + 1);
        memcpy(n1, p1, l2);
        memcpy(n2, p2, l2);
    }
    else
    {
        rez = (char*)malloc(sizeof(char) * (l1 + 1));
        n1 = (char*)malloc(sizeof(char) * l1);
        n2 = (char*)malloc(sizeof(char) * l1);
        memset(rez, '0', l1 + 1);
        memcpy(n1, p1, l1);
        memcpy(n2, p2, l1);
    }


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

    {
        char aux = rez[i];
        rez[i] = rez[nr_cifre - i - 1];
        rez[nr_cifre - i - 1] = aux;
    }
    return rez;

}