

#ifdef WANDOKA
  #define Assert(condition) assert(condition)
  #define debug(x) cerr << #x << " = " << x << endl;
  #define debug2(x,y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
  #define debug3(x,y,z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;
  #define debug_p(x) cerr << #x << " " << x.ff << " " << x.ss << endl;
  #define debug_v(x) cerr << #x << " "; for (auto ii : x) cerr << ii << " "; cerr << endl;
  #define debug_v2(x) cerr << "----" << #x << "----\n"; for(auto v : x) {for (auto ii : v) cerr << ii << " "; cerr << endl; } cerr << endl;
  #define debug_vk(x, k) cerr << #x << " "; for (int ii = 0; ii < k; ++ii) cerr << x[ii] << " "; cerr << endl;
  #define debug_vp(x) cerr << #x << " "; for (auto ii : x) cerr << '[' << ii.ff << " " << ii.ss << ']'; cerr << endl;
  #define debugnl() cerr << endl;
#else
  #define debug(x)
  #define debug2(x,y)
  #define debug3(x,y,z)
  #define debug_p(x)
  #define debug_v(x)
  #define debug_v2(x)
  #define debug_vp(x)
  #define debug_vk(x, k)
  #define debugnl()
  #define Assert(condition) ((void)0)
#endif

#include <bits/stdc++.h>

using namespace std;

#define PI 3.141592653589793238462643383279502884L
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long int ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> pii;

ll gen(ll x) { return rng() % x; }
ll gen(ll l, ll r) {
	ll sz = r - l + 1;
	return rng() % sz + l;
}
inline void boostIO() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
}

bool isPrime(int x) {
	if (x <= 4 || x % 2 == 0 || x % 3 == 0) return x == 2 || x == 3;
	for (int i = 5; i * i <= x; i += 6) if (x % i == 0 || x % (i + 2) == 0) return 0; return 1;
}

template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
	for (auto& x : v) os << x << " "; return os;
}
template <typename T> istream& operator>>(istream& is, vector<T>& vec) {
	for (auto& x : vec) is >> x; return is;
}

ll max(int a, ll b) { return a <= b ? b : a; } ll min(int a, ll b) { return a <= b ? a : b; }
template<typename A, typename B, typename C> bool lmr(A&& a, B&& b, C&& c) { return a <= b && b <= c; }
template<typename container> typename container::value_type getbegin(const container& cont) {
	if (cont.begin() != cont.end())   return *cont.begin();
	cerr << "Tried to dereference *x.begin() when x.size() == 0"; exit(1);
}

#define fori(n) for(int i = 0; i < (n); ++i)
#define forj(n) for(int j = 0; j < (n); ++j)
#define fork(n) for(int k = 0; k < (n); ++k)
#define forz(n) for(int z = 0; z < (n); ++z)
#define For(n,l,r) for(int n = l; n <= r; ++n)    
#define maxnew(a, n) a = max(a, n)
#define minnew(a, n) a = min(a, n)
#define sz(a) (int)a.size()

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define ff first
#define ss second
#define mp make_pair


/*
 pref_index_sum
 prev_sum 

 suf_index_sum
 suf_sum 


total_moves =  suf_index_sum - pref_index_sum
total_sum_change = suf_sum - pref_sum
 *
*/


ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(int a, int b) { return 1ll * a * b / gcd(a, b); }

ld ELAPSED_TIME() { return 1.0 * clock() / CLOCKS_PER_SEC; }

#define OR(a, b)  ((a) | (b))
#define AND(a, b) ((a) & (b))
#define XOR(a, b) ((a) ^ (b))
#define BIT(a) (1ll << (a))
#define HASBIT(a, b) ((a) & (1ll << (b)))

ll BITCOUNT(ll n) {
	ll count = 0;
	while (n) {
		count += n & 1ll;
		n >>= 1ll;
	}
	return count;
}

///////////////////////
#define int long long
const ll inf = 3e18 + 5;
//const int inf = 1e9 + 5;	
const ll mod = 1e9+7;
//#define endl "\n"
//////////////////////

