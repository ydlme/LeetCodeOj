
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    int findMin(vector<int> &num) {
        if ( num.size() == 1 ) return num[0];
        int left = 0, right = num.size()-1,mid, inc;
        while ( left < right ) {
                inc = 1;
                mid = left + (right - left) / 2;
                if ( num[mid] < num[right] ) {
                    for ( ; mid - inc > 0 && num[mid-inc] == num[mid]; inc++);
                    if ( num[mid-inc] < num[mid] ) {
                        right = mid - inc;
                    } else {
                        //cout << "block ret\n";
                        return num[mid];
                    }
                } else if ( num[mid] == num[right] ) {
                    int mmid = mid + (right-mid)/2;
                    if ( num[mmid] < num[right] ) {
                        left = mid + 1;
                    } else
                        right = mid;
                } else {
                    for ( ; mid+inc < right && num[mid+inc] == num[mid]; inc++);
                    left = mid + inc;
                }
        }
        //cout << "final ret\n";
        return num[left];
    }
};

int main()
{
    vector<int> Vnum{3,3,1,3}; //{1,3,3}; //{4,5,5,6,6,7,7,7,8, 8,-7,-6,-6,-6,-5,-5,-4,-4,-3,-3,-3,-3,-2,-1};
    Solution so;
    cout << so.findMin(Vnum) << endl;

    return 0;
}
