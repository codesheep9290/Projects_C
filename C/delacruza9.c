#include <stdio.h>
#include <stdlib.h>

typedef struct node_def node;

struct node_def
{
	int val;
	node *next;
};

node *Top = NULL; 

void push(int x);
int pop();
int top(); 
void printStack();
void toBin(int x); 

int main()
{
	int input = 0; 
	printf("Enter an integer: "); 
	scanf("%d", &input); 
	toBin(input); 

	return 0; 
}

void push(int x)
{
	node *new = malloc(sizeof(node)); 
	new->val = x; 
	new->next = NULL; 

	node *tmp = Top; 
	if (Top == NULL)
	{
		Top = new; 
	}

	else
	{
		while(tmp->next != NULL)
		{
			tmp = tmp->next; 
		}

		tmp->next = new; 
	}
}

int pop()
{
	int data = Top->val; 
	node *tmp = Top; 
	Top = Top->next; 

	free(tmp);

	return data; 
}

int top()
{
	return Top->val; 
}

void printStack()
{
	node *tmp = Top;

	while (tmp != NULL)
	{
		printf("%d ", tmp->val); 
		tmp = tmp->next; 
	} 

	printf("\n");
}

void toBin(int x)
{
	int num = 0; 

	while (x > 0)
	{
		num = x % 2; 
		x = x / 2; 
		push(num); 
	}

	printStack(); 
}

