#include"main.h"

Record r1 = { 0,20190101,20190101,-1,-1,1,"defualt",NULL,NULL };
User h = { "-1","1234",0,-1,{&r1,&r1,0},NULL,NULL };
//creatr a user list
User_List all_user = { &h,&h,1 };
//point to the user login now
User* login_now = NULL;

//create all_record list,backup_record list,interval_record list
Record rn = { -1,20190101,20190101,-1,-1,4,"defualt",NULL,NULL };
Record_List all_record = { &rn,&rn,1 };
Record bkn = { -1,20190101,20190101,-1,-1,4,"defualt",NULL,NULL };
Record_List backup_record = { &bkn,&bkn,1 };
Record itn = { -1,20190101,20190101,-1,-1,4,"defualt",NULL,NULL };
Record_List interval_record = { &itn,&itn,1 };



int main()
{
	int gdriver, gmode;
	gdriver = DETECT;
	initgraph(&gdriver, &gmode, "c:\\TC30\\bgi");

	Start_Activity();

	Main_Activity();

	closegraph();
	return 0;
}
