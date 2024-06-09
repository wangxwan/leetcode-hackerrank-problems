# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftBorder = getLeftBorder(nums, target);
        int rightBorder = getRightBorder(nums, target);
        // Scenario 1
        if (leftBorder == -2 || rightBorder == -2) {
            return {-1, -1};
        }
        // Scenario 3
        if (rightBorder - leftBorder > 1) {
            return {leftBorder + 1, rightBorder - 1};
        }
        // Scenario 2
        return {-1, -1};
    }
private:
    int getRightBorder(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int rightBorder = -2;  // Record the situation where "rightBorder" is not assigned a value.
        while (left <= right) {
            int middle = left + ((right - left) / 2);
            if (nums[middle] > target) {
                right = middle - 1;
            } else {  // Find the right boundary, update the left when nums[middle] == target.
                left = middle + 1;
                rightBorder = left;
            }
        }
        return rightBorder;
    }
    int getLeftBorder(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int leftBorder = -2;  // Record the situation where "leftBorder" is not assigned a value.
        while (left <= right) {
            int middle = left + ((right - left) / 2);
            if (nums[middle] >= target) { // Find the right boundary, update the left when nums[middle] == target.
                right = middle - 1;
                leftBorder = right;
            } else {
                left = middle + 1;
            }
        }
        return leftBorder;
    }
}; 

int main() {
    vector<int> nums;
    int i;
    int target;
    cout << "Enter an array of integers nums sorted in non-decreasing order(nums): ";
    while (cin >> i) {
        nums.push_back(i);
        if (cin.get() == '\n') {
            break;
        }
    }
    cout << "Enter an integer(target): ";
    cin >> target;
    Solution obj;
    vector<int> result = obj.searchRange(nums, target);
    cout << "[First-position, Last-position](if it's [-1, -1], means your input target is not found in the array): " << endl << "[";
    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}