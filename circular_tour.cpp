// https://www.geeksforgeeks.org/problems/circular-tour-1587115620/1?page=1&category=Queue&sortBy=submissions
  int tour(petrolPump p[],int n)
    {
       int start=0;int sum=0;int diff=0;
       for(int i=0;i<n;i++){
           sum+=p[i].petrol-p[i].distance;
           if(sum<0){
               diff+=sum;
               sum=0;
               start=i+1;
           }
       }
       if(sum+diff>=0){
           return start;
       }
       return -1;
    }
