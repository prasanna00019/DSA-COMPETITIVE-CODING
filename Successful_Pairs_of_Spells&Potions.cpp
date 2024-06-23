// https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description/

vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
 vector<int>ans;
  int n=spells.size();
  int m=potions.size();
  sort(potions.begin(),potions.end());
  for(int i=0;i<n;i++){
   int l=0;int r=m-1;int idx=m;
    while(l<=r){
     int mid=l+(r-l)/2;
      if(1LL*spells[i]*potions[mid]>=success){
       r=mid-1;idx=mid;
      }
      else{
       l=mid+1;
      }
    }
    ans.push_back(m-idx);
  }
  return ans;
}
