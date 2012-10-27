/** File queue.c
 *
 * @author Nathaniel Miller
 *
 * Functions which operate on queues:
 * create a queue, add an entry to the queue,
 * and remove an entry from the queue.
 */

#include "queue.h"


/** Creates a queue by allocating a Queue struct,
 * then initializes it, and allocates memory to hold
 * the entries to the queue.
 *
 * @param size The maximum number of entries in the queue.
 * @return new_queue A pointer to the newly created Queue struct.
 */

Queue *create_queue(int size) {
  
  Queue *new_queue; /* Hold pointer to the created Queue struct */
  new_queue = (Queue *) malloc(sizeof(Queue));

  if (new_queue == NULL) return NULL; /* if unable to allocate space */
  
  new_queue->size = size; /* fill in the struct field */

  /* allocate memory for the queue entries */
  new_queue->contents = (void **) calloc(sizeof(void *), size);
  if(new_queue->contents == NULL) {
    free(new_queue); /* free struct if unable to allocat entries space */
    return NULL;
  } /* end if */
  new_queue->queue_tail = new_queue->contents; /* start at tail of queue */
  new_queue->queue_head = NULL; /* make head NULL */

  return new_queue; /* return a pointer to the newly-created Queue struct */
} /* end function create_queue */


/** Adds an entry onto the tail-end of the Queue.
 * Tail pointer is increased after entry is added.
 *
 * @param *new_q The Queue struct.
 * @param *entry Pointer to an entry to be added to the Queue.
 */

int enqueue(Queue *new_q, void *entry) {
  
  /* checks if queue is full */
  if(new_q->queue_head == new_q->queue_tail) {
    return -1; /* return if full */
  } /* end if */

  /* check if queue is empty */
  if(new_q->queue_head == NULL) {
    new_q->queue_head = new_q->queue_tail; /* set head as tail, if empty */
  } /* end if */

  /* check if the tail is at the end of the queue */
  if(new_q->queue_tail == (new_q->contents + ((new_q->size) - 1))) {
    *(new_q->queue_tail) = entry; /* add queue entry onto the queue */
    new_q->queue_tail = new_q->contents; /* set the tail to the base */
  } /* end if */
  else {
    *(new_q->queue_tail) = entry; /* add queue entry onto the queue */
    (new_q->queue_tail)++; /* advance the tail location */
  } /* end else */

  return 0; /* success */
} /* end function enqueue */


/** Removes an entry from the Queue.
 * Entry is removed from the head-end.
 * Head pointer is increased to next entry.
 *
 * @param *new_q The Queue struct.
 * @return ent The stored removed value.
 */

void* dequeue(Queue *new_q) {

  /* check if queue is empty */
  if(new_q->queue_head == NULL) {
    printf("Queue is empty. Cannot remove an entry from an empty Queue!");
    return NULL;
  } /* end if */

  void* ent = *(new_q->queue_head); /* store the removed entry */
  
  /* check if head is at the end of the queue */
  if(new_q->queue_head == (new_q->contents + ((new_q->size) - 1))) {
    new_q->queue_head = new_q->contents; /* set the head as the base */
  } /* end inner if */
  else {
    (new_q->queue_head)++; /* otherwise advance the head */
  } /* end else */

  /* check if the queue is empty now */
  if(new_q->queue_head == new_q->queue_tail) {
    new_q->queue_head = NULL;
  } /* end if */

  return ent; /* return the stored entry */
} /* end function dequeue */



/** Deletes the Queue, freeing any 
 * allocated memory or structures.
 *
 * @param *the_q The Queue to be deleted.
 */

void delete_queue(Queue *the_q) {
  free(the_q->contents); /* Free the memory holding the queue entries */
  free(the_q); /* free the queue struct */
} /* end function delete_queue */
  
  

  
    
    
  
