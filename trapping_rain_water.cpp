

long long trappingWater(int arr[], int n){
      int left = 0, right = n - 1;
    int maxLeft = 0, maxRight = 0;
    long long int water = 0;

    while (left <  right) {
        if (arr[left] < arr[right]) {
            if (arr[left] >= maxLeft) {
                maxLeft = arr[left];
            } else {
                water += maxLeft - arr[left];
            }
            left++;
        } else {
            if (arr[right] >= maxRight) {
                maxRight = arr[right];
            } else {
                water += maxRight - arr[right];
            }
            right--;
        }
    }

    return water;
    }
