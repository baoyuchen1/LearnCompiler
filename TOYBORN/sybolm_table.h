#pragma once
#include"define.h"
class scope_node;
struct parameter{
	list<string> parameter_type;
};
struct sy_type_node{
	string name;
	int offset;
	int size;
	scope_node* currrent_scope;
};
struct sy_id_node{
	string name;
	int offset;
	string type;
};
struct sy_fuc_node{
	string name;
	int offset;
	string return_type;
	int par_num; 
	bool is_def;
	scope_node* currrent_scope;
	parameter* fuc_parameter;
};

class scope_node
{
	friend class analyze;
	friend class lex;
	string scope_name;
	scope_node* parent;
	map< string, sy_fuc_node*> fuc_table;
	map<string, sy_id_node*> id_table;
	map<string,sy_type_node*> type_table;
public:
	scope_node():scope_name(""),parent(0){}
	void init(){
		sy_type_node* int_node = new sy_type_node();
		int_node->name = "int";
		int_node->offset = 0;
		int_node->size = 4;
		int_node->currrent_scope = new scope_node("int", this);
		type_table["int"] = int_node;
		scope_name = "_golbal";
	}
	void fuc_push(sy_fuc_node* t){
		if (!if_exist(t->name))
		fuc_table[t->name] = t;
	}
	void id_push(sy_id_node* t){
		if (!if_exist(t->name))
		id_table[t->name] = t;
	}
	void type_push(sy_type_node* t){
		if (!if_exist(t->name))
		type_table[t->name] = t;
	}
	bool if_exist(const string& a){
		if (fuc_table.count(a) || id_table.count(a) || type_table.count(a))
			return true;
		return false;
	}
	scope_node(const string& a, scope_node* p) :scope_name(a), parent(p){}
	bool find_id(const string& a){
		if (id_table.count(a))
			return true;
		return false;
	}
	bool find_fuc(const string& a){
		if (fuc_table.count(a))
			return true;
		return false;
	}
	bool find_type(const string& a){
		if (type_table.count(a))
			return true;
		return false;
	}
	const sy_fuc_node* get_fuc_node(const string& a){
		if (find_fuc(a))
			return fuc_table[a];
		return 0;
	}
	const sy_id_node* get_id_node(const string& a){
		if (find_id(a))
			return id_table[a];
		return 0;
	}
	const sy_type_node* get_type_node(const string& a){
		if (find_type(a))
			return type_table[a];
		return 0;
	}
	scope_node* get_parent(){ return parent; }
	const string& get_scope_name(){ return scope_name; }
};