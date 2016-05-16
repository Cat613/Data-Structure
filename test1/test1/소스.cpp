#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

char *replaceAll(char *s, const char *olds, const char *news);

typedef struct CharFrequency{
	char character;
	int frequency;
	struct CharFrequency * next;
}CharFrequency;


typedef struct Tree {
	Tree* left;
	Tree* right;
	CharFrequency data;
}Tree;
typedef Tree * pTree;

typedef struct MinHeap
{
	int elementCount;
	pTree * pData;
}MinHeap;

typedef CharFrequency * pCharFrequency;
typedef MinHeap * pMinHeap;

int main(){

	string *str[100] = {  };
	char cstr[1000];
	char strall[10000]="";
	char smallwords[10000]="";
	char temp[10] = "";
	char* result;

	FILE *inputT = fopen("dataset.txt", "rt");

	if (inputT == NULL){
		puts("file open failed");
		return -1;
	}

	
	/*
	while (fgets(cstr, sizeof(cstr), inputT) != NULL){
		strlwr(cstr);
		cout << cstr;
	}
	*/

	while (fgets(cstr, sizeof(cstr), inputT) != NULL){
		strcat(strall,cstr);
	}

	strlwr(strall);
	
	for (int i = 0; i<strlen(strall); i++){
		
		if ((strall[i]>='a'&&strall[i]<='z')||(strall[i]==' '||strall[i]=='\n')){
			temp[0] = strall[i];
			strcat(smallwords,temp);
		}
		//cout << i << endl;
	}
	
	//cout << smallwords << endl;
	
	
	result = strtok(smallwords, " ");

	while (result != NULL)
	{
		// = result;
		cout<<result<<endl;
		result = strtok(NULL, " ");
	}
	
	
	//cout << *str << endl;

	if (feof(inputT) != 0){
		cout << "파일 출력 완료";
	}

	

	//cin >> *str;
	//cout << *str;

	fclose(inputT);

	return 0;
	
}

char *replaceAll(char *s, const char *olds, const char *news) {
	char *result, *sr;
	size_t i, count = 0;
	size_t oldlen = strlen(olds); if (oldlen < 1) return s;
	size_t newlen = strlen(news);


	if (newlen != oldlen) {
		for (i = 0; s[i] != '\0';) {
			if (memcmp(&s[i], olds, oldlen) == 0) count++, i += oldlen;
			else i++;
		}
	}
	else i = strlen(s);


	result = (char *)malloc(i + 1 + count * (newlen - oldlen));
	if (result == NULL) return NULL;


	sr = result;
	while (*s) {
		if (memcmp(s, olds, oldlen) == 0) {
			memcpy(sr, news, newlen);
			sr += newlen;
			s += oldlen;
		}
		else *sr++ = *s++;
	}
	*sr = '\0';

	return result;
}
