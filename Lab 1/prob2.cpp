#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

using namespace std;

int sortare(char str1[], char str2[])
{
	char s1[256], s2[256];
	strcpy(s1, str1);
	strcpy(s2, str2);
	for (int i = 0; i < strlen(s1); i++)
		s1[i] = tolower(str1[i]);
	for (int i = 0; i < strlen(s2); i++)
		s2[i] = tolower(s2[i]);

	return strcmp(s1, s2);
}

int main()
{
	char str[256];
	char words[100][256];
	int n = 0;

	scanf("%[^\n]s", str);
	char* p = strtok(str, " ");
	while (p != nullptr)
	{
		strcpy(words[n++], p);
		p = strtok(nullptr, " ");
	}
	bool ok;
	do
	{
		ok = 0;
		for (int i = 0; i < n - 1; i++)
			if (strlen(words[i]) < strlen(words[i + 1]))
			{
				char aux[1000];
				strcpy(aux, words[i]);
				strcpy(words[i], words[i + 1]);
				strcpy(words[i + 1], aux);
				ok = 1;
			}
	} while (ok);
	do
	{
		ok = 0;
		for (int i = 0; i < n - 1; i++)
			if (strlen(words[i]) == strlen(words[i + 1]) && sortare(words[i], words[i + 1]) > 0)
			{
				char aux[1000];
				strcpy(aux, words[i]);
				strcpy(words[i], words[i + 1]);
				strcpy(words[i + 1], aux);
				ok = 1;
			}
	} while (ok);
	for (int i = 0; i < n; i++)
		printf("%s\n", words[i]);
	return 0;
}