class Solution {
public:
multimap<char, char> PhoneMap{
    {'2', 'a'}, {'2', 'b'}, {'2', 'c'},
    {'3', 'd'}, {'3', 'e'}, {'3', 'f'},
    {'4', 'g'}, {'4', 'h'}, {'4', 'i'},
    {'5', 'j'}, {'5', 'k'}, {'5', 'l'},
    {'6', 'm'}, {'6', 'n'}, {'6', 'o'},
    {'7', 'p'}, {'7', 'q'}, {'7', 'r'}, {'7', 's'},
    {'8', 't'}, {'8', 'u'}, {'8', 'v'},
    {'9', 'w'}, {'9', 'x'}, {'9', 'y'}, {'9', 'z'}
};

vector<string> result;
void combination(string &tmp, int cur, string &digits)
{
    if (cur == digits.size()) {
        string elem = tmp;
        result.push_back(elem);
        //cout << elem << endl;
        return;
    }
    auto ret = PhoneMap.equal_range(digits[cur]);
    for (auto iter = ret.first; iter != ret.second; iter++) {
        tmp.push_back(iter->second);
        combination(tmp, cur + 1, digits);
        tmp.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        result.clear();
        string tmp;
        combination(tmp, 0, digits);
        return result;
    }
};
