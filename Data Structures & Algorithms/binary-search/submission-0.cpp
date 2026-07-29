
class Solution {
public:
    // Helper function for recursive binary search
    int binSearch(vector<int> &arr, int tar, int st, int end) {
        if (st <= end) {
            int mid = st + (end - st) / 2;
            if (arr[mid] == tar) return mid;
            else if (tar > arr[mid]) {
                return binSearch(arr, tar, mid + 1, end);
            } else {
                return binSearch(arr, tar, st, mid - 1);
            }
        }
        return -1; // Not found
    }

    int search(vector<int>& arr, int tar) {
        int st = 0, end = arr.size() - 1;
        return binSearch(arr, tar, st, end);
    }
};
