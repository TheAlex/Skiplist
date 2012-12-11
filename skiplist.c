#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * This is the struct for a listitem. It contains the value of the item,
 * the pointer to the next listitem, and optionally a pointer to the
 * "reference stack".
 */
struct entry {
	int value;
	struct entry* next;
	struct oneup* oneup;
	int oneups;
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

int oneupcount(int cnt_entries) {

	int result = 0;

	result = (int) ( log10(cnt_entries) / log10(2) );

	return result;
}

int entry_compare(struct entry* e1, struct entry* e2) {

	int result = 0;

	int res = e1->value - e2->value;

	if ( res > 0 ) {
		result = 1;
	} else if ( res < 0 ) {
		result = -1;
	} else {
		result = 0;
	}

	return result;
}

void sl_print(struct entry* sl) {

	printf("------------------\n");
	printf("Printing Skiplist:\n");

	if (sl == NULL) {
		printf("***List not initialized. Nothing to print.\n");
	} else {
		while (sl != NULL) {
			printf("entry: %p, value: %4d, next: %p, oneup: %8p\n", \
				sl, sl->value, sl->next, sl->oneup);
			sl = sl->next;
		}

		printf("List printed.\n");
	}
}

void sl_addentry(struct entry** sl, int value) {

	static int cnt_entries = 0;

	printf("----------------------------\n");
	printf("Adding entry with value %4d\n", value);

	struct entry* tmpentry = malloc(sizeof(struct entry));

	tmpentry->value = value;
	tmpentry->next = NULL;
	tmpentry->oneup = NULL;
	tmpentry->oneups = 0;

	if (*sl == NULL) {
		*sl = tmpentry;
	} else {
		struct entry* iterate = *sl;
		while (iterate->next != NULL) {
			iterate = iterate->next;
		}
		iterate->next = tmpentry;
	}		

	cnt_entries +=1;
	printf("Added entry. Count=%d. Oneupcount=%d\n", cnt_entries, oneupcount(cnt_entries));

}

int main(void) {

	struct entry* skiplist = NULL;

	sl_print(skiplist);

	sl_addentry(&skiplist, 5);
	sl_addentry(&skiplist, 7);
	sl_addentry(&skiplist, 9);
	sl_addentry(&skiplist, 9);
	sl_addentry(&skiplist, 9);
	sl_addentry(&skiplist, 9);
	sl_addentry(&skiplist, 9);
	sl_addentry(&skiplist, 9);
	sl_addentry(&skiplist, 9);
	sl_addentry(&skiplist, 9);
	sl_addentry(&skiplist, 9);
	sl_addentry(&skiplist, 9);
	sl_addentry(&skiplist, 9);
	sl_addentry(&skiplist, 9);
	sl_addentry(&skiplist, 9);

	sl_print(skiplist);

	return 0;
}
