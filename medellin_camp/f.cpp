#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
#define sl '\n'
typedef long long ll;

int main () {
    inic;
    inic1;
    inic2;
    string s;
    cin >> s;
    int sz = s.size();
    vector <int> nums;
    for(int i = 0; i < sz; i++) {
        if(i % 2 == 0) {
            int num = s[i] - '0';
            nums.push_back(num);
        }
    }
    
    sort(nums.begin(), nums.end());
    int szn = nums.size();
    for(int i = 0; i < szn; i++) {
        if(i < szn - 1) {
            cout << nums[i] << "+";
        }
        else {
            cout << nums[i];
        }
        
    }
}