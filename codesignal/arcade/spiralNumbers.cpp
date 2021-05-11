// Construct a square matrix with a size N × N containing integers from 1 to N * N in a spiral order, starting from top-left and in clockwise direction.

// Example

// For n = 3, the output should be

// spiralNumbers(n) = [[1, 2, 3],
//                     [8, 9, 4],
//                     [7, 6, 5]]

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> spiralNumbers(int n)
{

    // 1,2,3
    // 4,5,6
    // 7,8,9

    //1,2,3
    //8,9,4
    //7,6,5

    vector<vector<int>> v(n, vector<int>(n));

    int sw = 0, ew = n - 1, sh = 0, eh = n - 1;
    int count = 1;
    for (int lev = 0; lev < n / 2; lev++)
    {

        // top
        for (int i = sw; i <= ew; i++)
        {
            // cout<<sh<<"\t"<<i<<"\t"<< count++<<endl;
            v[sh][i] = count++;
        }
        sh++;

        // rght
        for (int i = sh; i <= eh; i++)
        {
            // cout<<i<<"\t"<<ew<<"\t"<< count++<<endl;
            v[i][ew] = count++;
        }
        ew--;
        //bottom
        for (int i = ew; i >= sw; i--)
        {
            // cout<<eh<<"\t"<<i<<"\t"<< count++<<endl;
            v[eh][i] = count++;
        }
        eh--;

        // left
        for (int i = eh; i >= sh; i--)
        {
            // cout<<i<<"\t"<<sw<<"\t"<< count++<<endl;
            v[i][sw] = count++;
        }
        sw++;
    }
    if (n & 1)
    {
        v[n / 2][n / 2] = count;
    }
    return v;
}
