#include <bits/stdc++.h>

using namespace std;

int maxArea(vector<int> &height)
{
	int n = height.size();

	int h = 0;
	int w = 0;
	int area = 0;

	int i = 0;
	int j = n - 1;

	while (i < j)
	{
		w = j - i;
		h = min(height[i], height[j]);
		area = max(area, h * w);
		if (height[i] < height[j])
			i++;
		else
			j--;
	}

	return area;
}

int main(void)
{
	system("cls");
	vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
	cout << maxArea(height) << endl;
}