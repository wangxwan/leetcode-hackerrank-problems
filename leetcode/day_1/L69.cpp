# include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int left = 1;
        int right = x;
        while (left <= right) {
            int middle = left + ((right - left) / 2);
            if (middle > x/middle) {
                right = middle - 1;
            } else if (middle < x/middle) {
                left = middle + 1;
            } else {
                return middle;
            }
        }
        return right;
    }
};

int main() {
    int x;
    Solution obj;
    cout << "Enter a non-negative integer x: ";
    cin >> x;
    cout << "The square root of " << x << " is " << obj.mySqrt(x) << endl;
}