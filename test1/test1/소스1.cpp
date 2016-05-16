#include <stdio.h>
#include <malloc.h>

#define NUM_OF_ALPHABET 26
#define MAX_HEAP_SIZE 100

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


pCharFrequency initList();
void addNode(pCharFrequency pHead, char ch);
pCharFrequency FindContainNode(pCharFrequency pHead, char ch);

//Heap Predefine
pMinHeap createMinHeap();
void insertMinHeap(pMinHeap pHeap, pTree pHead_Tree);
pTree deleteMinHeap(pMinHeap pHeap);

//Tree Pre-difine
pTree MakeTree(pTree left, pTree right);
pTree createHuffmanTree(pCharFrequency pHead_CharFrequency, pMinHeap pHead_MinHeap);
void PrintTree(pTree tree, int i, char *pCode);

int main()
{
	//File Read
	FILE *f;
	if (fopen_s(&f, "Text.txt", "r"))
	{
		printf("File can't open!");
		return -1;
	}
	//Init CharFrequency Linked List
	pCharFrequency head_CharFrequency = initList();

	int index = 'a';
	while (!feof(f)) {
		/* write here */

	}
	fclose(f);

	pMinHeap pHead_Heap = createMinHeap();

	pCharFrequency ptr;

	for (ptr = head_CharFrequency->next; ptr->next; ptr = ptr->next)
	{
		/* write here */
	}



	pTree huffman_tree = createHuffmanTree(head_CharFrequency, pHead_Heap);

	char binCode[300];
	PrintTree(huffman_tree, -1, binCode);

}


//========================================================================//
//Alphabet//
pCharFrequency initList()
{
	/* write here */
}
void addNode(pCharFrequency pHead, char ch)
{
	/* write here */
}
//if ch contains in CharFrequyency list, then return true, else false.
pCharFrequency FindContainNode(pCharFrequency pHead, char ch)
{
	/* write here */
}


//========================================================================//
//Priority Queue
pMinHeap createMinHeap()
{
	/* write here */
}
void insertMinHeap(pMinHeap pHeap, pTree pHead_Tree)
{
	/* write here */
}
pTree deleteMinHeap(pMinHeap pHeap) {
	/* write here */


}

//========================================================================//
//Huffman Tree
pTree createHuffmanTree(pCharFrequency pHead_CharFrequency, pMinHeap pHead_MinHeap)
{

	/* write here */
}
//HuffmanTree doesn't have only one child.
pTree MakeTree(pTree left, pTree right)
{
	/* write here */
}

void PrintTree(pTree tree, int i, char *pCode)
{
	/* write here */
}
