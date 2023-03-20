#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *l;
    struct node *r;
} node;

node* create(int x) {
    node *new = (node*) malloc(sizeof(node));
    new->val = x;
    new->l = NULL;
    new->r = NULL;
    return new;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int height(node *root) {
    if (root == NULL)
        return 0;
    return 1 + max(height(root->l), height(root->r));
}

int diameter(node *root, int *h) {
    if (root == NULL)
        return 0; 
    
    int lh = 0, rh = 0;
    int ld = diameter(root->l, &lh);
    int rd = diameter(root->r, &rh);

    *h = max(lh, rh) + 1;
    int temp = max(ld, rd);

    return max(lh + rh + 1, temp);
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
