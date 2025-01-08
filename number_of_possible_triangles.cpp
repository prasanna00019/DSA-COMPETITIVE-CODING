// https://www.geeksforgeeks.org/problems/count-possible-triangles-1587115620/1

 int countTriangles(vector<int>& arr) {
        // code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int count =0;
        for(int i=n-1;i>=0;i--){
            int j=0;
            int k=i-1;
            while(j<k){
                int sum=arr[j]+arr[k];
                if(sum>arr[i]){
                    count+=(k-j);
                    k--;
                }
                else {
                    j++;
                }
            }
        }
        return count;
    }
