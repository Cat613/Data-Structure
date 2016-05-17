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


typedef struct Tree {
	int index;
	Tree* left;
	Tree* right;
	CharFrequency data;
}Tree;
typedef Tree * pTree;

typedef CharFrequency * pCharFrequency;

Tree heapArr[10000] = { 0 };
int direction[20];
int tail_Index = 0;
int directionIndex = 0;
Tree* root = NULL;
void detectdirection(int* level, int index);
void pushNode(pTree heap, char* word);
Tree popNode(pTree heap);
pTree searchNode(pTree heap, int index);
void setArray(int* arr);


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

	// 파일에서 데이터를 입력받아서 strall에 넣는다.
	while (fgets(cstr, sizeof(cstr), inputT) != NULL) {
		strcat(strall, cstr);
	}
	strlwr(strall);		//소문자로 치환


						//알파벳 소문자와 띄어쓰기 간행문자를 제외한 문자를 smallwords에 넣는다.
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
		cout << "파일 출력 완료";
	}


	fclose(inputT);

	return 0;

}



void detectdirection(int* level, int index) {
	int temp[20];
	int i, j;
	for (i = 0; index>1; i++)
	{
		temp[i] = index % 2;
		index /= 2;
	}
	for (j = 0; j < sizeof(temp) / 4; j++)
	{
		level[j] = temp[i - 1 - j];
	}
}

void pushNode(pTree heap, char * word) {
	pTree parent, newNode;
	if (root == NULL) {
		root->data.character = word;
		root->index = 1;
		heapArr[1] = *root;
		tail_Index++;
	}
	else {
		setArray(direction);
		//detectdirection(direction, tail_Index);

		parent = searchNode(heap, (++tail_Index)/2);
		if (parent->left == NULL){ newNode = parent->left; }
		else{ newNode = parent->right; }
	}
	






}

Tree popNode(pTree heap){
	pTree minheap;
	minheap = heap;


	heap->data.character = ;

}

pTree searchNode(pTree heap, int index){
	detectdirection(direction, index);
	if (direction[directionIndex]==-1 && heap->index == index){
		return heap;
	}
	if (direction[directionIndex] == 0){
		directionIndex++;
		searchNode(heap->left, index);
	}
	else{
		directionIndex++;
		searchNode(heap->right, index);
	}
	
}

void setArray(int* arr){
	for (int i = 0; i < sizeof(arr)/4; i++)
	{
		arr[i] = -1;
	}
}