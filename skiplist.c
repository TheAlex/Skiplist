#include <stdio.h>
#include <stdlib.h>

/**
 * This is the struct for the "reference stack". It contains a pointer
 * to the referenced listitem and optionally a pointer to the
 * next entry of the reference stack.
 */
struct skip {
	struct item* item;
	struct skip* skip;
};

/**
 * This is the struct for a listitem. It contains the value of the item,
 * the pointer to the next listitem, and optionally a pointer to the
 * "reference stack".
 */
struct entry {
	int value;
	struct entry* next;
	struct skip* skip;
};

void sl_print(struct entry* sl) {

	printf("------------------\n");
	printf("Printing Skiplist:\n");

	if (sl == NULL) {
		printf("List not initialized. Nothing to print.\n");
	} else {
		while (sl != NULL) {
			printf("Entry: %8x, Value: %4d, Next: %8x, Skip: %8x\n", sl, sl->value, sl->next, sl->skip);
			sl = sl->next;
		}

		printf("List printed.\n");
	}
}

void sl_addentry(struct entry* sl, int value) {

	printf("----------------------------\n");
	printf("Adding entry with value %4d\n", value);

	struct entry* tmpentry = malloc(sizeof(struct entry));

	tmpentry->value = value;
	tmpentry->next = NULL;
	tmpentry->skip = NULL;

	if (sl == NULL) {
		printf("IS NULL\n");
		sl = tmpentry;
		printf("sl=%x\n",sl);
	} else {
		printf("IS NOT NOLL\n");
		while (sl->next != NULL) {
			sl = sl->next;
			sl->next = tmpentry;
		}
	}		

	printf("Added entry.\n");

}

int main(void) {

	struct entry* skiplist = NULL;

	sl_print(skiplist);

	printf("skiplist=%x\n",skiplist);

	sl_addentry(skiplist, 5);

	printf("skiplist=%x\n",skiplist);

	sl_addentry(skiplist, 7);

	printf("skiplist=%x\n",skiplist);

	sl_addentry(skiplist, 9);
	sl_addentry(skiplist, 10);
	sl_addentry(skiplist, 16);
	sl_addentry(skiplist, 44);

	sl_print(skiplist);

}
