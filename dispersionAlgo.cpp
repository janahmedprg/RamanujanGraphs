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
    srand(unsigned(time(0)));
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
        pos.push_back(j);
    }
    random_shuffle(pos.begin(), pos.end());
    vector<int> croudedness;
    croudedness.resize(n);
    for (int j = 0; j < i; ++j)
    {
        vector<int> tmpNeigbours;
        tmpNeigbours = neighborMat[pos[j]];
        int regularity = tmpNeigbours.size();
        for (int x = 0; x < regularity; ++x)
        {
            croudedness[tmpNeigbours[x]] += 1;
        }
    }
}