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
	cout << fixed << setprecision(15);
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
//#define int long long
int Mod = 1e9 + 7;
#define endl '\n'
/////////////////////

//int inf = 3e18+5;

//<--------------------------------------------------------->
//<--------------------------------------------------------->
//<--------------------------------------------------------->
//GEOMETRY
long double eps = 1e-9;
#define pi 3.14159265358979323846

bool equal(ld a, ld b) { return abs(a - b) < eps; }
bool LESS(ld a, ld b) { return a < b - eps; }
bool lessorequal(ld a, ld b) { return a <= b + eps; }
#define less LESS
#define isnormal NORMAL

struct point;
struct jump;
struct isnormal;
struct line;
struct ray;
struct segment;
struct circle;

jump normalize(jump j);
bool intersect(line l1, line l2);
ld distance(point p1, point p2);
ld distance(line l, point p);
ld distance(point p, line l);

struct point {
	point() {};
	ld x, y, angle;
	point(ld x, ld y);
	point(line l);
	point(point p, line l);
	point(line l, point p);
};

struct jump { //really it is a vector lol
	jump() {};
	ld X, Y, angle, len;
	jump(point p1, point p2);
	jump(ld X, ld Y);
	jump(isnormal n);
	jump(line l);
};

struct isnormal { //really it is a vector too lol
	isnormal() {};
	ld X, Y, angle, len;
	isnormal(ld X, ld Y);
	isnormal(point p1, point p2);
	isnormal(jump j);
	isnormal(line l);
};

struct line {
	line() {};
	ld a, b, c;
	point p;
	line(point p1, point p2);
	line(point p1, jump j);
	line(jump j, point p1);
	line(isnormal n, point p);
	line(point p, isnormal n);
	line(line l, point p);
	line(point p, line l);
	line(ld a, ld b, ld c) : a(a), b(b), c(c) {}
};


struct ray {
	ray() {};
	ld x, y, a, b, c;
	point p;
	jump j;
	line l;
	ray(point p1, point p2);
	ray(point p1, jump j);
	ray(jump j, point p1);
};

struct segment {
	segment() {};
	point p1, p2;
	line l;
	ld x1, y1, x2, y2, a, b, c;
	segment(point p1, point p2);
	segment(point p1, jump j);
	segment(jump j, point p1);
};

struct circle {
	circle() {};
	point p;
	ld radius;
	circle(point p, ld radius);
	circle(ld radius, point p);
};
struct CONFLUX {
	bool consumed = 0;
	point p[2];
	int size = 0;
	CONFLUX() {};
	CONFLUX(bool consumed) : consumed(consumed) {};
	CONFLUX(vector<point> v) : consumed(consumed) {
		fori(v.size()) {
			p[i] = v[i];
			++size;
		}
	};
	CONFLUX(point p1) {
		p[0] = p1;
		size = 1;
	}
	CONFLUX(point p1, point p2) {
		p[0] = p1;
		p[1] = p2;
		size = 2;
	}
} conflux;



bool equal(point p1, point p2) { return equal(p1.x, p2.x) * equal(p1.y, p2.y); }

point operator + (point p, jump j) { return point(p.x + j.X, p.y + j.Y); }
point operator + (jump j, point p) { return point(p.x + j.X, p.y + j.Y); }
point operator + (point p1, point p2) { return point(p1.x + p2.x, p1.y + p2.y); }
jump operator + (jump j1, jump j2) { return jump(j1.X + j2.X, j1.Y + j2.Y); }
point operator - (point p, jump j) { return point(p.x - j.X, p.y - j.Y); }
point operator - (jump j, point p) { return point(p.x - j.X, p.y - j.Y); }
point operator - (point p1, point p2) { return point(p1.x - p2.x, p1.y - p2.y); }
jump operator - (jump j1, jump j2) { return jump(j1.X - j2.X, j1.Y - j2.Y); }
jump operator * (jump j, ld v) { return jump(j.X * v, j.Y * v); }
jump operator * (ld v, jump j) { return jump(j.X * v, j.Y * v); }

