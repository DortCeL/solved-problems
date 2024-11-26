//////////////////////////////////////Linear Regression
#include <iostream>
#include <vector>

using namespace std;

void linearRegression(const vector<double> &x, const vector<double> &y, double &a, double &b)
{
  int n = x.size();
  double sumX = 0, sumX2 = 0, sumY = 0, sumXY = 0;

  for (int i = 0; i < n; i++)
  {
    sumX += x[i];
    sumX2 += x[i] * x[i];
    sumY += y[i];
    sumXY += x[i] * y[i];
  }

  b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
  a = (sumY - b * sumX) / n;
}

int main()
{
  int n;
  cout << "Enter the number of data points: ";
  cin >> n;

  vector<double> x(n), y(n);
  cout << "Enter the data points (xi and yi): " << endl;
  for (int i = 0; i < n; i++)
  {
    cout << "x[" << i + 1 << "]: ";
    cin >> x[i];
    cout << "y[" << i + 1 << "]: ";
    cin >> y[i];
  }

  double a, b;
  linearRegression(x, y, a, b);

  cout << "The values of a and b are: " << endl;
  cout << "a (intercept): " << a << endl;
  cout << "b (slope): " << b << endl;

  return 0;
}
//////////////////////////////////////////////////////////////////Curve Fitting
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void curveFitting(const vector<double> &x, const vector<double> &y, double &a, double &b)
{
  int n = x.size();
  double sumX = 0, sumX2 = 0, sumY = 0, sumXY = 0;

  for (int i = 0; i < n; i++)
  {
    double logX = log(x[i]);
    double logY = log(y[i]);
    sumX += logX;
    sumX2 += logX * logX;
    sumY += logY;
    sumXY += logX * logY;
  }

  double log_b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
  double log_a = (sumY - log_b * sumX) / n;

  a = exp(log_a);
  b = exp(log_b);
}

int main()
{
  int n;
  cout << "Enter the number of data points: ";
  cin >> n;

  vector<double> x(n), y(n);
  cout << "Enter the data points (xi and yi): " << endl;
  for (int i = 0; i < n; i++)
  {
    cout << "x[" << i + 1 << "]: ";
    cin >> x[i];
    cout << "y[" << i + 1 << "]: ";
    cin >> y[i];
  }

  double a, b;
  curveFitting(x, y, a, b);

  cout << "The values of a and b are: " << endl;
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;

  return 0;
}
//////////////////////////////////////////////////Lagrange Interpolation
#include <iostream>
#include <vector>

using namespace std;

double lagrangeInterpolation(const vector<double> &X, const vector<double> &Y, double Xp)
{
  int n = X.size();
  double Yp = 0;

  for (int i = 0; i < n; i++)
  {
    double pXp = 1;
    for (int j = 0; j < n; j++)
    {
      if (i != j)
      {
        pXp *= (Xp - X[j]) / (X[i] - X[j]);
      }
    }
    Yp += pXp * Y[i];
  }

  return Yp;
}

int main()
{
  int n;
  cout << "Enter the number of data points: ";
  cin >> n;

  vector<double> X(n), Y(n);
  cout << "Enter the data points (Xi and Yi): " << endl;
  for (int i = 0; i < n; i++)
  {
    cout << "X[" << i + 1 << "]: ";
    cin >> X[i];
    cout << "Y[" << i + 1 << "]: ";
    cin >> Y[i];
  }

  double Xp;
  cout << "Enter the independent variable Xp: ";
  cin >> Xp;

  double Yp = lagrangeInterpolation(X, Y, Xp);

  cout << "The interpolated value Yp at Xp = " << Xp << " is: " << Yp << endl;

  return 0;
}
/////////////////////////////////////////////////////newtonDividedDifference
#include <iostream>
#include <vector>

using namespace std;

