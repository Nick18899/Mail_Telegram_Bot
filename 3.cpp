#include <bits/stdc++.h>
using namespace std;
const vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 0};

int main(){
    assert(months.size() == 13);
    vector<bool> kek(366);
    vector<int> days_cnt(13);
    days_cnt[0] = 0;
    for(int i = 0; i < 13; ++i){
        days_cnt[i] = days_cnt[i-1] + months[i-1];
    }
    kek[365] = false;
    for(int m = 11; m >= 0; --m){
        for(int d = months[m]; d >= 0; --d){
            bool success = false;
            int curr = days_cnt[m] + d;
            if(curr == 365) continue;
            if (d + 1 <= months[m]){
                success |= kek[curr + 1];
            }
            if (d + 2 <= months[m]){
                success |= kek[curr + 2];
            }
            if (d <= months[m + 1]){
                success |= kek[curr + months[m+1]];
            }
            if (d <= months[m + 2]){
                success |= kek[curr + months[m+2]];
            }
            kek[curr] = (not success);
        }
    }
    int di, mi;
    cin >> di >> mi;
    --di, --mi;
    int resDay = days_cnt[mi] + di;
    cout << (kek[resDay] ? "YES\n": "NO\n");
    return 0;
}
