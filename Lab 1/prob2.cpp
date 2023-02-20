#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

using namespace std;

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
			if (strlen(words[i]) == strlen(words[i + 1]) && strcmp(words[i], words[i + 1]) > 0)
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