Given an array arr of n positive integers, your task is to find all the leaders in the array. An element of the 
array is considered a leader if it is greater than all the elements on its right side or if it is equal to the 
maximum element on its right side. The rightmost element is always a leader.

vector<int> leaders(int n, int arr[]) {
  vector<int>f1(n,0);
  vector<int>ans;
  f1[n-1]=INT_MIN;
  int d=0;
  for(int i=n-2;i>=0;i--){
    d=max(arr[i+1],d);
    f1[i]=d;
  }
  for(int i=0;i<n;i++){
   if(arr[i]>=f[i]){
   ans.push_back(arr[i]);
   }
  }
  return ans;
}