/*
1) Если спросили про k чисел, и ответ%2!=k%2 - то среди них есть тройка

окей, скажем я каждый раз спрашиваю случайную половину
какая вероятность того, что я попаду

всего 20 чисел

спрашиваю про первые 10

если каждой тваре по паре - ответ 0
если у меня есть [3] + [2]*3 + [1] - ответ 1
если у меня [1]*2 + [2]*4 - ответ 2

могу ли я тут получить нечётный ответ?

окей, если я спрашиваю про 11 элементов

то тогда когда всех тварей по парам +1, ответ 1
ответ 3
или ответ 2, если у меня есть тройка


если у меня 1 пара, и у всех остальных нет - ответ 

*/
int deb = 1;
vector<int> A;
vector<int> H;
int counter = 0;
int ask(int k) {
  ++counter;
  cout << "? " << endl;
  cout << k << " ";
  fori(k) {
    cout << A[i] << " ";
  }
  cout << endl;
  int ans; 
  if(deb == 0) {
    cin >> ans;
  }
  else {
    map<int,int> Map;
    fori(k) {
      Map[H[A[i]-1]]++;
    }
    ans = 0;
    for(auto p : Map) {
      if(p.ss == 1) {
        ++ans;
      }
    }
  }
  return (ans %2 != k%2);
}
int ask(vector<int> a) {
  ++counter;
  cout << "? " << endl;
  cout << a.size() << " ";
  for(auto i : a) {
    cout << A[i] << " ";
  }
  cout << endl;
  int ans;   
  if(deb == 0) {
    cin >> ans;
  }
  else {
    map<int,int> Map;
    for(auto i : a) {
      Map[H[A[i]-1]]++;
    }
    ans = 0;
    for(auto p : Map) {
      if(p.ss == 1) {
        ++ans;
      }
    }
  }
  return (ans %2 != a.size()%2);
}
void output(vector<int> a) {
  cout << "! ";
  for(auto x :a) {
    cout << x << " ";
  }
  cout << endl;
  if(deb) {
    cout << "counter = " << counter << endl;
  }
}

void solve(int TT) {
  counter = 0;
  int n; cin >> n;
   
  n = 2*n+1;
  debug(n);
  if(deb == 1) {
    H.assign(n, 0);
    fori(n) {
      H[i] = i/2;
    }
    H[n-1] = H[n-2];
    int Last = H[n-1];
    shuffle(all(H), rng);
    cout << H << endl;
    cout << "correct answer: ";
    fori(n) {
      if(H[i] == Last) {
        cout << i+1 << " ";
      }
    }
    cout << endl;

  }
  A.assign(n, 0);
  fori(n) {
    A[i] = i+1;
  }
  set<vector<int>> Seen;
  vector<int> HasToBe;
  while(true) {
    shuffle(all(A), rng);
    vector<int> B;
    int sz;
    if(A.size() > 1000) {
      sz = max((A.size()*4)/5, 3);
    }
    else {
      sz = max((A.size()*6)/7, 3);
    }
    fori(sz) {
      B.push_back(A[i]);
    }
    int found_hasto = 0;
    for(auto b : B) {
      for(auto h : HasToBe) {
        if(b == h) ++found_hasto; 
      }
    }
    if(found_hasto != HasToBe.size()) {
      continue;
    }
    sort(all(B));
    if(Seen.find(B) != Seen.end()) {
      continue;
    }
    Seen.insert(B);
    if(ask(sz)) {
      int leftover = (int)(A.size()) - sz;
      fori(leftover) {
        A.pop_back();
      }
      if(A.size() == 3) {
        output(A);
        return;
      }
    }
    else {  
      int leftover = (int)(A.size()) - sz;
      if(leftover == 1) {
        HasToBe.push_back(A.back());
      }
    }
  }
}


int32_t main(int32_t argc, char* argv[]) {
  boostIO();
  if (argc > 1) {
    FILE *f = fopen(argv[1], "r");
    if (f != NULL) {
      freopen(argv[1], "r", stdin);
    }
  }
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
  //precalc();
	int TT = 1; cin >> TT;
	while (TT--) {
		solve(TT);
	}
  cout.flush();
}



/*
 Главные общие принципы
  a) Проще - лучше, стараться максимально упростить себе жизнь
  b) Не спешить, не экономить время.
  c) Быть всегда конкретным == эмулировать дейсвтия. Если я это не делаю == я не думаю

Рассуждение: 
  Способ:
  1) Делаю самые простые и очевидные действия.
  2) Когда натыкаюсь на проблему, прихожу к какому-то выводу.
     Вывод - это факт, которым можно дополнить дано. Какое-то "ограничение"
  3) Начинаю рассуждать с самого начала, учитывая этот новый факт

Реализация:
  a) Хорошие названия переменных
  б) Всегда думаю - потом пишу. Никогда нельзя "сначала написать, потом проверить правильно ли"
  c) Никогда не пишу один и тот же код дважды
  d) Не бросаться сразу писать решение, планировать код перед написанием
  e) Смотреть посылки других людей в поисках красивых фичей реализации

Трюки:
  a) Не понимаю дано - эмулирую его по действиям
  b) Стресс тестирование по необходимости
  с) Рисовать задачу

Как тренироваться
  a) Длительные перерывы помогают. Решать задачи каждый день - вредно
  б) Решать задачи макс сложности (2800 в моём случае), тратить не более 2х часов, потом смотреть разбор

Психология
  a) Уверенность, что я всё решу - очень помогает
  b) Рассказать своё решение кому-то другому
  c) Жевачка помогает от нервов.

Дополнительно, не оч полезно:
  a) Negative space идея. Думаю не только про факт, но ещё и про !факт
  b) Переключатся с задачи на задачу. Решать 2 задачи проще, чем решать одну
  c) Не нужно пытаться "ваншотнуть" или "добить" задачу. Нужно её "poke", "исследовать"
  d) Одновременно можно "исправлять" только 1 свою ошибку, на остальное головы не хватает. 
*/



