#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include "trie.h"
#include <stdlib.h>
#define SIZE_WORD 2
 #define ALPHABET_SIZE 26
#define CASE 'a'

Node *newNode() //initialize a new node in graph
{
	Node *p = (Node *)malloc(sizeof(Node));
	if(p==NULL)
	{
		printf("error\n");
		exit(0);
	}
	p->parent = NULL; //previous letter
	p->occurrences = 0; //number of occurrences in graph 
	for (int i = 0; i < ALPHABET_SIZE; i++) //gets rid of garbage
	{
		p->children[i] = NULL;
	}

	return p;
}


void printPreOrder(Node *node, char s[], int index)
{
	if (node->occurrences > 0) //end of word
	{
		s[index]='\0';
		printf("%s\t%d\n", s, node->occurrences);
	}
	
	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		if (node->children[i] != NULL) //theres another letter following
		{
			s[index] = i + CASE;			
			index++;		
			printPreOrder(node->children[i], s,  index); //recursive call with updated array and next index
			index--; 		                             
		}		
	} 			
}  

void printReverse(Node *node, char s[], int index)
{
	if (node->occurrences > 0) //end of word
	{
		s[index]='\0';
		printf("%s\t%d\n", s, node->occurrences);
	}

	for (int i = ALPHABET_SIZE-1; i >= 0; i--)
	{
		if (node->children[i] != NULL)  //theres another letter following
		{
			s[index] = i + CASE; //adds next letter to array
			index++;
			printReverse(node->children[i], s, index); //recursive call with updated array and next index
			index--; 
		} 
	}
}

void freeNode(Node *trieTree) //free each letter on the tree
{
	Node *currentNode = trieTree;

	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		if (currentNode->children[i] != NULL)
		{
			freeNode(currentNode->children[i]);
		}
	}
	free(currentNode);
}

void insertNode(Node *trieNode, char l[]) //add letters to tree
{
	if (*l != '\0' && *l != ' ' && *l != '\t' && *l != '\n'){
	Node *currentNode = trieNode;
    
	while (*l != '\0' && *l != ' ' && *l != '\t' && *l != '\n')
	{

		if (currentNode->children[*l - CASE] == NULL)
		{
			currentNode->children[*l - CASE] = newNode();
			currentNode->children[*l - CASE]->parent = currentNode;
		}
		currentNode = currentNode->children[*l - CASE];
		l++;
	}
	currentNode->occurrences++;
}
}

