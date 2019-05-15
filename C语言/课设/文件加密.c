#include <stdio.h>


void lmenu()//显示登录菜单
{


printf("\n\n\t    欢迎使用会员登录系统\n\n");
printf("**********************************************");
printf("\n\n\t\t1.登录系统\n\n");
printf("\n\n\t\t2.创建账号\n\n");
printf("\n\n\t\t3.修改密码\n\n");
printf("\n\n\t\t4.退出系统\n\n");
printf("\n\n\t    请按键选择，回车确定\n");
printf("**********************************************");
return ;
}


void lmain()//登录功能函数
{
	void land();
	void xinjian();
	char choose;
	lmenu();
	scanf(" %c",&choose);
	switch(choose)//功能函数
  {
	  case'1':
	    land();
	    break;
	  case'2':
	  	xinjian();
	  	break;
	  	case'3':
	  	xgmm();
	  	break;
	  case'4':
	  	system("cls");
    getch();
  	exit(0);
  	system ("cls");
	break;
  }
}



void xinjian()//新建账户密码
{
	FILE *fp;
	int zhanghao;
	char password[20],password1[20];
	char hit=0;
	if ((fp=fopen("land.txt","r"))==NULL)//if语句：打开图书馆文件，不存在此文件则新建
	{
      fp=fopen("land.txt","w");
      fclose(fp);
    }
    system("cls");
	fp=fopen("land.txt","a");
	for(;;)//输入两次密码确认，两次相同才能确认
	{
	   printf("\n请按以下格式输入账户:\n学号 密码\n");
	   printf("请输入:");
	   scanf("%d %s",&zhanghao,password);
       printf("再次输入密码:\n");
	   scanf("%s",password1);
	   if(strcmp(password,password1)==0)
	   {
	       fprintf(fp,"%d %s\n",zhanghao,password);
		   break;
       }
       else
	   {
	       printf("两次输入密码不一致，继续创建按回车，退出按ESC");
	       hit=getch();
		   if(hit=27)
		   system("cls");
		   lmain();
		         }
   }
   fclose(fp);
   printf("创建成功，按任意键返回");
   getch();
   system("cls");
   lmain();
}



int match(int m,char a[20])//匹配数据库中的账号密码
{
	FILE*fp;
	int n=0,i=0;
	int zhanghao;
	char password[20];

	if ((fp=fopen("land.txt","r"))==NULL)//不存在读者文件
	  {
         system ("cls");
		 printf("\n 还未存在用户!请新建账户");
		 getch();
	 	system("cls");
		lmain();
	
      }


        for(;!feof(fp);)
      {
        fscanf(fp,"%d%s",&zhanghao,password);
        if(m==zhanghao)
        {
        	if(strcmp(a,password)==0)
			return 1;
			else
			{
			return -1;
		   }
	    }
	  }
	  return 0;
 }

void land()//输入账户密码的登录函数
{
	int zhanghao;
	char password[20];
	int i=2,j,k,n;
	char hit=0;
	//system("cls");
    CLEAR();
	do
	{
	   printf("\n请输入账号:\n");
       scanf("%d",&zhanghao);
       printf("确认输入请安回车，重新输入请按ECS");
       hit=getch();//暂停程序当i接收后继续下一条指令
       for (;hit!=13&&hit!=27;)//保证只能是CR和ESC才能退出循环,输入其他字符无用，暂停程序，按'CR'继续。
       {
	        hit=getch();
	   }
    }
    while(hit==27);
	 printf("\n请输入密码:\n");
	 scanf("%s",password);
     i=match(zhanghao,password);
     if(i==1)
	 {
       printf("登陆成功!按任意键继续");
	   getch();
	   main1();
	 }
	 else
	 {
	 	if(i==-1)
		 {
		 printf("密码错误!");
		 getch();
         land();
		 }
		 if(i==0)
		 printf("不存在此用户");
		 getch();
		 system("cls");
		 lmain();
	 }
}
