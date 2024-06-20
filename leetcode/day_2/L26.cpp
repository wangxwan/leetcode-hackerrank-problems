# include <iostream>
# include <vector>
using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slowIndex = 1;
        for (int fastIndex = 1; fastIndex < nums.size(); fastIndex++) {  // compare each element with its previous element to check for duplicates.
            if (nums[fastIndex] != nums[fastIndex - 1]) {
                nums[slowIndex] = nums[fastIndex];
                slowIndex++;
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
    Solution obj;
    int k = obj.removeDuplicates(nums);
    cout << k << ", nums = [";
    for (size_t i = 0; i < k; i++) {
        cout << nums[i];
        if (i < k - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}