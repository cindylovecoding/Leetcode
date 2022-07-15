#include<vector>
#include<cstdio>
#include<bits/stdc++.h>

class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
       vector<int> last{numeric_limits<int>::min()};

    for (auto ai : a) {
        for (size_t j = 1; j < last.size(); ++j)
            if (ai > last[j - 1]) last[j] = min(last[j], ai);
        if (last.back() < ai) last.push_back(ai);
    }

    return last.size() - 1; 
    }
};
