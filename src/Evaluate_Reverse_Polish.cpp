
#define ADDITION  '+'
#define SUBSTRACTION  '-'
#define MULTIPLICATION  '*'
#define DIVISION  '/'


class Solution {
public:
    set<char> tokenSet{'+', '-', '*', '/'};
    stack<int> num;
    int evalRPN(vector<string> &tokens) {
        for (auto &token : tokens) {
            auto iter = tokenSet.find( token[token.size()-1] );
            if ( iter == tokenSet.end() ) {
                num.push( atoi( token.c_str() ) );
            } else {
               int right = num.top();
               num.pop();
               int left = num.top();
               num.pop();
               switch ( *iter )
               {
                   case ADDITION :
                       num.push(left + right);
                       break;
                   case SUBSTRACTION:
                       num.push(left - right);
                       break;
                   case MULTIPLICATION:
                       num.push(left * right);
                       break;
                   case DIVISION:
                       num.push(left / right);
                       break;
                   default:
                       break;
               }
            }
        }
        int ret = num.top();
        num.pop();
        return ret;
    }
};

