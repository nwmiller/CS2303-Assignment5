/** File tnode.c
 *
 * @author Nathaniel Miller
 *
 * Functions which operating on trees,
 * i.e. Tnode structs, such as adding elements,
 * sorting, and traversing.
 */

#include "tnode.h"

#define ARR_MAX 6


/** Adds a tnode. Allocates a node if the existing
 * node is NULL, and stores the data into it. Compares
 * the node with contents of the passed node if node isn't
 * NULL, and recursively compares through the tree.
 *
 * @param *current_tnode The current tree node to add to.
 * @param value The string value to be stored in the node.
 *
 * @return current_tnode The newly created or modified Tnode
 */

Tnode *add_tnode(Tnode *current_tnode, char* value) {
  
  /* check if tree is empty */
  if(current_tnode == NULL) {
    current_tnode = malloc(sizeof(Tnode));
    
    /* check if memory was properly allocated and pointer isn't null */
    if(current_tnode != NULL) {
      (current_tnode)->str = value; /* fill in string field */
      (current_tnode)->left = NULL; /* initially empty */
      (current_tnode)->right = NULL; /* initially empty */
    } /* end if */
    /* if no memory is availble */
    else {
      printf("%s not inserted. No memory is available.\n", value);
    } /* end else */
    return current_tnode; /* return a pointer to the Tnode */
  } /* ende if */
  /* otherwise, if the tree is not empty to begin with */
  else {

    /* compare data to insert to current value of node */

    /* if new string is greater than the current data in the node */
    if( (strcmp(value, (current_tnode)->str)) > 0 ) {
      current_tnode->left = add_tnode( ((current_tnode)->left), value );
    } /* end if */

    /* if new string is less than current value of node */
    else if( (strcmp(value, (current_tnode)->str)) < 0 ) {
      current_tnode->right = add_tnode( ((current_tnode)->right), value );
    } /* end if */

    /* if the new string is exactly equal the current value of the node */
    else if( strcmp(value, current_tnode->str) == 0 ) {
      printf("Error. That entry already exists in the tree.\n");
    } /* end if */
  } /* end else*/
  return current_tnode; /* return a pointer to the Tnode */
} /* end function add_tnode */


/** Prints the tree by traversing the tree
 * inorder.
 *
 * @param *curr_tnode The pointer to the tree.
 */

void print_inOrder(Tnode *curr_tnode) {
  
  /* print each value in the tree, using recursion */
  if(curr_tnode != NULL) {
    print_inOrder(curr_tnode->left); /* print left child */
    printf("%s\n", curr_tnode->str); /* print node value itself */
    print_inOrder(curr_tnode->right); /* print right child */
  } /* end if */
} /* end function print_inOrder */


/** Generates pseudo-random integers 
 * within the range of uppercase ASCII chars.
 * Generator is seeded in main program,
 * in order to produce more random integers.
 *
 * @return letter The randomly generated integer for uppercase ASCII chars.
 */

int randCharInt() {

  int letter; /* stores randomly generated integer */
 
  /* generates a random integer corresponding to uppercase ASCII chars, inclusive */
  letter = (65 + rand() % (26));

  return letter; /* returns the random integer */

} /* end function randInt */


/** Takes in an array, the size of the array, and a specified maximum,
 * and fills the array with randomly generated integers, produced
 * by randInt function. When the array  is full, the array is printed,
 * then sorted, then printed again.
 *
 * @return a The character array filled with random chars.
 */

char *randFill() {

  int j = 0; /* loop counter */
  char* a = (char*) malloc(ARR_MAX + 1);
  char* p1 = a;
  
  /* loop until the max number of elements is reached */
  while( j < ARR_MAX ) {
    j++; /* advance to next element in array */
    *(p1++) = (char) randCharInt(); /* fill array with randomly gen. chars */
  }
  *p1 = '\0'; /* add the null terminator */

  return a; /* pointer to the randomly generated string */

} /* end function randFill */


/** Traverses an entire tree and frees
 * all the nodes being pointed to.
 *
 * @param *curr_tnode The tree to be traversed and freed.
 */

void free_tree(Tnode *curr_tnode) {

  /* free each node in the tree, using recursion */
  if(curr_tnode != NULL) {
    if((curr_tnode->left) != NULL) {
      free_tree(curr_tnode->left);
    } /* end if */
    else if((curr_tnode->right) != NULL) {
      free_tree(curr_tnode->right);
    } /* end else if */
    else {
      free(curr_tnode);
    } /* end else */
  } /* end if */
} /* end function free_tree */
  

    
