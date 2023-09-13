#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    vector <pair<int, int>> v;
    int n,a,b;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    }
    return 0;
}
