#include <stdio.h>

/**
 * This is the struct for the "reference stack". It contains a pointer
 * to the next referenced listitem and optionally a pointer to the
 * next entry of the reference stack.
 */
struct skip {
	struct item* next;
	struct skip* skip;
}

/**
 * This is the struct for a listitem. It contains the value of the item,
 * the pointer to the next listitem, and optionally a pointer to the
 * "reference stack".
 */
struct item {
	int value;
	struct item* next;
	struct skip* skip;
}

int main(void) {

	/**
	 * Initialize a new sample list
	 * 
	 * objectname:		|  A  |  |  B  |  |  C  |  |  D  |  |  E  |
	 * 			~~~~~~~  ~~~~~~~  ~~~~~~~  ~~~~~~~  ~~~~~~~
	 * value:		|  2  |  |  4  |  |  7  |  |  9  |  | 12  |
	 * struct item* next	| &B  |  | &C  |  | &D  |  | &E  |  |NULL |
 	 * struct skip*, next   | &C  |  |NULL |  | &E  |  |NULL |  |NULL |
	 * struct skip*, skip   | uh  |  |NULL |  |NULL |  |NULL |  |NULL |
	 *
	 * Inhalt struct "uh": next = &E, skip = NULL
	 *
	 */


	struct item mylist = NULL;

	// idead: storing the "reference stack" in an array.
	// would be easier to handle instead of a linked list.

	// but not today.

	



}
