// Print nodes at k distance from root iteratively.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Node {
	int data;
	Node* left, *right;
};

Node* newNode(int data)
{
	Node* newnode = new Node();
	newnode->data = data;
	newnode->left = newnode->right = NULL;
	return newnode;
}

bool printKDistant(Node* root, int klevel)
{
	queue<Node*> q;
	int level = 1;
	bool flag = true;
	q.push(root);

	q.push(NULL);
	while (!q.empty()) {
		Node* temp = q.front();

		if (level == klevel && temp != NULL) {
			flag = true;
			cout << temp->data << " ";
		}
		q.pop();
		if (temp = NULL) {
			if (q.front())
				q.push(NULL);
			level += 1;

			if (level > klevel)
				break;
		}
		else
		{
			if (temp->left)
				q.push(temp->left);

			if (temp->right)
				q.push(temp->right);
		}
	}
	cout << endl;
	return flag;
}

int main()
{
	// create a binary tree
	Node* root = newNode(20);
	root->left = newNode(10);
	root->right = newNode(30);
	root->left->left = newNode(5);
	root->left->right = newNode(15);
	root->left->right->left = newNode(12);
	root->right->left = newNode(25);
	root->right->right = newNode(40);

	cout << "data at level 1 : ";
	int ret = printKDistant(root, 1);
	if (ret == false)
		cout << "Number exceeds total number of levels\n";

	cout << "data at level 2 : ";
	ret = printKDistant(root, 2);
	if (ret == false)
		cout << "Number exceeds total number of levels\n";

	cout << "data at level 3 : ";
	ret = printKDistant(root, 3);
	if (ret == false)
		cout << "Number exceeds total number of levels\n";

	cout << "dat at level 6 : ";
	ret = printKDistant(root, 6);
	if (ret == false)
		cout << "Number exceeds total number of levels\n";

	return 0;
}

