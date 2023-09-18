#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

FILE* Openresource();
FILE* CreatAllKeywordsListTXT();
char* FindKeyword(FILE*);


int main()
{
	FILE* resource =Openresource();
	FILE* target = CreatAllKeywordsListTXT();
	char** Keywords[26];
	FindKeyword(resource);
	fclose(target);
	fclose(resource);
	return 0;
}

FILE* Openresource()
{
	FILE* f;
	if ((f = fopen("resource.txt", "rt")) == NULL)
	{
		printf("Can't open the resource file.");
		exit(0);
	}
	else
	{
		printf("Resource file opens successfully.\n");
		Sleep(500);
		return f;
	}
}

FILE* CreatAllKeywordsListTXT()
{
	FILE* f;
	if ((f = fopen("KeywordsList.txt", "at+")) == NULL)
	{
		printf("Can't open the keywords file.");
		exit(0);
	}
	else
	{
		printf("Keywords file opens successfully.\n");
		Sleep(500);
		return f;
	}
}

char* FindKeyword(FILE* fp)
{
	char ch;
	char* keyword = (char*)malloc(100);
	char* singleword= (char*)malloc(30);
	char* singlewordhead = singleword;
	*keyword = '\0';
	while ((ch = fgetc(fp)) != EOF)
	{
		if (ch <= 90 && ch >= 65)
		{
			while ((ch<=90 && ch>=65)||(ch<=122 && ch>=97)||ch==45 )
			{
				*singleword = ch;
 				singleword++;
				ch = fgetc(fp);
			}
			*singleword = '\0';
			singleword = singlewordhead;
			printf("%s\n", singleword);
		}
		
	}
	free(singlewordhead);
	return keyword;
}