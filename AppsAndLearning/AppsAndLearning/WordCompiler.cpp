#include<iostream>
#include<fstream>
#include<string>

using namespace std;



void main() {
	cout << "Enter the scrambled words:\n";
	string scram;
	string ans[1000];
	int n = 0;
	string res;
	cin >> scram;
	ifstream word;
	word.open("words.txt");
	while (word >> res)
	{
		int num = 0;
		string ts = scram;
		for (int i = 0; i < res.length(); i++)
		{
			int temp = 0;
			for (int j = 0; j < ts.length(); j++)
			{
				if (ts[j] == res[i]) {
					ts[j] = '!';
					temp++; num++;
					break;
				}
			}
			if (temp == 0) break;
			if (num == res.length()) ans[n++] = res;
		}
	}
	for (int i = 0; i <= n; i++)
	{
		cout << ans[i] << endl;
	}
}