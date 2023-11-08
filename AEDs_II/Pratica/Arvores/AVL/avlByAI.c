
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    int height;
    struct node *left;
    struct node *right;
} Node;

int max(int a, int b) {
    return a > b ? a : b;
}

int height(Node *node) {
    if (node == NULL) {
        return -1;
    }
    return node->height;
}

int balance_factor(Node *node) {
    if (node == NULL) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

Node *new_node(int key) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->key = key;
    node->height = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node *rotate_left(Node *node) {
    Node *new_root = node->right;
    node->right = new_root->left;
    new_root->left = node;
    node->height = max(height(node->left), height(node->right)) + 1;
    new_root->height = max(height(new_root->left), height(new_root->right)) + 1;
    return new_root;
}

Node *rotate_right(Node *node) {
    Node *new_root = node->left;
    node->left = new_root->right;
    new_root->right = node;
    node->height = max(height(node->left), height(node->right)) + 1;
    new_root->height = max(height(new_root->left), height(new_root->right)) + 1;
    return new_root;
}

Node *rotate_left_right(Node *node) {
    node->left = rotate_left(node->left);
    return rotate_right(node);
}

Node *rotate_right_left(Node *node) {
    node->right = rotate_right(node->right);
    return rotate_left(node);
}

Node *balance(Node *node) {
    if (balance_factor(node) == 2) {
        if (balance_factor(node->left) == -1) {
            node = rotate_left_right(node);
        } else {
            node = rotate_right(node);
        }
    } else if (balance_factor(node) == -2) {
        if (balance_factor(node->right) == 1) {
            node = rotate_right_left(node);
        } else {
            node = rotate_left(node);
        }
    }
    return node;
}

Node *insert(Node *node, int key) {
    if (node == NULL) {
        return new_node(key);
    }
    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    }
    node->height = max(height(node->left), height(node->right)) + 1;
    return balance(node);
}

void print_tree(Node *node) {
    if (node != NULL) {
        printf("%d\n", node->key);
        print_tree(node->left);
        print_tree(node->right);
    }
}

int main() {
    Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    print_tree(root);
    return 0;
}