ostream& operator<<(ostream& output, const point& p) {
	output << p.x << " " << p.y;
	return output;
}

istream& operator>>(istream& input, point& p) {
	input >> p.x >> p.y;
	return input;
}

//struct point
point::point(ld x, ld y) : x(x), y(y) {
	angle = atan2(y, x);
	if (angle < 0) angle = angle + 2 * pi; //[0, 2pi) without this line [-pi, pi)
};
point::point(line l) {
	if (equal(l.b, 0)) {
		x = -l.c / l.a;
		y = -10;
	}
	else if (equal(l.a, 0)) {
		x = -10;
		y = -l.c / l.b;
	}
	else {
		x = 10;
		y = (-10 * l.a - l.c) / l.b;
	}
}
point::point(point p, line l) {
	line l2(-l.b, l.a, l.b * p.x - l.a * p.y);
	intersect(l, l2);
	x = conflux.p[0].x;
	y = conflux.p[0].y;
	angle = atan2(y, x);
	if (angle < 0) angle = angle + 2 * pi; //[0, 2pi) without this line [-pi, pi)
}
point::point(line l, point p) {
	line l2(-l.b, l.a, l.b * p.x - l.a * p.y);
	intersect(l, l2);
	x = conflux.p[0].x;
	y = conflux.p[0].y;
	angle = atan2(y, x);
	if (angle < 0) angle = angle + 2 * pi; //[0, 2pi) without this line [-pi, pi)
}

//struct jump
jump::jump(point p1, point p2) {
	X = p2.x - p1.x;
	Y = p2.y - p1.y;
	angle = atan2(Y, X);
	if (angle < 0) angle = angle + 2 * pi; //[0, 2pi) without this line [-pi, pi)
	len = sqrt(X * X + Y * Y);
}
jump::jump(ld X, ld Y) : X(X), Y(Y) {
	angle = atan2(Y, X);
	if (angle < 0) angle = angle + 2 * pi; //[0, 2pi) without this line [-pi, pi)
	len = sqrt(X * X + Y * Y);
};

jump::jump(isnormal n) {
	X = n.X;
	Y = n.Y;
	angle = n.angle;
	len = n.len;
}
jump::jump(line l) {
	X = -l.b;
	Y = l.a;
	angle = atan2(Y, X);
	if (angle < 0) angle = angle + 2 * pi; //[0, 2pi) without this line [-pi, pi)
	len = sqrt(X * X + Y * Y);
}

//struct isnormal
isnormal::isnormal(ld X, ld Y) : X(X), Y(Y) {
	angle = atan2(Y, X);
	if (angle < 0) angle = angle + 2 * pi; //[0, 2pi) without this line [-pi, pi)
	len = sqrt(X * X + Y * Y);
};
isnormal::isnormal(point p1, point p2) {
	X = p2.x - p1.x;
	Y = p2.y - p1.y;
	angle = atan2(Y, X);
	if (angle < 0) angle = angle + 2 * pi; //[0, 2pi) without this line [-pi, pi)
	len = sqrt(X * X + Y * Y);
}
isnormal::isnormal(jump j) {
	X = j.X;
	Y = j.Y;
	angle = j.angle;
	len = j.len;
}
isnormal::isnormal(line l) {
	X = l.a;
	Y = l.b;
	angle = atan2(Y, X);
	if (angle < 0) angle = angle + 2 * pi; //[0, 2pi) without this line [-pi, pi)
	len = sqrt(X * X + Y * Y);
}

