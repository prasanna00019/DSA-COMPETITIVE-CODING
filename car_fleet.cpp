// There are n cars at given miles away from the starting mile 0, traveling to reach the mile target.

// You are given two integer array position and speed, both of length n, where position[i] is the starting mile of the ith car and speed[i] is the speed of the ith car in miles per hour.

// A car cannot pass another car, but it can catch up and then travel next to it at the speed of the slower car.

// A car fleet is a car or cars driving next to each other. The speed of the car fleet is the minimum speed of any car in the fleet.

// If a car catches up to a car fleet at the mile target, it will still be considered as part of the car fleet.

// Return the number of car fleets that will arrive at the destination
// https://leetcode.com/problems/car-fleet/description/

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
         vector<pair<int, int>> cars;
    for (int i = 0; i < position.size(); ++i) {
        cars.emplace_back(position[i], speed[i]);
    }

    // Sort cars by their starting position (furthest first)
    sort(cars.begin(), cars.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first;
    });

    int fleets = 0; // Count the number of fleets
    double maxTime = 0.0; // Keep track of the maximum time to reach the target for current fleet

    for (const auto& car : cars) {
        // Calculate time for this car to reach the target
        double time = static_cast<double>(target - car.first) / car.second;

        // If this car takes longer than the previous cars (or fleets), it forms a new fleet
        if (time > maxTime) {
            ++fleets; // Increment fleet count
            maxTime = time; // Update the maximum time for this new fleet
        }
    }

    return fleets;
    }
};
