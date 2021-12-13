int HASH(unsigned char* str) {
	unsigned int h = 5381;
	int c;
	unsigned char* p = str;
	while (c = *p++) {
		h = ((h << 5) + h) + c;
	}
	return h;
}

struct queue {
	int* arr;
	int n, sz;
	int head, tail;
	queue() {
		n = 1;
		arr = new int[n];
		sz = 0;
		head = tail = 0;
	}
	~queue() {
		delete[] arr;
	}
	void push(int t) {
		if (n == sz) {
			int* next = new int[n * 2];
			for (int i = 0; i < n; ++i) next[i] = arr[(head + i) % n];
			delete[] arr;
			arr = next;
			head = 0, tail = n;
			n *= 2;
		}
		arr[tail] = t;
		tail = (tail + 1) % n;
		sz++;
	}
	int pop() {
		int ret = arr[head];
		head = (head + 1) % n;
		sz--;
		return ret;
	}
};

void quickSort(int* a, int n) {
	if (n < 50) {
		for (int i = 1; i < n; ++i) {
			for (int j = i - 1; j >= 0; --j) {
				if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
				else break;
			}
		}
		return;
	}
	int pivot = a[n / 2], i = 0, j = n - 1;
	do {
		while (a[i] < pivot) i++;
		while (a[j] > pivot) j--;
		if (i <= j) swap(a[i++], a[j--]);
	} while (i <= j);
	if (0 < j) quickSort(a, j + 1);
	if (i < n) quickSort(a + i, n - i);
}

int arr[100010];
int ind;
 
void push(int t) {
	int i = ind;
	arr[ind++] = t;
	while (i != 1) {
		if (arr[i / 2] > arr[i]) {
			swap(arr[i / 2], arr[i]);
			i /= 2;
		}
		else break;
	}
}
 
void pop() {
	ind--;
	arr[1] = arr[ind];
	int i = 1;
	while (i) {
		if (i * 2 + 1 < ind) {
			if (arr[2 * i] < arr[2 * i + 1]) {
				if (arr[i] > arr[2 * i]) {
					swap(arr[i], arr[2 * i]);
					i = 2 * i;
				}
				else break;
			}
			else {
				if (arr[i] > arr[2 * i + 1]) {
					swap(arr[i], arr[2 * i + 1]);
					i = 2 * i + 1;
				}
				else break;
			}
		}
		else if (i * 2 < ind) {
			if (arr[i] > arr[2 * i]) {
				swap(arr[i], arr[2 * i]);
				i = 2 * i;
			}
			else break;
		}
		else break;
	}
}