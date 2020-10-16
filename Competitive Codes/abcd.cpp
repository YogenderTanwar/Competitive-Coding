// output generator file
#include<bits/stdc++.h>
using namespace std;
#define int int64_t

int numberOfTestCaseFiles = 10;

int32_t main() {
	for (int fileIdx = 1; fileIdx <= numberOfTestCaseFiles; ++fileIdx) {
		// freopen("in.txt" , "r" , stdin);
		ifstream fin;
		fin.open("in" + to_string(fileIdx) + ".txt");
		ofstream fout;
		fout.open("out" + to_string(fileIdx) + ".txt" );

		//input N from file
		int N;
		fin >> N;

		int sz;
		fin >> sz;
		// input vector from file
		vector<int> v(sz);
		for (auto& i : v) {
			fin >> i;
		}
		vector< int > v2(sz);
		for (auto &i : v2)  {
			fin >> i;
		}

		// generate the output file
		fout << "N was " << N << endl;
		fout << "Size of vector was " << sz << endl;
		fout << "sum : " << endl;
		for (int i = 0 ; i < sz; ++i)
			fout << (v[i] + v2[i]) % (1000) << " ";
		fout << endl;

		cout << "File out" << fileIdx << ".txt generated!" << endl;
	}

}