long long countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long p=1;
        long long ans,i,j;
        ans=0;i=0;j=0;
        for(i=0,j=0;j<n;j++){
            p*=a[j];
            while(p>=k and i<j){
                p/=a[i];i++;
            }
            if(p<k){
                ans+=(j-i+1);
            }
        }
        return ans;
    }
