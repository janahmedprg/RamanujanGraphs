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
    string filename = "lpsP157Q13";
    ifstream inFile(filename+".txt");
    int n;
    int i;
    char charT;
    inFile >> charT;
    if (charT == 'p'){
        inFile>> n;
    }
    cout<<"Enter independence number"<<endl;
    cin>>i;
    vector<vector<int>> A;
    A.resize(n, vector<int>(n)); 
    char tempChar;
    int a, b;
    inFile >>tempChar;
    if(tempChar == 'c'){
        string s;
        getline(inFile,s);
    }
    else{ 
        inFile>> a >> b;
    }
    while (a != -1 && b != -1)
    {
        if(tempChar == 'e'){
            A[a - 1][b - 1] = 1;
            A[b - 1][a - 1] = 1;
        }
        inFile >>tempChar;
        if(tempChar == 'c'){
            string s;    
            getline(inFile,s);
        }
        else{ 
            inFile>> a >> b;
        }
    }
    vector<vector<int>> neighborMat;
    for (int j = 0; j < n; ++j)
    {
        vector<int> tmpNeighbors;
        tmpNeighbors = getNeighbors(A[j]);
        neighborMat.push_back(tmpNeighbors);
    }
    for(int ii = 0; ii<100;++ii){
        cout<<ii<<"th iteration"<<"\n";
        bool done = true;
        vector<int> pos;
        for (int j = 0; j < n; ++j)
        {
            pos.push_back(j);
        }
        random_shuffle(pos.begin(), pos.end());
        pos.resize(i);
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
        int moved = 0;
        int independent = 0;
        for (int ite = 0; ite < 9000; ++ite)
        {
            // cout << "independent"
            //      << " moved" << endl;
            // cout << independent << "         " << moved << endl;
            if (independent == i)
            {
                // string outfilename = filename + "i" + to_string(i)+"ite" + to_string(ii) + ".txt";
                // ofstream outfile (outfilename);
                cout << "Found set in " << ite << " iterations. The set: \n";
                for (int j = 0; j < i; ++j)
                {
                    cout << pos[j] + 1 << " ";
                    // outfile<< pos[j] + 1 << " ";
                }
                cout << "\n";
                done = false;
                // outfile.close();
                break;
            }
            independent = 0;
            moved = 0;
            for (int j = 0; j < i; ++j)
            {
                vector<int> tmpNeigbours;
                tmpNeigbours = neighborMat[pos[j]];
                int regularity = tmpNeigbours.size();
                int minC = -(croudedness[pos[j]]);
                if (minC < 0)
                {
                    cout << minC << "  WTH  " << pos[j] << "\n";
                }
                int minCidx = pos[j];
                for (int x = 0; x < regularity; ++x)
                {
                    if (croudedness[tmpNeigbours[x]] > 0)
                    {
                        if (minC > croudedness[tmpNeigbours[x]] - 1)
                        {
                            minC = croudedness[tmpNeigbours[x]] - 1;
                            minCidx = tmpNeigbours[x];
                        }
                        else if (minC == croudedness[tmpNeigbours[x]] - 1)
                        {
                            if (rand() % 2 == 0)
                            {
                                minCidx = tmpNeigbours[x];
                            }
                        }
                    }
                    else if (croudedness[tmpNeigbours[x]] == 0)
                    {
                        cout << "Neigbor can't never have 0 crowdedness" << endl;
                        return 0;
                    }
                }
                if (pos[j] != minCidx)
                {
                    for (int x = 0; x < regularity; ++x)
                    {
                        if (croudedness[tmpNeigbours[x]] > 0)
                        {
                            croudedness[tmpNeigbours[x]] -= 1;
                        }
                        else
                        {
                            croudedness[tmpNeigbours[x]] += 1;
                        }
                    }
                    croudedness[pos[j]] = -croudedness[pos[j]];
                    pos[j] = minCidx;
                    vector<int> tmpN;
                    tmpN = neighborMat[pos[j]];
                    croudedness[pos[j]] = -croudedness[pos[j]];
                    if (croudedness[pos[j]] > 0)
                    {
                        cout << "not possible" << endl;
                        return 0;
                    }
                    for (int x = 0; x < regularity; ++x)
                    {
                        if (croudedness[tmpN[x]] < 0)
                        {
                            croudedness[tmpN[x]] -= 1;
                        }
                        else if (croudedness[tmpN[x]] == 0)
                        {
                            vector<int>::iterator isInPos = find(pos.begin(), pos.end(), tmpN[x]);
                            if (isInPos != pos.end() && *isInPos == tmpN[x])
                            {
                                croudedness[tmpN[x]] -= 1;
                            }
                            else
                            {
                                croudedness[tmpN[x]] += 1;
                            }
                        }
                        else
                        {
                            croudedness[tmpN[x]] += 1;
                        }
                    }
                    moved += 1;
                }
                if (croudedness[pos[j]] == 0)
                {
                    independent += 1;
                }
            }
        }
        // if(done){
        //     cout << "Didn't find set of size i but here is the current set: \n";
        //     int count = 0;
        //     for (int j = 0; j < i; ++j)
        //     {
        //         if (croudedness[pos[j]] == 0)
        //         {
        //             cout << pos[j] + 1 << " ";
        //             count += 1;
        //         }
        //     }
        //     cout << endl;
        //     cout << count << endl;
        // }
    }
    return 0;
}