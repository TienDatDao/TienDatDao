#include<bits/stdc++.h>

#define N 1000001
using namespace std;

bool check[N];

int main() {
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++)
		check[i] = true;
	for (int i = 2; i<= sqrt(n); i++)
	{
		if (check[i] == true)
		{
			for (int j = i * i; j <= n; j = j + i)
				check[j] = false;
		}	
	}
}
