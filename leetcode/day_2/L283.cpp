# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    void moveZeros(vector<int>& nums) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (nums[fastIndex] != 0) {
                swap(nums[slowIndex++], nums[fastIndex]);
            }
        }
    }
};

int main()
{
    vector<int> nums;
    int i;
    cout << "Enter an integer array(nums): ";
    while (cin >> i) {
        nums.push_back(i);
        if (cin.get() == '\n') {
            break;
        }
    }
    Solution obj;
    obj.moveZeros(nums);
    cout << "[";
    for (size_t i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}