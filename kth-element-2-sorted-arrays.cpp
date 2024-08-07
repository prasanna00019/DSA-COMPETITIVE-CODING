int kthElement(int k,vector<int>arr1,vector<int>arr2){
   int m=arr1.size();
  int n=arr2.size();
  if(m>n) return kthElement(k,arr2,arr1);
  if(m==0) return arr2[k-1];
  if(k==1) return min(arr1[0],arr2[0]);
  int i=min(m,k/2);
  int j=k-i;
  if(arr1[i-1]<arr2[j-1]){
     return kthElement(k-i,vector<int>(arr1.begin()+i,arr1.end()),arr2);
  }
  else{
       return kthElement(k-j,arr1,vector<int>(arr2.begin()+i,arr2.end()));

  }
}
