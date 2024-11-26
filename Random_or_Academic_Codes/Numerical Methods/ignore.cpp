
int n;
// cout<<"Enter the order of the matrix: ";
cin >> n;
take_input(n);
gauss_elimi

ion_print(int n) // backward substitution
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

  for (int j = 1; j <= n + 1; j++)
  {
    cout << setprecision(2) << co_eff[i][j] << "\t";
  }

  gfdgdffd