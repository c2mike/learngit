 ///
 /// @file    template.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-09-10 14:20:28
 /// 
#include "template.h"
template <typename T>
template <typename... Args>
T* singleton<T>::getinstance(Args... args)
{
	if(!_pinstance)
	{
			_pinstance=new T(args...);
	}
	return _pinstance;
}
template <typename T>
void singleton<T>::destroy()
{
	if(_pinstance)
		delete _pinstance;
}

