#pragma once
#include"define.h"
class symbol_list{
public:
	void type_list_push(const string& a);
	void  id_list_push(const string& a);
private:
	set<string> type_list;
	set<string> id_list;
};
