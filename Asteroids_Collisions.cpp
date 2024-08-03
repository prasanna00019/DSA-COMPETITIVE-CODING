// https://leetcode.com/problems/asteroid-collision/
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>s;
        for(int x:asteroids){
            bool exploded=false;
            while(!s.empty() && s.top()>0 && x<0){
                if(s.top()<-x){
                    s.pop();continue;
                }else if(s.top()==-x){
                     s.pop();
                }
                exploded=true;
                break;
            }
            if(!exploded){
                s.push(x);
            }
        }
        vector<int>result(s.size());
        for(int i=s.size()-1;i>=0;i--){
            result[i]=s.top();
            s.pop();
        }
        return result;
    }
};
