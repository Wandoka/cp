#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string> 
#include <set>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;

//#pragma comment(linker, "/stack:36777216")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")


inline void boostIO() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
}

typedef long long int ll;
typedef long double ld;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

#define fori(n) for(int i = 0; i < (n); ++i)
#define forj(n) for(int j = 0; j < (n); ++j)
#define fork(n) for(int k = 0; k < (n); ++k)

#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ff first
#define ss second
#define debug(x) cerr << #x << " = " << x << endl;
#define debug_p(x) cerr << #x << " " << x.ff << " " << x.ss << endl;
#define debug_v(x) cerr << #x << " "; for (auto ii : x) cout << i << " "; cout << endl;
#define debug_vp(x) cerr << #x << " "; for (auto ii : x) cout << '[' << ii.ff << " " << ii.ss << ']'; cout << endl;
#define mp make_pair

#define Return cerr<<endl<<"RUNTIME: "<<1.0*clock()/CLOCKS_PER_SEC << " s" <<endl; return 0;

#define PI 3.14159265

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }
ll fac(ll a) { return (a ? a * fac(a - 1) : 1); }

template<typename T> inline T getint() {
	T val = 0;
	char c;

	bool neg = false;
	while ((c = getchar()) && !(c >= '0' && c <= '9')) {
		neg |= c == '-';
	}

	do {
		val = (val * 10) + c - '0';
	} while ((c = getchar()) && (c >= '0' && c <= '9'));

	return val * (neg ? -1 : 1);
}

/////////////////////
//#define int long long
int Mod = 1e9 + 7;
#define endl '\n'
/////////////////////

ll inf = 2e18;

pair<ll, ll> Null = { -inf, -inf };
struct Tree {
	int n = 1;
	int t = 0;
	vector<ll> tree;
	vector<pair<ll, ll>> tset;
	vector<pair<ll, ll>> tadd;
	Tree(int N) {
		while (n < N) n *= 2;
		tree.assign(2 * n, 0);
		tset.assign(2 * n, Null);
		tadd.assign(2 * n, Null);
	}
	Tree(vector<int>& A) {
		while (n < A.size()) n *= 2;
		tree.assign(2 * n, 0);
		tset.assign(2 * n, Null);
		tadd.assign(2 * n, Null);
		for (int i = n; i < n + A.size(); ++i) {
			tree[i] = A[i - n];
		}
		for (int i = n - 1; i >= 1; --i) {
			tree[i] = tree[i * 2] + tree[i * 2 + 1];
		}
	}

	void Push(int l, int r, int x) {
		if (tset[x] != Null) {
			tree[x] = tset[x].ff * (r - l + 1);
			if (x < n) {
				int a = x * 2;
				if (tset[a].ss < tset[x].ss) {
					tset[a] = tset[x];
				}

				a = x * 2 + 1;
				if (tset[a].ss < tset[x].ss) {
					tset[a] = tset[x];
				}
			}
		}
		if (tadd[x] != Null && tadd[x].ss > tset[x].ss) {
			tree[x] += tadd[x].ff * (r - l + 1);
			if (x < n) {
				int a = x * 2;
				if (tadd[a] == Null) {
					tadd[a] = tadd[x];
				}
				else if (tadd[a].ss < tset[a].ss) {
					tadd[a] = tadd[x];
				}
				else {
					tadd[a].ff += tadd[x].ff;
				}
				a = x * 2 + 1;
				if (tadd[a] == Null) {
					tadd[a] = tadd[x];
				}
				else if (tadd[a].ss < tset[a].ss) {
					tadd[a] = tadd[x];
				}
				else {
					tadd[a].ff += tadd[x].ff;
				}
			}
		}
		tset[x] = Null;
		tadd[x] = Null;
	}
	ll GetT(int tl, int tr, int x, int l, int r) {
		if (tr < l || tl > r) {
			Push(tl, tr, x);
			return 0;
		}
		if (l <= tl && tr <= r) {
			Push(tl, tr, x);
			return tree[x];
		}
		Push(tl, tr, x);
		int tm = (tl + tr) / 2;
		ll ans = GetT(tl, tm, x * 2, l, r) + GetT(tm + 1, tr, x * 2 + 1, l, r);
		return ans;
	}

	inline ll Get(int l, int r) {
		++t;
		return GetT(0, n - 1, 1, l, r);
	}
	inline ll Get(int pos) {
		++t;
		return GetT(0, n - 1, 1, pos, pos);
	}


	void SetT(int tl, int tr, int x, int l, int r, int v) {
		if (tr < l || tl > r) {
			Push(tl, tr, x);
			return;
		}
		if (l <= tl && tr <= r) {
			tset[x] = {v, t};
			tadd[x] = Null;
			Push(tl, tr, x);
			return;
		}
		Push(tl, tr, x);
		int tm = (tl + tr) / 2;
		SetT(tl, tm, x * 2, l, r, v); 
		SetT(tm + 1, tr, x * 2 + 1, l, r, v);
		tree[x] = tree[x * 2] + tree[x * 2 + 1];
		return;
	}

	inline void Set(int l, int r, int v) {
		++t;
		return SetT(0, n - 1, 1, l, r, v);
	}
	inline void Set(int pos, int v) {
		++t;
		return SetT(0, n - 1, 1, pos, pos, v);
	}

	void AddT(int tl, int tr, int x, int l, int r, int v) {
		if (tr < l || tl > r) {
			Push(tl, tr, x);
			return;
		}
		if (l <= tl && tr <= r) {
			if (tadd[x] == Null) {
				tadd[x] = { v, t };
			}
			else if (tadd[x].ss < tset[x].ss) {
				tadd[x] = { v, t };
			}
			else {
				tadd[x].ff += v;
			}
			Push(tl, tr, x);
			return;
		}
		Push(tl, tr, x);
		int tm = (tl + tr) / 2;
		AddT(tl, tm, x * 2, l, r, v);
		AddT(tm + 1, tr, x * 2 + 1, l, r, v);
		tree[x] = tree[x * 2] + tree[x * 2 + 1];
		return;
	}

	inline void Add(int l, int r, int v) {
		++t;
		return AddT(0, n - 1, 1, l, r, v);
	}
	inline void Add(int pos, int v) {
		++t;
		return AddT(0, n - 1, 1, pos, pos, v);
	}

};
int32_t main() {
	boostIO();
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q; 
	n = getint<int>();
	q = getint<int>();
	vector<int> A(n);
	fori(n) {
		A[i] = getint<int>();
	}
	Tree T(A);
	while (q--) {
		int t = getint<int>();
		int l = getint<int>();
		int r = getint<int>();
		l--; r--;
		if (t == 1) {
			int v = getint<int>();
			T.Add(l, r, v);
		}
		else if (t == 2) {
			int v = getint<int>();
			T.Set(l, r, v);
		}
		else {
			cout << T.Get(l, r) << endl;
		}
	}
	return 0;
}