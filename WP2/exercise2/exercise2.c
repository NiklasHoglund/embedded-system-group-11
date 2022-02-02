#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#### Constants #####
#define MAX 5

// ##### typedefs ####
typedef struct q { // Typedef = define the structure as 'REGTYPE'
	int number; // Number data
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
	REGTYPE* act_post, * head = NULL, * firstNode = NULL; // Define REGTYPE objects

	srand(time(0)); // Seed rand to time
	head = random_list(MAX); // Call random_list with the value MAX and set the return value to head
	act_post = head;

	add_first(head, 1337); // Call add_first with the return value of random_list (head) and 1337

	while (act_post != NULL) { // Checks whether there is a node to print
		printf("\n Post nr %d : %d", nr++, act_post->number); // Print nodes
		act_post = act_post->next; // Set node to next node
	}

	// --- Free the allocated memory ---
	while ((act_post = head) != NULL) {
		head = act_post->next;
		free(act_post);
	}

	return 0;
}
// ==== End of main ======================================

// Understood it from: https://www.youtube.com/watch?v=7Fz7JSvlr9g&ab_channel=BBarters
REGTYPE* random_list(int nr) {
	int i = 0; // Iterator for the for loop
	REGTYPE* top = NULL, * old = NULL, * item = NULL; // Defines three nodes (REGTYPE objects)
	

	for (i = 0; i < nr; i++) // For loop which loops once for each node in the linked list
	{
		int rNum = rand() % 100; // Randomizes a value to give the number variable in each node
		
		// ========= Create an isolated node =========
		old = (REGTYPE*)malloc(sizeof(REGTYPE)); // Create a node
		old->number = rNum; // Store the randomized value
		old->next = NULL; // The new node shouldn't have any nodes following it (since its isolated)
		// ===========================================
		
		if (top == NULL) { // If the linked list is empty
			top = old; // Top becomes the newly created node (old)
		}
		else
		{ // Else, the loop has run a few times (the linked list is not empty)
			item = top;
			while (item->next != NULL) { // Iterates to the last node in the linked list
				item = item->next;
			}
			item->next = old; // Sets the last node to the newly created node
		}
	}

	return(top); // Returns the head of the linked list
}

//==========================================================
REGTYPE* add_first(REGTYPE* temp, int data) {
	
	REGTYPE* node = (REGTYPE*)malloc(sizeof(REGTYPE)); // Create a node
	temp->number = data; // Set the value of the node passed into the function to the data variable passed
	node->next = temp; // Set the node following (node) to the node passed	return(node); // Returns the new node}