//struct line
line::line(point p1, point p2) {
	a = (p1.y - p2.y);
	b = (p2.x - p1.x);
	c = (p1.x * p2.y - p2.x * p1.y);
}
line::line(point p1, jump j) {
	point p2(p1 + j);
	a = (p1.y - p2.y);
	b = (p2.x - p1.x);
	c = (p1.x * p2.y - p2.x * p1.y);
}
line::line(jump j, point p1) {
	point p2(p1 + j);
	a = (p1.y - p2.y);
	b = (p2.x - p1.x);
	c = (p1.x * p2.y - p2.x * p1.y);
}
line::line(isnormal n, point p) {
	a = n.X;
	b = n.Y;
	c = -p.x * n.X - p.y * n.Y;
}
line::line(point p, isnormal n) {
	a = n.X;
	b = n.Y;
	c = -p.x * n.X - p.y * n.Y;
}
line::line(line l, point p) {
	jump j(l);
	l = line(p, j);
	a = l.a;
	b = l.b;
	c = l.c;
}
line::line(point p, line l) {
	jump j(l);
	l = line(p, j);
	a = l.a;
	b = l.b;
	c = l.c;
}


//struct ray
ray::ray(point p1, point p2) {
	p = p1;
	j = jump(p1, p2);
	l = line(p1, p2);
}
ray::ray(point p1, jump j) {
	point p2(p1.x + j.X, p1.y + j.Y);
	p = p1;
	j = jump(p1, p2);
	l = line(p1, p2);
}
ray::ray(jump j, point p1) {
	point p2(p1.x + j.X, p1.y + j.Y);
	p = p1;
	j = jump(p1, p2);
	l = line(p1, p2);
}

//struct segment
segment::segment(point p1, point p2) : p1(p1), p2(p2) {
	l = line(p1, p2);
}
segment::segment(point p1, jump j) : p1(p1) {
	point p2(p1.x + j.X, p1.y + j.Y);
	l = line(p1, p2);
}
segment::segment(jump j, point p1) : p1(p1) {
	point p2(p1.x + j.X, p1.y + j.Y);
	l = line(p1, p2);
}

circle::circle(point p, ld radius) : p(p), radius(radius) {};
circle::circle(ld radius, point p) : p(p), radius(radius) {};


vector<point> Point;
vector<jump> Jump;
vector<line> Line;
vector<ray> Ray;
vector<segment> Segment;
vector<circle> Circle;

void add_circle(int g, point p, ld radius) {
	if (g >= Circle.size()) Circle.resize(g + 1);
	Circle[g] = circle(p, radius);
}
void add_circle(int g, ld radius, point p) {
	if (g >= Circle.size()) Circle.resize(g + 1);
	Circle[g] = circle(p, radius);
}
void add_circle(int g, circle c) {
	if (g >= Circle.size()) Circle.resize(g + 1);
	Circle[g] = c;
}
void input_circle_point_radius(int g) {
	point p; cin >> p;
	ld radius; cin >> radius;
	add_circle(g, p, radius);
}
void input_circle_radius_point(int g) {
	ld radius; cin >> radius;
	point p; cin >> p;
	add_circle(g, p, radius);
}
void input_circle_point_radius_int(int g) {
	int x, y; cin >> x >> y;
	int radius; cin >> radius;
	add_circle(g, point(x, y), radius);
}
void input_circle_radius_point_int(int g) {
	int radius; cin >> radius;
	int x, y; cin >> x >> y;
	add_circle(g, point(x, y), radius);
}

void add_segment(int g, segment s) {
	if (g >= Segment.size()) Segment.resize(g + 1);
	Segment[g] = s;
}
void add_segment(int g, point p1, point p2) {
	if (g >= Segment.size()) Segment.resize(g + 1);
	Segment[g] = segment(p1, p2);
}
void input_segment(int g) {
	ld a, b, c, d; cin >> a >> b >> c >> d;
	add_segment(g, point(a, b), point(c, d));
}
void input_segment_int(int g) {
	int a, b, c, d; cin >> a >> b >> c >> d;
	add_segment(g, point(a, b), point(c, d));
}

