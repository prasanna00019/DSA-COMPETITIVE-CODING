/*
Given an unsorted array Arr of size N of positive integers.
One number 'A' from set {1, 2,....,N} is missing and one number 'B' occurs twice in array. 
Find these two numbers.
*/  

vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        for(auto it:mp){
            if(it.second==2){
                ans.push_back(it.first);
            }
        }
        for(int i=1;i<=n;i++){
            if(mp.find(i)==mp.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
