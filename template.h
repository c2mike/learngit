 ///
 /// @file    template.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-09-10 14:14:56
 template <typename T>
 class singleton
{
	public:
		template <typename ...Args>
			static T* getinstance(Args...args);
			static void destroy();
	private:
		singleton();
		~singleton();
		static T* _pinstance;
};
