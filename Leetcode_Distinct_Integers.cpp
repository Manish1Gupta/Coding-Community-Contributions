/*
2442. Count Number of Distinct Integers After Reverse Operations
Input: nums = [1,13,10,12,31]
Output: 6
*/
class Solution {
 public:
  int countDistinctIntegers(vector<int>& nums) {
    unordered_set<int> numsSet{begin(nums), end(nums)};

    for (const int num : nums)
      numsSet.insert(reversed(num));

    return numsSet.size();
  }

 private:
  int reversed(int num) {
    int ans = 0;
    while (num > 0) {
      ans = ans * 10 + num % 10;
      num /= 10;
    }
    return ans;
  }
};
