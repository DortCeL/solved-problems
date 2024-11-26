#include <bits/stdc++.h>
using namespace std;

void displayMatrix(const vector<vector<double>>& mat) {
    int n = mat.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void displayAugmentedMatrix(const vector<vector<double>>& a, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2 * n; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void readMatrix(vector<vector<double>>& mat, int n) {
    cout << "Enter the elements of the " << n << "x" << n << " matrix row-wise:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> mat[i][j];
        }
    }
}

void gaussJordanElimination(vector<vector<double>>& a, int n) {
    // Create augmented matrix [a | I]
    vector<vector<double>> augmented(n, vector<double>(2 * n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            augmented[i][j] = a[i][j];
        }
        augmented[i][i + n] = 1;
    }

    // Applying Gauss-Jordan elimination with printing steps
    cout << "Initial Augmented Matrix:" << endl;
    displayAugmentedMatrix(augmented, n);

    for (int i = 0; i < n; ++i) {
        // Ensure the pivot is non-zero; if zero, swap rows
        if (augmented[i][i] == 0) {
            cout << "Mathematical Error: Matrix is singular!" << endl;
            exit(0);
        }

        // Scale row i to make augmented[i][i] equal to 1
        double scale = augmented[i][i];
        for (int j = i; j < 2 * n; ++j) {
            augmented[i][j] /= scale;
        }

        cout << "After scaling row " << i + 1 << ":" << endl;
        displayAugmentedMatrix(augmented, n);

        // Eliminate non-zero elements above and below the pivot
        for (int k = 0; k < n; ++k) {
            if (k != i) {
                double factor = augmented[k][i];
                for (int j = i; j < 2 * n; ++j) {
                    augmented[k][j] -= factor * augmented[i][j];
                }
                cout << "After eliminating column " << i + 1 << " in row " << k + 1 << ":" << endl;
                displayAugmentedMatrix(augmented, n);
            }
        }
    }

    // Copy the right half (inverse matrix) to original matrix 'a'
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = augmented[i][j + n];
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the matrix: ";
    cin >> n;

    vector<vector<double>> a(n, vector<double>(n));

    // Read the matrix from user input
    readMatrix(a, n);

    // Apply Gauss-Jordan elimination to find inverse with steps
    gaussJordanElimination(a, n);

    // Display the inverse matrix
    cout << "Inverse Matrix:" << endl;
    displayMatrix(a);

    return 0;
}
