#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include <sstream>

using std::cout;
using std::ifstream;
using std::vector;
using std::string;
using std::ostringstream;

void main() {
	ifstream file;
	vector <string> inp;
	string tstr;
	string tout = "00";
	file.open("1.txt");
	while (getline(file,tstr)) {
		inp.push_back(tstr);
	}
	for (int i = 1; i < 12; i++)
	{
		vector <string> temp;
		int k = 0;
		for (unsigned int j = 0; j < inp[i].length(); j++)
		{
			string tstr = inp.at(i);
			if (tstr[j] == ' ') {
				temp.push_back(tout);
				k = 0;
			}
			else { 
				tout[k] = tstr[j];
				k = 1;
			}
		}
		temp.push_back(tout);
		string out;
		int tnum = stoi(temp.at(0));
		while (out != temp.at(temp.size() -1))
		{
			ostringstream Convert;
			tnum++;
			Convert << tnum;
			out = Convert.str();
			int q = 0;
			for (unsigned int i = 1; i < temp.size(); i++) {
				if (out == temp.at(i)) q++;
			}
			if (q == 0) cout << out;
			cout << ' ';
		}
		cout << "\nNext Line: ";
	}
	return;
}