#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//#pragma comment(linker, "/stack:36777216")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")

ifstream fin("input.txt");
ofstream fout("output.txt");

bool isPrime(int x) {
	if (x <= 4 || x % 2 == 0 || x % 3 == 0) return x == 2 || x == 3;
	for (int i = 5; i * i <= x; i += 6) if (x % i == 0 || x % (i + 2) == 0) return 0; return 1;
}

int NumDigits(int x) {
	//x = abs(x);
	return (x < 10 ? 1 :
		(x < 100 ? 2 :
		(x < 1000 ? 3 :
			(x < 10000 ? 4 :
			(x < 100000 ? 5 :
				(x < 1000000 ? 6 :
				(x < 10000000 ? 7 :
					(x < 100000000 ? 8 :
					(x < 1000000000 ? 9 :
						10)))))))));
}

inline void boostIO() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
}

typedef long long int ll;
typedef long double ld;

#define fori(n)  for(int i = 0; i < (n); ++i)
#define forj(n)  for(int j = 0; j < (n); ++j)
#define fork(n) for(int k = 0; k < (n); ++k)
#define forx(n) for(int x = 0; x < (n); ++x)

#define LONG_LONG_MAX  9223372036854775807
#define LONG_LONG_MIN   -9223372036854775807
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))

#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
#define debug(x) cerr << #x << " = " << x << endl;
#define debug_p(x) cerr << #x << " " << x.ff << " " << x.ss << endl;
#define debug_v(x) cerr << #x << " "; for (auto ii : x) cout << i << " "; cout << endl;
#define debug_vp(x) cerr << #x << " "; for (auto ii : x) cout << '[' << ii.ff << " " << ii.ss << ']'; cout << endl;
#define mp make_pair

#define Return cerr<<endl<<"RUNTIME: "<<1.0*clock()/CLOCKS_PER_SEC << " s" <<endl; return 0;

#define PI 3.14159265

ll Pow10[19] = { (ll)1,(ll)1e1,(ll)1e2,(ll)1e3,(ll)1e4,(ll)1e5,(ll)1e6,(ll)1e7,(ll)1e8,(ll)1e9,(ll)1e10,
				(ll)1e11,(ll)1e12,(ll)1e13,(ll)1e14,(ll)1e15,(ll)1e16,(ll)1e17,(ll)1e18 };

//int mid = low + ((high - low) / 2);
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

/*
struct comp {
	bool operator()(Mine const & a, Mine const & b)const {
		return a.g >= b.g;
	}
};
set<Mine, comp> Set;
*/

//__builtin_clz(int); amount of 0 in the begining
//__builtin_ctz(int); amoint of 0 in the end
//__builtin_popcount(int); amount of 1

//memset(dp, -1, sizeof dp);

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

/*
template<typename T> T getint() {
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
*/

/////////////////////
#define int long long
int Mod = 1e9 + 7;
#define endl '\n'
////////////////////

int inf = 1e18;

int mul(int a, int b, int c = 1, int d = 1, int e = 1, int g = 1) {
	a %= Mod; b %= Mod; c %= Mod; d %= Mod; e %= Mod; g %= Mod;
	return (a * b % Mod * c % Mod * d % Mod * e % Mod * g % Mod);
}

int Pow(int a, int b) {
	if (b == 0)
		return 1;
	if (b % 2 == 0) {
		int x = Pow(a, b / 2);
		return mul(x, x);
	}
	else {
		int x = Pow(a, b / 2);
		return  mul(a, x, x);
	}
}

struct cords {
	int x = 0;
	int y = 0;
};

//struct comp {
	//bool operator()(My const& a, My const& b) const {
		//return a.x < b.x;
	//}
//};;

struct MaxFlow {
	int s;//source
	int w; //node after sourse that connects every1
	int t;//sink

	int nodes;
	struct Edge {
		int from, to, flow, cap;
		Edge(int from, int to, int flow, int cap) : from(from), to(to), flow(flow), cap(cap) {};
	};

	int ans;

	vector<Edge> E;
	vector<int> Level;
	vector<vector<int>> adj;
	vector<int> num;
	vector<int> Reachable;

