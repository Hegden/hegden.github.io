#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct TreeNode {
	int val;
	struct TreeNode * left;
	struct TreeNode * right;
} TreeNode;

TreeNode * buildNode(int key) {
	TreeNode * retval = malloc(sizeof(TreeNode));
	retval->val = key;
	retval->left = NULL;
	retval->right = NULL;
	return retval;
}

bool contains(TreeNode * root, int key) {
	if (root == NULL) return false;
	if (root->val == key) return true;
	else if (root->val < key) return contains(root->right, key);
	else return contains(root->left, key);
}

bool add(TreeNode * * rootPtr, int key) {
	if (* rootPtr == NULL) {
		* rootPtr = buildNode(key);
		return true;
	} else if ((* rootPtr)->val == key) {
		return false;
	} else if ((* rootPtr)->val < key) {
		return add(&((* rootPtr)->right), key);
	} else {
		return add(&((* rootPtr)->left), key);
	}
}

TreeNode * removeMin(TreeNode * * rootPtr) {
	if (* rootPtr == NULL) return NULL;
	
	if ((* rootPtr)->left == NULL) {
		TreeNode * retval = * rootPtr;
		* rootPtr = (* rootPtr)->right;
		return retval;
	} else {
		return removeMin(&((* rootPtr)->left));
	}
}

bool removeNode(TreeNode * * rootPtr, int key) {
	if (* rootPtr == NULL) {
		return false;
	} else if ((* rootPtr)->val < key) {
		return removeNode(&((* rootPtr)->right), key);
	} else if ((* rootPtr)->val > key) {
		return removeNode(&((* rootPtr)->left), key);
	}
	
	TreeNode * toDelete = * rootPtr;
	
	if ((* rootPtr)->left == NULL) {
		* rootPtr = (* rootPtr)->right;
	} else if ((* rootPtr)->right == NULL) {
		* rootPtr = (* rootPtr)->left;
	} else {
		TreeNode * newRoot = removeMin(&(* rootPtr)->right);
		newRoot->left = (* rootPtr)->left;
		newRoot->right = (* rootPtr)->right;
		* rootPtr = newRoot;
	}
	
	free(toDelete);
	
	return true;
}

static void printTreeHelper(TreeNode * t, int offset, FILE * fptr) {
	if (t == NULL) return;
	
	for (int i = 0; i < offset; i++) {
		fprintf(fptr, "  ");
	}
	fprintf(fptr, "%d\n", t->val);
		
	printTreeHelper(t->left, offset + 1, fptr);
	printTreeHelper(t->right, offset + 1, fptr);
}

void printTree(TreeNode * t, FILE * fptr) {
	printTreeHelper(t, 0, fptr);
}

int main(int argc, char * * argv) {
	
	TreeNode * root = NULL;
	
	add(&root, 13);
	add(&root, 7);
	add(&root, 5);
	add(&root, 10);
	add(&root, 29);
	add(&root, 17);
	add(&root, 35);
	add(&root, 19);
	
	printTree(root, stderr);
	
	fprintf(stderr, "\n");
	
	removeNode(&root, 5);

	printTree(root, stderr);	
	
	fprintf(stderr, "\n");
	
	removeNode(&root, 7);
	
	printTree(root, stderr);	
	
	fprintf(stderr, "\n");
	
	removeNode(&root, 13);
	
	printTree(root, stderr);
		
	return EXIT_SUCCESS;
}