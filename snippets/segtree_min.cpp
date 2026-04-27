struct TreeMin{
	int n = 1;
	vector<int> t;
	TreeMin(int N) {
		while(n < N) n *= 2;
		t.assign(2 * n, inf);
	}
	TreeMin(vector<int> &A) {
		while(n < A.size()) n*=2;
		t.assign(2*n, inf);
		fori(A.size()) {
			t[i+n] = A[i];
		}
		for(int i = n-1; i >= 0; --i) {
			t[i] = min(t[i*2], t[i*2+1]);
		}
	}
	
	int Get(int l, int r) {
		int ans = inf;
		if(l > r) return ans;
		for(l += n, r += n; l <= r; l/=2, r/=2) {
			if(l % 2 == 1) ans = min(ans, t[l++]);
			if(r % 2 == 0) ans = min(ans, t[r--]);
		}
		return ans;
	}
	
	void Set(int i, int v) {
		i += n;
		t[i] = v;
		i/=2;
		while(i >= 1) {
			t[i] = min(t[i*2], t[i*2+1]);
			i/=2;
		}
		return;
	}
};
