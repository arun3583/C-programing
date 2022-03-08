#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* NewNode(int x) {
    struct Node* new = (struct Node *)malloc(sizeof(struct Node));
    new->left = NULL;
    new->right = NULL;
    new->data = x;
    return new;
}

struct Node* Insert(struct Node *root, int x) {
    if (root == NULL)
        root = NewNode(x);
    else if (x <= root->data)
        root->left = Insert(root->left, x);
    else
        root->right = Insert(root->right, x);
    return root;
}

bool Search(struct Node* root, int x) {
    if (root == NULL)
        return false;
    else if (root->data == x)
        return true;
    else if (x < root->data)
        return Search(root->left, x);
    else if (x > root->data)
        return Search(root->right, x);
}

struct Node* FindMin(struct Node* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}

struct Node* Delete(struct Node *root, int data) {
	if(root == NULL) return root; 
	else if(data < root->data) root->left = Delete(root->left,data);
	else if (data > root->data) root->right = Delete(root->right,data);
	else {
		if(root->left == NULL && root->right == NULL) { 
			free(root);
			root = NULL;
		}
		else if(root->left == NULL) {
			struct Node *temp = root;
			root = root->right;
			free(temp);
		}
		else if(root->right == NULL) {
			struct Node *temp = root;
			root = root->left;
			free(temp);
		}
		else { 
			struct Node *temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	return root;
}

void inOrder(struct Node* root) {
    if(root==NULL)
        return;
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}

int main() {

    struct Node *root = NULL;
    int choice = 0, item;
    bool existential;
    while (1)
    {
        printf("\n1.Insert \n2.Search \n3.Delete\n4.Display in Inorder\n5.Exit\n");
        printf("\nEnter your choice?\n");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter Item value: ");
            scanf("%d", &item);
            root = Insert(root,item);
            break;
        case 2:
            printf("\nEnter Item value: ");
            scanf("%d", &item);
            existential = Search(root,item);
            if(existential)
                printf("Element exists!");
            else
                printf("Doesn't exist");
            break;
        case 3:
            printf("Enter value");
            scanf("%d", &item);
            root = Delete(root, item);
            break;
        case 4:
            printf("Inorder = ");
            inOrder(root);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Please enter valid choice..");
        }
    }

}
