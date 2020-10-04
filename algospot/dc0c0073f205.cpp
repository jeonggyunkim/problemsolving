#include <iostream>
#include <vector>
using namespace std;

typedef int Keytype;

struct Node {
	Keytype key;
	int priority, size;

	Node *left, *right;

	Node(const Keytype& _key) : key(_key), priority(rand()), size(1), left(nullptr), right(nullptr) {}

	void setLeft(Node* leftptr) {
		left = leftptr;
		calSize();
	}

	void setRight(Node* rightptr) {
		right = rightptr;
		calSize();
	}

	void calSize() {
		size = 1;
		if (left) size += left->size;
		if (right) size += right->size;
	}
};

typedef pair<Node*, Node*> Nodepair;

Nodepair split(Node* root, Keytype key) {
	if (!root) return Nodepair(nullptr, nullptr);
	if (root->key < key) {
		Nodepair rs = split(root->right, key);
		root->setRight(rs.first);
		return Nodepair(root, rs.second);
	}
	else {
		Nodepair rs = split(root->left, key);
		root->setLeft(rs.second);
		return Nodepair(rs.first, root);
	}
}

Node* insert(Node* root, Node* node) {
	if (!root) return node;

	if (root->priority < node->priority) {
		Nodepair splitted = split(root, node->key);
		node->setLeft(splitted.first);
		node->setRight(splitted.second);
		return node;
	}
	else {
		if (node->key < root->key) {
			root->setLeft(insert(root->left, node));
		}
		else {
			root->setRight(insert(root->right, node));
		}
		return root;
	}
}

Node* merge(Node* a, Node* b) {
	if (!a) return b;
	if (!b) return a;
	if (a->priority < b->priority) {
		b->setLeft(merge(a, b->left));
		return b;
	}
	else {
		a->setRight(merge(a->right, b));
		return a;
	}
}

Node* erase(Node* root, Keytype key) {
	if (!root) return root;
	if (root->key == key) {
		Node* ret = merge(root->left, root->right);
		delete root;
		return ret;
	}
	else {
		if (root->key > key) {
			root->setLeft(erase(root->left, key));
		}
		else {
			root->setRight(erase(root->right, key));
		}
		return root;
	}
}

Node* kth(Node* root, int k) {
	if (k > root->size) return nullptr;
	int leftSize = 0;
	if (root->left) leftSize = root->left->size;
	if (k <= leftSize) return kth(root->left, k);
	else if (k == leftSize + 1) return root;
	else {
		return kth(root->right, k - leftSize - 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int> arr(n), ans(n);
		for (int i = 0; i < n; ++i) cin >> arr[i];

		Node* root = nullptr;
		for (int i = 1; i <= n; ++i) {
			root = insert(root, new Node(i));
		}

		for (int i = n - 1; i >= 0; --i) {
			ans[i] = kth(root, i + 1 - arr[i])->key;
			root = erase(root, ans[i]);
		}

		for (int i = 0; i < n; ++i) cout << ans[i] << ' ';
		cout << '\n';
	}
}
