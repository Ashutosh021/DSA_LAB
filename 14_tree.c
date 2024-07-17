// #include <stdio.h>
// #include <stdlib.h>

// struct node {
//   int item;
//   struct node* left;
//   struct node* right;
// };


// void inorderTraversal(struct node* root) {
//   if (root == NULL) return;
//   inorderTraversal(root->left);
//   printf("%d ->", root->item);
//   inorderTraversal(root->right);
// }


// void preorderTraversal(struct node* root) {
//   if (root == NULL) return;
//   printf("%d ->", root->item);
//   preorderTraversal(root->left);
//   preorderTraversal(root->right);
// }

// void postorderTraversal(struct node* root) {
//   if (root == NULL) return;
//   postorderTraversal(root->left);
//   postorderTraversal(root->right);
//   printf("%d ->", root->item);
// }


// int main() {
//   struct node* root = (struct node *)malloc(sizeof(struct node*));

//   root->item=20;
//   root->left->item=30;
//   root->right->item=40;

//   root->left->left=NULL;
//   root->left->right=NULL;

//   printf("Inorder traversal \n");
//   inorderTraversal(root);

//   printf("\nPreorder traversal \n");
//   preorderTraversal(root);

//   printf("\nPostorder traversal \n");
//   postorderTraversal(root);
// }





#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

void InsertioInTree(node **root, int item)
{
    node *nn = (node *)malloc(sizeof(node));
    nn->data = item;
    nn->left = nn->right = NULL;
    if ((*root) == NULL)
        *root = nn;
    else
    {
        node *ptr = *root;
        node *temp;
        while (ptr != NULL)
        {
            temp = ptr;
            if (ptr->data < item)
                ptr = ptr->right;
            else
                ptr = ptr->left;
        }
        if (temp->data > item)
            temp->left = nn;
        else
            temp->right = nn;
    }
}

void Inorder(node *root)
{
    if (root == NULL)
        return;
    else
    {
        Inorder(root->left);
        printf("%d  ", root->data);
        Inorder(root->right);
    }
}
void Preorder(node *root)
{
    if (root == NULL)
        return;
    else
    {
        printf("%d  ", root->data);
        Inorder(root->left);
        Inorder(root->right);
    }
}
void Postorder(node *root)
{
    if (root == NULL)
        return;
    else
    {
        Inorder(root->left);
        Inorder(root->right);
        printf("%d  ", root->data);
    }
}



int main()
{
    node *root = NULL;
    InsertioInTree(&root, 100);
    InsertioInTree(&root, 80);
    InsertioInTree(&root, 140);
    InsertioInTree(&root, 90);
    InsertioInTree(&root, 95);
    InsertioInTree(&root, 120);
    InsertioInTree(&root, 115);
    InsertioInTree(&root, 116);
    InsertioInTree(&root, 89);
    InsertioInTree(&root, 92);
    printf("\n Inorder :- ");
    Inorder(root);
    printf("\n Preorder :- ");
    Preorder(root);
    printf("\n Postorder :- ");
    Postorder(root);
    return 0;
}