 ///
 /// @file    Index.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-09-12 17:03:50
 ///
#ifndef __index__
#define __index__
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <utility>
#include <vector>
#include <fstream>
using std::ofstream;
using std::map;
using std::vector;
using std::pair;
using std::string;
using std::cout;
using std::endl;
using std::set;
class Index
{
	public:
		Index(const string&,const vector<pair<string,int>>&,const set<string>&);
		void buildIndex();
		void storyIndex();
	private:
		vector<string> getcsubstr(string);
		bool isenglish(string);
		string _targetfile;
		vector<pair<string,int>> _word;
		map<string,set<int>> _index;
		set<string> _stop;
};
#endif
