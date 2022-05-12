#include <iostream>
using namespace std;

typedef struct _tree
{
	int value;
	struct _tree *left;
	struct _tree *right;
}tree;

tree* push(tree *t, tree *p, int key)
{
	if (t == NULL)
	{
		tree *newT = new tree;
		newT->value = key;
		newT->left = NULL;
		newT->right = NULL;
		t = newT;
		if (p != NULL)
		{
			if (p->value < t->value)
				p->right = t;
			else
				p->left = t;
		}
		return t;
	}
	if (t->value < key)
		push(t->right, t, key);
	else
		push(t->left, t, key);
}
tree* seach(tree *t, int key)
{
	if (t == NULL)
		return NULL;
	if (t->value == key)
		return t;

	if (t->value < key)
		seach(t->right, key);
	else
		seach(t->left, key);
}
int main()
{
	tree* bt = NULL;
	int key;
	cin >> key;

	bt = push(bt, NULL, 5);
	push(bt, NULL, 3);
	push(bt, NULL, 7);
	push(bt, NULL, 2);
	push(bt, NULL, 4);
	push(bt, NULL, 6);
	push(bt, NULL, 8);

	cout << seach(bt, key);

	return 0;
}