 ///
 /// @file    Configuration.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-09-10 13:43:08
 ///
#ifndef __Configuration__
#define __Configuration__
#include <string>
#include "Nocopyable.h"
using std::string;
class Configuration
:public nocopyable
{
	public:
		Configuration(const string&);
		string getenglishpath() const;
		string getchinesepath() const;
	private:
		string _path;
		string _englishpath;
		string _chinesepath;
};
#endif

