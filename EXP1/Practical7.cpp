#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        while (true) {
            vector<int> arr;
            for (int i = 0; i < nums.size() - 1; i++) {
                arr.push_back((nums[i] + nums[i + 1]) % 10);
            }
            nums = arr;

            if (nums.size() == 1) return nums[0];
            if (nums.size() == 0) break;
        }
        return -1;
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    int result = obj.triangularSum(nums);

    cout << "Triangular Sum: " << result << endl;

    return 0;
}