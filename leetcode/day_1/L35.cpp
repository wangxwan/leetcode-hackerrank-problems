# include <iostream>
# include <vector>
using namespace std;

/*
// version 1: brute force approach
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            // Handle the following three cases separately:
            // The target value is before all elements in the array
            // The target value is equal to one of the elements in the array
            // The target value is to be inserted into a specific position in the array
            // The target value is after all elements in the array
            if (nums[i] >= target) {
                // Once we find a num[i] that is greater than or equal to the target, 
                // then i is the result we want.
                return i;
            }
        }
        // Target value after all elements in the array
        // If target is the largest, or nums is empty, 
        // return the length of nums.
        return nums.size();
    }
};

*/

// version 2: binary search method ---- target in [left, right]

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            int middle = left + ((right - left) / 2);
            if (nums[middle] > target) {
                right = middle - 1;
            } else if (nums[middle] < target) {
                left = middle + 1;
            } else {
                return middle;
            }
        }
        return right + 1;
    }
};


/*
// version 3: binary search method ---- target in [left, right)

class Solution {
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n;
        while (left < right) {
            int middle = left + ((right - left) >> 1);
            if (nums[middle] > target) {
                right = middle;
            } else if (nums[middle] < target) {
                left = middle + 1;
            } else {
                return middle;
            }
        }
        return right;
    }
};
*/


int main() {
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
    int result = obj.searchInsert(nums, target);
    cout << "Index: " << result <<endl;
}