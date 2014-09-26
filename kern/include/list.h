#ifndef _LIST_H_
#define _LIST_H_

/*
 * Singly-linked list of void pointers.
 *
 * Functions:
 *      list_create     - Allocates and returns a new list object.
 *                        Returns NULL on error.
 *      list_push_back  - Append a new element to the back of the list.
 *      list_pop_front  - Removes the next element from the front of the list
 *      list_front      - Returns the next element from the front of the list.
 *                        Does not remove the element from the list.
 *                        Returns NULL if the list is empty.
 *      list_isempty    - Returns whether the list is empty or not.
 *      list_getsize    - Returns the number of elements in the list.
 *      list_destroy    - Destroys the list: frees internal data structures.
 *                        frees the list object.
 *                        DOES NOT free any elements contained in the list.
 *                        To avoid memory leak, please free all the elements
 *                        in the list.
 */

struct list;  /* Opaque. */

struct list* list_create(void);
void list_push_back(struct list* lst, void* newval);
void list_pop_front(struct list* lst);
void* list_front(struct list* lst);
int list_isempty(struct list* lst);
unsigned int list_getsize(struct list* lst);
void list_destroy(struct list* lst);

#endif /* _LIST_H_ */
