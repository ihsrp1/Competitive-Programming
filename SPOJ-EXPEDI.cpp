#include <bits/stdc++.h>

using namespace std;

int n;
pair<int, int> stop[10001];

int heapsize = 0;

void bubble_up(int h[]){
	int i = heapsize-1;
	int j;
	if(i % 2 == 0) j = i/2-1;
	else j = i/2;

	while(i > 0 && h[i] >= h[j]){
		int aux;
		aux = h[i];
		h[i] = h[j];
		h[j] = aux;

		i = j;
		if(i % 2 == 0) j = i/2-1;
		else j = i/2;
	}
}

void heap_insert(int h[], int k){
	h[heapsize] = k;
	heapsize++;
	bubble_up(h);
}

void heapify(int h[], int i){
	int m, l, r;
	m = i;
	l = 2*i + 1;
	r = 2*i + 2;

	if(l < heapsize && h[l] >= h[m]){
		m = l;
	}
	if(r < heapsize && h[r] >= h[m]){
		m = r;
	}

	if(m != i){
		int aux;
		aux = h[i];
		h[i] = h[m];
		h[m] = aux;
		heapify(h, m);
	}
}


int heap_extract(int h[]){
	int ret = h[0];
	swap(h[0], h[heapsize-1]);
	heapsize--;
	heapify(h, 0);
	return ret;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		
		heapsize = 0;
		int P, L;
		int d, c;
		int maxHeap[10001];

		for (int i = 0; i < n; ++i) {
			scanf("%d %d", &d, &c);
			stop[i] = {d, c};
		}

		scanf("%d %d", &d, &c);

		for (int i = 0; i < n; ++i){
			stop[i].first = d - stop[i].first;
		}

		int cnt = 0, MAX = 0;
		sort(stop, stop + n);

		stop[n] = {d, 0};
		for (int i = 0; i < n + 1; ++i) {

			while (c < stop[i].first && !(heapsize == 0)) {
				c += heap_extract(maxHeap);
				++cnt;
			}

			if (c < stop[i].first)
				break;
			heap_insert(maxHeap, stop[i].second);
			
		}
		if (c < d)
			cnt = -1;
		printf("%d\n", cnt);
	}

	return 0;
}