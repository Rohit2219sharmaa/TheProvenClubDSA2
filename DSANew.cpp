#include <bits/stdc++.h>

using namespace std;

vector<int> arr({0,2,3,4,5,6,7});
int findShiftPoint(int n) {

    //Assuming n >=3 to follow the sequence but still having check
    if(n >=3 && getValue(1) - getValue(0) != getValue(2) - getValue(1)) {
        return 1;
    }
    int low = 0;
    int high = n-2;
    while(low < high) {
        int mid = low + (high-low)/2;
        int current = getValue(mid);
        int nextValue = getValue(mid+1);
        int prevValue = (mid > 0) ? getValue(mid-1): 0;
        int diffPrev = current - prevValue;
        int diffAfter = nextValue - current;
        if(diffPrev != diffAfter) {
            high = mid;
        } else{
            low = mid+1;
        }
    }
    return low+1;
}

int main() {
    cout<<findShiftPoint(arr.size());
    return 0;
}