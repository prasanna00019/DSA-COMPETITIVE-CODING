int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here4
      sort(arr,arr+N);
      int c=0;
      int m=0;
      for(int i=0;i<N-1;i++){
          if(arr[i+1]-arr[i]==1) c++;
          else if (arr[i+1]==arr[i]) continue;
          else {
              c=0;
      }
      if(c>m) {
          m=c;
      }
    
    }
    return m+1;
    }
