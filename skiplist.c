#include "skiplist.h"

int main(void) {

	struct entry* skiplist = NULL;

	list_print(skiplist);

	list_addvalue(&skiplist, 5);
	list_addvalue(&skiplist, 7);
	list_addvalue(&skiplist, 9);
	list_addvalue(&skiplist, 12);
	list_addvalue(&skiplist, 20);
	list_addvalue(&skiplist, 23);
	list_addvalue(&skiplist, 27);
	list_addvalue(&skiplist, 30);
	list_addvalue(&skiplist, 35);
	list_addvalue(&skiplist, 42);
	list_addvalue(&skiplist, 47);
	list_addvalue(&skiplist, 51);
	list_addvalue(&skiplist, 54);
	list_addvalue(&skiplist, 60);
	list_addvalue(&skiplist, 64);

	list_print(skiplist);

	return 0;
}

void list_print(struct entry* sl) {

	printf("------------------\n");
	printf("Printing Skiplist:\n");

	if (sl == NULL) {
		printf("*info* List not initialized. Nothing to print.\n");
	} else {
		while (sl != NULL) {
			printf("entry: %9p, value: %4d, next: %9p, oneup: %9p\n", \
				sl, sl->value, sl->next, sl->oneup);
			sl = sl->next;
		}

		printf("List printed.\n");
	}
}

struct entry* entry_new(int pvalue, struct entry* pnext, struct oneup* poneup) {

	struct entry* e = malloc(sizeof(struct entry));

	e->value = pvalue;
	e->next = pnext;
	e->oneup = poneup;
	e->oneups = 0;

	return e;
}

int list_addentry(struct entry** sl, struct entry* newentry) {

	return 0;
}

void list_addvalue(struct entry** sl, int value) {

	static int entries_count = 0;

	printf("----------------------------\n");
	printf("Adding entry with value %4d\n", value);

	struct entry* newentry = entry_new(value, NULL, NULL);

	if (*sl == NULL) {
		*sl = newentry;
	} else {
		struct entry* iterate = *sl;
		while (iterate->next != NULL) {
			iterate = iterate->next;
		}
		iterate->next = newentry;
	}		

	entries_count +=1;

	printf("Added entry. Count=%d. Oneupcount=%d\n", entries_count, calc_oneupcount(entries_count));

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

int calc_oneupcount(int entries_count) {

	int result = 0;

	result = (int) ( log10(entries_count) / log10(2) );

	return result;
}
