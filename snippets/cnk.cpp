const int N = 1e6+5;
vector<int> Fac(N);
vector<int> dFac(N);
int Pow(int a, int b) {
	if(b == 0) return 1;
	int c = Pow(a, b/2);
	c = c * c % mod;
	if(b % 2 == 1) c = c * a % mod;
	return c;
}
int d(int a) {
	return Pow(a, mod-2);
}
int C(int k, int n) {
	if(k > n) return 0;
	return Fac[n] * dFac[k] % mod * dFac[n-k] % mod;
}

void precalc() {
	Fac[0] = 1;
	for(int i = 1; i < N; ++i) {
		Fac[i] = Fac[i-1] * i % mod;
	}
	dFac[N-1] = d(Fac[N-1]);
	for(int i = N-2; i >= 0; --i) {
		dFac[i] = dFac[i+1] * (i+1) % mod;
	}
}
