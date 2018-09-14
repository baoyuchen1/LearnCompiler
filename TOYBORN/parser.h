#pragma once
#include"define.h"
#include"lex.h"
#include"AST.h"
#include"sybolm_table.h"
class item{
public:
grammer left;//�ķ���
vector<grammer> right;//�ķ��Ҳ�
int point;//��ǰ��Լ�ķ�
int R;//��Լ���
vector<grammer> look_front;//��ǰ������
bool operator==(const item&);
};
class item_table{
public:
vector<item> it_table;//��ʼ���ķ���
item_table();
map<grammer,grammer> first;
void init();
void test();
};
class closure{
public:
vector<item> closure_unit; //DFA�ڵ㣬
vector<item>& makeunit(item_table&);
closure(){closure_unit.reserve(100);}
map<grammer,int> action;
int move;
//vector<grammer> stack;
};
class closure_table{
public:
	vector<closure> table;//DFA��
	item_table stable;//��ʼ���ķ�
	vector<item>& gotonext(closure&,grammer,int&);
	void items();
	closure_table(){table.reserve(200);}
};
class node{
public:
	friend class analyze;
void set_nature(const grammer &t){nature=t;}
int get_number(){return number;}
//private:
grammer nature;
bool is_leaf;
list<int> child;
int left;
int right;
int parent;
int value;
int number;
string name;
public:
	node(grammer n,bool i,int v,int nu):nature(n),is_leaf(i),value(v),number(nu){}
};
class analyze{
public:
friend class lex;
scope_node* g_symbol_table;
vector<grammer> grammer_stack;
int current_state;
vector<node> tree_node;
vector<node> specification_stack;
AST* grammer_tree;
closure_table DFA;
vector<int> state_stack;
int count;
vector<AST_base_node*> tree_node_stack;
vector<string> scope_stack;
scope_node* scope_tree;
public:
	lex lex_anay;
	analyze(){ g_symbol_table = new scope_node();
	lex_anay.l_symbol_table = g_symbol_table;
	scope_tree = new scope_node();
	scope_tree->init();
	}
	void make_item(){DFA.items();}
	 bool analyze_grammer(list<GETTOKEN> &);
	 bool Specification(const int&);
	 void Shift(list<GETTOKEN>&,const int &);
	 void make_test_code();
	 void tree_unit_code(string ,vector<node>::iterator it);

private:
	void new_Shift(list<GETTOKEN>&);
public:
	void new_Specification();
	 bool is_control_tree();
	 bool is_calculate_tree();
	 bool is_seq_tree();
	 void make_control_tree();
	 void make_calculate_tree();
	 void make_seq_tree();
	 void make_struct_tree();
	 void show_the_tree();
	 bool check_d(const int&);
};
