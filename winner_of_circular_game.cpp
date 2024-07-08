// https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/?envType=daily-question&envId=2024-07-08
 int findTheWinner(int n, int k) {
        queue<int>circle;
        for(int i=1;i<=n;i++){
            circle.push(i);
        }
        while(circle.size()>1){
            for(int i=0;i<k-1;i++){
                circle.push(circle.front());
                circle.pop();
            }
            circle.pop();
        }
        return circle.front();
    }
