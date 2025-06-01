class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int slow = 0; 
        for (int fast = 1; fast < nums.size(); ++fast) {
            if (nums[fast] != nums[slow]) { 
                slow++; 
                nums[slow] = nums[fast]; 
            }
        }
        
        for(int i = 0; i <= slow; i++){
            cout << nums[i] << " ";
        }
        cout << endl;

        return slow + 1; 
    }
};

// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

// Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:
