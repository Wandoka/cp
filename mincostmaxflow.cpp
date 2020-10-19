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
//#define int long long
int Mod = 1e9 + 7;
#define endl '\n'
////////////////////

int inf = 2e9;

struct cords {
	int x = 0;
	int y = 0;
};

//struct comp {
	//bool operator()(My const& a, My const& b) const {
		//return a.x < b.x;
	//}
//};;

template<typename INT, const INT MAXIMUM_CAPACITY> struct MinCostMaxFlow {
	int s;//source
	int w; //node after sourse that connects every1
	int t;//sink
	int nodes;
	struct Edge {
		int from, to;
		INT flow, cap;
		ll cost;
		Edge(int from, int to, INT flow, INT cap, ll cost) : from(from), to(to), flow(flow), cap(cap), cost(cost) {};
	};

	ll ans_flow;
	ll ans_cost;
	bool UNDIRECTED = 0;
	//static const INT MAXIMUM_CAPACITY; // changes time complexity

	vector<Edge> E;

	void __addedge(int from, int to, INT cap, INT cost) {
		Edge e_normal(from, to, 0, cap, cost);
		E.push_back(e_normal);

		Edge e_backwards(to, from, cap, cap, -cost);
		E.push_back(e_backwards);
	}

	
	
	bool bf() {
		vector<ll> Cost(nodes, 9e18);
		vector<int> Prev(nodes);
		vector<INT> Flow(nodes, MAXIMUM_CAPACITY + 1);
		bool flag = 1;
		Cost[s] = 0;
		while (flag) {
			flag = 0;
			fori(E.size()) {
				int& from = E[i].from; int& to = E[i].to; INT& flow = E[i].flow; INT& cap = E[i].cap; ll& cost = E[i].cost;
				if (Cost[from] != 9e18 && Cost[from] + cost < Cost[to] && flow < cap) {
					flag = 1;
					Prev[to] = i;
					INT pushed = min(Flow[from], cap - flow);
					Flow[to] = pushed;
					Cost[to] = Cost[from] + cost;
				}
			}
		}
		if (Cost[t] == 9e18 || Flow[t] == 0) return false;

		int v = t;
		while (v != s) {
			int i = Prev[v];
			E[i].flow += Flow[t];
			E[i ^ 1].flow -= Flow[t];
			ans_cost += E[i].cost * Flow[t];
			v = E[i].from;
		}

		ans_flow = ans_flow + Flow[t];
		return true;
	}

	MinCostMaxFlow(int n) {
		s = n; w = n + 1; t = n + 2;
		nodes = n + 3;
		__addedge(s, w, MAXIMUM_CAPACITY, 0);
	}

	void go(){
		ans_flow = 0;
		ans_cost = 0;
		while (bf());
	}

	void wantedge(int from, int to, INT cap, ll cost) {
		__addedge(from, to, cap, cost);
		if (UNDIRECTED) __addedge(to, from, cap, cost);
	}

	void fromsource(int v, INT cap = MAXIMUM_CAPACITY, ll cost = 0) {
		__addedge(w, v, cap, cost);
	}
	void tosink(int v, INT cap = MAXIMUM_CAPACITY, ll cost = 0) {
		__addedge(v, t, cap, cost);
	}
};

int32_t main() {
	boostIO();
	//freopen("flow.in", "r", stdin);
	//freopen("flow.out", "w", stdout);
	int n, m; cin >> n >> m;

	const int mc = 1e8;
	MinCostMaxFlow<int, mc> f(n);
	f.UNDIRECTED = false;
	

	fori(m) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		a--;
		b--;
		f.wantedge(a, b, c, d);
	}

	int s, t; cin >> s >> t;
	s--; t--;
	f.fromsource(s);
	f.tosink(t);
	
	f.go();
	cerr << f.ans_flow << endl;
	cout << f.ans_cost << endl;
	return 0;
}