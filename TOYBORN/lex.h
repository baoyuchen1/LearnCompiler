
#pragma once
#include"control_table.h"
#include"define.h"
#include"sybolm_table.h"
class GETTOKEN{
int row;
int column;
state TOKEN;
string value;
public:
GETTOKEN(int i,int j,state W,char v):row(i),column(j),TOKEN(W){value=v;}
GETTOKEN(int i,int j,state W,string &v):row(i),column(j),TOKEN(W),value(v){v.clear();}
GETTOKEN():value(""),TOKEN(state::state_unknow),row(0),column(0){}
GETTOKEN(state t):value(""),TOKEN(t),row(0),column(0){}
state getTOKEN(){
	return TOKEN;}
void settoken(const state& t){TOKEN=t;}
string get_value(){return value;}
};
class lex{
friend class symbol_table;
friend class analyze;
public:
scope_node* l_symbol_table;
//set<string> temp_func_id_table;
scope_node* sym_list;
list<GETTOKEN> TOKENTABLE;
string word;
string::iterator it;
state STATE;//自动机状态
string savevalue;//暂存每个读入的单词
public:
lex() :STATE(state_start), row(0), column(0){}
void setTOKEN(ifstream &fin);
void State_star(int,int);//初始字符的处理
void DFA_FinNodemaker(const char&,char check,state);//生成各种保留字的最终节点
void DFA_NextNodemaker(const char&,char check,state);//生成各种保留字的中间节点
void DFA_NumNodemaker(const char&);
void DFA_CheckId(const int&,const int&);
int row;//横行
	int column;//竖列
};