#include <fstream>
#include <string>
#include <iostream>
#include "TextQuery.h"

using namespace std;

void runQueries(ifstream &infile)
{
	TextQuery tq(infile);
	string word;
	while(cin >> word && word != "q")
	{
		//cout << tq.query(word) << endl;
		print(cout, tq.query(word)) << endl;
	}
}

int main()
{
	ifstream file("text.txt");
	runQueries(file);
	file.close();
}