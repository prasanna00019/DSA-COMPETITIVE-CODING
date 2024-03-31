/*
Given an array of strings arr[] of length n representing non-negative integers, arrange them in a manner, such that, after concatanating them in order, \
it results in the largest possible number. Since the result may be very large, return it as a string.
Example 1:
Input: 
n = 5
arr[] =  {"3", "30", "34", "5", "9"}
Output: "9534330"
Explanation: 
Given numbers are  {"3", "30", "34", "5", "9"}, 
the arrangement "9534330" gives the largest value.
*/
static bool comp(string &s1,string &s2){
	    return s1+s2>s2+s1;
	}
	string printLargest(int n,vector<string>&arr){
	    sort(arr.begin(),arr.end(),comp);
	    string ans="";
	    for(int i=0;i<arr.size();i++){
	        ans+=arr[i];
	    }
	    return ans;
	}
