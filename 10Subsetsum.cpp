#include <iostream>
#include <vector>

using namespace std;

void findSubsetsWithSum(vector<int>& nums, int targetSum, int index, int currentSum, vector<int>& ds, vector<vector<int>>& ans) {
    if (currentSum == targetSum) {
        ans.push_back(ds);
        return;
    }
    if (index >= nums.size() || currentSum > targetSum) {
        return;
    }
    ds.push_back(nums[index]);
    findSubsetsWithSum(nums, targetSum, index + 1, currentSum + nums[index], ds, ans);
    ds.pop_back();
    findSubsetsWithSum(nums, targetSum, index + 1, currentSum, ds, ans);
}

int main() {
     vector<int> nums = {1,2,5,6,8};
    int targetSum = 9;
    vector<int> ds;
    vector<vector<int>> ans;
    findSubsetsWithSum(nums, targetSum, 0, 0, ds, ans);
    for (const vector<int>& subset : ans) {  //OR for(auto subset:ans)
        for (int num : subset) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
