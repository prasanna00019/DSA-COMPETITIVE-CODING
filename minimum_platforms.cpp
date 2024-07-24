// https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1?page=1&status=solved&sortBy=submissions
int findPlatform(int arr[], int dep[], int n)
    {
    sort(arr,arr+n);
    sort(dep,dep+n);
 
    int ans=1;
    int count=0;
    int i=0,j=0;
    while(i<n && j<n)
    {
        if(arr[i]<=dep[j]) //one more platform needed
        {
            count++;
            i++;
        }
        else //one platform can be reduced
        {
            count--;
            j++;
        }
        ans=max(ans,count); //updating the value with the current maximum
    }
    return ans;
    }
