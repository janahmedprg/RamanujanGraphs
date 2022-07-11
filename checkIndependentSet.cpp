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
    int n;
    cout << "Enter number of vertices"
         << "\n";
    cin >> n;
    vector<vector<int>> A;
    A.resize(n, vector<int>(n));
    ifstream inFile("lpsP3Q13.txt");
    int a, b;
    inFile >> a >> b;
    while (a != -1 && b != -1)
    {
        A[a - 1][b - 1] = 1;
        A[b - 1][a - 1] = 1;
        inFile >> a >> b;
    }
    vector<vector<int>> neighborMat;
    vector<int> pos;
    for (int j = 0; j < n; ++j)
    {
        vector<int> tmpNeighbors;
        tmpNeighbors = getNeighbors(A[j]);
        neighborMat.push_back(tmpNeighbors);
    }
    int i;
    cout<<"Enter set size"<<endl;
    cin>>i;
    cout<< "Enter set values"<<endl;
    for (int j= 0;j<i;++j){
        int a;
        cin>>a;
        pos.push_back(a-1); 
    }
    sort(pos.begin(), pos.end());
    for (int j = 0; j < i; ++j)
    {
        if(j!=i-1){
            if(pos[j] == pos[j+11]){
                cout<< "There are duplicates"<<endl;
                return 0;
            }
        }
        vector<int> tmpNeigbours;
        tmpNeigbours = neighborMat[pos[j]];
        int regularity = tmpNeigbours.size();
        for (int x = 0; x < regularity; ++x)
        {
            vector<int>::iterator isInSet = lower_bound(pos.begin(), pos.end(), tmpNeigbours[x]);
            if (isInSet != pos.end() && *isInSet == tmpNeigbours[x])
            {
                cout<<"Not Independent "<<pos[j] + 1<<" and "<< tmpNeigbours[x] + 1<<" are adjacent"<<endl;
                return 0;
            }
        }
    }
    cout<<"It is an Indepenent set"<<endl;
    return 0;
}