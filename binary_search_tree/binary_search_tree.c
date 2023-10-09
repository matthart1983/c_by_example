#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* create_node(int data){
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insert_node(Node* node, int data) {
    if (node == NULL) {
        return create_node(data);
    }else if(data < node->data){
        node -> left = insert_node(node -> left, data);
    } else if (data > node -> data) {
        node -> right = insert_node(node -> right, data);
    }
    return node;
}

void inorder_traversal(Node* node) {
    if(node != NULL){
        inorder_traversal(node -> left);
        printf("%d ", node -> data);
        inorder_traversal(node -> right);
    }
}

int main() {
    Node* root = NULL;
    root = insert_node(root, 50);
    insert_node(root, 30);
    insert_node(root, 80);
    insert_node(root, 10);
    insert_node(root, 30);
    insert_node(root, 40);
    insert_node(root, 70);

    inorder_traversal(root);

    return 0;
}
