/** File queue.h
 *
 * @author Nathaniel Miller
 *
 * Holds the Queue struct definition,
 * and function prototypes for functions which
 * operate on queues.
 */


#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>


/* Struct to define a queue, where each entry is
 * capable of holding a pointer to anything.
 */
struct queue {
  int size; /* maximum number of entries in the queue */
  void **queue_head; /* pointer to head of queue */
  void **queue_tail; /* pointer to tail of queue */
  void **contents; /* pointer to queue buffer */
};

typedef struct queue Queue;


/* function prototypes */

Queue *create_queue(int size);

int enqueue(Queue *new_q, void *entry);

void* dequeue(Queue *new_q);

void delete_queue(Queue *the_q);

#endif


