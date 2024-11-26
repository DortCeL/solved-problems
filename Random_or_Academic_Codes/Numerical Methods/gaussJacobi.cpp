#include <bits/stdc++.h>
using namespace std;

double co_eff[100][100], res[100], total, temp[100], error, permit_error = 0.01, temp_error;

void take_input(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n + 1; j++)
        {
            cin >> co_eff[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
        res[i] = 0;
}

void jacobi(int n)
{
    int iteration = 0;
    do
    {
        cout << "Iteration " << iteration << ":" << endl;
        temp_error = 0;
        for (int i = 1; i <= n; i++)
        {
            total = 0;
            for (int j = 1; j <= n; j++)
            {
                if (i != j)
                {
                    total += co_eff[i][j] * res[j];
                }
            }
            temp[i] = (co_eff[i][n + 1] - total) / co_eff[i][i];
            error = fabs(res[i] - temp[i]);
            if (error > temp_error)
            {
                temp_error = error;
            }
            cout << "x" << i << " = " << temp[i] << endl;
        }
        cout << "Max error in iteration " << iteration << " = " << temp_error << endl;
        cout << endl;

        for (int i = 1; i <= n; i++)
        {
            res[i] = temp[i];
        }
        iteration++;
    } while (temp_error >= permit_error);
}

void solution_print(int n)
{
    cout << "Solution after convergence:" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << "x" << i << " = " << res[i] << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    take_input(n);
    jacobi(n);
    solution_print(n);
    return 0;
}
