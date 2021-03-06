
#ifndef TEXTQUERY_H_
#define TEXTQUERY_H_

#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <memory>
#include <sstream>
#include "QueryResult.h"

using namespace std;

class TextQuery
{
public:
	// using line_no = vector<string>::size_type;
	TextQuery(ifstream&);
	~TextQuery();
	QueryResult query(const string&) const;

private:
	shared_ptr<vector<string>> file;
	// 每个单词到它所在的行号的集合的映射
	map<string, shared_ptr<set<int>>> wm;
	
};

#endif