/** File tnodetest.c
 *
 * @author Nathaniel Miller
 *
 * Program to demonstrate Tnode structs,
 * as well as sorting, adding to, and traversing trees.
 */

#include "tnode.h"

int main() {

  Tnode *root; /* intialize a root node */
  root = add_tnode(NULL, "Zed"); /* add one entry to the root node */

  /* add a good sample of varying names to the tree, out or order */
  add_tnode(root, "Nate");
  add_tnode(root, "Adam");
  add_tnode(root, "Sam");
  add_tnode(root, "Devin");
  add_tnode(root, "Zane");
  add_tnode(root, "Devon");
  add_tnode(root, "James");
  add_tnode(root, "Britney");

  /* simple message to user to label output */
  printf("Tree of strings, in descending order:\n");

  /* print the tree of strings in descending order, inorder traversal */
  print_inOrder(root);

  free_tree(root); /* frees all the nodes in the tree */

  return 0; /* success */
} /* end function main */
