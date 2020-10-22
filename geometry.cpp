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
//#define int long long
int Mod = 1e9 + 7;
#define endl '\n'
/////////////////////

//int inf = 3e18+5;

long double eps = 1e-7;

struct ld {
	ld() {};
	long double v;
	operator long double() { return v; }
	operator long double() const { return v; }
	bool operator == (ld a) {
		if (fabs(a.v - v) < eps) return true;
		else return false;
	}
	ld(long double x) : v(x) {};
	ld& operator = (long double a) {
		v = move(a);
		return *this;
	}
	ld& operator = (int a) {
		v = move(a);
		return *this;
	}
	ld& operator = (long long a) {
		v = move(a);
		return *this;
	}
	ld& operator += (long double a) {
		v = a + v;
		return *this;
	}
	ld& operator *= (long double a) {
		v = a * v;
		return *this;
	}
};

ostream& operator<<(ostream& output, const ld& a) {
	output << a.v;
	return output;
}

istream& operator>>(istream& input, ld& a) {
	input >> a.v;
	return input;
}

struct Geometry {
#define pi 3.14159265358979323846
	struct point {
		point() {};
		ld x, y;
		ld angle;
		ld radiusSQ;
		point(ld x, ld y) : x(x), y(y) {
			angle = atan2(y, x);
			if (angle < 0) angle = angle + 2 * pi; //[0, 2pi) without this line [-pi, pi)
			radiusSQ = x * x + y * y;
		};
	};
	struct jump { //really it is a vector lol
		jump() {};
		ld X, Y;
		ld angle;
		ld lenSQ;
		jump(point p1, point p2) {
			X = p2.x - p1.x;
			Y = p2.y - p1.y;
			angle = atan2(Y, X);
			if (angle < 0) angle = angle + 2 * pi; //[0, 2pi) without this line [-pi, pi)
			lenSQ = X * X + Y * Y;
		}
		jump(ld X, ld Y) : X(X), Y(Y) {
			angle = atan2(Y, X);
			if (angle < 0) angle = angle + 2 * pi; //[0, 2pi) without this line [-pi, pi)
			lenSQ = X * X + Y * Y;
		};
	};

	struct line {
		line() {};
		ld a, b, c;
		line(point p1, point p2) {
			a = (p1.y - p2.y);
			b = (p2.x - p1.x);
			c = (p1.x * p2.y - p2.x * p1.y);
		}
		line(ld a, ld b, ld c) : a(a), b(b), c(c) {}
	};

	struct ray {
		ray() {};
		ld x, y, X, Y, lenSQ, a, b, c, angle;
		ray(point p1, point p2) {
			x = p1.x;
			y = p1.y;
			X = p2.x - p1.x;
			Y = p2.y - p1.y;
			lenSQ = X * X + Y * Y;
			a = (p1.y - p2.y);
			b = (p2.x - p1.x);
			c = (p1.x * p2.y - p2.x * p1.y);
			angle = atan2(Y, X);
			if (angle < 0) angle = angle + 2 * pi; //[0, 2pi) without this line [-pi, pi)
		}

		ray(point p1, jump j) {
			point p2(p1.x + j.X, p1.y + j.Y);
			x = p1.x;
			y = p1.y;
			X = p2.x - p1.x;
			Y = p2.y - p1.y;
			lenSQ = X * X + Y * Y;
			a = (p1.y - p2.y);
			b = (p2.x - p1.x);
			c = (p1.x * p2.y - p2.x * p1.y);
			angle = atan2(Y, X);
			if (angle < 0) angle = angle + 2 * pi; //[0, 2pi) without this line [-pi, pi)
		}
	};

	struct segment {
		segment() {};
		ld x1, y1, x2, y2, a, b, c;
		segment(point p1, point p2) {
			x1 = p1.x;
			y1 = p1.y;
			x2 = p2.x;
			y2 = p2.y;
			a = (p1.y - p2.y);
			b = (p2.x - p1.x);
			c = (p1.x * p2.y - p2.x * p1.y);
		}
	};

	
	jump normalize(jump a) {
		jump b(a.X / sqrt(a.lenSQ), a.Y / sqrt(a.lenSQ));
		return b;
	}
	ld vc(jump a, jump b) {
		return a.X * b.Y - a.Y * b.X;
	}
	ld sc(jump a, jump b) {
		return a.X * b.X + a.Y * b.Y;
	}

	vector<point> Point;
	vector<jump> Jump;
	vector<line> Line;
	vector<ray> Ray;
	vector<segment> Segment;
	

	void add_point(int g, ld x, ld y) {
		Point[g] = point(x, y);
	}
	void input_point(int g) {
		ld x, y; cin >> x >> y;
		add_point(g, x, y);
	}

	void input_point_int(int g) {
		int x, y; cin >> x >> y;
		add_point(g, x, y);
	}

	ray bisector(point p, point p1, point p2) {
		jump j1(p, p1);
		jump j2(p, p2);
		j1 = normalize(j1);
		j2 = normalize(j2);
	}
	ray bisector(point p, jump j1, jump j2) {

	}

	void add_ray(int g, point p, jump j) {
		if (g >= Ray.size()) Ray.resize(g);
		Ray[g] = ray(p, j);
	}
	void add_ray(int g, ray r) {
		if (g >= Ray.size()) Ray.resize(g);
		Ray[g] = r;
	}

	void add_jump(int g, jump j) {
		if (g >= Jump.size()) Jump.resize(g);
		Jump[g] = j;
	}
	void add_jump(int g, point p1, point p2) {
		if (g >= Jump.size()) Jump.resize(g);
		Jump[g] = jump(p1, p2);
	}
	void add_jump(int g, int i1, int i2) {
		if (g >= Jump.size()) Jump.resize(g);
		Jump[g] = jump(Point[i1], Point[i2]);
	}

	void add_line(int g, line l) {
		if (g >= Line.size()) Line.resize(g);
		Line[g] = l;
	}
	void add_line(int g, ld a, ld b, ld c) {
		if (g >= Line.size()) Line.resize(g);
		Line[g] = line(a, b, c);
	}
	void add_line(int g, point p1, point p2) {
		if (g >= Line.size()) Line.resize(g);
		Line[g] = line(p1, p2);
	}
	void add_line(int g, int i1, int i2) {
		if (g >= Line.size()) Line.resize(g);
		Line[g] = line(Point[i1], Point[i2]);
	}

	ld angle(point a, point b) {
		ld big, small;
		big = max(a.angle, b.angle);
		small = min(a.angle, b.angle);
		return min(big - small, small + 2 * pi - big);
	}

	ld area(vector<int>& A) {
		int n = A.size();
		ld area = 0;
		vector<jump> V;
		for(int i = 1; i < n; ++i) {
			V.push_back(jump(Point[A[0]], Point[A[i]]));
		}
		//auto cmp = [](const jump& a, const jump& b) { return a.angle < b.angle; };
		//sort(all(V), cmp);
		for (int i = 0; i < (int)V.size() - 1; ++i) {
			area += vc(V[i], V[i+1]);
		}
		return fabs(area) / 2;
	}
};

int32_t main() {
	boostIO();
	//freopen("bisector.in", "r", stdin);
	//freopen("bisector.out", "w", stdout);
	Geometry G;
	for (int i = 1; i <= 3; ++i) {	
		G.input_point_int(i);
	}
	G.add_ray();
	

	cout << G.area(A) << endl;
	Return;
}