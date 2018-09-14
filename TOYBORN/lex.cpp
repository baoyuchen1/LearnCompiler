
#include"define.h"
#include "StdAfx.h"
#include"lex.h"
#pragma comment(lib,"ws2_32.lib")
void lex::setTOKEN(ifstream &fin){
	char temp;
	GETTOKEN* temp_token;
	while(getline(fin,word)){//读取一行数据
		word+="###";
		for(it=word.begin();it!=word.end()-1;it++,column++){
			if(*it=='#')
				break;
		switch(STATE){
		case state_start:
			temp=*it;
			State_star(row,column);
			temp=NULL;
			break;
		case state_id:
		DFA_CheckId(row,column);
		break;
		case state_if_i:
			temp=*it;
			DFA_FinNodemaker(temp,'f',state_if_f);
			break;
			case state_return_r:
			temp=*it;
			DFA_NextNodemaker(temp,'e',state_return_e);
			break;
			case state_return_e:
			temp=*it;
			DFA_NextNodemaker(temp,'t',state_return_t);
			break;
			case state_return_t:
			temp=*it;
			DFA_NextNodemaker(temp,'u',state_return_u);
			break;
			case state_return_u:
			temp=*it;
			DFA_NextNodemaker(temp,'r',state_return_rn);
			break;
			case state_return_rn:
			temp=*it;
			DFA_FinNodemaker(temp,'n',state_return_n);
			break;
			case state_new_n:
				temp=*it;
			DFA_NextNodemaker(temp,'e',state_new_e);
			break;
			case state_new_e:
			temp=*it;
			DFA_FinNodemaker(temp,'w',state_new_w);
			break;
		case state_while_w:
			temp=*it;
			DFA_NextNodemaker(temp,'h',state_while_h);
			break;
			case state_while_h:
			temp=*it;
			DFA_NextNodemaker(temp,'i',state_while_i);
			break;
			case state_while_i:
			temp=*it;
			DFA_NextNodemaker(temp,'l',state_while_l);
			break;
			case state_while_l:
			temp=*it;
			DFA_FinNodemaker(temp,'e',state_while_e);
			break;
			case state_break_b:
			temp=*it;
			DFA_NextNodemaker(temp,'r',state_break_r);
			break;
			case state_break_r:
			temp=*it;
			DFA_NextNodemaker(temp,'e',state_break_e);
			break;
			case state_break_e:
			temp=*it;
			DFA_NextNodemaker(temp,'a',state_break_a);
			break;
			case state_break_a:
			temp=*it;
			DFA_FinNodemaker(temp,'k',state_break_k);
			break;
			case state_continue_c:
			temp=*it;
			DFA_NextNodemaker(temp,'o',state_continue_o);
			break;
			case state_continue_o:
			temp=*it;
			DFA_NextNodemaker(temp,'n',state_continue_n);
			break;
			case state_continue_n:
			temp=*it;
			DFA_NextNodemaker(temp,'t',state_continue_t);
			break;
			case state_continue_t:
			temp=*it;
			DFA_NextNodemaker(temp,'i',state_continue_i);
			break;
				case state_continue_i:
			temp=*it;
			DFA_NextNodemaker(temp,'n',state_continue_in);
			break;
				case state_continue_in:
			temp=*it;
			DFA_NextNodemaker(temp,'u',state_continue_u);
			break;
				case state_continue_u:
			temp=*it;
			DFA_FinNodemaker(temp,'e',state_continue_e);
			break;
			case state_struct_s:
			temp=*it;
			DFA_NextNodemaker(temp,'t',state_struct_t);
			break;
				case state_struct_t:
			temp=*it;
			DFA_NextNodemaker(temp,'r',state_struct_r);
			break;
			case state_struct_r:
			temp=*it;
			DFA_NextNodemaker(temp,'u',state_struct_u);
			break;
				case state_struct_u:
			temp=*it;
			DFA_NextNodemaker(temp,'c',state_struct_c);
			break;
						case state_struct_c:
			temp=*it;
			DFA_FinNodemaker(temp,'t',state_struct_ct);
			break;
			case state_priandpub_p:
			temp=*it;
			if(*it=='r')
			DFA_NextNodemaker(temp,'r',state_private_r);
			if(STATE!=state_private_r)
			DFA_NextNodemaker(temp,'u',state_public_u);
			break;
			case state_private_r:
			temp=*it;
			DFA_NextNodemaker(temp,'i',state_private_i);
			break;
          case state_private_i:
			temp=*it;
			DFA_NextNodemaker(temp,'v',state_private_v);
			break;
			 case state_private_v:
			temp=*it;
			DFA_NextNodemaker(temp,'a',state_private_a);
			break;
			case state_private_a:
			temp=*it;
			DFA_NextNodemaker(temp,'t',state_private_t);
			break;
				case state_private_t:
			temp=*it;
			DFA_FinNodemaker(temp,'e',state_private_t);
			break;
				case state_public_u:
			temp=*it;
			DFA_NextNodemaker(temp,'b',state_public_b);
			break;
				case state_public_b:
			temp=*it;
			DFA_NextNodemaker(temp,'l',state_public_l);
			break;
			case state_public_l:
			temp=*it;
			DFA_NextNodemaker(temp,'i',state_public_i);
			break;
       	case state_public_i:
			temp=*it;
			DFA_FinNodemaker(temp,'c',state_public_c);
			break;
			case state_orout_o:
			temp=*it;
			if(*it=='u')
			DFA_NextNodemaker(temp,'u',state_out_u);
			if(STATE!=state_out_u)
			DFA_FinNodemaker(temp,'r',state_or_r);
			break;
			   	case state_out_u:
					temp=*it;
			DFA_FinNodemaker(temp,'t',state_out_t);
			break;
			case state_and_a:
			temp=*it;
			DFA_NextNodemaker(temp,'n',state_and_n);
			break;
			 	case state_and_n:
			temp=*it;
			DFA_FinNodemaker(temp,'d',state_and_d);
			break;
			case state_free_f:
			temp=*it;
			DFA_NextNodemaker(temp,'r',state_free_r);
			break;
			case state_free_r:
			temp=*it;
			DFA_NextNodemaker(temp,'e',state_free_e);
			break;
			case state_free_e:
			temp=*it;
			DFA_FinNodemaker(temp,'e',state_free_ee);
			break;
			case state_num:
			temp=*it;
			DFA_NumNodemaker(temp);
			break;
			case state_doubleQuotationMark_s:
				if(*it=='"'){
					savevalue+=*it;
					temp_token=new GETTOKEN(row,column,state_doubleQuotationMark_e,savevalue);
					TOKENTABLE.push_back(*temp_token);
				delete temp_token;}
				else savevalue+=*it;
					break;
			case state_unknow:
				cout<<"error"<<endl;
				return;
		}//switch*/
		}//for
		if(!savevalue.empty()){
			temp_token=new GETTOKEN(row,column,STATE,savevalue);
			TOKENTABLE.push_back(*temp_token);
			delete temp_token;
		}
		STATE=state_start;
row++;
	}

fin.close();
}
void lex::State_star(int row,int column){
	GETTOKEN* temp_token;
		if(*it=='i'){             //if
			STATE=state_if_i;
			savevalue+=*it;
			}
				else	if(*it=='4'){//while
			STATE=state_return_r;
			savevalue+=*it;
			}
		else	if(*it=='w'){//while
			STATE=state_while_w;
			savevalue+=*it;
			}
		else	if(*it=='n'){//free
			STATE=state_new_n;
			savevalue+=*it;
			}
		else	if(*it=='f'){//free
			STATE=state_free_f;
			savevalue+=*it;
			}
		else	if(*it=='a'){//and
			STATE=state_and_a;
			savevalue+=*it;
			}
				else	if(*it=='r'){//return
			STATE=state_return_r;
			savevalue+=*it;
			}
		else	if(*it=='o'){//or  out
			STATE=state_orout_o;
			savevalue+=*it;
			}
		else	if(*it=='b')
			{//break
			STATE=state_break_b;
			savevalue+=*it;
			}
	else	if(*it=='c')
			{//continue
				STATE=state_continue_c;
				savevalue+=*it;
			}
		else	if(*it=='s'){//struct
			STATE=state_struct_s;
			savevalue+=*it;
			}
		else	if(*it=='p'){//private public
				STATE=state_priandpub_p;
				savevalue+=*it;
			}
		else	if(*it<='z'&&*it>='a'){//id
				if(STATE==state_start){
					STATE=state_id;
				savevalue+=*it;}
			}	
		else	if(*it=='('){// (
			STATE=state_start;
		  temp_token=new GETTOKEN(row,column,state_leftParentheses,*it);
			TOKENTABLE.push_back(*temp_token);
			delete temp_token;
			}
			else	if(*it==','){// (
			STATE=state_start;
			temp_token=new GETTOKEN(row,column,state_comma,*it);
			TOKENTABLE.push_back(*temp_token);
			delete temp_token;
			}
		else	if(*it==')'){//   )
			STATE=state_start;
			temp_token=new GETTOKEN(row,column,state_rightParentheses,*it);
			TOKENTABLE.push_back(*temp_token);
			delete temp_token;
			}
		else	if(*it=='!'){//  !
			STATE=state_start;
			temp_token=new GETTOKEN(row,column,state_not,*it);
			TOKENTABLE.push_back(*temp_token);
			delete temp_token;
			}
		else if(*it=='&'){//  &
			STATE=state_start;
			temp_token=new GETTOKEN(row,column,state_reference,*it);
			TOKENTABLE.push_back(*temp_token);
			delete temp_token;
			}
	else	if(*it=='{'){// {
			STATE=state_start;
			temp_token=new GETTOKEN(row,column,state_leftBrace,*it);
			TOKENTABLE.push_back(*temp_token);
			delete temp_token;
			}
	else	if(*it=='}'){//   }
			STATE=state_start;
			temp_token=new GETTOKEN(row,column,state_rightBrace,*it);
			TOKENTABLE.push_back(*temp_token);
			delete temp_token;
			}
		else	if(*it==';'){// ;
			STATE=state_start;
			temp_token=new GETTOKEN(row,column,state_semicolon,*it);
			TOKENTABLE.push_back(*temp_token);
			delete temp_token;
			}
		else	if(*it=='+'){// +
			STATE=state_start;
			temp_token=new GETTOKEN(row,column,state_plus,*it);
			TOKENTABLE.push_back(*temp_token);
			delete temp_token;
			}		
		else	if(*it=='-'){// -
			STATE=state_start;
			temp_token=new GETTOKEN(row,column,state_sub,*it);
			TOKENTABLE.push_back(*temp_token);
			delete temp_token;
			}		
		else	if(*it=='*'){// *
			STATE=state_start;
			temp_token=new GETTOKEN(row,column,state_mul,*it);
			TOKENTABLE.push_back(*temp_token);
			delete temp_token;
			}		
	else	if(*it=='/'){// /
			STATE=state_start;
			temp_token=new GETTOKEN(row,column,state_div,*it);
			TOKENTABLE.push_back(*temp_token);
			delete temp_token;
			}		
		else	if(*it=='.'){// /
			STATE=state_start;
			temp_token=new GETTOKEN(row,column,state_point,*it);
			TOKENTABLE.push_back(*temp_token);
			delete temp_token;
			}		
		else	if(*it=='<'){// /
			STATE=state_start;
			temp_token=new GETTOKEN(row,column,state_leftBracket,*it);
			TOKENTABLE.push_back(*temp_token);
			delete temp_token;
			}		
			else	if(*it=='>'){// /
			STATE=state_start;
			temp_token=new GETTOKEN(row,column,state_rightBracket,*it);
			TOKENTABLE.push_back(*temp_token);
			delete temp_token;
			}		
			else	if(*it==';'){// /
			STATE=state_start;
			temp_token=new GETTOKEN(row,column,state_semicolon,*it);
			TOKENTABLE.push_back(*temp_token);
			delete temp_token;
			}		
	else	if(*it<='9'&&*it>='0'){
		STATE=state_num;
				savevalue+=*it;
		}
	else if(*it==32){
	STATE=state_start;
	}
	else if(*it=='"'){
		STATE=state_doubleQuotationMark_s;
		savevalue+=*it;
	}
	else if(*it=='=')
			{
			if(++it!=word.end()){
				if(*it=='='){
					STATE=state_start;
					temp_token=new GETTOKEN(row,column,state_equal,*it);
					TOKENTABLE.push_back(*temp_token);
					delete temp_token;
					column++;
				}
				else {
					STATE=state_start;
					temp_token=new GETTOKEN(row,column,state_assignment,*it);
					TOKENTABLE.push_back(*temp_token);
					delete temp_token;
				--it;
				}}
			else {
			STATE=state_start;
			temp_token=new GETTOKEN(row,column,state_assignment,*it);
					TOKENTABLE.push_back(*temp_token);
					delete temp_token;
				--it;
			}	}
	else{
	STATE=state_unknow;
	savevalue+=*it;
	temp_token=new GETTOKEN(row,column,state_unknow,savevalue);	
	TOKENTABLE.push_back(*temp_token);
	delete temp_token;
	}
}
void lex::DFA_FinNodemaker(const char& temp,char check,state currentstate){
	GETTOKEN* temp_token;
if(temp==check){//如果目前的字符与期望的字符相同
	if(*(++it)!='#'){//如果没有到队尾
		if(*it>='a'&&*it<='z'&&*it<='9'&&*it>='0'){//如果后面还有其他字母 ，数字，属性变为id
	STATE=state_id;
	savevalue+=temp;
    --it;
	return;
		}
		else if(*it==32){//如果后面啥也没有  匹配成功！
		STATE=state_start;
	savevalue+=temp;
	temp_token=new GETTOKEN(row,column,currentstate,savevalue);
	TOKENTABLE.push_back(*temp_token);
	delete temp_token;
	return;
		}
		else {//如果后面不是字母和数字 查查它是什么
			savevalue+=temp;
			temp_token=new GETTOKEN(row,column,currentstate,savevalue);
	TOKENTABLE.push_back(*temp_token);
		State_star(row,column);
		delete temp_token;
		return;
		}
	}
	STATE=state_start;//如果关键字就是队尾，匹配成功！
	savevalue+=temp;
	temp_token=new GETTOKEN(row,column,currentstate,savevalue);
	TOKENTABLE.push_back(*temp_token);
	delete temp_token;
}
else if((*it>='a'&&*it<='z')||(*it<='9'&&*it>='0')){//如果与状态不匹配但是字母或者数字
	STATE=state_id;
	savevalue+=temp;
	return;
		}
else if(*it=='=')
	return;
else {//如果是符号 或者其他非保留字符
DFA_CheckId(row,column);
		return;}
}
void lex::DFA_NextNodemaker(const char& temp,char check,state nextstate){
	//GETTOKEN* temp_token;
	if(*(it)=='#')//如果字符抵达队尾
	{
if((temp>='a'&&temp<='z')||(temp>='0'&&temp<='9'))//如果当前字符是字母或者数字，则匹配id
{
		savevalue+=temp;
DFA_CheckId(row,column);
}
else{//如果是符号或者其他为保留符号，这去查找这个字符属于哪里  然后把前面的部分匹配id
DFA_CheckId(row,column);
}
	}
else if(temp==check){//如果当前字符与期望字符相同，并且不是队尾
	savevalue+=temp;
STATE=nextstate;//继续匹配
}
else if(temp>='a'&&temp<='z'){//如果匹配失败，但当前字符是字母或者数字，则匹配id
		savevalue+=temp;
	STATE=state_id;
}
else if(temp>='0'&&temp<='9'){
		savevalue+=temp;
	STATE=state_id;}
else {//其他字符就要去查找，然后前面部分匹配id
DFA_CheckId(row,column);
}
}
void lex::DFA_NumNodemaker(const char& temp){
	GETTOKEN* temp_token;
	if(temp!='#'){//如果没到队尾
	if('0'<=temp&&temp<='9')//如果是数字 匹配成功！
	{savevalue+=temp;}
	else	if(temp>='a'&&temp<='z'){//如果是字母 匹配未知
		savevalue+=temp;
		STATE=state_unknow;}
	else if(temp==32){
		STATE=state_start;
		temp_token=new GETTOKEN(row,column,state_num,savevalue);
	TOKENTABLE.push_back(*temp_token);
	delete temp_token;
	}
	else {//如果既不是字母也不是数字
		temp_token=new GETTOKEN(row,column,state_num,savevalue);
			TOKENTABLE.push_back(*temp_token);
	State_star(row,column);
			STATE=state_start;
			delete temp_token;
	}
	}
	else{
		temp_token=new GETTOKEN(row,column,state_num,savevalue);
	TOKENTABLE.push_back(*temp_token);
	delete temp_token;
	}
	
	}
