 ///
 /// @file    Configuration.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-09-10 15:14:22
 ///
#include"Configuration.h"
#include<utility>
#include<iostream>
#include<fstream>
using std::ifstream;
using std::endl;
using std::cout;
Configuration::Configuration(const string &lhs)
:_path(std::move(lhs))
{
ifstream in(_path);
if(!in)
	cout<<"open error"<<endl;
else
{
	in>>_englishpath>>_chinesepath;
}
in.close();
}
string Configuration::getenglishpath()const
{
	return _englishpath;
}
string Configuration::getchinesepath() const
{
	return _chinesepath;
}

