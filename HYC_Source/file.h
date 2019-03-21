#define _CRT_SECURE_NO_DEPRECATE

#ifndef __FILE_H__
#define __FILE_H__



#include<stdio.h>
#include"search.h"
#include"list.h"
#include"config.h"
#include"main.h"


/*save*/
int Save_Records();
int Save_Users();
int Save_BackupRecords();
int Save_Config();

/*read*/
int Read_Records();
int Read_Users();
int Read_BackupRecords();
int Read_Config();

extern int bkcolor;

#endif 
