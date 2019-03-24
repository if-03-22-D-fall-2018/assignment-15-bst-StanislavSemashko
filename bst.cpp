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
     delete_bst(bst->left);
     delete_bst(bst->right);
     sfree(bst);
  }

}



/**
*** @return The depth of the BST
*/
int get_depth(Bst bst)
{

  if (bst == 0)return 0;
  if (bst->right == 0 && bst->left == 0)return 1;
  if (get_depth(left_subtree(bst)) > get_depth(right_subtree(bst)))return 1+get_depth(left_subtree(bst));
  return 1+get_depth(right_subtree(bst));
}

/**
*** Adds a value to the BST
*/
void insert(Bst start_node, Bst new_node);

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
  insert(*bst, new_node);
}

void insert(Bst start_node, Bst new_node)
{
  if (new_node->value <= start_node->value)
  {
    if (start_node->left == 0)
    {
      start_node->left = new_node;
    }
    else
    {
      insert(start_node->left, new_node);
    }
  }
  else
  {
    if (start_node->right == 0)
    {
      start_node->right = new_node;
    }
    else
    {
      insert(start_node->right, new_node);
    }
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
  if(bst != 0)
  {
    elements[start] = bst->value;
 if(get_depth(bst) > 0)
 {
   start+=1;
   start = traverse_pre_order(bst->left, elements, start);
   start = traverse_pre_order(bst->right, elements, start);

 }
}
return start;
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
  if(bst != 0)
  {
    if(bst->left != 0)
    {
      start = traverse_in_order(bst->left, elements, start);
    }
    elements[start] = bst->value;
    start+=1;
    if(bst->right != 0)
    {
      start = traverse_in_order(bst->right, elements, start);
    }
  }
  return start;
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
  if(bst != 0)
  {
      if(bst->left != 0)
      {
        start = traverse_post_order(bst->left, elements, start);
      }
      if(bst->right != 0)
      {
        start = traverse_post_order(bst->right, elements, start);
      }
      elements[start] = bst->value;
      start+=1;
  }
  return start;
}

/**
*** Checks whether two trees are equal
*** @param bst1 First bst
*** @param bst2 Second bst
*** @return true if bst1 and bst2 are equal, false otherwise
*/
bool are_equal(Bst bst1, Bst bst2)
{
  if(bst1 == 0)
  {
      return bst2 == 0;
  }
    else if(get_depth(bst1) == get_depth(bst2))
    {
      if(bst1->value == bst2->value)
      {
        return are_equal(bst1->left, bst2->left) && are_equal(bst1->right, bst2->right);
      }
    }
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
  if(bst != 0){
      if(get_depth(bst->right) > get_depth(bst->left)){
        add(branch, bst->value);
        most_left_longest_branch(&(*bst->right), branch);
      }else if(get_depth(bst->right) == get_depth(bst->left) || get_depth(bst->right) < get_depth(bst->left)){
        add(branch, bst->value);
        most_left_longest_branch(&(*bst->left), branch);
      }
  }
}

/**
*** Gets the number of non-empty subtrees of a tree
*** @param bst The tree which number of subtrees to get
*** @return The number of non-empty subtrees
*/
int get_number_of_subtrees(Bst bst)
{
  int count = 0;
  if(bst != 0)
  {
    if(bst->left == 0 && bst->right == 0) return count;
    if(bst->left == 0 && bst->right != 0)
    {
      count+=1;
      count += get_number_of_subtrees(bst->right);
    }
    else if(bst->left != 0 && bst->right == 0)
    {
      count+=1;
      count += get_number_of_subtrees(bst->left);
    }
    else
    {
      count+=2;
      count += get_number_of_subtrees(bst->left);
      count += get_number_of_subtrees(bst->right);
    }
    return count;
  }
  return -1;
}