void add_ray(int g, point p, jump j) {
	if (g >= Ray.size()) Ray.resize(g + 1);
	Ray[g] = ray(p, j);
}
void add_ray(int g, jump j, point p) {
	if (g >= Ray.size()) Ray.resize(g + 1);
	Ray[g] = ray(p, j);
}
void add_ray(int g, ray r) {
	if (g >= Ray.size()) Ray.resize(g + 1);
	Ray[g] = r;
}
void add_ray(int g, point p1, point p2) {
	if (g >= Ray.size()) Ray.resize(g + 1);
	Ray[g] = ray(p1, p2);
}
void input_ray_point_jump(int g) {
	ld a, b, c, d; cin >> a >> b >> c >> d;
	add_ray(g, point(a, b), jump(c, d));
}
void input_ray_point_jump_int(int g) {
	int a, b, c, d; cin >> a >> b >> c >> d;
	add_ray(g, point(a, b), jump(c, d));
}
void input_ray_point_point(int g) {
	ld a, b, c, d; cin >> a >> b >> c >> d;
	add_ray(g, point(a, b), point(c, d));
}
void input_ray_point_point_int(int g) {
	int a, b, c, d; cin >> a >> b >> c >> d;
	add_ray(g, point(a, b), point(c, d));
}

void add_line(int g, line l) {
	if (g >= Line.size()) Line.resize(g + 1);
	Line[g] = l;
}
void add_line(int g, ld a, ld b, ld c) {
	if (g >= Line.size()) Line.resize(g + 1);
	Line[g] = line(a, b, c);
}
void add_line(int g, point p1, point p2) {
	if (g >= Line.size()) Line.resize(g + 1);
	Line[g] = line(p1, p2);
}
void input_line(int g) {
	ld a, b, c; cin >> a >> b >> c;
	add_line(g, a, b, c);
}
void input_line_int(int g) {
	int a, b, c; cin >> a >> b >> c;
	add_line(g, a, b, c);
}

void add_jump(int g, jump j) {
	if (g >= Jump.size()) Jump.resize(g + 1);
	Jump[g] = j;
}
void add_jump(int g, point p1, point p2) {
	if (g >= Jump.size()) Jump.resize(g + 1);
	Jump[g] = jump(p1, p2);
}
void add_jump(int g, ld x, ld y) {
	if (g >= Jump.size()) Jump.resize(g + 1);
	Jump[g] = jump(x, y);
}
void input_jump(int g) {
	ld x, y; cin >> x >> y;
	add_jump(g, x, y);
}
void input_jump_int(int g) {
	int x, y; cin >> x >> y;
	add_jump(g, (ld)x, (ld)y);
}

