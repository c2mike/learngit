 ///
 /// @file    Nocopyable.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-09-10 13:36:05
 ///
#ifndef __nocopyable__
#define __nocopyable__
class nocopyable
{
	public:
	nocopyable()=default;
	~nocopyable()=default;
	private:
	nocopyable(const nocopyable&);
	nocopyable& operator=(const nocopyable&);
};
#endif
