class Solution {
public:

    bool possible(vector<int>& a, int days, int m, int k) {

        int cnt = 0;
        int nb = 0;

        for(int i = 0; i < a.size(); i++) {

            if(a[i] <= days) {
                cnt++;
            }
            else {
                nb = nb + (cnt / k);
                cnt = 0;
            }
        }

        // Remaining consecutive flowers
        nb = nb + (cnt / k);

        return nb >= m;
    }

    int minDays(vector<int>& a, int m, int k) {
        if(1LL * m * k > a.size())
            return -1;

        int low = *min_element(a.begin(), a.end());
        int high = *max_element(a.begin(), a.end());

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(possible(a, mid, m, k)) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};