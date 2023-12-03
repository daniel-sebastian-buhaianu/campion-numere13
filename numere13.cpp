#include <fstream>
using namespace std;
int main()
{
	ifstream f("numere13.in");
	ofstream g("numere13.out");
	int C;
	f >> C;
	if (C == 1)
	{
		int n;
		f >> n;
		int x = 1;
		for (int i = 1; i <= n; i++)
		{
			int pas;
			f >> pas;
			x = pas == 1 ? x+i : x+i+1;
		}
		f.close();
		g << x;
	}
	else
	{
		int k;
		f >> k;
		f.close();
		int x = 1, lvl = 1, sst, sdr;
		sst = sdr = x;
		while (k > x+lvl-1)
		{
			x += lvl;
			lvl++;
			sst += x;
			sdr += x+lvl-1;
		}
		if (k == x)
			g << sst;
		else if (k == x+lvl-1)
			g << sdr;
		else
		{
			int s = 0;
			do
			{
				s += k;
				k = k-lvl+1;
				x = x-lvl+1;
				lvl--;
			} while (lvl > 0 && k-lvl+1 < x);
			do
			{
				s += k;
				k = k-lvl;
				lvl--;
			} while (k >= 1);
			g << s;
		}
	}
	g.close();
	return 0;
}

