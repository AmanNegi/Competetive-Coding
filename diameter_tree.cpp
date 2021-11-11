#include <bits/stdc++.h>

using namespace std;

struct Node
{

	int value;
	Node *left;
	Node *right;
};

Node *head = nullptr;
Node *getNewNode(int n)
{
	Node *newNode = new Node();
	newNode->value = n;
	newNode->left = newNode->right = nullptr;

	return newNode;
}

Node *insert(Node *node, int n, string s)
{
	if (s.size() < 0)
		return nullptr;

	if (s.size() == 0)
	{
		node = getNewNode(n);
		return node;
	}

	if (s[0] == 'L')
		node->left = insert(node->left, n, s.substr(1, s.size()));
	else
		node->right = insert(node->right, n, s.substr(1, s.size()));

	return node;
}

void printTree(Node *node)
{
	if (node == NULL)
		return;

	cout << node->value << " ";
	printTree(node->left);
	printTree(node->right);
}
pair<int, int> recursiveDiameter(Node *node)
{
	if (node == NULL)
		return pair<int, int>(0, 0);

	auto lTree = recursiveDiameter(node->left);
	auto rTree = recursiveDiameter(node->right);

	pair<int, int> ans;
	ans.first = max(max(lTree.first, rTree.first), (lTree.second + rTree.second + 1));
	ans.second = max(lTree.second, rTree.second) + 1;

	return ans;
}
int main()
{
	int t, x;

	cin >> t >> x;
	head = getNewNode(x);
	t--;
	while (t--)
	{

		int n;
		string s;
		cin >> s >> n;
		head = insert(head, n, s);
	}
	pair<int, int> diameter = recursiveDiameter(head);
	cout <<  max(diameter.first, diameter.second) ;
	return 0;
}
