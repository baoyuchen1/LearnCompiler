#include "StdAfx.h"
#include "parser.h"
bool item::operator==(const item& a){
	if(a.left!=left)
		return false;
	if(a.point!=point)
		return false;
	if(a.R!=R)
		return false;
	//if(a.look_front!=look_front)
		//return false;
	return true;
}
void item_table::test(){
	item temp;
	temp.R=0;
	temp.point=0;
	temp.left=state_start;//start->stmt_sequence
	temp.right.push_back(stmt_sequence);
	it_table.push_back(temp);//0
	temp.right.clear();
	temp.R++;
	temp.left=stmt_sequence;//stmt_sequence->stmt_sequence stmt
	temp.right.push_back(stmt_sequence);
	temp.right.push_back(stmt);
	it_table.push_back(temp);
	temp.right.clear();
	temp.R++;
    temp.right.push_back(stmt);//stmt_sequence->stmt
	it_table.push_back(temp);
	temp.right.clear();
	temp.R++;
	temp.left=stmt;//stmt->assign_stmt
	temp.right.push_back(assign_stmt);
	it_table.push_back(temp);
	temp.right.clear();
	temp.R++;
	temp.right.push_back(if_stmt);//stmt->if_stmt
	it_table.push_back(temp);
	temp.right.clear();
	temp.R++;
	temp.right.push_back(function_call_stmt);//stmt->function_call_stmt
	it_table.push_back(temp);
	temp.right.clear();
	temp.R++;
	temp.right.push_back(while_stmt);//stmt->while_stmt
	it_table.push_back(temp);
	temp.right.clear();
	temp.R++;
	temp.right.push_back(break_stmt);//stmt->break;
	it_table.push_back(temp);
	temp.right.clear();
	temp.R++;
	temp.right.push_back(continue_stmt);//stmt_continue;
	it_table.push_back(temp);
	temp.right.clear();
	temp.R++;
	temp.right.push_back(define_stmt);//stmt->define_stmt
	it_table.push_back(temp);
	temp.right.clear();
	temp.R++;
	temp.right.push_back(out_stmt);//stmt->out_stmt
	it_table.push_back(temp);
	temp.right.clear();
	temp.R++;
	temp.right.push_back(return_stmt);//stmt->return_stmt
	it_table.push_back(temp);
	temp.right.clear();
	temp.R++;
	temp.right.push_back(function_define_stmt);//stmt->function_define_stmt
	it_table.push_back(temp);
	temp.right.clear();
	temp.R++;
	temp.right.push_back(struct_stmt);//stmt->struct_stmt
	it_table.push_back(temp);
	temp.right.clear();
	temp.R++;
	temp.left=if_stmt;//if_stmt->if(exp){stmt_sequence}
	temp.right.push_back(state_if_f);
	temp.right.push_back(state_leftParentheses);
	temp.right.push_back(e_exp);
	temp.right.push_back(state_rightParentheses);
	temp.right.push_back(state_leftBrace);
	temp.right.push_back(stmt_sequence);
	temp.right.push_back(state_rightBrace);
	it_table.push_back(temp);
	temp.R++;
	temp.left=while_stmt;//while->while(exp){stmt_sequence}
	temp.right[0]=state_while_e;
	it_table.push_back(temp);
	temp.right.clear();
	temp.R++;
	temp.left=assign_stmt;//assign_stmt->state_idcanuse = exp;
	temp.right.push_back(state_idcanuse);
	temp.right.push_back(state_assignment);
	temp.right.push_back(e_exp);
	temp.right.push_back(state_semicolon);
	it_table.push_back(temp);
	temp.right.clear();
	temp.R++;
	temp.right.push_back(state_idcanuse);//assign_stmt->idcanuse=new type;
	temp.right.push_back(state_assignment);
	temp.right.push_back(state_new_w);
	temp.right.push_back(state_type);
	temp.right.push_back(state_semicolon);
	it_table.push_back(temp);
	temp.right.clear();
	temp.R++;
	temp.left=out_stmt;//out_stmt->out(id);
	temp.right.push_back(state_out_t);
	temp.right.push_back(state_leftParentheses);
	temp.right.push_back(state_idcanuse);
	temp.right.push_back(state_rightParentheses);
	temp.right.push_back(state_semicolon);
	it_table.push_back(temp);
	temp.right.clear();
	temp.R++;
	temp.left=e_exp;//exp->simple_exp compare_op simple_exp
	temp.right.push_back(simple_exp);
	temp.right.push_back(compare_op);
	temp.right.push_back(simple_exp);
	it_table.push_back(temp);
	temp.right.clear();
	temp.R++;
	temp.right.push_back(simple_exp);//exp->simple_exp
	it_table.push_back(temp);
	temp.right.clear();
	temp.R++;
	temp.left=compare_op;//compare_op-><
	temp.right.push_back(state_leftBracket);
	it_table.push_back(temp);
	temp.right.clear();
	temp.R++;
	temp.right.push_back(state_rightBracket);//compare_op->>
	it_table.push_back(temp);
	temp.right.clear();
	temp.R++;
	temp.right.push_back(state_equal);//compare_op->==
	it_table.push_back(temp);
	temp.right.clear();
	temp.R++;
	temp.right.push_back(state_and_d);//compare_op->and
	it_table.push_back(temp);
	temp.right.clear();
	temp.R++;
	temp.right.push_back(state_or_r);//compare->or
	it_table.push_back(temp);
	temp.right.clear();
	temp.R++;
	temp.left=simple_exp;//simple_exp->simple_exp low_op term
	temp.right.push_back(simple_exp);
	temp.right.push_back(low_op);
	temp.right.push_back(term);
	it_table.push_back(temp);
	temp.right.clear();
	temp.R++;
	temp.right.push_back(term);//simple_exp->term
	it_table.push_back(temp);
	temp.right.clear();
	temp.R++;
	temp.left=low_op;
	temp.right.push_back(state_plus);//low_op->+
	it_table.push_back(temp);
	temp.right.clear();
	temp.R++;
	temp.right.push_back(state_sub);//low_op->-
	it_table.push_back(temp);
	temp.right.clear();
	temp.R++;
	temp.left=term;//term->term high_op factor
	temp.right.push_back(term);
	temp.right.push_back(high_op);
	temp.right.push_back(factor);
	it_table.push_back(temp);
	temp.right.clear();
	temp.R++;
	temp.right.push_back(factor);//term->factor
	it_table.push_back(temp);
	temp.right.clear();
	temp.R++;
	temp.left=high_op;
	temp.right.push_back(state_mul);//high_op->*
	it_table.push_back(temp);
	temp.right.clear();
	temp.R++;
	temp.right.push_back(state_div);//high_op->/
	it_table.push_back(temp);
	temp.right.clear();
	temp.R++;
	temp.left=factor;
	temp.right.push_back(state_idcanuse);//factor->idcanuse
	it_table.push_back(temp);
	temp.right.clear();
	temp.R++;
	temp.right.push_back(state_num);//factor->num
	it_table.push_back(temp);
	temp.right.clear();
	temp.R++;
	temp.right.push_back(function_call);//factor->func_call
	it_table.push_back(temp);
	temp.right.clear();
	temp.R++;
	temp.right.push_back(state_leftParentheses);
	temp.right.push_back(e_exp);
	temp.right.push_back(state_rightParentheses);
	it_table.push_back(temp);
	temp.right.clear();
	temp.R++;
	temp.left=state_idcanuse;//idcanuse->id
	temp.right.push_back(state_id);
	it_table.push_back(temp);
	temp.right.clear();
	temp.R++;
	temp.right.push_back(state_idcanuse);//idcanuse->id.id
	temp.right.push_back(state_point);
	temp.right.push_back(state_id);
	it_table.push_back(temp);
	temp.right.clear();
	temp.R++;
	temp.left=function_define_stmt;//function_define_stmt->type func_id (v_partamter){stmt_sequence}
	temp.right.push_back(state_type);
	temp.right.push_back(state_func_id);
	temp.right.push_back(state_leftParentheses);
	temp.right.push_back(v_partamter);
	temp.right.push_back(state_rightParentheses);
	temp.right.push_back(state_leftBrace);
	temp.right.push_back(stmt_sequence);
	temp.right.push_back(state_rightBrace);
	it_table.push_back(temp);
	temp.R++;
	temp.right.clear();
	temp.right.push_back(state_type);//function_define_stmt->type func_id(){stmt_sequence}
	temp.right.push_back(state_func_id);
	temp.right.push_back(state_leftParentheses);
	temp.right.push_back(state_rightParentheses);
	temp.right.push_back(state_leftBrace);
	temp.right.push_back(stmt_sequence);
	temp.right.push_back(state_rightBrace);
	it_table.push_back(temp);
	temp.R++;
	temp.right.clear();
	temp.left=define;//define->type id
	temp.right.push_back(state_type);
	temp.right.push_back(state_id);
	it_table.push_back(temp);
	temp.R++;
	temp.right.clear();
	temp.left=define;
	temp.right.push_back(define);//define->define,define
	temp.right.push_back(state_comma);
	temp.right.push_back(define);
	it_table.push_back(temp);
	temp.right.clear();
	temp.R++;
	temp.left=v_partamter;//v_partamter->define
	temp.right.push_back(define);
	it_table.push_back(temp);
	temp.R++;
	temp.right.clear();
	temp.left=define_stmt;//define_stmt->v_partamter;
	temp.right.push_back(v_partamter);
	temp.right.push_back(state_semicolon);
	it_table.push_back(temp);
	temp.R++;
	temp.right.clear();
	temp.right.push_back(define_stmt);
	temp.right.push_back(define_stmt);//define_stmt->define_stmt define_stmt
	it_table.push_back(temp);
	temp.R++;
	temp.right.clear();
	temp.left=break_stmt;//break_stmt->break;
	temp.right.push_back(state_break_k);
	temp.right.push_back(state_semicolon);
	it_table.push_back(temp);
	temp.R++;
	temp.right.clear();
	temp.left=continue_stmt;//continue_stmt->continue;
	temp.right.push_back(state_continue_e);
	temp.right.push_back(state_semicolon);
	it_table.push_back(temp);
	temp.R++;
	temp.right.clear();
	temp.left=return_stmt;//return_stmt->return exp;
	temp.right.push_back(state_return_n);
	temp.right.push_back(e_exp);
	temp.right.push_back(state_semicolon);
	it_table.push_back(temp);
	temp.R++;
	temp.right.clear();
	temp.left=function_call;
	temp.right.push_back(state_func_id);//func_call->func_id(r_partamter)
	temp.right.push_back(state_leftParentheses);
	temp.right.push_back(r_partamter);
	temp.right.push_back(state_rightParentheses);
	it_table.push_back(temp);
	temp.R++;
	temp.right.clear();
	temp.right.push_back(state_func_id);//func_call->func_id()
	temp.right.push_back(state_leftParentheses);
	temp.right.push_back(state_rightParentheses);
	it_table.push_back(temp);
	temp.R++;
	temp.right.clear();
	temp.left=r_partamter;//r_partamter->exp
	temp.right.push_back(e_exp);
	it_table.push_back(temp);
	temp.R++;
	temp.right.clear();
	temp.right.push_back(r_partamter);//r_partamter->r_partamter,exp
	temp.right.push_back(state_comma);
	temp.right.push_back(e_exp);
	it_table.push_back(temp);
	temp.R++;
	temp.right.clear();
	temp.left=function_call_stmt;
	temp.right.push_back(function_call);
	temp.right.push_back(state_semicolon);
	it_table.push_back(temp);
	temp.R++;
	temp.right.clear();
	temp.left=struct_stmt;//struct_stmt->strcut  type{define_stmt}
	temp.right.push_back(state_struct_ct);
	temp.right.push_back(state_type);
	temp.right.push_back(state_leftBrace);
	temp.right.push_back(define_stmt);
	temp.right.push_back(state_rightBrace);
	it_table.push_back(temp);
}
item_table::item_table(){
//init();
	test();
}
vector<item>& closure::makeunit(item_table &table){
	set<int> temp_stack;
	for(vector<item>::iterator it=closure_unit.begin();it!=closure_unit.end();it++){//变量DFA节点中的每一个文法
		for(vector<item>::iterator j=table.it_table.begin();j!=table.it_table.end();j++){//与初始化文法表中的文法进行对比
			if(it->right.begin()+it->point==it->right.end()){//边界检查
				continue;
			}
			if((*(it->right.begin()+it->point)==j->left)&&temp_stack.count(j->R)==0)//如果当前point指向的符号可以在初始化文发表中找到，
			{
				closure_unit.push_back(*j);//把这个文法加入节点
				temp_stack.insert(j->R);
		/*		if(it->right.begin()+it->point+1!=it->right.end())//对向前看符号的边界检查
					closure_unit.back().look_front.insert(table.first[*(it->right.begin()+it->point+1)]);//如果point对象之后还有符号
				else closure_unit.back().look_front.insert(table.first[it->look_front]);//没符号了
			}
			else if((*(it->right.begin()+it->point)==j->left)&&temp_stack.count(j->R)!=0){
			}*/
		}
		}
	}
		return closure_unit;
}
bool operator==(vector<item> a,vector<item> b){
	/*
利用关联容器检查，两个item容器是不是一样的
	*/
	if(a.size()!=b.size())//
		return false;
	map<int,set<int>> check;
	map<int,set<grammer>> check_front;
	vector<item>::iterator it;
	for(it=a.begin();it!=a.end();it++){
		check[it->R].insert(it->point);
		//check_front[it->R].insert(it->look_front);
	}
	for(it=b.begin();it!=b.end();it++){
		if(check[it->R].empty())
			return false;
		vector<int>::iterator j;
		//if(check_front[it->R].count(it->look_front)==0)
			//return false;
		if(check[it->R].count(it->point)==0)
			return false;
	}
	return true;
}
void closure_table::items(){
//初始化
	closure* temp=new closure();
	vector<item> temp_goto;
	temp->closure_unit.push_back(stable.it_table[0]);
	temp->makeunit(stable);
	table.push_back(*temp);
	int temp_move;
	for(vector<closure>::iterator it=table.begin();it!=table.end();it++){//查找每一个 dfa节点
		for(int X=state_start;X!=state_count_num;X=X++){//遍历每一个符号
			temp_move=-1;
			temp_goto=gotonext(*it,(grammer)X,temp_move);//goto
			vector<closure>::iterator j;
			if(temp_goto.empty())
				continue;
			for(j=table.begin();j!=table.end();j++){
				if(j->closure_unit==temp_goto){//如果有重复节点,
					it->action[(grammer)X]=distance(table.begin(),j);
					break;}
			}
			if(j==table.end())//如果没重复节点，就把新节点加入
			{
				temp->closure_unit=temp_goto;
				table.push_back(*temp);
				it->action[(grammer)X]=table.size()-1;
				if(temp_move>=0)
				table.back().move=temp_move;
			}
		}
	}
	delete temp;
}
vector<item>& closure_table::gotonext(closure &I,grammer X,int &move){
	closure* j=new closure();
	typedef vector<item>::iterator iter;
	for(iter it=I.closure_unit.begin();it!=I.closure_unit.end();it++){//遍历DAF节点中每一个文法
		if(it->right.begin()+it->point==it->right.end()){//边界检查
			continue;}
		if(*(it->right.begin()+it->point)==X){//与要goto的文法对比
		if(it->right.begin()+it->point+1<=it->right.end()){//检查point是否已达最后
			j->closure_unit.push_back(*it);
			j->closure_unit.back().point++;
			if((j->closure_unit.back().right.begin()+j->closure_unit.back().point)==j->closure_unit.back().right.end()){
				move=j->closure_unit.back().R;
		}
		}
		}
	}
	if(j->closure_unit.empty())
		return j->closure_unit;
	return j->makeunit(stable); 
}
/*bool analyze(const closure_table &j,vector<grammer> &input){
	vector<int> state_stack;
	vector<grammer> symbol_stack;
	state_stack.push_back(0);
	while(true){
		int temp_state=state_stack.back();
		if(j.table[temp_state].move==0&&input.back()==$)
			return true;
		else if(temp_state==9){
			if(input.back()==left_bracket||input.back()==right_bracket||input.back()==ps||input.back()==sub)
			{
			grammer t=input.back();
			state_stack.push_back(j.table[temp_state].action.find(t)->second);
			input.pop_back();
			}
		}
		else if(0<j.table[temp_state].move&&j.table[temp_state].move<26)
		{
			int temp=j.table[temp_state].move;
			int beita=j.stable.it_table[temp].right.size();
			for(int i=0;i!=beita;i++){
				state_stack.pop_back();
			}
			beita=state_stack.back();
			//[j.stable.it_table[temp].left]
			beita=j.table[beita].action.find(j.stable.it_table[temp].left)->second;
			state_stack.push_back(beita);
		}
		else if(j.table[temp_state].action.find(input.back())->second){
			grammer t=input.back();
			state_stack.push_back(j.table[temp_state].action.find(t)->second);
			input.pop_back();
		}
		else return false;
	}	
}*/
bool analyze::analyze_grammer(list<GETTOKEN>& input){
	state_stack.push_back(0);
	count=0;
	while(true){
		current_state=state_stack.back();
		//cout<<state_stack.back()<<endl;
		if(!input.empty())
		if(DFA.table[current_state].action.count(input.front().getTOKEN())==0){
			if(DFA.table[current_state].move<0||DFA.table[current_state].move>R_count)
			return false;
		}
		if(DFA.table[current_state].move==0&&input.front().getTOKEN()==$)
			return true;
	else if(current_state==33){
		if (input.front().getTOKEN() == state_leftBracket || input.front().getTOKEN() == state_rightBracket || input.front().getTOKEN() == state_plus || input.front().getTOKEN() == state_sub || input.front().getTOKEN() == state_and_d || input.front().getTOKEN() == state_or_r || input.front().getTOKEN() == state_equal)
			//	Shift(input, current_state);
			new_Shift(input);
		else
			//	Specification(current_state);
			new_Specification();
		}
		else if(current_state==29){
			if (input.front().getTOKEN() == state_point)
				//	Shift(input,current_state);
				new_Shift(input);
			else
				//Specification(current_state);
				new_Specification();
		}
				else if(current_state==12||current_state==78){
			if(input.front().getTOKEN()==state_comma)
				//Shift(input,current_state);
				new_Shift(input);
			else
				//Specification(current_state);
				new_Specification();
		}
				else if(current_state==25||current_state==52){
					list<GETTOKEN>::iterator it = input.begin();
			if(it->getTOKEN()==state_type&&(++it)->getTOKEN()!=state_func_id)
				//Shift(input,current_state);
				new_Shift(input);
			else
				//Specification(current_state);
				new_Specification();
		}
		else if(current_state==35||current_state==81){
			if(input.front().getTOKEN()==state_div||input.front().getTOKEN()==state_mul)
				//Shift(input,current_state);
				new_Shift(input);
			else
				//Specification(current_state);
				new_Specification();
		}
			else if(current_state==80){
			if(input.front().getTOKEN()==state_plus||input.front().getTOKEN()==state_sub)
				//Shift(input,current_state);
				new_Shift(input);
			else
			//	Specification(current_state);
			new_Specification();
		}
		else if(DFA.table[current_state].move>0&&DFA.table[current_state].move<R_count){
		//Specification(current_state);
			new_Specification();
		}
		else if(DFA.table[current_state].action.count(input.front().getTOKEN())){
		//Shift(input,current_state);
			new_Shift(input);
		}
	}
}
void analyze::Shift(list<GETTOKEN>& input,const int &current_state){
	state gettoken=input.front().getTOKEN();
if(gettoken==state_id||gettoken==state_num){
		node* temp_node=new node(gettoken,true,0,count);
		count++;
//		base_node* temp=new base_node(input.front().getTOKEN(),false);
		//grammer_tree->ptr_push(temp);
		//if(gettoken==state_id);
		//	temp->set_name(input.front().get_value());
		specification_stack.push_back(*temp_node);
		tree_node.push_back(*temp_node);
		delete temp_node;
	}
	else if(gettoken==state_leftParentheses||gettoken==state_rightParentheses||gettoken==state_leftBrace||gettoken==state_rightBrace||gettoken==state_semicolon){
	//do nothing
	}
	else
	{
	node *temp_node=new node(gettoken,false,0,count);
	count++;
	bool check_break=false;
	if(gettoken==state_break_k||gettoken==state_continue_e){
		for(int i=specification_stack.size()-1;i>-1;i--)
			if(specification_stack[i].nature==state_while_e){
			check_break=true;
			temp_node->left=specification_stack[i].number;
			break;
			}
		if(!check_break)
			return;
	}
	specification_stack.push_back(*temp_node);
	tree_node.push_back(*temp_node);
		delete temp_node;
	}
	grammer t=gettoken;
	state_stack.push_back(DFA.table[current_state].action.find(t)->second);
	grammer_stack.push_back(t);
	input.pop_front(); 

}
bool analyze::Specification(const int& current_state){
int temp=DFA.table[current_state].move;
			int beita=DFA.stable.it_table[temp].right.size();
			for(int i=0;i!=beita;i++){
				state_stack.pop_back();
				grammer_stack.pop_back();
			}
			grammer_stack.push_back(DFA.stable.it_table[temp].left);
			beita=state_stack.back();
			beita=DFA.table[beita].action.find(DFA.stable.it_table[temp].left)->second;
			state_stack.push_back(beita);
 temp=DFA.table[current_state].move;
	 beita=DFA.stable.it_table[temp].right.size();
	if(beita==1||(beita==2&&temp!=1)){
		specification_stack.back().set_nature(DFA.stable.it_table[temp].left);
	}
	else	if(beita>=3){
		if(specification_stack.size()<3)
			return false;
		int l_leaf,r_leaf,m_node;
		int c=specification_stack.size();
		if(beita<=4){
	      l_leaf=specification_stack[c-3].get_number();
		 r_leaf=specification_stack[c-1].get_number();
		 m_node=specification_stack[c-2].get_number();
		}
		else if(beita>4&&temp<34){
		 l_leaf=specification_stack[c-2].get_number();
		 r_leaf=specification_stack[c-1].get_number();
		 m_node=specification_stack[c-3].get_number();
		 tree_node[m_node].child.push_back(count);
		}
		else if(temp>33) return true;
		tree_node[l_leaf].parent=m_node;
		tree_node[r_leaf].parent=m_node;
		tree_node[m_node].left=l_leaf;
		tree_node[m_node].right=r_leaf;
		node temp_node=tree_node[m_node];
		temp_node.nature=DFA.stable.it_table[temp].left;
		specification_stack.pop_back();
		specification_stack.pop_back();
		specification_stack.pop_back();
		specification_stack.push_back(temp_node);
	}
	else	if(beita==2){
			if(specification_stack.size()<2)
			return false;
			int c=specification_stack.size();
			int s_node=specification_stack[c-2].get_number();
			int next_leaf=specification_stack[c-1].get_number();
			tree_node[next_leaf].parent=s_node;
			tree_node[s_node].child.push_back(next_leaf);
			specification_stack.pop_back();
	}
	return true;
/*	int temp=DFA.table[current_state].move;
	int beita=DFA.stable.it_table[temp].right.size();
	for(int i=0;i!=beita;i++){
				state_stack.pop_back();
				grammer_stack.pop_back();
			}
	state table_left=DFA.stable.it_table[temp].left;
	grammer_stack.push_back(table_left);
	beita=state_stack.back();
	beita=DFA.table[beita].action.find(DFA.stable.it_table[temp].left)->second;
	state_stack.push_back(beita);
	if(table_left==if_stmt||table_left==while_stmt||table_left==function_define_stmt){
	AST_node* parent,left,right;
	right=grammer_tree->ptr_pop();
	left=grammer_tree->ptr_pop();
	parent=grammer_tree->ptr_pop();
	parent->push_child(left);
	parent->push_child(right);
	}
	return true;*/
}
void analyze::make_test_code(){
	int i=0;
	int while_check=-1;
	int while_posistion;
	for(vector<node>::iterator it=tree_node.begin();it!=tree_node.end();it++){
		//cout<<i<<endl;
		if(i==while_check)
			cout<<"goto"<<while_posistion<<endl;
		i++;
		if(it->nature==state_or_r)
			tree_unit_code("or",it);
		else if(it->nature==state_and_d)
			tree_unit_code("and",it);
		else	if(it->nature==state_assignment)
		tree_unit_code("=",it);
		else if(it->nature==state_equal)
		tree_unit_code("==",it);
		else	if(it->nature==state_plus)
			tree_unit_code("+",it);
		else	if(it->nature==state_sub)
			tree_unit_code("-",it);
		else	if(it->nature==state_div)
			tree_unit_code("/",it);
		else	if(it->nature==state_mul)
			tree_unit_code("*",it);
		else	if(it->nature==state_leftBracket)
			tree_unit_code("<",it);
		else	if(it->nature==state_rightBracket)
			tree_unit_code(">",it);
		else	if(it->nature==state_break_k)
			cout<<"goto"<<tree_node[it->left].child.front()<<endl;
		else	if(it->nature==state_continue_e)
			cout<<"goto"<<it->left<<endl;
		else	if(it->nature==state_if_f){
			cout<<"check"<<it->left<<"  goto"<<it->right<<endl;
			cout<<"goto"<<it->child.front()<<endl;
		}
		else	if(it->nature==state_while_e){
			cout<<"check"<<it->left<<"  goto"<<it->right<<endl;
			cout<<"goto"<<it->child.front()<<endl;
			while_check=it->child.front()-1;
			while_posistion=it->right;
		}
		}
}
void analyze::tree_unit_code( string t,vector<node>::iterator it){
		if(tree_node[it->left].nature==state_id){
				cout<<tree_node[it->left].name<<" ";
				cout<<t<<"  ";
			}
			else {
				cout<<it->left<<" ";
				cout<<t<<" ";
			}
			if(tree_node[it->right].nature==state_id){
				cout<<tree_node[it->right].name<<" ";
			}
			else cout<<it->right;
			cout<<endl;
}
void analyze::new_Shift(list<GETTOKEN>& input){
	state token=input.front().getTOKEN();
	/*
	如果移进结点是id,num,将leaf_node压入tree_node_stack中。
	如果结点beark,continue,do sometest 将leaf_node压入tree_node_stack中。
	如果移进结点是if,while，将control_node压入tree_node_stack中。
	如果移进结点是+ - * / and or < > == =将calculate_node。
	如果移进结点是struct结点，将struct_seq_node压入tree_node_stack中。
	如果移进结点是func_id结点,判断grammer_stack的栈顶有没有type_id。如果有则用control_node压栈，否则用func_call_node压栈。
	其余语素不压入tree_node_stack。
	将结点token压入grammer_stack。
	状态栈压入在状态机中找到的元素。
	*/
	if (token==state_type){
		list<GETTOKEN>::iterator it = input.begin();
		it++;
		if (it->getTOKEN() == state_id){
			string temp = input.front().get_value();
			leaf_node* c = new leaf_node(state_id, it->get_value(), temp);
			c->def();
			tree_node_stack.push_back(c);
		}
	}
	else if (token == state_id||token==state_num){
		if (grammer_stack.back() != state_type){
			leaf_node* temp = new leaf_node(token, input.front().get_value());
			tree_node_stack.push_back(temp);
		}
	}
	else if (token == state_return_n){
		return_node* temp = new return_node(token);
		tree_node_stack.push_back(temp);
	}
	else if(token==state_break_k||token==state_continue_e){
		//some test
		leaf_node* temp=new leaf_node(token);
		tree_node_stack.push_back(temp);
	}
	else	if(token==state_if_f||token==state_while_e){
	control_node* temp=new control_node(token);
	tree_node_stack.push_back(temp);
	}
	else if(token==state_plus||token==state_sub||token==state_mul||token==state_div||token==state_and_d
		||token==state_or_r||token==state_assignment||token==state_leftBracket||token==state_rightBracket||token==state_equal){
	calculate_node* temp=new calculate_node(token);
	tree_node_stack.push_back(temp);
	}
	else if(token==state_struct_ct){
	//	input.pop_front();
		list<GETTOKEN>::iterator it = input.begin();
		it++;
		struct_seq_node* temp = new struct_seq_node(state_type,it->get_value());
		tree_node_stack.push_back(temp);
	}
	else if(token==state_func_id){
		if(grammer_stack.back()==state_type){
			string r_type = this->lex_anay.l_symbol_table->fuc_table[input.front().get_value()]->return_type;
			fuc_define_node* temp = new fuc_define_node(token, input.front().get_value(), r_type);
		tree_node_stack.push_back(temp);
		}
		else{
			func_call_node* temp = new func_call_node(token, input.front().get_value());
		tree_node_stack.push_back(temp);
		}
	}
	grammer_stack.push_back(token);
	//state_stack.push_back(DFA.table[current_state].action.find(t)->second);
	token=(state)DFA.table[current_state].action.find(token)->second;
	state_stack.push_back(token);
	input.pop_front();
}
void analyze::new_Specification(){
	int temp = DFA.table[current_state].move;//得到要归约语句的编号
	if(is_control_tree()){
	make_control_tree();
	}
	else if(is_calculate_tree()){
		make_calculate_tree();
	}
	else if(is_seq_tree()){
	make_seq_tree();
	}
	else if (temp == 39){//idcanuse->idcanuse.id
		AST_base_node* child = tree_node_stack.back();
		tree_node_stack.pop_back();
		leaf_node* parent = dynamic_cast<leaf_node*>(tree_node_stack.back());
		parent->list_push_back(child->getname());
	}
	else if (temp == 49||temp==50){//return_stmt->return exp;//fuc_call->fuc_id(v_p)
		AST_base_node* child = tree_node_stack.back();
		tree_node_stack.pop_back();
		AST_base_node* parent = tree_node_stack.back();
		child->set_parent(parent);
		parent->push_child(child);
	}
	/*
	测试用
	*/
	int beita = DFA.stable.it_table[temp].right.size();//得到规约语句的长度
	for (int i = 0; i != beita; i++){//根据长度弹出相应的状态
		state_stack.pop_back();
		grammer_stack.pop_back();
	}
	grammer_stack.push_back(DFA.stable.it_table[temp].left);//将规约的目标符号压栈
	beita = state_stack.back();//得到状态栈栈顶状态
	beita = DFA.table[beita].action.find(DFA.stable.it_table[temp].left)->second;//根据自动机相应状态中移进项中通过利用规约的目标符号找到要压栈的新状态
	state_stack.push_back(beita);//新状态压栈
	//temp = DFA.table[current_state].move;
}
void analyze::make_control_tree(){
		AST_base_node* right_child=tree_node_stack.back();
		tree_node_stack.pop_back();
		AST_base_node* left_child;
		if (DFA.table[current_state].move != 41){
			left_child = tree_node_stack.back();
			tree_node_stack.pop_back();
		}
		else
			left_child = NULL;	
		AST_base_node* parent=tree_node_stack.back();
		//tree_node_stack.pop_back();
		right_child->set_parent(parent);
		if (left_child!=NULL)
		left_child->set_parent(parent);
		parent->push_child(left_child);
		parent->push_child(right_child);
}
void analyze::make_calculate_tree(){
	AST_base_node* right_child=tree_node_stack.back();
	tree_node_stack.pop_back();
	AST_base_node* parent=tree_node_stack.back();
	tree_node_stack.pop_back();
	AST_base_node* left_child=tree_node_stack.back();
	tree_node_stack.pop_back();
		right_child->set_parent(parent);
		left_child->set_parent(parent);
		parent->push_child(left_child);
		parent->push_child(right_child);
		tree_node_stack.push_back(parent);
}
void analyze::make_seq_tree(){
	int temp = DFA.table[current_state].move;//得到要归约语句的编号
	int beita = DFA.stable.it_table[temp].right.size();//得到规约语句的长度
	state t_current_state = DFA.stable.it_table[temp].left;
	if (check_d(temp)){//temp==45->define_stmt
		AST_base_node* child = tree_node_stack.back();
		tree_node_stack.pop_back();
		AST_base_node* parent = tree_node_stack.back();
		parent->push_child(child);
		child->set_parent(parent);
	}
	else if (temp == 43){//define->define,define
		AST_base_node* child = tree_node_stack.back()->children.front();
		tree_node_stack.pop_back();
		AST_base_node* parent = tree_node_stack.back();
		parent->push_child(child);
		child->set_parent(parent);

	}
	else{
		sequence_node* parent = new sequence_node(t_current_state);
		AST_base_node* child = tree_node_stack.back();
		if (temp == 42){
			leaf_node* id_def = dynamic_cast<leaf_node*>(child);
		}
		parent->push_child(child);
		child->set_parent(parent);
		tree_node_stack.pop_back();
		tree_node_stack.push_back(parent);
	}
}
bool analyze::is_control_tree(){
	int temp = DFA.table[current_state].move;
	state check = DFA.stable.it_table[temp].left;
	switch (check)
	{
	case if_stmt:
	case while_stmt:
	case function_define_stmt:
		return true;
	default:
		return false;
		break;
	}

}
bool analyze::is_calculate_tree(){
	int temp = DFA.table[current_state].move;
	state check = DFA.stable.it_table[temp].left;
	state_func_id;
	switch (check){
	case assign_stmt:
		return true;
	case e_exp:
	case simple_exp:
	case term:
		if (DFA.stable.it_table[temp].right.size() > 1)
			return true;
	default:return false;
	}
}
bool analyze::is_seq_tree(){
	int temp = DFA.table[current_state].move;
	state check = DFA.stable.it_table[temp].left;
	switch (check){
	case r_partamter:
	case stmt_sequence:
	case struct_stmt:
	case define_stmt: 
	case define:
		return true;
	default: return false;

	}
}
void analyze::show_the_tree(){

}
bool analyze::check_d(const int& t){
	switch (t)
	{
	case 2:
	case 42:
	case 44:
	case 45:
	case 52:
	case 43:
		return false;
	default:
		return true;
	}
}