
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
        if ( num.size() == 1 ) return num[0];
        int left = 0, right = num.size()-1,mid;
        while ( left < right ) {
                mid = left + (right - left) / 2;
                if ( num[mid] < num[right] ) {
                    if ( mid > 0 && num[mid-1] < num[mid] ) {
                        right = mid - 1;
                    } else
                        return num[mid];
                } else
                    left = mid + 1;
        }
        return num[left];
    }
};

int main()
{
    vector<int> Vnum{6,7,8,9,-5,-4,-3,1,2};
    Solution so;
    cout << so.findMin(Vnum) << endl;

    return 0;
}
