#include <stdio.h>
#include <stdlib.h>
//#include "skiplist.h"

/**
 * This is the struct for a listitem. It contains the value of the item,
 * the pointer to the next listitem, and optionally a pointer to the
 * "reference stack".
 */
struct entry {
	int value;
	struct entry* next;
	struct oneup* oneup;
};

/**
 * This is the struct for the "reference stack". It contains a pointer
 * to the referenced listitem and optionally a pointer to the
 * next entry of the reference stack.
 */
struct oneup {
	struct entry* entry;
	struct oneup* oneup;
};


void sl_print(struct entry* sl) {

	printf("------------------\n");
	printf("Printing Skiplist:\n");

	if (sl == NULL) {
		printf("***List not initialized. Nothing to print.\n");
	} else {
		while (sl != NULL) {
			printf("entry: %8x, value: %4d, next: %8x, oneup: %8x\n", sl, sl->value, sl->next, sl->oneup);
			sl = sl->next;
		}

		printf("List printed.\n");
	}
}

void sl_addentry(struct entry** sl, int value) {

	printf("----------------------------\n");
	printf("Adding entry with value %4d\n", value);

	struct entry* tmpentry = malloc(sizeof(struct entry));

	tmpentry->value = value;
	tmpentry->next = NULL;
	tmpentry->oneup = NULL;

	if (*sl == NULL) {
		*sl = tmpentry;
	} else {
		struct entry* iterate = *sl;
		while (iterate->next != NULL) {
			iterate = iterate->next;
		}
		iterate->next = tmpentry;
	}		

	printf("Added entry.\n");

}

int main(void) {

	struct entry* skiplist = NULL;

	sl_print(skiplist);
	
	sl_addentry(&skiplist, 5);
	sl_addentry(&skiplist, 7);
	sl_addentry(&skiplist, 9);

	sl_print(skiplist);

}
