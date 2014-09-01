class Solution {
public:
    vector<vector<int> > result;
    vector<int> tmp;
public:

    vector<vector<int> > threeSum(vector<int> &num) {
        result.clear();
        if (num.size() < 3)  return result;
        sort( num.begin(), num.end() );

        int diff, last, last2;
        for (int i = 0; i < num.size() - 2; i++) {
            if ( i > 0 && last == num[i] ) {
                continue;
            }
            last = num[i];
            tmp.push_back(num[i]);
            for (int j = i + 1; j < num.size() - 1; j++) {
                if ( j > i + 1 && last2 == num[j] ) continue;
                last2 = num[ j ];
                tmp.push_back(num[j]);
                diff = 0 - num[i] - num[j];
                if ( binary_search(num.begin() + j + 1, num.end(), diff ) ) {
                    tmp.push_back(diff);
                    result.push_back( tmp );
                    tmp.pop_back();
                }
                tmp.pop_back();
            }
            tmp.pop_back();
        }
        return result;
    }
};


