#include<bits/stdc++.h>

using namespace std;

#define MAX 3

int n = MAX;

vector<vector<double>> a(MAX, vector<double>(MAX + 1));
vector<double> x(MAX);

void readCoefficient()
{
    cout << "Enter the coefficients of the matrix:" << endl;
    for (int k = 0; k < n; k++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            cin >> a[k][j];
        }
    }
}

void display()
{
    cout << "Coefficient Matrix:" << endl;
    for (int k = 0; k < n; k++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            cout << a[k][j] << " ";
        }
        cout << endl;
    }
}

void gauss_elimination()
{
    double pivot;
    for (int i = 0; i < n; i++)
    {
        if (a[i][i] == 0)
        {
            cout << "Mathematical Error" << endl;
            return;
        }
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                pivot = a[j][i] / a[i][i];
                for (int k = 0; k < n + 1; k++)
                {
                    a[j][k] = a[j][k] - pivot * a[i][k];
                }
            }
        }

        cout << "Matrix after step " << i + 1 << " of Gaussian Jordan:" << endl;
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n + 1; col++)
            {
                cout << a[row][col] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        x[i] = a[i][n] / a[i][i];
    }
}

int main()
{
    readCoefficient();
    display();
    gauss_elimination();

    cout << "Solution Vector:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "x[" << i + 1 << "] = " << x[i] << endl;
    }

    return 0;
}
