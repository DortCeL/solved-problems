#include <bits/stdc++.h>
using namespace std;

double co_eff[100][100], res[100], factor;
int itr = 0;

/*
3
3 -2 3 -1
-3 9 1 2
2 -1 -7 3
*/

void take_input(int n)
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n + 1; j++)
            cin >> co_eff[i][j];

    cout << endl
         << "Iterations after forward elimination are:" << endl
         << endl;

    cout << "Itr" << "\t";

    for (int i = 1; i <= n; i++)
        cout << "x" << i << "\t";
    cout << "C" << endl;
    cout << "------------------------------------" << endl;
}

void print(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n + 1; j++)
        {
            cout << setw(15) << setprecision(2) << co_eff[i][j] << "\t";
        }
        cout << endl
             << "\t";
    }
    cout << endl;
}

void gauss_elimination(int n) // forward elimination
{
    for (int i = 1; i <= n - 1; i++)
    { // all the row except last
        for (int j = i + 1; j <= n; j++)
        {                                         // all the row accept first row
            factor = co_eff[j][i] / co_eff[i][i]; // coeff of 2nd row/coeff of 1st row
            for (int k = 1; k <= n + 1; k++)
            { // access the columns
                co_eff[j][k] = co_eff[j][k] - factor * co_eff[i][k];
            }
        }
        cout << ++itr << ")\t";
        print(n);
    }
}

void solution_print(int n) // backward substitution
{
    res[n] = co_eff[n][n + 1] / co_eff[n][n];
    for (int i = n - 1; i >= 1; i--)
    { // all the row accept last row
        double sum = 0;
        for (int j = i + 1; j <= n; j++)
        {
            sum = sum + co_eff[i][j] * res[j]; // multiply the coefficient with res[j] and sum up all together.
        }
        res[i] = (1 / co_eff[i][i]) * (co_eff[i][n + 1] - sum);
    }
    cout << "Final result after forward substitution" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << "x" << i << " = ";
        cout << res[i] << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    take_input(n);
    gauss_elimination(n);
    solution_print(n);

    return 0;
}
