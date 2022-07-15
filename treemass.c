#define _CRT_SECURE_NO_WARNINGS
#define M_PI 3.14159265358979323846
#include <stdio.h> 
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
	int item;
	struct node* left;
	struct node* right;
};

struct node* createNode(int value) {
	struct node* newNode = malloc(sizeof(struct node));
	newNode->item = value;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

void add(int value, struct node* node) {
	if (!node->item) {
		createNode(value);
	} else {
		if (node->item <= value) {
			if (node->right == NULL) {
				node->right = createNode(value);
			}
			else {
				add(value, node->right);
			}
		}
		if (node->item > value) {
			if (node->left == NULL) {
				node->left = createNode(value);
			}
			else {
				add(value, node->left);
			}
		}
	}
}

int find(int value, struct node* node) {
	if (node == NULL) {
		return -1000;
	}
	if (value == node->item) {
		return 1;
	}
	else if (value > node->item) {
		return find(value, node->right) + 1;
	}
	else if (value <= node->item) {
		return find(value, node->left) + 1;
	}
	
}
int main() {
	srand(time(0));
	int arr[100000];
	for (int i = 0; i < 1000; i++) {
		arr[i] = rand() % 3000;
	}
	struct node* root = createNode(arr[0]);
	for (int i = 1; i < 1000; i++) {
		add(arr[i], root);
	}
	int x, i=0;
	printf("input num: ");
	scanf("%d", &x);
	while (arr[i] != x && i < 1000) {
		i++;
	}
	int time_1 = i, time_2 = find(x, root);
	if (time_2 < 0) {
		printf("NO");
		return 0;
	}
	printf("vector: %d sec\n", time_1);
	printf("tree: %d sec\n", time_2);
}