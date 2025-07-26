class Solution {
public:

    bool solve(const vector<int>& bloomDay, int m, int k, int day) {
        int count = 0, flowers = 0;
        for (int i : bloomDay) {
            if (i <= day) {
                flowers++;
                if (flowers == k) {
                    count++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }
        return count >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long totalNeeded = 1LL * m * k;
        if (totalNeeded > bloomDay.size()) return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (solve(bloomDay, m, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
