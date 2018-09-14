#pragma once
#include<string>
#include<vector>
#include<iostream>
#include <stdio.h>
#include <tchar.h>
#include<fstream>
#include<map>
#include<set>
#include<memory>
#include<list>
#include<time.h>
typedef int type_unit;
const int int_type=1;
const int char_type=2;
const int state_count_num=66;
const int DFA_node_count=110;
const int R_count=56;
const std::string empty_str = " ";
const std::string compare = "1";
const std::string not_compare = "0";
const std::string int_string = "int";
using namespace std;
enum state{
//规约到头的标示符
$,
state_start,
/*
终结符号
*/

state_new_w,
state_free_ee,
state_return_n,
state_out_t,
state_while_e,
state_if_f,
state_or_r,
state_and_d,
state_not,           //!
state_break_k,
state_continue_e,
state_point,//.
state_assignment,  //=
state_equal,           //==
state_leftParentheses,    //(
state_rightParentheses,  //)
state_leftBrace,   //{
state_rightBrace,  //}
state_semicolon,  //；
state_plus,  //+
state_sub,//-
state_div,//  /
state_mul, // *
state_leftBracket,//小于号
state_comma,//,
state_rightBracket,
state_doubleQuotationMark_s,   //"
state_doubleQuotationMark_e,
state_singleQuoteMark,//'
state_struct_ct,
state_type,
state_id,
state_func_id,
state_idcanuse,
state_num,
sate_point,
state_unknow,
state_annotation,     //    #   注释
/*
非终结符号
*/
define,
v_partamter,
r_partamter,
stmt_sequence,
stmt,
if_stmt,
function_call,
function_call_stmt,
function_define_stmt,
while_stmt,
assign_stmt,
common_stmt,
break_stmt,
continue_stmt,
return_stmt,
define_stmt,
struct_stmt,
state_parameter,
e_exp,
out_stmt,
simple_exp,
compare_op,
low_op,
high_op,
factor,
term,
//全局域
global,
/*
底下是用不上的
*/
state_new_n,
state_new_e,
state_free_f,
state_free_r,
state_free_e,
state_return_r,
state_return_e,
state_return_t,
state_return_u,
state_return_rn,
state_while_w,
state_while_h,
state_while_i,
state_while_l,
state_out_u,      //输出流
state_if_i,
state_struct_s,
state_struct_t,
state_struct_r,
state_struct_u,
state_struct_c,
state_priandpub_p,
state_private_r,
state_private_i,
state_private_v,
state_private_a,
state_private_t,
state_private_e,
state_public_u,
state_public_b,
state_public_l,
state_public_i,
state_public_c,
state_and_a,
state_and_n,
state_orout_o,  //out  和 or
state_reference,    //&
state_break_b,
state_break_r,
state_break_e,
state_break_a,
state_continue_c,
state_continue_o,
state_continue_n,
state_continue_t,
state_continue_i,
state_continue_in,
state_continue_u,
};
typedef state grammer;