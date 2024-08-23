// Given a string expression representing an expression of fraction addition and subtraction, return the calculation result in string format.

// The final result should be an irreducible fraction. If your final result is an integer, change it to the format
// of a fraction that has a denominator 1. So in this case, 2 should be converted to 2/1.

 

// Example 1:

// Input: expression = "-1/2+1/2"
// Output: "0/1"
// Example 2:

// Input: expression = "-1/2+1/2+1/3"
// Output: "1/3"
// Example 3:

// Input: expression = "1/3-1/2"
// Output: "-1/6"

string fractionAddition(string expression){
   int numerator=0;int denominator=1;
   int i=0;int n=expression.size();
   while(i<n){
    int sign=1;
     if(expression[i]=='+'||expression[i]=='-'){
      if(expression[i]=='-'){
      sign=-1;
      }
       i++;
     }
     int num=0;
     while(i<n && isdigit(expression[i])){
        num=num*10+(expression[i]-'0');
        i++;
     }
     num*=sign;
     i++;
     int den=0;
     while(i<n && isdigit(expression[i])){
     den=den*10+(expression[i]-'0');
       i++;
     }
     numerator=numerator*den+ num*denominator;
     denominator*=den;
     int gcdval=gcd(abs(numerator),denominator);
     numerator/=gcdval;
     denominator/=gcdval;
   }
  return to_string(numerator)+"/"+ to_string(denominator);
}
