class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        for(int i=0;i<1000;i++) {
            auto it = std::find(nums.begin(), nums.end(), target-i);
            if (it != nums.end()) {
                if (i == 0) {
                    return distance(nums.begin(), it);
                }
                else {
                    return distance(nums.begin(), it) + 1;
                }
            }
        }
        return 0;
    }
};

//Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

//You must write an algorithm with O(log n) runtime complexity.