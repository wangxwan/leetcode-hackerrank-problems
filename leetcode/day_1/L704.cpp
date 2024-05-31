# include <iostream>
# include <vector>
using namespace std;

// version 1: target in [left, right]

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1; // define target in [left, right]
        while (left <= right) {
            int middle = left + ((right - left) / 2);  // prevent overflow. it's the same thing as ((left + right) / 2)
            if (nums[middle] > target) {
                right = middle - 1;  // target in the left range, so [left, middle - 1]
            } else if (nums[middle] < target) {
                left = middle + 1;  // target in the right range, so [middle + 1, right]
            } else {
                return middle;
            }
        }
        // no target value found
        return -1;
    }
};

/*
//version 2: target in [left, right)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int middle = left + ((right - left) >> 1);  // >> means shift right one bit, the same as the above
           if (nums[middle] > target) {
                right = middle;  // for right open, no need to - 1
            } else if (nums[middle] < target) {
                left = middle + 1;
            } else {
                return middle;                
            }
        }
        return -1;
    }
};
*/

int main()
{
    vector<int> nums;
    int i;
    int target;
    cout << "Enter an array of integers with ascending order(nums): ";
    while (cin >> i) {
        nums.push_back(i);
        if (cin.get() == '\n') {
            break;
        }
    }
    cout << "Enter an integer(target): ";
    cin >> target;
    Solution obj;
    int result = obj.search(nums, target);
    if (result == -1) {
        cout << "No such value in your input array!";
    } else {
        cout << "Index: " << result;
    }
}
