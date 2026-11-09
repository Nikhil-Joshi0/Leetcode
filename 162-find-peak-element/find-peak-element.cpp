class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n = arr.size();
        int start = 0;
        int end = n-1;
        int mid;
        while(start <= end){
            mid = (start + end)/2;
            if( (mid == n-1 || arr[mid + 1] < arr[mid]) &&
            (mid == 0 || arr[mid - 1] < arr[mid]) )
                return mid;
            else if(mid < n-1 && arr[mid + 1] > arr[mid]){
                start = mid + 1;
            }
            else end = mid - 1;
        }
        return -1;
    }
};