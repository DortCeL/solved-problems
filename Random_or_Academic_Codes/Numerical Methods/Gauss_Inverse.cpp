//! inverse matrix with gauss jordan

#include <bits/stdc++.h>
using namespace std;

void gaussJordan(vector<vector<double>> &a, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i][i] == 0)
        {
            cout << "Mathematical Error!" << endl;
            return;
        }
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                double pivot = a[j][i] / a[i][i];
                for (int k = 0; k < 2 * n; k++)
                {
                    a[j][k] = a[j][k] - pivot * a[i][k];
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        double diagElement = a[i][i];
        for (int j = 0; j < 2 * n; j++)
        {
            a[i][j] = a[i][j] / diagElement;
        }
    }
}

void printMatrix(const vector<vector<double>> &a, int n)
{
    cout << fixed << setprecision(5);
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j < 2 * n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the order of matrix: ";
    cin >> n;

    vector<vector<double>> a(n, vector<double>(2 * n));
    cout << "Enter the elements of the matrix row-wise:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = n; j < 2 * n; j++)
        {
            if (i == (j - n))
                a[i][j] = 1;
            else
                a[i][j] = 0;
        }
    }

    gaussJordan(a, n);

    cout << "The inverse matrix is:" << endl;
    printMatrix(a, n);

    return 0;
}
