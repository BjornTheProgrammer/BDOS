/*
kernel.c manages the proccess and the safty of those proccess
i.e. prevent crashing of entire system from process accessing wrong memory or null.
*/

#include "pico/stdlib.h"
#include <stdio.h>
#include "kernel.h"
#include "malloc.h"
#include <string.h>

// Creation of linked list
typedef struct __task {
	void 			(*function_pointer)(void);
	int 			priority;
	uint8_t			process_id;
	struct __task*	next;
} __task;

__task* __head = NULL;

uint8_t __task_list_size;

void kernel_initalize() {
	// stdio_init_all();
	printf("Kernel: Kernal being initaized.\n");
}

void kernel_start() {
	// stdio_init_all();
	printf("Kernel: Kernal starting.\n");
	while (1) {
		// statement
	}
}

// returns task id.
uint8_t kernel_create_process(void (*pointer_to_task_function)(void), int priority) {
	printf("Kernel: Creating a kernel process.\n");

	//create a new node
	__task *new_node = malloc(sizeof(__task));
	new_node->function_pointer = pointer_to_task_function;
	new_node->priority = priority;
	new_node->process_id = 0;
	new_node->next = NULL;

	//if head is NULL, it is an empty list
	//Otherwise, find the last node and add the new_node
	if(__head == NULL) {
		__head = new_node;
	} else {
		__task *last_node = __head;

		//last node's next address will be NULL.
		while(last_node->next != NULL) {
			last_node = last_node->next;
		}

		//add the new_node at the end of the linked list
		last_node->next = new_node;
	}
	
}

void list_all_tasks() {
	printf("Within list_all_tasks \n");

	/* Print all the elements in the linked list */
	__task *current_node = __head;
	while ( current_node != NULL) {
		printf("priority: %i \n", current_node->priority);
		current_node = current_node->next;
	}
}

bool kernel_kill_process_by_pointer(void (*pointer_to_task_function)(void)) {
	return true;
}

bool kernel_kill_process_by_id(uint8_t task_id) {
	return true;
}