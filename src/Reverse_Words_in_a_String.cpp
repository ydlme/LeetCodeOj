class Solution {
public:

    void reverseWords(string &s)
    {
        string rs;
        string word;
        for (int i = s.length()-1; i >= 0; ) {
            while ( s[i] == ' ') i--;
            if ( i < 0 ) break;
            if ( !rs.empty() ) {
                rs.push_back(' ');
            }
            word.clear();
            while ( i >= 0 && s[i] != ' ') {
                word.push_back( s[i--] );
            }
            reverse( word.begin(), word.end() );
            rs.append(word);
        }
        s = rs;
    }
};
