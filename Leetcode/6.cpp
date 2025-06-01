class Solution {
public:
    int removeElement(vector<int>& nums_here, int val) {
        for (int i = 0; i < nums_here.size(); i++) {
            if (val == nums_here[i]) {
                nums_here.erase(nums_here.begin() + i);
                i--;
            }
        }
        int k = nums_here.size();
        return k;
    }
};

// Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

// Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

// Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
// Return k.
