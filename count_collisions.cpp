// https://leetcode.com/problems/count-collisions-on-a-road/

class Solution {
public:
   int countCollisions(string directions) {
    int collisions = 0;
    int n = directions.size();
    int i = 0;

    // Skip all leading 'L' since they will not collide with anything
    while (i < n && directions[i] == 'L') {
        i++;
    }

    // Start counting collisions from the first non-'L' character
    for (; i < n; ++i) {
        if (directions[i] == 'R') {
            // Count 'R' cars
            int rightMovingCars = 0;
            while (i < n && directions[i] == 'R') {
                rightMovingCars++;
                i++;
            }

            // Check what follows the 'R' cars
            if (i < n && (directions[i] == 'L' || directions[i] == 'S')) {
                // All 'R' cars will collide
                collisions += rightMovingCars;
                // The current 'L' will also collide
                if (directions[i] == 'L') {
                    collisions++;
                }
            }
        } else if (directions[i] == 'L') {
            // Any 'L' car after 'S' will collide with 'S' or previously colliding 'R'
            collisions++;
        }
    }

    return collisions;
}

};
