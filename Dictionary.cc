 ///
 /// @file    Dictionary.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-09-11 22:11:48
 ///
#include"Dictionary.h"
#include<unistd.h>
#include <fstream>
#include <cctype>
using std::ifstream;
using std::ofstream;
Dictionary::Dictionary(string& s1,string& s2,string& s3,string& s4,Splittool* sp)
:_chineseconfigtxt(s1),_englishconfigtxt(s2),_dictstorydir(s3),_stoppath(s4),_split(sp)
{
	ifstream cconfigtxt(_chineseconfigtxt.c_str());
	ifstream econfigtxt(_englishconfigtxt.c_str());
	ifstream _stop(_stoppath);
		if(_stop)
		{
			string s2;
			while(_stop>>s2)
			{
				_stopword.insert(s2);
			}
		}
	if(cconfigtxt)
	{
		string s;
		while(cconfigtxt>>s)
		{
			_chinesepath.push_back(s);
		}
	}
	else
		cout<<"open chinesttxt fail"<<endl;
	if(econfigtxt)
	{
		string s0;
		while(econfigtxt>>s0)
		{
			_englishpath.push_back(s0);
		}
	}
	else
		cout<<"open englishttxt fail"<<endl;
	_vec.reserve(10000);
}
void Dictionary::chandleWord(string& s1)
{
	for(auto it=s1.begin();it!=s1.end();it++)
	{
		if(isdigit(*it)|ispunct(*it))
		{	s1.erase(it);
			it--;
		}
	}
}
void Dictionary::ehandleWord(string& s1)
{
	for(auto it=s1.begin();it!=s1.end();it++)
	{
		if(isupper(*it))
		{
			*it=*it+32;
		}
		if(isdigit(*it)|ispunct(*it))
		{
			s1.erase(it);
			it--;
		}
	}
}
void Dictionary::buildDict()
{	
	string temp;
	for(auto it:_englishpath)
	{
		 ifstream in(it);
			 if(!in)
			 {
				 cout<<"open cfile fail"<<endl;
				 return;
			 }
		 while(in>>temp)
		 {
			 ehandleWord(temp);
			 if(temp==""|temp==" ")
				 continue;
			 auto it2=_dict.find(temp);
			if(it2==_dict.end())
			{
				_dict[temp]=1;
			}
			else
				++_dict[temp];
		 }
		in.close();
	}
	for(auto it3:_chinesepath)
	{
		ifstream in2(it3);
			if(!in2)
			{
				cout<<"open chinesetxt fail"<<endl;
				return;
			}
			while(getline(in2,temp))
			{
				_split->cut(temp);
				vector<string> ret=_split->getvector();
				for(auto it4:ret)
				{
					auto iter=_stopword.find(it4);
					if(iter!=_stopword.end())
						continue;
						ehandleWord(it4);
						if(it4==""|it4==" ")
							continue;
					if(_dict.find(it4)!=_dict.end())
					{
						_dict[it4]++;
					}
					else
						_dict[it4]=1;
				}
			}
			in2.close();
	}
}
void Dictionary::dictStory()
{
	ofstream of(_dictstorydir);
	for(auto it:_dict)
	{
		of<<it.first<<" "<<it.second<<endl;
	}
	of.close();
}
void Dictionary::buildvector()
{
	for(auto it:_dict)
		_vec.push_back(it);
}
vector<pair<string,int>>& Dictionary::getvector()
{
	return _vec;
}
void Dictionary::display()
{
	auto it=_dict.begin();
	for(size_t i=0;i<100;i++)
	{
		cout<<it->first<<" "<<it->second<<endl;
		it++;
	}
}
set<string>& Dictionary::getset()
{
			return _stopword;
}




















