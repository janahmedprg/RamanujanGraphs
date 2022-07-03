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
        A[a][b] = 1;
        A[b][a] = 1;
        inFile >> a >> b;
    }
    vector<vector<int>> neighborMat;
    for (int j = 0; j < n; ++j)
    {
        vector<int> tmpNeighbors;
        tmpNeighbors = getNeighbors(A[j]);
        neighborMat.push_back(tmpNeighbors);
    }
    cout << "Enter independence number"
         << "\n";
    int i;
    vector<int> pos;
    for (int j = 0; j < i; ++j)
    {
        pos.push_back(rand() % n);
    }
    sort(pos.begin(), pos.end());
    vector<int> croudedness;
    croudedness.resize(n);
    for (int j = 0; j < i; ++j)
    {
        vector<int> tmpNeigbours;
        tmpNeigbours = neighborMat[pos[j]];
        int regularity = tmpNeigbours.size();
        for (int x = 0; x < regularity; ++x)
        {
            vector<int>::iterator isInSet = lower_bound(pos.begin(), pos.end(), tmpNeigbours[x]);
            if (isInSet != pos.end() && *isInSet == tmpNeigbours[x])
            {
                croudedness[tmpNeigbours[x]] -= 1;
            }
            else
            {
                croudedness[tmpNeigbours[x]] += 1;
            }
        }
    }
    for (int ite = 0; ite < 300; ++ite)
    {
        int indeVertices = 0;
        for (int j = 0; j < i; ++j)
        {
            vector<int> tmpNeigbours;
            tmpNeigbours = neighborMat[pos[j]];
            int regularity = tmpNeigbours.size();
            int minC = -(croudedness[j]);
            int minCidx = j;
            for (int x = 0; x < regularity; ++x) {
                if (croudedness[tmpNeigbours[x]]>=0){
                    if(minC>croudedness[tmpNeigbours[x]]){
                        minC = croudedness[tmpNeigbours[x]];
                        minCidx = tmpNeigbours[x];
                    }
                    else if ( minC == croudedness[tmpNeigbours[x]]){
                        if (rand()%2==0) {
                            minCidx = tmpNeigbours[x];
                        }
                    }
                }
            }
            if (j!=minCidx){
                pos[j] = minCidx;
                for (int x = 0; x<regularity; ++x){
                    if (minCidx==tmpNeigbours[x]){
                        continue;
                    }
                    if(croudedness[tmpNeigbours[x]]>0){
                        croudedness[tmpNeigbours[x]]-=1;
                    }
                    else{
                        croudedness[tmpNeigbours[x]] += 1;
                    }
                }
                croudedness[j]=-croudedness[j];
                vector<int> tmpN;
                tmpN = neighborMat[pos[j]];
                
            }
        }
    }
}