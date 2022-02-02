#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#### Constants #####
#define MAX 5

// ##### typedefs ####
typedef struct q { // Typedef = define the structure as 'REGTYPE'
	int number;
	struct q* next; // Points to the next node
	struct q* prev; // Points to the previous node
} REGTYPE;

// ##### Function declarations #####
REGTYPE* random_list(int nr);
REGTYPE* add_first(REGTYPE* temp, int data);

//###### Main program #######
int main(int argc, char* argv[])
{
	int nr = 0;
	REGTYPE* act_post, * head = NULL, * firstNode = NULL;

	srand(time(0)); // Random seed
	head = random_list(MAX);
	act_post = head;

	add_first(head, 1337);

	while (act_post != NULL) {
		printf("\n Post nr %d : %d", nr++, act_post->number);
		act_post = act_post->next;
	}


	// --- Free the allocated memory ---
	while ((act_post = head) != NULL) {
		head = act_post->next;
		free(act_post);
	}

	return 0;
}

// Friendly Indian guy helped us: https://www.youtube.com/watch?v=7Fz7JSvlr9g&ab_channel=BBarters
// ==== End of main ======================================
REGTYPE* random_list(int nr) {
	int i = 0;
	REGTYPE* top = NULL, * old = NULL, * item = NULL;
	

	for (i = 0; i < nr; i++)
	{
		int rNum = rand() % 100;
		//create individual node
		old = (REGTYPE*)malloc(sizeof(REGTYPE));
		old->number = rNum;
		old->next = NULL;
		
		if (top == NULL) { //if top is empty -> make old as top
			top = old;
		}
		else
		{
			item = top;
			while (item->next != NULL) {
				item = item->next;
			}
			item->next = old;
		}
	}

	return(top);
}

// Source: my big brain
//==========================================================
REGTYPE* add_first(REGTYPE* temp, int data) {
	
	REGTYPE* node = (REGTYPE*)malloc(sizeof(REGTYPE));;

	temp->number = data;
	node->next = temp;	return(node);}