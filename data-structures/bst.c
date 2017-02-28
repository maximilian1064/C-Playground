/*
 *sorting input values using binary search tree
 *small detour to two ways of getting input elements with unknown quantity into array
 *
 *Code used for learnig purpose:
 *1.  link list reviewed
 *2.  Two ways of getting input elements with unknown quantity into array
 *    -- link list
 *    -- malloc & realloc
 *    (there maybe other methods)
 *3.  sorting using binary search tree 
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct t_node{
    int data;
    struct t_node *left,
                  *right;
} bst_node;

// store input in link list 
typedef struct input_data{
    int data;
    struct input_data* next;
} input;

int getInputList(input** in)
{
    int d, i=0;
    while(scanf("%d", &d)==1)
    {
        // build the input list backwardly
        input* newnode = malloc(sizeof(input));
        newnode->data = d;
        newnode->next = *in;
        *in = newnode;
        // count the elements of the list, 
        i++;
    }
    return i;
}

void BSTinsertion(bst_node** root, int value)
{
    bst_node* newnode = malloc(sizeof(bst_node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    if(!(*root)) 
        *root = newnode;
    else if(value < (*root)->data)
        BSTinsertion( &((*root)->left), value); 
    else 
        BSTinsertion( &((*root)->right), value);
}

void BSTshowNode(bst_node* root)
{
    if(root)
    {
        if(root->left!=NULL)
            BSTshowNode(root->left);
        printf("%d\n", root->data);
        if(root->right!=NULL)
            BSTshowNode(root->right);
    }
}

int main(int argc, char* argv[])
{
    // transfer data from list to array
    input* in_list=NULL;
    int input_length = getInputList(&in_list);
    int* in_array = malloc(sizeof(int)*input_length); 
    int i;
    for(i=0; i<input_length && in_list!=NULL; i++)
    {
        in_array[i] = in_list->data;
        in_list = in_list->next;
    }

    bst_node* root_node = NULL;
    // construct BST tree
    for(i=0; i<input_length; i++)
        BSTinsertion(&root_node, in_array[i]);

    // show the result of sorting, aka, traverse the BST tree
    BSTshowNode(root_node);

    return 0;
}
