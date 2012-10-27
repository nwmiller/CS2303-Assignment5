/** File tnode.h
 *
 * @author Nathaniel Miller
 *
 * Holds the Tnode struct definition,
 * and function prototypes for functions which
 * operate on Tnodes, such as sorting the tree.
 */


#ifndef TNODE_H
#define TNODE_H

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <time.h>


/* Struct to define a Tnode, which holds
 * a pointer to a C-style string, as well as
 * pointers to a left and right child.
 */
typedef struct node {
  char *str; /* pointer to character string */
  struct node *left; /* pointer to the left child of the tree */
  struct node *right; /* pointer to the right child of the tree */
} Tnode;


/* function prototypes */

Tnode *add_tnode(Tnode *current_tnode, char* value);

void print_inOrder(Tnode *curr_tnode);

int randCharInt();

char *randFill();

void free_tree(Tnode *curr_tnode);

#endif


