vector<int> p(2);
vector<int> h(2);
void precalc() {
	fori(2) {
		p[i] = rng() % 100 + 40;
		bool good = true;
		if(!isPrime(p[i])) good = false;
		forj(i) {
			if(p[j] == p[i]) good = false;
		}
		
		if(!good) {
			--i;
		}
	}
	
	fori(2) {
		h[i] = rng() % 10000 + 1e9;
		bool good = true;
		if(!isPrime(h[i])) good = false;
		forj(i) {
			if(h[j] == h[i]) good = false;
		}
		
		if(!good) {
			--i;
		}
	}	
}

struct Hash{
	int n;
	vector<int> P[2];
	vector<int> H[2];
	Hash(string &s) {
		n = s.size();
		forx(2) {
			P[x].assign(n + 1, 0);
			H[x].assign(n + 1, 0);
		}
		forx(2) {
			P[x][0] = 1;
		}

		forx(2) {
			for (int i = 1; i <= s.size(); ++i) {
				P[x][i] = (1ll * P[x][i - 1] * p[x]) % h[x];
				H[x][i] = (1ll * H[x][i - 1] * p[x] + (s[i - 1] - 'a' + 1)) % h[x];
			}
		}
	}
	pair<int, int> Get(int l, int r) {
		pair<int, int> hashans = { 0, 0 };
		forx(2) {
			int v = (H[x][r + 1] - 1ll * H[x][l] * P[x][r - l + 1] % h[x] + h[x]);
			if (v >= h[x]) v -= h[x];
			if (x == 0) hashans.ff = v;
			else hashans.ss = v;
		}
		return hashans;
	}
};