	vector<int> Cut;
	void addedge(int from, int to, int cap) {
		Edge e_normal(from, to, 0, cap);
		E.push_back(e_normal);
		adj[from].push_back(E.size() - 1);

		Edge e_backwards(to, from, cap, cap);
		E.push_back(e_backwards);
		adj[to].push_back(E.size() - 1);
	}

	bool BuildLevels() {
		Level.assign(nodes, -1);
		queue<int> q;
		q.push(s);
		Level[s] = 0;
		while (q.size()) {
			int node = q.front();
			q.pop();
			for (auto i : adj[node]) {
				int& from = E[i].from; int& to = E[i].to; int& flow = E[i].flow; int& cap = E[i].cap;
				if (Level[to] == -1 && flow < cap) {
					q.push(to);
					Level[to] = Level[from] + 1;
				}
			}
		}
		if (Level[t] == -1) return false;
		return true;
	}

	int dfs(int node, int f) {
		if (!f) return 0;
		if (node == t) return f;
		for (num[node]; num[node] < adj[node].size(); ++num[node]) {
			int i = adj[node][num[node]];
			int& from = E[i].from; int& to = E[i].to; int& flow = E[i].flow; int& cap = E[i].cap;
			if (Level[from] + 1 != Level[to]) continue;

			int pushing = min(f, max(0ll, (cap - flow)));
			int pushed = dfs(to, pushing);
			if (pushed != 0) {
				E[i].flow += pushed;
				E[i ^ 1].flow -= pushed;
				return pushed;
			}
		}
		return 0;
	}

	//<-------------------->
	// FLOW STARTING VALUES
	//<-------------------->


	void FindReachable(int node) {
		Reachable[node] = 1;
		for (auto i : adj[node]) {
			if (i % 2 == 1) continue;
			int& from = E[i].from; int& to = E[i].to; int& flow = E[i].flow; int& cap = E[i].cap;
			if (cap - flow == 0) continue;
			if (Reachable[to] == 0) FindReachable(to);
		}
	}
	void FindCut() {
		FindReachable(s);
		for (int i = 0; i < E.size(); i += 2) {
			int& from = E[i].from; int& to = E[i].to; int& flow = E[i].flow; int& cap = E[i].cap;
			if (Reachable[from] && !Reachable[to]) {
				if (i % 4 == 2) {
					Cut.push_back(i - 2);
				}
				else {
					Cut.push_back(i);
				}
			}
		}
	}
	MaxFlow(int n, vector<int> From, vector<int> To, vector<int> Cap) {
		int m = From.size();

		s = n;
		w = n + 1;
		t = n + 2;
		nodes = n + 3;
		Reachable.assign(nodes, 0);
		vector<int> temp;
		adj.assign(nodes, temp);

		fori(m)
			addedge(From[i], To[i], Cap[i]);

		const int INITIAL_CAPACITY = inf;
		const int CAPACITY = inf;

		addedge(s, w, INITIAL_CAPACITY);


		//make connections w -> node
		addedge(w, 0, CAPACITY);
		fori(n) {
			//addedge(w, i, CAPACITY);
		}


		//make connections node -> t
		addedge(n - 1, t, CAPACITY);
		fori(n) {
			//addedge(i, t, CAPACITY);
		}

		ans = 0;
		while (BuildLevels()) {
			num.assign(nodes, 0);
			while (int f = dfs(s, inf)) {
				ans += f;
			}
		}

		FindCut();
	}



};

int32_t main() {
	boostIO();
	//freopen("flow.in", "r", stdin);
	//freopen("flow.out", "w", stdout);
	int n, m; cin >> n >> m;
	vector<int> From(0);
	vector<int> To(0);
	vector<int> Cap(0);
	From.reserve(m);
	To.reserve(m);
	Cap.reserve(m);

	fori(m) {
		int a, b, c; cin >> a >> b >> c;
		a--;
		b--;

		From.push_back(a);
		From.push_back(b);
		To.push_back(b);
		To.push_back(a);
		Cap.push_back(c);
		Cap.push_back(c);
	}

	MaxFlow f(n, From, To, Cap);

	cout << f.ans << endl;
	cout << f.Cut.size() << endl;
	for (auto e : f.Cut) {
		cout << f.E[e].from + 1 << " " << f.E[e].to + 1 << endl; 
	}
	return 0;
}