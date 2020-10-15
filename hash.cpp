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
//#define int long long
int Mod = 1e9 + 7;
#define endl '\n'
/////////////////////

ll inf = 2e18;


struct Hash {
	int pp[4] = {};
	int hh[4] = {};
	char SEENHASH = 0;
	int randpp[38] = { 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199 };
	int randhh[200] = { 950000017, 950000021, 950000047, 950000063, 950000071, 950000089, 950000101, 950000159, 950000167, 950000179, 950000231, 950000267, 950000297, 950000339, 950000347, 950000351, 950000353, 950000369, 950000407, 950000411, 950000417, 950000479, 950000483, 950000489, 950000497, 950000501, 950000503, 950000521, 950000573, 950000587, 950000599, 950000651, 950000659, 950000663, 950000699, 950000729, 950000747, 950000759, 950000761, 950000837, 950000899, 950000911, 950000917, 950000929, 950000941, 950000951, 950000959, 950000971, 950001047, 950001061, 950001071, 950001161, 950001167, 950001181, 950001187, 950001209, 950001263, 950001287, 950001289, 950001313, 950001323, 950001331, 950001337, 950001359, 950001379, 950001427, 950001431, 950001439, 950001443, 950001449, 950001461, 950001557, 950001581, 950001587, 950001589, 950001593, 950001641, 950001659, 950001671, 950001697, 950001713, 950001737, 950001757, 950001763, 950001791, 950001827, 950001863, 950001869, 950001883, 950001907, 950001947, 950001953, 950002043, 950002057, 950002069, 950002087, 950002091, 950002111, 950002159, 950002171, 950002199, 950002201, 950002243, 950002289, 950002301, 950002303, 950002309, 950002321, 950002331, 950002421, 950002423, 950002429, 950002531, 950002553, 950002567, 950002579, 950002609, 950002633, 950002637, 950002709, 950002747, 950002763, 950002783, 950002819, 950002847, 950002853, 950002883, 950002897, 950002927, 950002931, 950002987, 950003011, 950003023, 950003039, 950003069, 950003099, 950003101, 950003107, 950003137, 950003149, 950003183, 950003189, 950003213, 950003221, 950003261, 950003267, 950003291, 950003357, 950003387, 950003413, 950003437, 950003449, 950003473, 950003491, 950003507, 950003539, 950003557, 950003563, 950003567, 950003573, 950003581, 950003597, 950003599, 950003611, 950003617, 950003627, 950003647, 950003683, 950003689, 950003699, 950003713, 950003731, 950003737, 950003759, 950003797, 950003801, 950003827, 950003833, 950003849, 950003851, 950003863, 950003869, 950003939, 950003941, 950003987, 950004001, 950004019, 950004023, 950004037, 950004043, 950004073, 950004131, 950004137, 950004173, 950004191, 950004229, 950004233, 950004239, 950004241, 950004247 };

	int seenpp[38] = {};
	int seenhh[200] = {};

	int n;
	vector<int> P[2];
	vector<int> H[2];
	int p[2];
	int h[2];
	Hash(string s) {
		if (SEENHASH == 0) {
			SEENHASH = 1;
			forx(2) {
				int y = rng() % 38;
				if (seenpp[y] == 1) {
					--x;
					continue;
				}
				pp[x] = randpp[y];
				seenpp[y] = 1;
			}

			forx(2) {
				int y = rng() % 200;
				if (seenhh[y] == 1) {
					--x;
					continue;
				}
				hh[x] = randhh[y];
				seenhh[y] = 1;
			}
		}
		forx(2) {
			p[x] = pp[x];
			h[x] = hh[x];
		}
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


int32_t main() {
	boostIO();
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s; cin >> s;
	int n = s.size();
	Hash S(s);
	vector<map<pair<int, int>, int>> Map(5001);
	int q; cin >> q;
	while (q--) {
		string z; cin >> z;
		if (z.size() > 5000) continue;

		Hash Z(z);
		++Map[z.size()][Z.Get(0, z.size() - 1)];
	}
	vector<int> dp(n + 1);
	dp[0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			pair<int, int> hash = S.Get(i, j);
			if (Map[j - i + 1].find(hash) != Map[j - i + 1].end())
				dp[j + 1] = (dp[j + 1] + dp[i] * Map[j - i + 1][hash]) % Mod;
		}
	}
	cout << dp[n] << endl;
	Return;
}