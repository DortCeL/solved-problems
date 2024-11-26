#include <bits/stdc++.h>
using namespace std;

double co_eff[100][100], res[100], factor;
int itr;

/*
3
3 -2 3 -1
-3 9 1 2
2 -1 -7 3
*/

void take_input(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n + 1; j++)
        {
            cin >> co_eff[i][j];
        }
    }
    cout << endl
         << "Iterations are:" << endl
         << endl;
    cout << "Itr" << "\t";
    for (int i = 1; i <= n; i++)
        cout << "X" << i << "\t";
    cout << "C" << n + 1 << endl;
    cout << "------------------------------------" << endl;
}

void print(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n + 1; j++)
        {
            cout << setprecision(2) << co_eff[i][j] << "\t";
        }
        cout << endl
             << "\t";
    }
    cout << endl;
}

int gauss_jordan(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (co_eff[i][i] == 0.0)
        {
            cout << "Mathematical Error!" << endl;
            return -1;
        }

                for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            factor = co_eff[j][i] / co_eff[i][i];
            for (int k = 1; k <= n + 1; k++)
            {
                co_eff[j][k] = co_eff[j][k] - factor * co_eff[i][k];
            }
            cout << ++itr << ")\t";
            print(n);
        }
    }
    return 1;
}

void solution_print(int n)
{
    for (int i = 1; i <= n; i++)
    {
        res[i] = co_eff[i][n + 1] / co_eff[i][i];
    }
    cout << "Final results are: " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << "x" << i << " = ";
        cout << res[i] << endl;
    }
}
int main()
{
    int n;
    // cout << "Enter the order of the matrix: ";
    cin >> n;
    take_input(n);
    int ret = gauss_jordan(n);
    if (ret == 1)
    {
        solution_print(n);
    }
    return 0;
}
