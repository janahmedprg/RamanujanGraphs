#include <bits/stdc++.h>

using namespace std;

vector<int> inverse(int q, vector<int> invs)
{
    for (int i = 1; i < q; ++i)
    {
        if (i == 1)
        {
            continue;
        }
        invs[i] = q - q / i * invs[q % i] % q;
    }
    return invs;
}

vector<int> numToMat(int k, int q, vector<int> invs)
{
    int q0 = (k - 1) / ((q - 1) / 2);
    int r0 = k - 1 - q0 * ((q - 1) / 2);
    int q1 = q0 / (q + 1);
    int r1 = q0 - q1 * (q + 1);
    vector<int> A;
    if (r1 != q)
    {
        A.push_back((r0 + 1) % q);
        A.push_back((q1) % q);
        A.push_back((r1) % q);
        A.push_back(((1 + r1 * q1) * invs[(r0 + 1) % q]) % q);
    }
    else
    {
        A.push_back(0);
        A.push_back((q - invs[(r0 + 1) % q]) % q);
        A.push_back((r0 + 1) % q);
        A.push_back(q1 % q);
    }
    return A;
}

vector<vector<int>> sumOfFourSquares(int p)
{
    int max = sqrt(p);
    bool isOneMod = true;
    if (p % 4 == 3)
    {
        isOneMod = false;
    }
    vector<vector<int>> v;
    vector<vector<int>> res;
    for (int i = 0; i <= max; i++)
    {
        for (int j = 0; j <= max; j++)
        {
            for (int k = 0; k <= max; k++)
            {
                for (int l = 0; l <= max; l++)
                    if (i * i + j * j + k * k + l * l == p)
                    {
                        if (isOneMod && i % 2 == 1 && j % 2 == 0 && k % 2 == 0 && l % 2 == 0)
                        {
                            vector<int> tmp{i, j, k, l};
                            v.push_back(tmp);
                        }
                        else if (!isOneMod && i % 2 == 0 && j % 2 == 1 && k % 2 == 1 && l % 2 == 1)
                        {
                            vector<int> tmp{i, j, k, l};
                            v.push_back(tmp);
                        }
                        break;
                    }
            }
        }
    }
    map<vector<int>, int> permuts;
    map<vector<int>, int> permutsFin;
    int sumK = v.size();
    for (int i = 0; i < sumK; ++i)
    {
        vector<int> tmp{v[i][0], v[i][1], v[i][2], v[i][3]};
        permuts[tmp] = 1; 
    }
    for (auto const &x : permuts)
    {
        vector<int> tmp{x.first[0], x.first[1], x.first[2], x.first[3]};
        permutsFin[tmp] = 1;
        tmp[2] = x.first[3];
        tmp[3] = x.first[2];
        permutsFin[tmp] = 1;
        tmp[1] = x.first[2];
        tmp[3] = x.first[1];
        permutsFin[tmp] = 1;
        tmp[2] = x.first[1];
        tmp[3] = x.first[3];
        permutsFin[tmp] = 1;
        tmp[1] = x.first[3];
        tmp[3] = x.first[2];
        permutsFin[tmp] = 1;
        tmp[2] = x.first[2];
        tmp[3] = x.first[1];
        permutsFin[tmp] = 1;
    }
    for (auto const &x : permuts){
        vector<int> tmp{x.first[0], x.first[1], x.first[2], -x.first[3]};
        permutsFin[tmp] = 1;
        tmp[3] = -tmp[3];
        tmp[2] = -tmp[2];
        permutsFin[tmp] = 1;
        tmp[2] = -tmp[2];
        tmp[1] = -tmp[1];
        permutsFin[tmp] = 1;
    }
    for (auto const &x : permutsFin)
    {
        res.push_back(x.first);
    }
    return res;
}

int findRootNegOne(int q)
{
    int im = 0;
    for (int i = 1; i < q; i++)
    {
        if ((i * i) % q == q - 1)
        {
            im = i;
            break;
        }
    }
    return im;
}

vector<int> square(int q)
{
    vector<int> sq(q + 1);
    for (int i = 1; i <= q; ++i)
    {
        for (int j = 1; j <= q; ++j)
        {
            if ((i*i)%q == j)
            {
                sq[j] = i;
            }
        }
    }
    return sq;
}

