#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct node {
	node* left = nullptr;
	node* right = nullptr;
	char v = 0;
};

void insert(node* head, char u) {
	if (u < head->v) {
		if (head->left) insert(head->left, u);
		else {
			node* t = new node;
			t->v = u;
			head->left = t;
		}
	}
	else {
		if (head->right) insert(head->right, u);
		else {
			node* t = new node;
			t->v = u;
			head->right = t;
		}
	}
}

void print_pre(node* head) {
	cout << head->v;
	if (head->left) print_pre(head->left);
	if (head->right) print_pre(head->right);
}

void del(node* head) {
	if (head->left) del(head->left);
	if (head->right) del(head->right);
	delete head;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<string> input;
	while (1) {
		string s;
		cin >> s;
		if (s[0] < 'A') {
			node* head = new node;
			head->v = input.back()[0];
			for (int i = input.size() - 2; i >= 0; --i) {
				for (int u: input[i]) insert(head, u);
			}
			print_pre(head);
			del(head);
			cout << '\n';
			if (s[0] == '$') break;
			else input.clear();
		}
		else input.push_back(s);
	}
}