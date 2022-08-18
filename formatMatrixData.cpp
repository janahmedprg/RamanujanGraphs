#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream iSet("lpsXp3q13mat.txt");
    ifstream matFile("lpsP3Q13mat.txt");
    ofstream outfile("iSetMatP3Q13.txt");
    vector<int> v;
    int a;
    while(iSet>>a){
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    int n=v.size();
    for(int i = 0;i<n;++i){
        int k,a,b,c,d;
        cin>>k>>a>>b>>c>>d;
        if(k==v[i]){
            outfile<<"[ "<<a<<" "<<b<<" "<<c<<" "<<d<<" ]\n";
        }
    }
    outfile.close();
    return 0;
}