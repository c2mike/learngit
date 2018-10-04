 ///
 /// @file    Splittool.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-09-11 14:00:11
 ///
#include"Splittool.h"
Splittool::Splittool(string s1,string s2,string s3,string s4,string s5)
:_jieba(s1,s2,s3,s4,s5)
{

}
void Splittool::cut(string s)
{
		_jieba.Cut(s,result);
}
vector<string>& Splittool::getvector()
{
	return result;
}
