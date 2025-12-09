#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;

}Node;

Node* CreateNode(int val){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->right = NULL;
    node->left = NULL;
    return node;
}

Node* Insert(Node* root, int val){
    if (root == NULL){
        return CreateNode(val);
    }
    
    if (val < root->data){
        root->left = Insert(root->left, val);
    }
    else if (val > root->data){
        root->right = Insert(root->right, val);
    }
    
    return root;
}

int Search(Node* root, int target){
    if (! root){
        return 0;
    }
    if (root->data == target){
        return 1;
    }
    if (root->data > target){
        return Search(root->left, target);
    }
    if (root->data < target){
        return Search(root->right, target);
    }
    return 0;
}

void InOrder(Node* root){
    if (root == NULL){
        return;
    }
    InOrder(root->left);
    printf("%d ", root->data);
    InOrder(root->right);
}

void PreOrder(Node* root){
    if (root == NULL){
        return;
    }
    printf("%d ", root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}

void PostOrder(Node* root){
    if (root == NULL){
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d ", root->data);
}

int main(){
    Node* root = NULL;
    /* Insert values into BST */
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(values) / sizeof(values[0]);
    printf("Inserting values: ");
    for (int i = 0; i < n; i++){
        printf("%d ", values[i]);
        root = Insert(root, values[i]);
    }
    
    printf("\n\n");
    
    printf("InOrder ");
    InOrder(root);
    printf("\n\n");
    
    printf("PreOrder ");
    PreOrder(root);
    printf("\n\n");
    
    printf("PostOrder ");
    PostOrder(root);
    printf("\n\n");
      
    printf("Searching for values:\n");
    int search_vals[] = {40, 25, 80, 100};
    for (int i = 0; i < 4; i++){
        if (Search(root, search_vals[i])){
            printf("%d found\n", search_vals[i]);
        }
        else{
            printf("%d not found\n", search_vals[i]);
        }
    }
    
    return 0;
}
