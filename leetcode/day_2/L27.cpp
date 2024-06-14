# include <iostream>
# include <vector>
using namespace std;
/*
// version 1: brute force approach

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] == val) {  // Find the element that needs to be removed, then move the whole array forward by one.
                for (int j = i + 1; j < size; j++) {
                    nums[j - 1] = nums[j];
                }
                i--;  // Because the values after index i have all shifted forward by one position, so i also shifts forward by one position.
                size--;  // The size of the array minus one.
            }
        }
        return size;
    }
};
*/

// version 2: Two-pointer method (fast-slow pointer method)

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (val != nums[fastIndex]) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
    }
};


int main()
{
    vector<int> nums;
    int i;
    int val;
    cout << "Enter an integer array(nums): ";
    while (cin >> i) {
        nums.push_back(i);
        if (cin.get() == '\n') {
            break;
        }
    }
    cout << "Enter an integer(val) to remove: ";
    cin >> val;
    Solution obj;
    int k = obj.removeElement(nums, val);
    cout << k << ", nums = [";
    for (size_t i = 0; i < k; i++) {
        cout << nums[i];
        if (i < k - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}