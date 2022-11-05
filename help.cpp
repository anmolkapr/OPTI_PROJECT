#include <bits/stdc++.h>
using namespace std;

int randomarray[362881][9];
int ctr ;

void permute(string &a, int l, int r)
{
	if (l == r)
		{
      int i;
      for(i = 0 ; i < a.length();i++){
          randomarray[ctr][i] = a[i] - 'A';
      }
      ctr++;
    } 
	else
	{
		for (int i = l; i <= r; i++)
		{
      swap(a[l], a[i]);
			permute(a, l+1, r);
			swap(a[l], a[i]);
		}
	}
}

int main()
{
  ctr = 0;
	string str = "ABCDEFGHI";
	int n = str.size();
	permute(str, 0, n-1);
  int i;
  for(i = 0 ;i < 362881;i++){
    int j;
    for(j = 0 ; j < 9;j++){
      cout << randomarray[i][j] << ' ';
    }
    cout << endl;
  }
	return 0;
}

