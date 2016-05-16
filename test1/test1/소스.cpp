#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;


typedef struct CharFrequency{
	char character;
	int frequency;
	struct CharFrequency * next;
}CharFrequency;


typedef struct HeapTree {
	Tree* left;
	Tree* right;
	CharFrequency data;
}Tree;
typedef Tree * pTree;

typedef CharFrequency * pCharFrequency;

int heapArr[10000];
void pushNode(char* word);
Tree popNode();


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


	// ���Ͽ��� �����͸� �Է¹޾Ƽ� strall�� �ִ´�.
	while (fgets(cstr, sizeof(cstr), inputT) != NULL){
		strcat(strall,cstr);
	}
	strlwr(strall);		//�ҹ��ڷ� ġȯ


	//���ĺ� �ҹ��ڿ� ���� ���๮�ڸ� ������ ���ڸ� smallwords�� �ִ´�.
	for (int i = 0; i<strlen(strall); i++){
		if ((strall[i]>='a'&&strall[i]<='z')||(strall[i]==' '||strall[i]=='\n')){
			temp[0] = strall[i];
			strcat(smallwords,temp);
		}
	}
	
	
	result = strtok(smallwords, " ");
	while (result != NULL){
		cout<<result<<endl;
		result = strtok(NULL, " ");
	}
	

	if (feof(inputT) != 0){
		cout << "���� ��� �Ϸ�";
	}
	
	
	fclose(inputT);

	return 0;
	
}