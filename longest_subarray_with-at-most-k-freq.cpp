 // Length of Longest Subarray With at Most K Frequency
  int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int maxlen=0;int len;
        int left=0;int right=0;
        unordered_map<int,int>mp;
        while(right<n){
            mp[nums[right]]++;
            while(mp[nums[right]]>k and left <=right){
                mp[nums[left]]--;
                left++;
            }
            len=right-left+1;
            maxlen=max(maxlen,len);right++;
        }
        return maxlen;
    }
