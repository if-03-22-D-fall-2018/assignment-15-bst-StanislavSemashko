/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			bst.cpp
 * Author(s):		Peter Bauer
 * Due Date:		May 31, 2017
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include "bst.h"
#include <stdlib.h>
#include "general.h"

struct Node
{
  int value;
  Bst left;
  Bst right;
};



/**
*** Initializes the binary search tree. Deletes all existing nodes in the tree
*** @return The number of deleted nodes
*/
Bst new_bst()
{
  return 0;
}

void delete_bst(Bst bst)
{
  if(bst != 0)
  {
    if (bst->left != 0)
    {
      sfree(bst->left);
    }
    if (bst->right != 0)
    {
      sfree(bst->right);
    }
    sfree(bst);
  }

}



/**
*** @return The depth of the BST
*/
int get_depth(Bst bst)
{
  if (bst == 0)return 0;
  if (bst->left != 0 || bst->right != 0)return 2;
 return 1;
}

/**
*** Adds a value to the BST
*/
void insert(Bst* start_node, Bst new_node);

void add(Bst* bst, int value)
{
  Bst new_node = (Bst)malloc(sizeof(struct Node));
  new_node->value = value;
  new_node->left = 0;
  new_node->right = 0;
  if (*bst == 0)
  {
    *bst = new_node;
    return;
  }
  insert(bst, new_node);
  // if (value <= (*bst)->value)
  // {
  //   (*bst)->left = new_node;
  // }else
  // {
  //   (*bst)->right = new_node;
  // }
}

void insert(Bst* start_node, Bst new_node)
{
  if (new_node->value <= (*start_node)->value)
  {
    if ((*start_node)->left == 0)
    {
      (*start_node)->left = new_node;
    }
    insert((*start_node)->left, new_node);
  }else
  {
    if ((*start_node)->right == 0)
    {
      (*start_node)->right = new_node;
    }
    insert((*start_node)->right, new_node);
  }
}

/**
*** @return The value of the root element of the BST
*/
int root_value(Bst bst)
{
  if (bst == 0 )return 0;
  return bst->value;
}

/**
*** @return The left subtree of the BST
*/
Bst left_subtree(Bst root)
{
  if (root == 0)return 0;
  return root->left;
}

/**
*** @return The right subtree of the BST
*/
Bst right_subtree(Bst root)
{
  if (root == 0)return 0;
  return root->right;
}

/**
*** Traverses the BST depth first by first returning the root, then traversing the left
*** subtree, then traversing the right subtree.
*** @param bst The BST to be traversed
*** @param elements Array of elements in the order how they are found during traversal
*** @param start Start index of elements wherer the function should start to add the found elements
*** @return Number of elements found during traversal
*/
int traverse_pre_order(Bst bst, int *elements, int start)
{
  return 0;
}

/**
*** Traverses the BST depth first by first traversing the left subtree, then adding the root,
*** then traversing the right subtree.
*** @param bst The BST to be traversed
*** @param elements Array of elements in the order how they are found during traversal
*** @param start Start index of elements wherer the function should start to add the found elements
*** @return Number of elements found during traversal
*/
int traverse_in_order(Bst bst, int *elements, int start)
{
  return 0;
}

/**
*** Traverses the BST depth first by first traversing the left subtree, then traversing the right
*** subtree and finally adding the root.
*** @param bst The BST to be traversed
*** @param elements Array of elements in the order how they are found during traversal
*** @param start Start index of elements wherer the function should start to add the found elements
*** @return Number of elements found during traversal
*/
int traverse_post_order(Bst bst, int *elements, int start)
{
  return 0;
}

/**
*** Checks whether two trees are equal
*** @param bst1 First bst
*** @param bst2 Second bst
*** @return true if bst1 and bst2 are equal, false otherwise
*/
bool are_equal(Bst bst1, Bst bst2)
{
  return false;
}

/**
*** Calculates the longest branch in the tree. If two branches are equally long
*** the left branch is taken.
*** @param bst Bst which longest branch should be found
*** @return A tree where each node has only one child equal to the longest
*** branch of bst
*/
void most_left_longest_branch(Bst bst, Bst* branch)
{

}

/**
*** Gets the number of non-empty subtrees of a tree
*** @param bst The tree which number of subtrees to get
*** @return The number of non-empty subtrees
*/
int get_number_of_subtrees(Bst bst)
{
  return 0;
}
