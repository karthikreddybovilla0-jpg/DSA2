class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;

        for (int x : nums) {
            st.insert(x);
        }

        int multiple = k;

        while (st.find(multiple) != st.end()) {
            multiple += k;
        }

        return multiple;
    }
};
/*class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

        for (int i = 1; ; i++) {

            bool found = false;

            for (int j = 0; j < nums.size(); j++) {

                if (i * k == nums[j]) {
                    found = true;
                    break;
                }
            }

            if (found == false) {
                return i * k;
            }
        }
    }
};
brute force approach 
*/