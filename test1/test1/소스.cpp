#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;


typedef struct CharFrequency {
	char* character;
	int frequency;
	struct CharFrequency * next;
}CharFrequency;


typedef struct HeapTree {
	int index;
	Tree* left;
	Tree* right;
	CharFrequency data;
}Tree;
typedef Tree * pTree;

typedef CharFrequency * pCharFrequency;

Tree heapArr[10000] = { 0 };
int tailIndex = 0;
Tree* root = NULL;
int* detectdirection(int index);
void pushNode(char* word);
Tree popNode();


int main() {

	string *str[100] = {};
	char cstr[1000];
	char strall[10000] = "";
	char smallwords[10000] = "";
	char temp[10] = "";
	char* result;

	FILE *inputT = fopen("dataset.txt", "rt");

	if (inputT == NULL) {
		puts("file open failed");
		return -1;
	}

	// ���Ͽ��� �����͸� �Է¹޾Ƽ� strall�� �ִ´�.
	while (fgets(cstr, sizeof(cstr), inputT) != NULL) {
		strcat(strall, cstr);
	}
	strlwr(strall);		//�ҹ��ڷ� ġȯ


						//���ĺ� �ҹ��ڿ� ���� ���๮�ڸ� ������ ���ڸ� smallwords�� �ִ´�.
	for (int i = 0; i<strlen(strall); i++) {
		if ((strall[i] >= 'a'&&strall[i] <= 'z') || (strall[i] == ' ' || strall[i] == '\n')) {
			temp[0] = strall[i];
			strcat(smallwords, temp);
		}
	}


	result = strtok(smallwords, " ");
	while (result != NULL) {
		cout << result << endl;
		result = strtok(NULL, " ");
	}


	if (feof(inputT) != 0) {
		cout << "���� ��� �Ϸ�";
	}


	fclose(inputT);







	return 0;

}



int * detectdirection(int index) {
	int temp[20], level[20];
	int i;
	for (i = 0; index>1; i++)
	{
		temp[i] = index % 2;
	}
	return nullptr;
}

void pushNode(char * word) {
	if (root == NULL) {
		root->data.character = word;
		root->index = 1;
		heapArr[1] = *root;
		tailIndex++;
	}
	else {

	}
}
