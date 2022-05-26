#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main() {
  class Solution {
  public:
    bool containsDuplicate(vector<int> &nums) {
      sort(nums.begin(), nums.end());
      for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i] == nums[i + 1])
          return true;
      }
      return false;
    };
  };

  Solution s;
  vector<int> nums{5, 2, 5, 7, 6};
  cout << s.containsDuplicate(nums) << endl;
  return 0;
}