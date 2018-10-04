 ///
 /// @file    main.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-09-13 15:15:51
 ///
 
#include"Configuration.h"
#include"Dictionary.h"
#include"Index.h"
#include"Splittool.h"
//#include"template.h"
#include"template.cc"
#include<memory>
using std::unique_ptr;
template<typename T>
T* singleton<T>::_pinstance=NULL;
int main()
{
string path="./config.txt";
string _stopwordpath="./stop_words_zh.txt";
string storepath="./server/data/dict.txt";
string indexpath="./server/data/index.txt";
Configuration* _pconfig=singleton<Configuration>::getinstance(path);
Splittool* sp=new Splittool();
Dictionary* _pdictionary=singleton<Dictionary>::getinstance(_pconfig->getchinesepath(),_pconfig->getenglishpath(),storepath,_stopwordpath,sp);
_pdictionary->buildDict();
_pdictionary->dictStory();
_pdictionary->buildvector();
unique_ptr<Index> ind(new Index(indexpath,_pdictionary->getvector(),_pdictionary->getset()));
ind->buildIndex();
ind->storyIndex();
}
