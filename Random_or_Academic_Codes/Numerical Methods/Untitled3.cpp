#include <bits/stdc++.h>
using namespace std;
double coeff[100][100], res[100], factor;

//! gauss elimination

void gauss_elem(int n)
{
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            factor = coeff[j][i] / coeff[i][i];
            for (int k = 1; k <= n + 1; k++)
                coeff[j][k] = coeff[j][k] - factor * (coeff[i][k]);
        }
    }
}
void print_sol(int n)
{
    res[n] = coeff[n][n + 1] / coeff[n][n];
    for (int i = n - 1; i >= 1; i--)
    {
        double sum = 0;
        for (int j = 1; j <= n; j++)
            sum += coeff[i][j] * res[j];
        res[i] = (coeff[i][n + 1] - sum) / coeff[i][i];
    }
    for (int i = 1; i <= n; i++)
        cout << "x" << i << "=" << res[i] << endl;
}

//! jacobi
/*
double temp[100],temp_error,error,permitted_error=0.000001,total;
void jacobi(int n)
{
    do{
        temp_error=0;
        for(int i=1;i<=n;i++)
        {
            total=0;
            for(int j=1;j<=n;j++)
            {
                if(i!=j)
                    total+=coeff[i][j]*res[j];
            }
            temp[i]=(coeff[i][n+1]-total)/coeff[i][i];
            error=fabs(res[i]-temp[i]);
            if(error>temp_error)
                temp_error=error;

        }
        for(int i=1;i<=n;i++)
            res[i]=temp[i];
    }while(temp_error>=permitted_error);
}

void print_sol(int n)
{
    for(int i=1;i<=n;i++)
        cout<<"x"<<i<<"="<<res[i]<<endl;
}
*/

void print(int n, vector<vector<double>> &coeff)
{
    cout << fixed << setprecision(5);
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j < 2 * n; j++)
            cout << coeff[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> coeff[i][j];

    gauss_elem(n);
    print_sol(n);
    return 0;
}
/*
3
3 -2 3 -1
-3 9 1 2
2 -1 -7 3
*/
