// You are given a 0-indexed integer array mapping which represents the mapping rule of a shuffled decimal system. mapping[i] = j means digit i should be mapped to digit j in this system.

// The mapped value of an integer is the new integer obtained by replacing each occurrence of digit i in the integer with mapping[i] for all 0 <= i <= 9.

// You are also given another integer array nums. Return the array nums sorted in non-decreasing order based on the mapped values of its elements.

// Notes:

// Elements with the same mapped values should appear in the same relative order as in the input.
// The elements of nums should only be sorted based on their mapped values and not be replaced by them.

int helper(int num, vector<int>& mapping) {
        int i = 1;
        int newNum = 0;
        if (num == 0) {
            return mapping[0];
        }
        while (num) {
            int rem = num % 10;
            num /= 10;
            newNum += mapping[rem] * i;
            i *= 10;
        }
        return newNum;
    }
    
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> mp(n);
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            mp[i].first = nums[i];
            mp[i].second = helper(num, mapping);
        }
        
        sort(mp.begin(), mp.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.second < b.second;
        });
        
        vector<int> result;
        for (int i = 0; i < n; i++) {
            result.push_back(mp[i].first);
        }
        
        return result;
    }
