#define _CRT_SECURE_NO_DEPRECATE

#ifndef __LIST_H__
#define __LIST_H__

/*create a user list to save user information 
each user have his own record list ,and all the 
record list are linked together*/

//define account type
#define UNLOGIN -1
#define ADMINISTRATOR 0
#define USER 1

enum DealType { POS=1, cash=2, mobile=3 ,defualt=4};

//to save a record in a structure
typedef struct Record
{
	int id;//id
	long int deal_date;//deal date
	long int account_date;//accout date
	float deal_amount;//amount
	float balance;//balance
	int deal_type;//(1.Pos/2.cash/3.MObile pay£©
	char deal_site[51];//deal site
	struct Record*pre;
	struct Record*next;
}Record;

//to save a record list information
typedef struct _record_list
{
	Record*head;
	Record*tail;
	int node_number;/*number of nodes,include the head node*/
}Record_List;

//to save a user's information in a structure
typedef struct User
{
	char login_name[21];//account
	char password[21];// password
	int account_type;//account type
	float my_money;/*my current balance*/
	Record_List my_record;//record list
	struct User*pre;
	struct User*next;
}User;

//to save a user list information
typedef struct _user_list
{
	User*head;
	User*tail;
	int node_number;/*number of nodes,include the head node*/
}User_List;


#include"main.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"config.h"
#include"search.h"


/*create*/
User_List Create_UserList();
Record_List Create_RecordList();
User* Create_UserNode();
Record* Create_RecordNode();
Record* Create_EmptyRecordNode();

/*operate*/
/*add*/
int Add_User(User_List* _list, User* _p);
int Add_Record(Record_List* _list, Record* _p);
int Add_ToBackupList(Record* _p);


/*delete*/
void Delete_UserNode(User_List _list, User* _p);
int Delete_RecordNode(Record_List*_list,Record* _p);

/*free*/
int FreeUserList(User_List _list);
int FreeRecordList(Record_List _list);

/*imput*/
long int Input_Date();
char* Input_LoginNumber(char*_arr);
int Input_DealType();
float Input_Money();
char*Input_DealSite(char *_arr);
int Input_Interval();
int Input_ID();
int Input_AccounType();
int Input_Color();

#endif 