void lex::DFA_CheckId(const int& row,const int& column){
	GETTOKEN* temp;
	if((*it>='a'&&*it<='z')||(*it<='9'&&*it>='0')){
	savevalue+=*it;
	return;
	}
	else if(savevalue=="int"){
temp=new GETTOKEN(row,column,state_type,savevalue);
		//	sym_list->type_list_push(savevalue);
		TOKENTABLE.push_back(*temp);
		//State_star(row,column);
	}
	else if (l_symbol_table->fuc_table.count(savevalue))
	{
		temp = new GETTOKEN(row, column, state_func_id, savevalue);
		TOKENTABLE.push_back(*temp);
	}
	else if (l_symbol_table->id_table.count(savevalue)){
		temp = new GETTOKEN(row, column, state_id, savevalue);
		TOKENTABLE.push_back(*temp);
	}
	else if (l_symbol_table->type_table.count(savevalue)){
		temp = new GETTOKEN(row, column, state_type, savevalue);
		TOKENTABLE.push_back(*temp);
	}
	else if (!TOKENTABLE.empty() && TOKENTABLE.back().getTOKEN() == state_struct_ct){
		if (!l_symbol_table->type_table.count(savevalue))
		{
			sy_type_node* sy_temp;
			sy_temp = new sy_type_node();
			sy_temp->name = savevalue;
			l_symbol_table->type_table[savevalue] = sy_temp;
		}
		temp = new GETTOKEN(row, column, state_type, savevalue);
		TOKENTABLE.push_back(*temp);
	}
	else if (!TOKENTABLE.empty() && TOKENTABLE.back().getTOKEN() == state_type&&*(it) == '('){
		if (!l_symbol_table->fuc_table.count(savevalue))
		{
			sy_fuc_node* sy_temp;
			sy_temp = new sy_fuc_node();
			sy_temp->name = savevalue;
			sy_temp->return_type = TOKENTABLE.back().get_value();
			l_symbol_table->fuc_table[savevalue] = sy_temp;
		}
		temp = new GETTOKEN(row, column, state_func_id, savevalue);
		TOKENTABLE.push_back(*temp);
	}
	else {
		if (!l_symbol_table->id_table.count(savevalue))
		{
			sy_id_node* sy_temp;
			sy_temp = new sy_id_node();
			sy_temp->name = savevalue;
			l_symbol_table->id_table[savevalue] = sy_temp;
		}
		temp = new GETTOKEN(row, column, state_id, savevalue);
		TOKENTABLE.push_back(*temp);
	}
	State_star(row, column);
	/*else{
		if(!TOKENTABLE.empty()&&TOKENTABLE.back().getTOKEN()==state_struct_ct){
			temp=new GETTOKEN(row,column,state_type,savevalue);
			if (l_symbol_table->type_table[savevalue] == NULL)
			{
				sy_type_node sy_temp;
				sy_temp.name = savevalue;
				l_symbol_table->type_table[savevalue] = sy_temp;
			}
		//	sym_list->type_list_push(savevalue);
			TOKENTABLE.push_back(*temp);
		}
		else if(!TOKENTABLE.empty()&&TOKENTABLE.back().getTOKEN()==state_type&&*(it)=='('){
		//	temp_func_id_table.insert(savevalue);
			temp=new GETTOKEN(row,column,state_func_id,savevalue);
			if (l_symbol_table->fuc_table[savevalue] == NULL)
			{
				sy_fuc_node sy_temp;
				sy_temp.name = savevalue;
				l_symbol_table->fuc_table[savevalue] = sy_temp;
			}
	//	sym_list->id_list_push(savevalue);
			TOKENTABLE.push_back(*temp);
		}
		else{
			if(l_symbol_table->fuc_table[savevalue]!=NULL){
			temp=new GETTOKEN(row,column,state_func_id,savevalue);
			TOKENTABLE.push_back(*temp);
			}
			else{	
				temp=new GETTOKEN(row,column,state_id,savevalue);
			//sym_list->id_list_push(savevalue);
			TOKENTABLE.push_back(*temp);}
		}
		delete temp;
	State_star(row,column);
	return;
	}*/
	
}