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
#include <chrono>
#include <random>
#include <complex>
using namespace std;

//#pragma comment(linker, "/stack:36777216")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline void boostIO() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
}

bool isPrime(int x) {
	if (x <= 4 || x % 2 == 0 || x % 3 == 0) return x == 2 || x == 3;
	for (int i = 5; i * i <= x; i += 6) if (x % i == 0 || x % (i + 2) == 0) return 0; return 1;
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
#define forx(n) for(int x = 0; x < (n); ++x)


#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ff first
#define ss second
#define debug(x) cerr << #x << " = " << x << endl;
#define debug_p(x) cerr << #x << " " << x.ff << " " << x.ss << endl;
#define debug_v(x) cerr << #x << " "; for (auto ii : x) cout << i << " "; cout << endl;
#define debug_vp(x) cerr << #x << " "; for (auto ii : x) cout << '[' << ii.ff << " " << ii.ss << ']'; cout << endl;
#define mp make_pair
#define rand kjsdflsdfsdlsjdlkfsdjflsjdfl 

#define Return cerr<<endl<<"RUNTIME: "<<1.0*clock()/CLOCKS_PER_SEC << " s" <<endl; return 0;

#define PI 3.14159265

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

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
#define int long long
int Mod = 1e9 + 7;
#define endl '\n'
/////////////////////

//int inf = 3e18+5;

const int Initial_Value = 0;
template<int m> struct decomp {
	struct Block {
		vector<int> a;
		int ans = Initial_Value;
		int addvalue = Initial_Value;
		int l, r;
		Block(vector<int>& V, int l, int r) : l(l), r(r) {
			for (int i = l; i <= r; ++i) {
				a.push_back(V[i]);
				ans += V[i];
			}
		};

		int get(int ql, int qr) {
			if (ql <= l && r <= qr) {
				return ans;
			}
			int ans2 = 0;
			for (int i = max(l, ql); i <= min(r, qr); ++i) {
				ans2 += a[i - l] + addvalue;
			}
			return ans2;
		}

		void upd(int ql, int qr, int v) {
			if (ql <= l && r <= qr) {
				ans += (r - l + 1) * v;
				addvalue += v;
				return;
			}
			for (int i = max(l, ql); i <= min(r, qr); ++i) {
				a[i - l] += v;
				ans += v;
			}
		}
	};
	vector<Block> A;

	decomp(vector<int>& V) {
		int i = 0;
		for (int k = 1; k <= 1e6; ++k) {
			if (i >= V.size()) break;
			int l = i;
			int r = min((int)V.size() - 1, k * m - 1);
			Block b(V, l, r);
			A.push_back(b);
			i = r + 1;
		}
	}


	int get(int ql, int qr) {
		int l = ql / m;
		int r = qr / m;
		int ans = 0;
		for (int i = l; i <= r; ++i) {
			ans += A[i].get(ql, qr);
		}
		return ans;
	}

	void upd(int ql, int qr, int v) {
		int l = ql / m;
		int r = qr / m;
		for (int i = l; i <= r; ++i) {
			A[i].upd(ql, qr, v);
		}
	}


};

int32_t main() {
	boostIO();
	int n, q; cin >> n >> q;
	vector<int> A(n);
	fori(n) {
		cin >> A[i];
	}

	decomp<150> D(A);
	fori(q) {
		int t; cin >> t;
		if (t == 1) {
			int l, r, v; cin >> l >> r >> v;
			--l; --r;
			D.upd(l, r, v);
		}
		else {
			int l; cin >> l;
			--l;
			cout << D.get(l, l) << endl;
		}
	}
	Return;
}