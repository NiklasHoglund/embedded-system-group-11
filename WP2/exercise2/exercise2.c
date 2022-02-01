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
	REGTYPE* act_post, * head = NULL;
	srand(time(0)); // Random seed
	int rNum = rand() % 10;
	printf("\nRand: %d", rNum);
	head = random_list(rNum);
	act_post = head;
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

// ==== End of main ======================================
REGTYPE* random_list(int nr) {
	int i = 0;
	REGTYPE* top = NULL, * old = NULL, * item = NULL;
	
	for (i = 0; i < nr; i++)
	{
		//create individual node
		old = (REGTYPE*)malloc(sizeof(REGTYPE));
		printf("\nEnter the data for node number %d: ", i + 1);
		scanf_s("%d", &(old->number));
		old->next = NULL;

		if (top == NULL) { //if list is currently empty, then make old as top
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

//==========================================================
REGTYPE* add_first(REGTYPE* temp, int data) {
}