void add_point(int g, ld x, ld y) {
	if (g >= Point.size()) Point.resize(g + 1);
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

jump normalize(jump a) {
	jump b(a.X / a.len, a.Y / a.len);
	return b;
}
ld vc(jump a, jump b) {
	return a.X * b.Y - a.Y * b.X;
}
ld sc(jump a, jump b) {
	return a.X * b.X + a.Y * b.Y;
}

jump rotate_counter_clockwise(jump j, ld angle) {
	return jump(j.X * cos(angle) - j.Y * sin(angle), j.X * sin(angle) + j.Y * cos(angle));
}
jump rotate_counter_clockwise(ld angle, jump j) {
	return jump(j.X * cos(angle) - j.Y * sin(angle), j.X * sin(angle) + j.Y * cos(angle));
}

jump rotate_clockwise(jump j, ld angle) {
	angle = -angle;
	return jump(j.X * cos(angle) - j.Y * sin(angle), j.X * sin(angle) + j.Y * cos(angle));
}
jump rotate_clockwise(ld angle, jump j) {
	angle = -angle;
	return jump(j.X * cos(angle) - j.Y * sin(angle), j.X * sin(angle) + j.Y * cos(angle));
}

ray bisector(int i, int i1, int i2) {
	point p = Point[i];
	point p1 = Point[i1];
	point p2 = Point[i2];
	jump j1(p, p1);
	jump j2(p, p2);
	j1 = normalize(j1);
	j2 = normalize(j2);
	p1 = p + j1;
	p2 = p + j2;
	point pmid((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
	return ray(p, pmid);
}
ray bisector(point p, point p1, point p2) {
	jump j1(p, p1);
	jump j2(p, p2);
	j1 = normalize(j1);
	j2 = normalize(j2);
	p1 = p + j1;
	p2 = p + j2;
	point pmid((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
	return ray(p, pmid);
}
ray bisector(point p, jump j1, jump j2) {
	j1 = normalize(j1);
	j2 = normalize(j2);
	point p1 = p + j1;
	point p2 = p + j2;
	point pmid((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
	return ray(p, p);
}


ld angle(jump a, jump b) { //may be piece of shit
	ld big, small;
	big = max(a.angle, b.angle);
	small = min(a.angle, b.angle);
	ld ans = min(big - small, small + 2 * pi - big);
	if (ans < 0) ans = 0;
	if (ans > 2 * pi) ans = 2 * pi;
	return ans;
}

ld area(vector<int>& A) {
	int n = A.size();
	ld area = 0;
	vector<jump> V;
	for (int i = 1; i < n; ++i) {
		V.push_back(jump(Point[A[0]], Point[A[i]]));
	}
	//auto cmp = [](const jump& a, const jump& b) { return a.angle < b.angle; };
	//sort(all(V), cmp);
	for (int i = 0; i < (int)V.size() - 1; ++i) {
		area += vc(V[i], V[i + 1]);
	}
	return fabs(area) / 2;
}

ld area(point p1, point p2, point p3) {
	vector<point> p = { p1, p2, p3 };
	int n = p.size();
	ld area = 0;
	vector<jump> V;
	for (int i = 1; i < n; ++i) {
		V.push_back(jump(p[0], p[i]));
	}
	//auto cmp = [](const jump& a, const jump& b) { return a.angle < b.angle; };
	//sort(all(V), cmp);
	for (int i = 0; i < (int)V.size() - 1; ++i) {
		area += vc(V[i], V[i + 1]);
	}
	return fabs(area) / 2;
}

ld area(point p1, point p2, point p3, point p4) {
	vector<point> p = { p1, p2, p3, p4 };
	int n = p.size();
	ld area = 0;
	vector<jump> V;
	for (int i = 1; i < n; ++i) {
		V.push_back(jump(p[0], p[i]));
	}
	//auto cmp = [](const jump& a, const jump& b) { return a.angle < b.angle; };
	//sort(all(V), cmp);
	for (int i = 0; i < (int)V.size() - 1; ++i) {
		area += vc(V[i], V[i + 1]);
	}
	return fabs(area) / 2;
}


bool intersect(point p1, point p2) {
	if (equal(p1.x, p2.x) && equal(p1.y, p2.y)) return 1;
	else return 0;
}

bool intersect(line l1, line l2) {
	if (equal(l1.a, l2.a) && equal(l1.b, l2.b)) {
		conflux = CONFLUX(1);
		return 1;
	}
	ld y = (l2.c * l1.a - l2.a * l1.c) / (l2.a * l1.b - l1.a * l2.b);
	ld x = (l1.b * l2.c - l2.b * l1.c) / (l2.b * l1.a - l2.a * l1.b);
	conflux = CONFLUX(point(x, y));
	return 1;
}

bool intersect(point p, line l) {
	if (equal(l.a * p.x + l.b * p.y + l.c, 0)) return 1;
	else return 0;
}

bool intersect(line l, point p) {
	if (equal(l.a * p.x + l.b * p.y + l.c, 0)) return 1;
	else return 0;
}

bool intersect(ray r, point p) {
	if (intersect(p, r.l) == 0) return 0;
	jump j(r.p, p);
	return !less(sc(r.j, j), 0);
}
bool intersect(point p, ray r) {
	if (intersect(p, r.l) == 0) return 0;
	jump j(r.p, p);
	return !less(sc(r.j, j), 0);
}

bool intersect(point p, segment s) {
	if (intersect(p, s.l) == 0) return 0;
	jump j(s.p1, s.p2);
	ld lx = min(s.p1.x, s.p2.x);
	ld rx = max(s.p1.x, s.p2.x);
	ld mx = p.x;

	ld ly = min(s.p1.y, s.p2.y);
	ld ry = max(s.p1.y, s.p2.y);
	ld my = p.y;

	return !less(rx, mx) && !less(mx, lx) && !less(ry, my) && !less(my, ly);
}
bool intersect(segment s, point p) {
	if (intersect(p, s.l) == 0) return 0;
	jump j(s.p1, s.p2);
	ld lx = min(s.p1.x, s.p2.x);
	ld rx = max(s.p1.x, s.p2.x);
	ld mx = p.x;

	ld ly = min(s.p1.y, s.p2.y);
	ld ry = max(s.p1.y, s.p2.y);
	ld my = p.y;

	return !less(rx, mx) && !less(mx, lx) && !less(ry, my) && !less(my, ly);
}


bool intersect(segment a, segment b) {
	line LA(a.p1, a.p2);
	line LB(b.p1, b.p2);

	point minA(min(a.p1.x, a.p2.x), min(a.p1.y, a.p2.y));
	point maxA(max(a.p1.x, a.p2.x), max(a.p1.y, a.p2.y));
	point minB(min(b.p1.x, b.p2.x), min(b.p1.y, b.p2.y));
	point maxB(max(b.p1.x, b.p2.x), max(b.p1.y, b.p2.y));

	jump vec13(a.p1, b.p1);
	jump vec12(a.p1, a.p2);
	jump vec14(a.p1, b.p2);

	jump vec31(b.p1, a.p1);
	jump vec34(b.p1, b.p2);
	jump vec32(b.p1, a.p2);
	bool ans = ((lessorequal(minA.x, maxB.x) && lessorequal(minA.y, maxB.y) && lessorequal(minB.x, maxA.x) && lessorequal(minB.y, maxA.y)) && (lessorequal(vc(vec13, vec12) * vc(vec14, vec12), 0)) && (lessorequal(vc(vec31, vec34) * vc(vec32, vec34), 0)));
	if (ans) intersect(a.l, b.l);
	return ans;
}

bool intersect(point p, circle c) {
	jump j(p, c.p);
	if (less(distance(p, c.p), c.radius)) {
		conflux = CONFLUX(0);
		return false;
	}
	if (equal(distance(p, c.p), c.radius)) {
		conflux = CONFLUX(p);
		return true;
	}
	ld len = sqrt(j.len * j.len - c.radius * c.radius);

	ld a = asin(c.radius / j.len);
	jump j1 = rotate_clockwise(j, a);
	jump j2 = rotate_counter_clockwise(j, a);
	
	j1 = normalize(j1);
	j2 = normalize(j2);
	
	j1 = j1 * len;
	j2 = j2 * len;

	point p1 = p + j1;
	point p2 = p + j2;
	conflux = CONFLUX(p1, p2);
	return false;
}

bool intersect(circle c, point p) {
	jump j(p, c.p);
	if (less(distance(p, c.p), c.radius)) {
		conflux = CONFLUX(0);
		return false;
	}
	if (equal(distance(p, c.p), c.radius)) {
		conflux = CONFLUX(p);
		return true;
	}
	ld len = sqrt(j.len * j.len - c.radius * c.radius);

	ld a = asin(c.radius / j.len);
	jump j1 = rotate_clockwise(j, a);
	jump j2 = rotate_counter_clockwise(j, a);

	j1 = normalize(j1);
	j2 = normalize(j2);

	j1 = j1 * len;
	j2 = j2 * len;

	point p1 = p + j1;
	point p2 = p + j2;
	conflux = CONFLUX(p1, p2);
	return false;
}

bool intersect(circle c, line l) {
	ld dist = distance(c.p, l);
	if (less(c.radius, dist)) {
		conflux = CONFLUX(0);
		return false;
	}
	else if (equal(c.radius, dist)) {
		point p(c.p, l);
		conflux = CONFLUX(p);
		return true;
	}
	point p(c.p, l);
	ld len = sqrt(c.radius * c.radius - dist * dist);
	jump j(l);
	j = normalize(j);
	j = j * len;
	point p1 = p + j;
	point p2 = p - j;

	conflux = CONFLUX(p1, p2);
	return true;
}

bool intersect(line l, circle c) {
	ld dist = distance(c.p, l);
	if (less(c.radius, dist)) {
		conflux = CONFLUX(0);
		return false;
	}
	else if (equal(c.radius, dist)) {
		point p(c.p, l);
		conflux = CONFLUX(p);
		return true;
	}
	point p(c.p, l);
	ld len = sqrt(c.radius * c.radius - dist * dist);
	jump j(l);
	j = normalize(j);
	j = j * len;
	point p1 = p + j;
	point p2 = p - j;

	conflux = CONFLUX(p1, p2);
	return true;
}

bool intersect(circle c1, circle c2) {
	if (equal(c1.p, c2.p) && equal(c1.radius, c2.radius)) {
		conflux = CONFLUX(1);
		return true;
	}
	line l(-2 * c1.p.x + 2 * c2.p.x, -2 * c1.p.y + 2 * c2.p.y, c1.p.x * c1.p.x - c2.p.x * c2.p.x + c1.p.y * c1.p.y - c2.p.y * c2.p.y - c1.radius * c1.radius + c2.radius * c2.radius);
	return intersect(l, c1);
}

ld distance(point p1, point p2) {
	if (intersect(p1, p2) == 1) return 0;
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
ld distance(point p, line l) {
	if (intersect(l, p) == 1) return 0;
	return (fabs(l.a * p.x + l.b * p.y + l.c) / sqrt(l.a * l.a + l.b * l.b));
}
ld distance(line l, point p) {
	if (intersect(l, p) == 1) return 0;
	return (fabs(l.a * p.x + l.b * p.y + l.c) / sqrt(l.a * l.a + l.b * l.b));
}

ld distance(ray r, point p) {
	if (intersect(r, p) == 1) return 0;
	jump j1(r.j);
	jump j2(p, r.p);
	if (less(angle(j1, j2), pi / 2))
		return distance(p, r.p);
	else return distance(p, r.l);
}

ld distance(point p, ray r) {
	if (intersect(r, p) == 1) return 0;
	jump j1(r.j);
	jump j2(r.p, p);
	if (less(angle(j1, j2), pi / 2))
		return distance(p, r.l);
	else return distance(p, r.p);
}

ld distance(point p, segment s) {
	if (intersect(s, p) == 1) return 0;
	jump j1(s.p1, s.p2);
	jump j2(s.p1, p);
	jump j3(s.p2, s.p1);
	jump j4(s.p2, p);
	if (less(angle(j1, j2), pi / 2) && less(angle(j3, j4), pi / 2))
		return distance(p, s.l);
	else return min(distance(p, s.p1), distance(p, s.p2));
}
ld distance(segment s, point p) {
	if (intersect(s, p) == 1) return 0;
	jump j1(s.p1, s.p2);
	jump j2(s.p1, p);
	jump j3(s.p2, s.p1);
	jump j4(s.p2, p);
	if (less(angle(j1, j2), pi / 2) && less(angle(j3, j4), pi / 2))
		return distance(p, s.l);
	else return min(distance(p, s.p1), distance(p, s.p2));
}
ld distance(segment s1, segment s2) {
	if (intersect(s1, s2)) return 0;
	return min({ distance(s1.p1, s2), distance(s1.p2, s2), distance(s2.p1, s1), distance(s2.p2, s1) });
}

int side(point p, line l) {
	if (intersect(p, l)) return 0;
	ld v = l.a * p.x + l.b * p.y + l.c;
	if (v < 0) return 1;
	else return 2;
}
int side(line l, point p) {
	if (intersect(p, l)) return 0;
	ld v = l.a * p.x + l.b * p.y + l.c;
	if (v < 0) return 1;
	else return 2;
}
//<--------------------------------------------------------->
//<--------------------------------------------------------->
//<--------------------------------------------------------->



int32_t main() {
	boostIO();
	//ALWAYS COPY DATA FROM CONFLUX AFTER DOING ANYTHING
	

	Return;
}