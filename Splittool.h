 ///
 /// @file    Splittool.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-09-11 13:39:47
 ///
#ifndef __Splittool__
#define __Splittool__
#include <iostream>
#include <vector>
#include <string>
#include "../cppjieba/include/cppjieba/Jieba.hpp"
using std::string;
using std::vector;
using std::cout;
using std::endl;
class Splittool
{
	public:
	Splittool(string s1="../cppjieba/dict/jieba.dict.utf8"
			,string s2="../cppjieba/dict/hmm_model.utf8"
			,string s3="../cppjieba/dict/user.dict.utf8"
			,string s4="../cppjieba/dict/idf.utf8"
			,string s5="../cppjieba/dict/stop_words.utf8");
	void cut(string);
	vector<string>& getvector();
	private:
	vector<string> result;
	cppjieba::Jieba _jieba;
};
#endif
