/** File randtree.c
 *
 * @author Nathaniel Miller
 *
 * Program to demonstrate Tnode structs,
 * as well as sorting, adding to, and traversing trees.
 * Generating random strings and inserting strings
 * into trees, and sorting randomized trees is also
 * demonstrated.
 */

#include "tnode.h"

int main() {

  srand(time(NULL)); /* call srand() to seed random char generator */

  Tnode *root; /* intialize a root node */
  root = add_tnode(NULL, randFill()); /* add one random string to the root */

  /* generate some random strings */
  char *s1 = randFill();
  char *s2 = randFill();
  char *s3 = randFill();
  char *s4 = randFill();
  char *s5 = randFill();

  /* add a good sample of random strings to the tree */
  add_tnode(root, s1);
  add_tnode(root, s2);
  add_tnode(root, s3);
  add_tnode(root, s4);
  add_tnode(root, s5);

  /* simple message to user to label output */
  printf("Tree of randomly generated strings, in descending order:\n");

  /* print the tree of random strings in descending order, inorder traversal */
  print_inOrder(root);

  free_tree(root); /* frees all the nodes in the tree */

  return 0; /* success */
} /* end function main */
