 ///
 /// @file    Dictionary.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-09-11 17:31:21
 ///
#ifndef __Dictionary__
#define __Dictionary__
#include <iostream>
#include <string>
#include <map>
#include <memory>
#include "Splittool.h"
#include <utility>
#include <set>
using std::set;
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::shared_ptr;
using std::pair;
class Dictionary
{
	public:
		Dictionary(string&,string&,string&,string&,Splittool*);	
		void chandleWord(string&);
		void ehandleWord(string&);
		void buildDict();
		void dictStory();
		map<string,int>& getmap();
		void buildvector();
		vector<pair<string,int>>& getvector();
		void display();
		set<string>& getset();
	private:
		string _chineseconfigtxt;
		string _englishconfigtxt;
		string _dictstorydir;
		string _stoppath;
		vector<string> _chinesepath;
		vector<string> _englishpath;
		set<string> _stopword;
		shared_ptr<Splittool> _split;
		map<string,int> _dict;
		vector<pair<string,int>> _vec;
};
#endif                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
