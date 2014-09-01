class Solution {
public:
    vector<vector<int> > result;
    int m_target;
public:
    void combine(vector<int> &sets, int lastSum, vector<int> &num, int cur) {
        if (cur >= num.size()) {
            return;
        }
        sets.push_back(num[cur]);
        if (lastSum + num[cur] == m_target) {
            result.push_back(sets);
            sets.pop_back();
            return;
        }
        if (lastSum + num[cur] < m_target) {
            unordered_map<int, char> usedSet;
            for (int i = cur + 1; i < num.size(); i++) {
                if ( usedSet.find(num[i]) != usedSet.end() ) continue;
                usedSet[num[i]] = 1;
                combine(sets, lastSum + num[cur], num, i);
            }
        }
        sets.pop_back();
    }

    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        result.clear();
        vector<int> sets;
        m_target = target;
        sort(num.begin(), num.end());

        unordered_map<int, char> usedSet;
        for (int i = 0; i < num.size(); i++) {
            if ( usedSet.find(num[i]) != usedSet.end() )  continue;
            usedSet[num[i]] = 1;
            combine(sets, 0, num, i);
        }
        return result;
    }
};
