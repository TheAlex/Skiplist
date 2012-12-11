#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Struct describing an entry. It contains the value,
 * a pointer to the next entry, a pointer to the
 * reference stack ("oneup") and the number of levels
 * of the reference stack ("oneups").
 */
struct entry {
	int value;
	struct entry* next;
	struct oneup* oneup;
	int oneups;
};

/*
 * Struct describing an entry of the reference stack.
 * It contains a pointer to the next entry (the
 * distance to this item is depending on the reference
 * stack level) and a pointer to the next reference
 * stack entry.
 */
struct oneup {
	struct entry* next;
	struct oneup* oneup;
};

void list_print(struct entry* sl);
void list_addvalue(struct entry** sl, int value);
int list_addentry(struct entry** sl, struct entry* newentry);

struct entry* entry_new(int pvalue, struct entry* pnext, struct oneup* poneup);
int entry_compare(struct entry* e1, struct entry* e2);

int calc_oneupcount(int entries_count); 

