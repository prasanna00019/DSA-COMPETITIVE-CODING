// https://www.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1?page=3&status=solved&sortBy=submissions
  string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        string str="";
        sort(arr,arr+N);
        string s=arr[0];
        string p=arr[N-1];
        if(s.length()<p.length()){
            for(int i=0;i<s.length();i++){
                if(s[i]==p[i]){
                    str+=s[i];
                }
                else{break;}
            }
        }
        else{
            for(int i=0;i<p.length();i++){
                if(s[i]==p[i]){
                    str+=s[i];
                }
                else{break;}
            }
        }
        if(str==""){return "-1";}
        else{return str;}
    }
