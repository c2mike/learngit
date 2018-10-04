 ///
 /// @file    copy.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-09-30 09:50:55
 ///
//test git  
#include <iostream>
using std::cout;
using std::endl;
vector<string> Index::getcsubstr(string s)
{	
	vector<string> temp;
	for(size_t i=0;i<s.size();i++)
	{	
		unsigned char c=(unsigned)s[i];
		if(c>=0xFC)
		{
			temp.push_back(s.substr(i,6));
			i=i+5;
			continue;
		}
		if(c>=0xF8)
		{
			temp.push_back(s.substr(i,5));
			i=i+4;
			continue;
		}
		if(c>=0xF0)
		{
			temp.push_back(s.substr(i,4));
			i=i+3;
			continue;
		}
		if(c>=0xE0)
		{
			temp.push_back(s.substr(i,3));
			i=i+2;
			continue;
		}
		if(c>=0xC0)
		{
			temp.push_back(s.substr(i,2));
			i=i+1;
			continue;
		}
		if(c>=0x00)
		{
			temp.push_back(s.substr(i,1));
			continue;
		}
	}
	return temp;
}
