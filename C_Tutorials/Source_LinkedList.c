#include "Header_LinkedList.h"

void main()
{
	struct node *head = NULL;

	int No_of_input = 0, input_data = 0, counter = 0, choice = 0, No_Of_Nodes = 0;

	printf("How many inputs?\n");
	scanf("%d", &No_of_input);

	printf("Provide data:\n");
	for(counter = 0; counter < No_of_input; counter++)
	{
		scanf(" %d", &input_data);

#if POINTER_TO_POINTER
		addNodeToEnd(&head, input_data);
#else
		head = addNodeToEnd(head, input_data);
#endif

	}

	while(1)
	{
		printf("Select options:\n");
		printf("1. Print Linked List\n");
		printf("2. Insert value at beginning of list.\n");
		printf("3. Insert value at end of list.\n");
		printf("4. Insert value at location.\n");
		printf("5. Delete a node by location.\n");
		printf("6. Delete a node by value.\n");
		printf("7. Reverse a linked list.\n");
		printf("8. Exit.\n");

		scanf("%d", &choice);

		switch(choice)
		{
		case 1:
			printLinkedList(&head);
			break;

		case 2:
			insertInBeginning(&head);
			break;

		case 3:
			insertAtEnd(head);
			break;

		case 4:
			No_Of_Nodes = countNodes(head);
			insertAtLoc(&head, No_Of_Nodes);
			break;

		case 5: 
			DeleteByLocation(&head);
			break;

		case 6:
			DeleteByValue(&head);
			break;

		case 7:
			ReveseList(&head);
			break;

		case 8:
			exit(0);
		}

	}

}


#if POINTER_TO_POINTER
//As the head itself will change its value so its address needs to be passed.
//So a ** is used. Another way is to return a pointer to the modified linked list.
void addNodeToEnd(struct node **head, int data)
{
	struct node *newNode = (struct node*) malloc(sizeof(struct node));
	struct node *tmpNode = *head;

	newNode->data = data;
	newNode->next = NULL;

	if(*head == NULL)
	{
		*head = newNode;
	}
	else
	{
		while(tmpNode->next != NULL) 
		{ 
			tmpNode = tmpNode->next;
		}

		tmpNode->next = newNode;
	}
}
#else
struct node* addNodeToEnd(struct node *head, int data)
{
	struct node *newNode = (struct node*) malloc(sizeof(struct node));
	struct node *tmpNode = head;

	newNode->data = data;
	newNode->next = NULL;

	if(head == NULL)
	{
		return newNode;
	}
	else
	{
		while(tmpNode->next != NULL) 
		{ 
			tmpNode = tmpNode->next;
		}

		tmpNode->next = newNode;
	}

	return head;
}

#endif

//Print till adress is NULL
void printLinkedList(struct node **head)
{
	struct node * tempNode = *head;

	while(tempNode != NULL)
	{
		printf("%d->", tempNode->data);
		tempNode = tempNode->next;
	}
	printf("END\n");
}

//Replace the head
void insertInBeginning(struct node **head)
{
	int data;
	struct node* newNode = (struct node*) malloc(sizeof(struct node));

	printf("Provide data:\n");
	scanf("%d", &data);

	newNode->next = *head;
	newNode->data = data;

	*head = newNode;

}

//Find the last node and add append a node to it.
void insertAtEnd(struct node *head)
{
	int data;
	struct node* tmpNode;
	struct node* newNode = (struct node*) malloc(sizeof(struct node));

	printf("Provide data:\n");
	scanf("%d", &data);

	tmpNode = head;

	while(tmpNode->next != NULL)
	{
		tmpNode = tmpNode->next;
	}

	newNode->data = data;
	newNode->next = NULL;

	tmpNode->next = newNode;
}

//Count node till NULL is encountered
int countNodes(struct node *head)
{
	int count = 0;

	struct node* tmpNode;

	tmpNode = head;

	while(tmpNode != NULL)
	{
		tmpNode = tmpNode->next;
		count++;
	}

	return count;

}


void insertAtLoc(struct node **head, int No_Of_Nodes)
{
	int data, location;
	int counter = 0;
	struct node* tmpNode;
	struct node* newNode = (struct node*) malloc(sizeof(struct node));

	printf("Provide location:\n");
	scanf("%d", &location);

	if (location > No_Of_Nodes)
	{
		printf("List has %d number of nodes. Provide valid location.", No_Of_Nodes);
		return;
	}

	if(location == 1)
	{
		insertInBeginning(head);
	}
	else if(location == No_Of_Nodes)
	{
		insertAtEnd(*head);
	}
	else
	{
		printf("Provide data:\n");
		scanf("%d", &data);

		tmpNode = *head;

		while(tmpNode != NULL && counter < (location - 2))
		{
			tmpNode = tmpNode->next;
			counter++;
		}

		newNode->data = data;
		newNode->next = tmpNode->next;
		tmpNode->next = newNode;

	}

}

void DeleteByLocation(struct node **head)
{
	int data = 0;
	int location = 0;
	int counter = 0;
	struct node *tmpNode;
	int No_Of_Nodes = countNodes(*head);

	printf("List has %d number of nodes.\nProvide location of node to be deleted:\n", No_Of_Nodes);
	scanf("%d", &location);

	if (location > No_Of_Nodes)
	{
		printf("List has %d number of nodes. Provided location is not valid.\n", No_Of_Nodes, location);
		return;
	}

	if (location == 1)
	{
		*head = (*head)->next;
	}
	else if (location == No_Of_Nodes)
	{
		tmpNode = *head;

		while(tmpNode->next->next != NULL)
		{
			tmpNode = tmpNode->next;
		}
		tmpNode->next = NULL;

	}
	else
	{
		tmpNode = *head;

		while(tmpNode != NULL && counter < (location - 2))
		{
			tmpNode = tmpNode->next;
			counter++;
		}

		tmpNode->next = tmpNode->next->next;

	}

}


void DeleteByValue(struct node **head)
{
	int data = 0;
	struct node* tmpNode;

	printf("Provide data to be deleted:\n");
	scanf("%d", &data);

	if((*head)->data == data && (*head)->next == NULL)
	{
		(*head)->next = NULL;
	}
	else if((*head)->data == data)
	{
		(*head) = (*head)->next;
	}
	else
	{
		tmpNode = *head;

		while(tmpNode->next != NULL && tmpNode->next->data != data)
		{
			tmpNode = tmpNode->next;
		}

		if (tmpNode->next == NULL)
		{
			printf("Data not found. Provide valid data.\n");
			return;
		}
		else
		{
			tmpNode->next = tmpNode->next->next;
		}
	}

}


void ReveseList(struct node** head)
{
	struct node *prevNode, *nextNode, *currNode;

	prevNode = NULL;
	currNode = (*head);
	nextNode = (*head);

	while(nextNode != NULL)
	{
		nextNode = currNode->next;
		currNode->next = prevNode;
		prevNode = currNode;
		currNode = nextNode;
	}

	(*head) = prevNode;

}


/***************************************************************************************************************************

***************************************************************************************************************************/