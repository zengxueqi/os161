#include <queue.h>
#include <types.h>
#include <lib.h>
#include <test.h>

#define TESTSIZE 133

int
queuetest(int nargs, char **args)
{
    (void)nargs;
    (void)args;

    kprintf("Beginning queue test...\n");

    struct queue* newqueue;
    newqueue = queue_create();
    KASSERT(newqueue != NULL);
    KASSERT(queue_getsize(newqueue) == 0);
    KASSERT(queue_isempty(newqueue));

    int i;
    int* elem;
    /* push back TESTSIZE number of elements */
    for (i = 0; i < TESTSIZE; ++i) {
        elem = (int*)kmalloc(sizeof(int));
        *elem = i;
        queue_push(newqueue, (void*) elem);
    }
    KASSERT(queue_getsize(newqueue) == TESTSIZE);
    KASSERT(!queue_isempty(newqueue));

    /* pop front TESTSIZE number of elements */
    for (i = 0; i < TESTSIZE; ++i) {
        elem = (int*)queue_front(newqueue);
        KASSERT(*elem == i);
        queue_pop(newqueue);
        kfree(elem);
    }
    KASSERT(queue_getsize(newqueue) == 0);
    KASSERT(queue_isempty(newqueue));

    /* push back TESTSIZE number of elements */
    for (i = 0; i < TESTSIZE; ++i) {
        elem = (int*)kmalloc(sizeof(int));
        *elem = i;
        queue_push(newqueue, (void*) elem);
    }
    KASSERT(queue_getsize(newqueue) == TESTSIZE);
    KASSERT(!queue_isempty(newqueue));

    /* pop front TESTSIZE number of elements */
    for (i = 0; i < TESTSIZE; ++i) {
        elem = (int*)queue_front(newqueue);
        KASSERT(*elem == i);
        queue_pop(newqueue);
        kfree(elem);
    }
    KASSERT(queue_getsize(newqueue) == 0);
    KASSERT(queue_isempty(newqueue));

    queue_destroy(newqueue);

    kprintf("queue test complete\n");

    return 0;
}
