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

struct fedge {
	int from, to, flow, cap, cost;
	fedge(int from, int to, int flow, int cap, int cost) : from(from), to(to), flow(flow), cap(cap), cost(cost) {};
};

struct edge {
	int a = 0;
	int b = 0;
	int w = 0;
	edge(int a, int b, int w) : a(a), b(b), w(w) {}
};;
struct find_apoints {
	int n = 0;
	int time = 0;
	vector<int> t;
	vector<int> fup;
	vector<vector<int>>& adj;
	vector<int> seen;
	vector<edge>& E;
	vector<int> IsApoint;
	vector<int> apoints;
	int start = 0;
	void dfs(int node) {
		++time;
		t[node] = time;
		fup[node] = time;
		int amount = 0;
		for (auto& e : adj[node]) {
			if (seen[e] == 1) continue;
			seen[e] = 1;
			int x = E[e].a;
			if (x == node) x = E[e].b;
			if (t[x] == 0) {
				++amount;
				dfs(x);
				fup[node] = min(fup[node], fup[x]);
				if (t[node] <= fup[x] && node != 0) {
					IsApoint[node] = 1;
				}
			}
			else {
				fup[node] = min(fup[node], t[x]);
			}
		}
		if (amount > 1 && node == start) {
			IsApoint[node] = 1;
		}
		
	}
	//articulation point
	find_apoints(vector<vector<int>>& in_adj, vector<edge>& in_E) : adj(in_adj), E(in_E) {
		n = adj.size();
		t.assign(n, 0);
		fup.assign(n, 0);
		seen.assign(E.size(), 0);
		IsApoint.assign(n, 0);
		fori(n) {
			if (t[i] == 0) {
				start = i;
				find_apoints::dfs(i);
			}
		}
		for (int i = 0; i < n; ++i) {
			if (IsApoint[i]) apoints.push_back(i);
		}
	}

};

int32_t main() {
	boostIO();
	freopen("points.in", "r", stdin);
	freopen("points.out", "w", stdout);
	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n);
	vector<edge> E;
	fori(m) {
		int a, b; cin >> a >> b;
		a--; b--;
		E.push_back({ a, b, 0 });
		adj[a].push_back(E.size() - 1);
		adj[b].push_back(E.size() - 1);
	}

	find_apoints f(adj, E);
	cout << f.apoints.size() << endl;
	for (auto x : f.apoints) {
		cout << x + 1 << " ";
	}
	return 0;
}