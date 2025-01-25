class Solution {
public:

vector<int> smallestRange(vector<vector<int>>& nums) {
    int k = nums.size(); 
    int l = -100000;     
    int r = 100000;     
    int ans = r - l;    
    set<pair<int, int>> st;

    for (int i = 0; i < k; i++) {
        st.insert({nums[i][0], i});
    }

    vector<int> indices(k, 0); 
    int minRangeL = l, minRangeR = r; 
    while (true) {
        l = st.begin()->first; 
        r = st.rbegin()->first; 

       
        if (r - l < ans) {
            ans = r - l;
            minRangeL = l;
            minRangeR = r;
        }

        int listIndex = st.begin()->second;
        st.erase(st.begin());

        // Move to the next element in the corresponding list
        indices[listIndex]++;
        if (indices[listIndex] == nums[listIndex].size()) {
            // If we've reached the end of one list, break
            break;
        }

        // Add the next element from the same list to the set
        st.insert({nums[listIndex][indices[listIndex]], listIndex});
    }

    return {minRangeL, minRangeR}; // Return the smallest range
}

};