#define MOD 9999991
#include <iostream>

long long c(int n, int k) {
	static long long mem[30][30] = {};

	if (mem[n][k] > 0) return mem[n][k];
	if (k == 0 || n == k) return mem[n][k] = 1;
	return mem[n][k] = (c(n - 1, k - 1) + c(n - 1, k)) % MOD;
}

struct node {
	node* p = nullptr;
	node* l = nullptr;
	node * r = nullptr;
	int n;
	int num = 1;
	long long cal = 0;
};

void d(node* ptr) {
	if (ptr->l == nullptr) {
		if (ptr->r == nullptr) {
			ptr->cal = 1;
			return;
		}
		else {
			if (ptr->r->cal == 0) d(ptr->r);
			ptr->cal = ptr->r->cal;
			delete ptr->r;
			ptr->r = nullptr;
			return;
		}
	}
	else {
		if (ptr->r == nullptr) {
			if (ptr->l->cal == 0) d(ptr->l);
			ptr->cal = ptr->l->cal;
			delete ptr->l;
			ptr->l = nullptr;
			return;
		}
		else {
			if (ptr->l->cal == 0) d(ptr->l);
			if (ptr->r->cal == 0) d(ptr->r);
			ptr->cal = (c(ptr->l->num + ptr->r->num, ptr->l->num) * ptr->l->cal) % MOD;
			ptr->cal = (ptr->cal * ptr->r->cal) % MOD;
			delete ptr->l;
			delete ptr->r;
			ptr->l = nullptr;
			ptr->r = nullptr;
			return;
		}
	}
}

class bst {
private:
	node* root;
public:
	bst(int n) { root = new node; root->n = n; }
	~bst();
	void insert(int n);
};

bst::~bst() {
	d(root);
	printf("%d\n", root->cal);
	delete root;
}

void bst::insert(int n) {
	node* ptr = root;
	node* next = root;
	while (next != nullptr) {
		ptr = next;
		ptr->num++;
		if (n < ptr->n) next = ptr->l;
		else next = ptr->r;
	}
	if (n < ptr->n) {
		ptr->l = new node;
		ptr->l->p = ptr;
		ptr->l->n = n;
	}
	else {
		ptr->r = new node;
		ptr->r->p = ptr;
		ptr->r->n = n;
	}
}


int main() {
	int T, N, M;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		scanf("%d", &N);
		scanf("%d", &M);
		bst b(M);
		for (int j = 1; j < N; ++j) {
			scanf("%d", &M);
			b.insert(M);
		}
	}

	return 0;
}