int main()
{
    int p, q;
    cout << "Enter p:\n";
    cin >> p;
    cout << "Enter q:\n";
    cin >> q;
    int n = q * (q * q - 1) / 2;
    int imagin = findRootNegOne(q);
    vector<vector<int>> v;
    vector<int> invs(q + 1, 1);
    invs = inverse(q, invs);
    vector<int> sq = square(q);
    for (int k = 1; k <= n; ++k)
    {
        vector<int> A;
        A = numToMat(k, q, invs);
        v.push_back(A);
    }
    // string outfilename = "lpsP3Q13mat.txt";
    // ofstream outfile (outfilename);
    // for(int i = 0;i<n;++i){
    //     outfile<<i+1<<"\n";
    //     outfile<<v[i][0]<<" "<<v[i][1]<<"\n"<<v[i][2]<<" "<<v[i][3]<<"\n";
    // }
    // outfile.close();
    vector<vector<int>> sumsSol;
    sumsSol = sumOfFourSquares(p);
    cout << sumsSol.size() << " size\n";
    vector<vector<int>> gen;
    for (vector<int> x : sumsSol)
    {
        // cout<<"[ "<<x[0]<<" "<<x[1]<<" "<<x[2]<<" "<<x[3]<<" ]\n";
        vector<int> tmp{(q + (x[0] + imagin * x[1]) % q) % q, (q + (x[2] + x[3] * imagin) % q) % q, (q + ((q - x[2]) % q + x[3] * imagin) % q) % q, (q + (x[0] + (q - x[1] * imagin) % q) % q) % q};
        if ((q + (tmp[0] * tmp[3] - tmp[1] * tmp[2]) % q) % q != 1)
        {
            int sk = invs[sq[(q + (tmp[0] * tmp[3] - tmp[1] * tmp[2]) % q) % q]];
            tmp[0] = (tmp[0] * sk) % q;
            tmp[1] = (tmp[1] * sk) % q;
            tmp[2] = (tmp[2] * sk) % q;
            tmp[3] = (tmp[3] * sk) % q;
        }
        if (tmp[0] > (q - 1) / 2)
        {
            tmp[0] = (q - tmp[0]) % q;
            tmp[1] = (q - tmp[1]) % q;
            tmp[2] = (q - tmp[2]) % q;
            tmp[3] = (q - tmp[3]) % q;
        }
        cout << "[ " << tmp[0] << " " << tmp[1] << " " << tmp[2] << " " << tmp[3] << " ]\n";
        gen.push_back(tmp);
    }
    // vector<vector<int>> eList;
    // int g=gen.size();
    // for(int i=0;i<g;++i){
    //     int g1=gen[i][0];
    //     int g2=gen[i][1];
    //     int g3=gen[i][2];
    //     int g4=gen[i][3];
    //     for(int i=0;i<n;++i){
    //         int a,b,c;
    //         if((v[i][0]*g1+v[i][1]*g3) == 0){
    //             b = q;
    //             a = (v[i][2]*g1+v[i][3]*g3)%q;
    //             c = (v[i][2]*g2+v[i][3]*g4)%q;
    //         }
    //         else if((v[i][0]*g1+v[i][1]*g3)>(q-1)/2){
    //             a = (q-(v[i][0]*g1+v[i][1]*g3)%q)%q;
    //             b = (q-(v[i][2]*g1+v[i][3]*g3)%q)%q;
    //             c = (q-(v[i][0]*g2+v[i][1]*g4)%q)%q;
    //         }
    //         else{
    //             a = (v[i][0]*g1+v[i][1]*g3)%q;
    //             b = (v[i][2]*g1+v[i][3]*g3)%q;
    //             c = (v[i][0]*g2+v[i][1]*g4)%q;
    //         }
    //         int k = c*(q*q-1)/2+b*(q-1)/2+a;
    //         if(i+1<k){
    //             vector<int> tmp{i+1,k};
    //             eList.push_back(tmp);
    //         }
    //     }
    // }
    // outfilename = "lpsXp3q13.txt";
    // ofstream ofile (outfilename);
    // ofile<<"p "<<n<<"\n";
    // for(auto e:eList){
    //     // cout<<e[0]<<" "<<e[1]<<"\n";
    //     ofile<<"e "<<e[0]<<" "<<e[1]<<"\n";
    // }
    // ofile<<"e -1 -1"<<"\n";
    // ofile.close();
    return 0;
}