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
const ll mod = 998244353;
#define endl "\n"
//////////////////////

/*
https://codeforces.com/problemset/problem/2187/D
0) Последний член последовательности всегда имеет вид kx+y или kx
1) Сумма всех значений всегда имеет вид A*x + B*y
2) Cумма последовательности = abs(A)*(abs(A)+1)/2*x + y*(n - A)
3) если A = w*(w+1)/2

????
0000 4x
0010 0


1000 -3x



100
y y+x y+3x

x 3x  yxx

x 3x 6x


1) Если знаем K, (где a[n] = x*k + y+l)
то итоговая сумма членов массива: 
1) 
11:22
11:28 дочитал дано


0 x 2x 3x 4x y-4x 4x y-4x 4x 5x 6x 7x y-7x y-6x y-5x y-4x y-3x 3x 4x 5x 6x 7x 8x
0 y 0 y 0 y 0 y 0 y 0 y 0 y 0


11:54
x * y = 1e12

13:30
Дано: у меня есть 2 операции a[i] = a[i-1]+x и  a[i] = y - a[i-1]
Пусть sum = E(a[i])

Если мы смогли получить sum, пометим b[sum] = 1

Ответ - сумма всех sum, таких что b[sum] == 1

010101011101010?101010101????10101
0 это фиксированная операция "+x"
1 это "-y"
? это любая из них

1) Максимальное число a[n] = x*n
2) Минимальное число a[n] = y-x*(n-1)
3) Сумма это кол-во y всего + (кол-во X последнего-1) * (кол-во X последнего)/2
это дп, у которой есть 2 параметра: всего Y, и кол-во X у последнего.
4) 



X  X  X   X   Y    Y      Y     Y      X       X       X            Y        X       X       X        X      X   X  X
0 x 2x 3x  4x y-4x  4x   y-4x    4x     5x      6x      7x         y-7x     y-6x    y-5x     y-4x    y-3x   y-2x y-x  y
0 x 3x 6x 10x y+6x y+10x 2y+6x  2y+10x 2y+15x  2y+21x  2y+28x      3y+21x  4y+15x   5y+10x   6y+6x   7y+3x 8y+x 9y   10y
0


0 y  y+x  y+2x   y+3x   y+4x    y+5x   -5x    -4x  -3x   -2x    -1x 0 x 2x 3x 4x
0 y  2y+x 3y+3x  4y+6x  5y+10x  6y+15x 6y+10x 6y+6x 6y+3x  6y+x  6y 6y

Y Y  Y  Y  Y  Y  Y  Y 
0 y 0  y  0  y  0  y  0
y y 2y 2y 3y 3y 4y 4y


X  Y  X
x y-x y
x y  2y


X X Y
x 2x y-2x
x 3x y+x

0 0 0  0  0   0    1  0     0     1    0    1      1    1   0     0    0       0    1    1    1    1   
0 x 3x 6x 10x 15x 21x 15x   10x   15x  21x  15x   21x  15x   10x   6x   3x     x    3x   x    3x   x  

0 x 2x 3x 4x   5x  6x y-6x  y-5x   5x   6x  y-6x  6x   y-6x  y-5x  y-4x y-3x  y-2x  2x  y-2x  2x  y-2x


если 0, то можно либо x, либо в 0

если больше, то можно либо больше, либо меньше

0 x 3x 6x  3x   x     0    0   x
0 x 2x 3x y-3x y-2x  y-x   y  y+x

0 x 3x 6x  3x   x     0    0   0  0  0 x 3x
0 x 2x 3x y-3x y-2x  y-x   y   0  y  0 x 2x

0 0 0  0    1   0     0    0   1  1  1 1  0    0
0 x 3x 6x  3x   x     0    0   0  0  0 0  x   3x
0 x 2x 3x y-3x y-2x  y-x   y   0  y  0 y y+x y+2x




0 x 3x 6x  3x   x     0    x  

0 x 2x 3x y-3x y-2x  y-x   x


0 x 3x 6x  3x   x     0    0   0 ?

0 x 2x 3x y-3x y-2x  y-x   y   0  y 0

6x
3x
x
0
0
x
3x
6x


правда ли сколько y зависит от x?
Могу ли я прийти на одном и том же этапе к одному и тому же x, используя разное кол-во y?

0 3x 6x 3x  x   3x  6x 3x x
0 3x 6x 10x 15x 10x 6x 3x x
0  2  3  4   5   6  7  8  9
0  2  3  4   5   4  3  2  1

8
разница 8
это значит /4
0 3x 6x y-3x y-x 3x 6x y-3x y-x
0 3x 6x 10x 15x y-10x y-6x y-3x y-x


Окей, если я знаю кол-во X, я знаю кол-во Y
Типа сумма фиксированная
Посчитаем формулу



Типа мне нужно грубо говоря сделать следущее:
a) го попробуем прийти го всем возможным значениям конечных X
б) Посчитаем, сколько есть вариантов расставить  какие-то y так, чтобы мы пришли ровно к X
б) Для каждого варианта посчитаем, 

теперь мне нужно знать
для каждого Y i guess
!!!   разница между теоритическим максимумом и текущим/22 - определяет кол-во y  !!

окей, а знаю ли я кол-во разворотов?

Типа грубо говоря, если я знаю, сколько способов прийти к X
я победил
Мне без разницы на всё остальное



И тут получается не то что я считаю, сколько у меня вариантов
----------
задача свелась к 
получи массив чисел, какие возможные X можно получить


10011110001001110000

я иду по всем элементам

?0000000000000
-X  X
я не могу получить все между ними..





*/
void solve(int TT) {
int N, X, Y; cin >> N >> X >> Y;
string S; cin >> S;
int CENTER_R = N+2;
const int MAX_X = 2*N+5;
vector<vector<char>> dp(MAX_X, vector<char>(2));
dp[CENTER_R][0] = true;
fori(N) {
  vector<vector<char>> new_dp(MAX_X, vector<char>(2));
  for(int x = 0; x < MAX_X; ++x) {
    for(int direction = 0; direction <= 1; ++direction) {
      if(dp[x][direction] == 0) continue;
      int new_x = x+1;
      if(direction == 1)
        new_x = x-1;
      if(S[i] == '0' || S[i] == '?')
        maxnew(new_dp[new_x][direction], dp[x][direction]);
      if(S[i] == '1' || S[i] == '?')
        maxnew(new_dp[new_x^(x+1)^(x-1)][1-direction], dp[x][direction]);
      
    }
  }
  dp = new_dp;
} 
int max_possible_x = N;
int total_sum = 0;
set<int> Seen;
for(int i = 0; i < MAX_X; ++i) {
  int x;
  int y;
  x = i - CENTER_R;
  y = (max_possible_x - x)/2; 

  int of_center_x;
  if(i >= CENTER_R) {
    of_center_x = i - CENTER_R;
  }
  else {
    of_center_x = CENTER_R-1-i;
  }
  int sum = of_center_x * (of_center_x+1)/2*X + y *Y;
  if(dp[i][0] || dp[i][1]) {
    if(Seen.find(sum) == Seen.end()) {
      Seen.insert(sum);
      total_sum += sum;
      total_sum %= mod;
    }
  }
}
cout << total_sum << endl;


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





