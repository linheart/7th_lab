#include <iostream>
#include <string>

using namespace std;

bool find_expression(int, int, int, int, string, string &);

int main() {
  int target;
  string result;

  cin >> target;

  if (find_expression(2, 1, 0, target, "", result))
    cout << result << endl;
  else
    cout << "No valid expressions found" << endl;
  return 0;
}

bool find_expression(int digit, int current_num, int total, int target,
                     string expression, string &result) {
  string current_number_str = to_string(current_num);

  if (digit > 9) {
    if (total + current_num == target) {
      result = expression + current_number_str;
      return true;
    }
    return false;
  }

  if (find_expression(digit + 1, current_num * 10 + digit, total, target,
                      expression, result))
    return true;

  else if (find_expression(digit + 1, digit, total + current_num, target,
                           expression + current_number_str + '+', result))
    return true;

  else if (find_expression(digit + 1, -digit, total + current_num, target,
                           expression + current_number_str, result))
    return true;
  return false;
}
