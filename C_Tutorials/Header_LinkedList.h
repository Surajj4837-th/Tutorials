#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define POINTER_TO_POINTER			0

struct node
{
	int data;
	struct node *next;
};

#if POINTER_TO_POINTER
void addNodeToEnd(struct node *head, int data);
#else
struct node* addNodeToEnd(struct node *head, int data);
#endif

void printLinkedList(struct node *head);
void insertInBeginning(struct node **head);
void insertAtEnd(struct node *head);
int countNodes(struct node *head);
void insertAtLoc(struct node **head, int No_Of_Nodes);
void DeleteByLocation(struct node **head);
void DeleteByValue(struct node **head);
void ReveseList(struct node** head);
