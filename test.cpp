#include "iostream"

using namespace std;

int main() {
  string s; cin >> s;

  int Last_X = -1e9; 
  int Last_Y = -1e9;
  int ans = 1e9;
  for(int i = 0; i < s.size(); ++i) {
    if(s[i] == 'X') {
      ans = min(ans, i - Last_Y);
      Last_X = i;
    }
    if(s[i] == 'Y') {
      ans = min(ans, i - Last_X);
      Last_Y = i;
    }
  }
  if(ans == 1e9) ans = -1;
  cout << ans << endl;
}
