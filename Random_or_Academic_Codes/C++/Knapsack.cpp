#include <bits/stdc++.h>
using namespace std;

int main (void)
{
    unordered_map<int, vector<int>> sack;
    sack[1] = {2,3};
    sack[2] = {3,4};
    sack[3] = {4,5};
    sack[4] = {5,6};

    int n = 4;
    int W = 5;

    int V[n+1][W+1];

    for (int i=0; i<=n; i++)
        V[0][i] = 0;
    for (int i=0; i<=W; i++)
        V[i][0] = 0;

    for (int i=1; i<=n; i++)
        for (int w=0; w <= W; w++) {
            int item_weight = sack[i][0];
            int item_benefit = sack[i][1];
            int remaining_weight =  w - item_weight;

            if (item_weight <= w) {
                V[i][w] = max(item_benefit + V[i-1][remaining_weight], V[i-1][w]);
            else 
                V[i][w] = V[i-1][w];
            

            // if ( sack[i][0] <= w )
            //     if ( item_benefit +  V[i-1][remaining_weight]  > V[i-1][w] )
            //         V[i][w] = item_benefit +  V[i-1][remaining_weight];
            //     else
            //         V[i][w] = V[i-1][w];
                

            // else
            //     V[i][w] = V[i-1][w];

        }


    for (int i=0; i<=n; i++) {
        for (int j=0; j<=W; j++)
            cout << V[i][j] << " ";

        cout << endl;
    }


}
