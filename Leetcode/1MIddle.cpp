class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int count = 0;
        vector<pair<int,int>> sizes;
        int maxLen = 0;
    
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1 and count == 0){
                count = 1;
            }
            else if(count != 0 and nums[i] == 1){
                count++;
                if(i == nums.size()-1){ 
                    sizes.push_back({count, i});
                    if(count > maxLen){
                        maxLen = count;
                    }
                }
            }

            else if(count != 0 and nums[i] == 0){
                sizes.push_back({count, i-1});
                if(count > maxLen){
                    maxLen = count;
                }
                count = 0;
            }
        }

        if(count > 0){
            sizes.push_back({count, (int)nums.size()-1});
            maxLen = std::max(maxLen, count);
        }

        int result = 0;
        
        for (int i = 1; i < sizes.size(); i++){

            int len1 = sizes[i-1].first;
            int end1 = sizes[i-1].second;
            int len2 = sizes[i].first;
            int end2 = sizes[i].second;
            int start2 = end2 - len2 + 1;

            if( start2 - end1 == 2){
                if( len1 + len2 > result){
                    result = std::max(result, len1 + len2);
                }
            }
        }
        

        if(maxLen == nums.size()){
            return maxLen - 1;
        }

        return std::max(result, maxLen);
    }
};
