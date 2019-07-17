#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

const int MAX = 1000;

struct node {
	int item;
	struct node *left;
	struct node *right;
};

struct node *new_node(int an_item) {
	struct node *n;
	n = (struct node *)calloc(1, sizeof(struct node));
	n->item = an_item;
	n->left = NULL;
	n->right = NULL;
	return n;
}

struct node *add_node(struct node *root, struct node *a_node) {
	assert(root != NULL);
	assert(a_node != NULL);
	assert(a_node->left == NULL);
	assert(a_node->right == NULL);
	if (a_node->item <= root->item) {
		if (!root->left) {
			root->left = a_node;
		}
		else {
			add_node(root->left, a_node);
		}
	}
	else {
		if (!root->right) {
			root->right = a_node;
		}
		else {
			add_node(root->right, a_node);
		}
	}
	return root;
}

void print_tree(struct node *root) {
	if (root) {
		print_tree(root->left);
		printf("%d ", root->item);
		print_tree(root->right);
	}
}

int main() {
	struct node *root;
	int i;

	srand(1234567890);
	root = new_node(rand() % MAX);
	for (i = 0; i < 1000000; ++i) {
		add_node(root, new_node(rand() % MAX));
	}
	print_tree(root);
	return 0;
}