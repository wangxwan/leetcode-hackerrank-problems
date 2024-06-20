# include <iostream>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int st1 = finalSize(s);
        int st2 = finalSize(t);
        if (st2 != st1) {
            return false;
        }
        for (int i = 0; i < st2; i++) {
            if (s[i] != t[i]) {
                return false;
            }
        }
        return true;
    }
public:
    int finalSize(string& str) {
        int k = 0;
        for (char c : str) {
            if (c != '#') {
                str[k++] = c;
            } else if (k > 0) {
                k--;
            }
        }
        return k;
    }
};

int main() {
    string s, t;
    cout << "Enter the first string(s): ";
    cin >> s;
    cout << "Enter the second string(t): ";
    cin >> t;
    Solution obj;
    cout << boolalpha << obj.backspaceCompare(s, t) << endl;
}