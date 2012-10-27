/** File queuetest.c
 *
 * @author Nathaniel Miller
 *
 * Program to test the Queue and functions
 * which operate on the Queue.
 */

#include "queue.h"

/* Foo struct definition */
typedef struct {
  int x;
  double y;
} Foo; /* struct for demonstrations and tests */

int main() {
  const int max_entries = 5; /* size of the queue */

  /* define some variables to hold Foo structs*/
  Foo* new_foo1;
  Foo* new_foo2; 
  Foo* new_foo3;
  Foo* new_foo4;
  Foo* new_foo5;
  Foo* new_foo6;
  Foo* returned_foo;

  /* create a Queue struct with max_entries size */
  Queue *new_queue = create_queue(max_entries);

  /* show pointer addresses to demonstrate wrap around */
  printf("\nWrap around demonstration before Queue is modified:");
  printf("\nBuffer: %p\n", new_queue);
  printf("Head: %p\n", new_queue->queue_head);
  printf("Tail: %p\n\n", new_queue->queue_tail);


  /* allocate a Foo and add it onto the queue */
  new_foo1 = (Foo *) malloc(sizeof(Foo));
  new_foo1->x = 6;
  new_foo1->y = 14.79;
  printf("Adding: x = %5d, y = %10.3f\n", new_foo1->x, new_foo1->y);
  enqueue(new_queue, (void *) new_foo1);

  /* allocate a Foo and add it onto the queue */
  new_foo2 = (Foo *) malloc(sizeof(Foo));
  new_foo2->x = 217;
  new_foo2->y = 3.14159;
  printf("Adding: x = %5d, y = %10.3f\n", new_foo2->x, new_foo2->y);
  enqueue(new_queue, (void *) new_foo2);;

  /* allocate a Foo and add it onto the queue */
  new_foo3 = (Foo *) malloc(sizeof(Foo));
  new_foo3->x = 500;
  new_foo3->y = 4.50483;
  printf("Adding: x = %5d, y = %10.3f\n", new_foo3->x, new_foo3->y);
  enqueue(new_queue, (void *) new_foo3);

  /* allocate a Foo and add it onto the queue */
  new_foo4 = (Foo *) malloc(sizeof(Foo));
  new_foo4->x = 4059;
  new_foo4->y = 22.48300;
  printf("Adding: x = %5d, y = %10.3f\n", new_foo4->x, new_foo4->y);
  enqueue(new_queue, (void *) new_foo4);

  /* allocate a Foo and add it onto the queue */
  new_foo5 = (Foo *) malloc(sizeof(Foo));
  new_foo5->x = 1010;
  new_foo5->y = 1056.3827;
  printf("Adding: x = %5d, y = %10.3f\n", new_foo5->x, new_foo5->y);
  enqueue(new_queue, (void *) new_foo5);

  /* show pointer addresses to demonstrate wrap around */
  printf("\nWrap around demonstration after max entries are added:");
  printf("\nBuffer: %p\n", new_queue);
  printf("Head: %p\n", new_queue->queue_head);
  printf("Tail: %p\n\n", new_queue->queue_tail);
  
  /* attempt to add more than max number of entries onto the queue */
  new_foo6 = (Foo *) malloc(sizeof(Foo));
  new_foo6->x = 666;
  new_foo6->y = 66.666666;
  printf("Attempting to add more than max # of entries to the queue.\n");
  printf("Last entry is not added to queue!\n");
  printf("Adding: x = %5d, y = %10.3f\n", new_foo6->x, new_foo6->y);
  enqueue(new_queue, (void *) new_foo6);

  /* remove entries from the queue and print them */
  returned_foo = (Foo *) dequeue(new_queue);
  printf("Removed:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
  returned_foo = (Foo *) dequeue(new_queue);
  printf("Removed:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
  returned_foo = (Foo *) dequeue(new_queue);
  printf("Removed:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
  returned_foo = (Foo *) dequeue(new_queue);
  printf("Removed:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
  returned_foo = (Foo *) dequeue(new_queue);
  printf("Removed:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);

  /* show pointer addresses to demonstrate wrap around */
  printf("\nWrap around demonstration after entries are removed:");
  printf("\nBuffer: %p\n", new_queue);
  printf("Head: %p\n", new_queue->queue_head);
  printf("Tail: %p\n\n", new_queue->queue_tail);

  /* attempt to remove non-existant element from queue */
  returned_foo = (Foo *) dequeue(new_queue);
  /* check for removing  more elements than exist in the queue */
  if(returned_foo != NULL) {
    printf("Removed:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
  } else {
    printf("\nError. Trying to remove nonexistant entry from queue!\n");
  } /* end else */
  

  /* free any allocated memory and clean up */
  delete_queue(new_queue);
  free(new_foo1);
  free(new_foo2);
  free(new_foo3);
  free(new_foo4);
  free(new_foo5);
  free(new_foo6);

  return 0; /* success */
} /* end function main */
  

