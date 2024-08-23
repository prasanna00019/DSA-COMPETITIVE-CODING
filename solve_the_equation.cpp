// Solve a given equation and return the value of 'x' in the form of a string "x=#value". 
// The equation contains only '+', '-' operation, the variable 'x' and its coefficient. 
// You should return "No solution" if there is no solution for the equation, or "Infinite solutions" if there are infinite solutions for the equation.
// If there is exactly one solution for the equation, we ensure that the value of 'x' is an integer.
// Example 1:
// Input: equation = "x+5-3+x=6+x-2"
// Output: "x=2"
// Example 2:
// Input: equation = "x=x"
// Output: "Infinite solutions"
// Example 3:
// Input: equation = "2x=x"
// Output: "x=0"

 string solveEquation(string equation) {
    int leftX = 0, rightX = 0;
    int leftSum = 0, rightSum = 0;
    int n = equation.size();
    int sign = 1, i = 0;

    // Process the left side of the equation
    while (equation[i] != '=') {
        if (equation[i] == '+') {
            sign = 1;
            i++;
        } else if (equation[i] == '-') {
            sign = -1;
            i++;
        }

        int num = 0;
        bool isNum = false;
        while (i < n && isdigit(equation[i])) {
            num = num * 10 + (equation[i] - '0');
            isNum = true;
            i++;
        }

        if (i < n && equation[i] == 'x') {
            leftX += (isNum ? num : 1) * sign;
            i++;
        } else {
            leftSum += num * sign;
        }
    }

    i++;  // Skip '='

    sign = 1;
    // Process the right side of the equation
    while (i < n) {
        if (equation[i] == '+') {
            sign = 1;
            i++;
        } else if (equation[i] == '-') {
            sign = -1;
            i++;
        }

        int num = 0;
        bool isNum = false;
        while (i < n && isdigit(equation[i])) {
            num = num * 10 + (equation[i] - '0');
            isNum = true;
            i++;
        }

        if (i < n && equation[i] == 'x') {
            rightX += (isNum ? num : 1) * sign;
            i++;
        } else {
            rightSum += num * sign;
        }
    }

    // Move all x terms to one side and constant terms to the other
    int totalX = leftX - rightX;
    int totalSum = rightSum - leftSum;

    // Determine the result
    if (totalX == 0) {
        if (totalSum == 0) return "Infinite solutions";
        else return "No solution";
    } else {
        return "x=" + to_string(totalSum / totalX);
    }
}
