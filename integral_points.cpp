// Given two points p (x1, y1) and q (x2, y2), Calculate the number of integral points lying on the line joining them.
// Note: You are given the 4 points x1, y1, x2, y2 as Input.

  int  boundary(int x1, int x2,int y1,int y2){
      if(x1==x2){
          return abs(y1-y2) - 1;
      }
      else if (y1==y2){
          return abs(x1==x2) - 1;
      }
      return gcd(abs(x1-x2), abs(y1-y2)) - 1;
  }
  int gcd(int a,int b){
      if(b == 0){ return a; }
      return gcd(b, a % b);
  }
    int countIntegralPoints(int x1, int y1, int x2, int y2) {
        // code here
        int ans=boundary(x1,x2,y1,y2);
        // ans==-1?0:ans;
        if(ans==-1){
            return 0;
        }
        else return ans;
    }
