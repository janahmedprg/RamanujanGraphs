#include <bits/stdc++.h>

using namespace std;

int main()
{
    srand(time(0));
    int n;
    char charT;
    ifstream inFile("lpsXp17q13.txt");
    inFile >> charT;
    if (charT == 'p'){
        inFile>> n;
    }
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
    return 0;
}