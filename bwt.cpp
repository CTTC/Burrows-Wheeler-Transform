#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::sort;

string BWT(const string& text) {
  string result = "";
  vector<string> cyclicTexts;
  for (int i = 0; i < text.size(); i++)
  {
  	string temp = text.substr(i) + text.substr(0, i);
  	cyclicTexts.push_back(temp);
  }
  sort(cyclicTexts.begin(), cyclicTexts.end());
  for (string& temp : cyclicTexts)
  {
  	result += *(temp.end() - 1);
  }


  return result;
}

int main() {
  string text;
  cin >> text;
  cout << BWT(text) << endl;
  return 0;
}
