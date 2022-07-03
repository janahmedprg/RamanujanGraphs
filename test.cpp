#include <bits/stdc++.h>

using namespace std;

vector<int> getNeighbors(vector<int> adjacencyList)
{
    vector<int> neighbors;
    int n = adjacencyList.size();
    for (int i = 0; i < n; ++i)
    {
        if (adjacencyList[i] == 1)
        {
            neighbors.push_back(i);
        }
    }
    return neighbors;
}

int main()
{
    srand(time(0));
    for (int i = 0; i<20; ++i){
        cout<<rand()%2<<endl;
    }    
    return 0;
}