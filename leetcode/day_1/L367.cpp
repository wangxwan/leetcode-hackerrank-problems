# include <iostream>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        long left = 1;
        long right = num;
        while (left <= right) {
            long middle = left + ((right - left) / 2);
            long square = middle * middle;
            if (square == num) {
                return true;
            } else if (square < num) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
        return false;
    }
};

int main() {
    int num;
    cout << "Enter a positive integer(num): ";
    cin >> num;
    Solution obj;
    cout << boolalpha << obj.isPerfectSquare(num) << endl;
}