    vector<int> subarraySum(vector<int> arr, int n, long long sum) {
       int currentSum=arr[0]; int i; int start=0;
      vector<int>res;
      for(int i=1;i<=n;i++){
       while(currentSum>sum && start < i-1){
        currentSum-=arr[start];
          start++;
       }
        if(currentSum==sum){
         res.push_back(start+1);
         res.push_back(i);return res;
        }
        if(i<n){
         currentSum+=arr[i];
        }
      }
      res.push_back(-1);
      return res;
    }
