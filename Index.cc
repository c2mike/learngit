 ///
 /// @file    Index.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-09-12 19:40:18
 ///
 
#include"Index.h"
Index::Index(const string& targetfile,const vector<pair<string,int>>& word,const set<string>& _stopword)
:_targetfile(targetfile),_word(word),_stop(_stopword)
{	
}
bool Index::isenglish(string s)
{
	auto it=s.begin();
	if((*it>'a'&&*it<'z')||(*it>'A'&&*it<'Z'))
//		if(*it>=0)
		return true;
	else
		return false;
}
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
void Index::buildIndex()
{
	for(size_t i=0;i<_word.size();i++)
	{
		if(isenglish(_word[i].first))
		{
			for(auto ch:_word[i].first)
			{
				string sch(ch,1);
				auto ret=_index.find(sch);
				if(ret==_index.end())
				{
					set<int> intset;
					intset.insert(i);
					_index[sch]=intset;
				}
				else
				{
					ret->second.insert(i);
				}
			}
		}
		else
		{
	vector<string> hz=getcsubstr(_word[i].first);
	
			for(auto each:hz)
			{
				auto iter=_stop.find(each);
				if(iter!=_stop.end())
					continue;
				auto res=_index.find(each);
					if(res==_index.end())
					{
						set<int> intset;
						intset.insert(i);
						_index[each]=intset;
					}
					else
						res->second.insert(i);
			}
		}
	}
}
void Index::storyIndex()
{
	ofstream of(_targetfile);
		if(!of)
		{
			cout<<"create targetfile fail"<<endl;
			return;
		}
	for(auto each:_index)
	{
		of<<each.first<<" ";
		for(auto each2:each.second)
		{
			of<<each2<<" ";
		}
		of<<endl;
	}
	of.close();
}














