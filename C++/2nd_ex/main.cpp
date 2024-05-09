#include <iostream>
#include <string>

using namespace std;

bool isMatch(string &s, string &p, int s_pos = 0, int p_pos = 0) {
  if (p_pos == p.size())
    return s_pos == s.size();

  if (p[p_pos] == '*')
    return (s_pos < s.size() && isMatch(s, p, s_pos + 1, p_pos)) ||
           isMatch(s, p, s_pos, p_pos + 1);
  else if (s_pos < s.size() && (p[p_pos] == '?' || s[s_pos] == p[p_pos]))
    return isMatch(s, p, s_pos + 1, p_pos + 1);

  return false;
}

int main() {
  string s, p;
  cin >> s >> p;
  cout << (isMatch(s, p) ? "true" : "false") << endl;

  return 0;
}