double newtonDividedDifference(const vector<double> &X, vector<vector<double>> &Y, double Xp)
{
  int n = X.size();

  // Calculating the divided difference table
  for (int i = 1; i < n; i++)
  {
    int k = i;
    for (int j = 0; j < n - i; j++)
    {
      Y[i][j] = (Y[i - 1][j + 1] - Y[i - 1][j]) / (X[k] - X[j]);
      k++;
    }
  }

  // Calculating the value of Yp by applying Newton Divided Difference Formula
  double Yp = Y[0][0];
  for (int i = 1; i < n; i++)
  {
    double product_of_x = 1;
    for (int j = 0; j < i; j++)
    {
      product_of_x *= (Xp - X[j]);
    }
    Yp += product_of_x * Y[i][0];
  }

  return Yp;
}

int main()
{
  int n;
  cout << "Enter the number of data points: ";
  cin >> n;

  vector<double> X(n);
  vector<vector<double>> Y(n, vector<double>(n));

  cout << "Enter the data points (Xi and Yi): " << endl;
  for (int i = 0; i < n; i++)
  {
    cout << "X[" << i + 1 << "]: ";
    cin >> X[i];
    cout << "Y[" << i + 1 << "]: ";
    cin >> Y[0][i]; // The first row of Y is the input Y values
  }

  double Xp;
  cout << "Enter the independent variable Xp: ";
  cin >> Xp;

  double Yp = newtonDividedDifference(X, Y, Xp);

  cout << "The interpolated value Yp at Xp = " << Xp << " is: " << Yp << endl;

  return 0;
}
///////////////////////polynomial
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to perform Gaussian Elimination
vector<double> gaussianElimination(vector<vector<double>> A, vector<double> B, int degree)
{
  int n = degree + 1;

  for (int i = 0; i < n; i++)
  {
    // Partial pivoting
    for (int k = i + 1; k < n; k++)
    {
      if (abs(A[i][i]) < abs(A[k][i]))
      {
        for (int j = 0; j <= n; j++)
        {
          swap(A[i][j], A[k][j]);
        }
        swap(B[i], B[k]);
      }
    }

    // Forward elimination
    for (int k = i + 1; k < n; k++)
    {
      double t = A[k][i] / A[i][i];
      for (int j = 0; j <= n; j++)
      {
        A[k][j] -= t * A[i][j];
      }
      B[k] -= t * B[i];
    }
  }

  // Backward substitution
  vector<double> coeffs(n);
  for (int i = n - 1; i >= 0; i--)
  {
    coeffs[i] = B[i];
    for (int j = i + 1; j < n; j++)
    {
      coeffs[i] -= A[i][j] * coeffs[j];
    }
    coeffs[i] /= A[i][i];
  }

  return coeffs;
}

int main()
{
  int n, degree;
  cout << "Enter the number of data points: ";
  cin >> n;

  vector<double> x(n), y(n);
  cout << "Enter the data points (xi yi):" << endl;
  for (int i = 0; i < n; i++)
  {
    cin >> x[i] >> y[i];
  }

  cout << "Enter the degree of the polynomial: ";
  cin >> degree;

  // Step 4: Initialize x0 = n;
  vector<double> sum_x(2 * degree + 1, 0.0);
  sum_x[0] = n;

  // Step 5: Calculate sum of powers of x
  for (int i = 1; i < 2 * degree + 1; i++)
  {
    for (int j = 0; j < n; j++)
    {
      sum_x[i] += pow(x[j], i);
    }
  }

  // Step 6: Calculate sum of y * x^i
  vector<double> sum_y(degree + 1, 0.0);
  for (int i = 0; i < degree + 1; i++)
  {
    for (int j = 0; j < n; j++)
    {
      sum_y[i] += y[j] * pow(x[j], i);
    }
  }

  // Step 7 and 8: Set matrix for Gaussian Elimination
  vector<vector<double>> A(degree + 1, vector<double>(degree + 1, 0.0));
  vector<double> B(degree + 1, 0.0);

  for (int i = 0; i <= degree; i++)
  {
    for (int j = 0; j <= degree; j++)
    {
      A[i][j] = sum_x[i + j];
    }
    B[i] = sum_y[i];
  }

  // Step 9: Find coefficients using Gaussian Elimination
  vector<double> coeffs = gaussianElimination(A, B, degree);

  // Output the coefficients
  cout << "The coefficients of the polynomial are:" << endl;
  for (int i = 0; i <= degree; i++)
  {
    cout << "a" << i << " = " << coeffs[i] << endl;
  }

  return 0;
}
