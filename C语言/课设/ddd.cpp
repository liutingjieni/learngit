#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <termios.h>

#define CLEAR()     printf("\ec")     //清屏   
#define CLOSE()     printf("\e[0m")   //关闭所有属性


typedef struct p{
	char poetName[20];
	char creatTime[20];
	char poetMan[20];
	char poet[500];
	char command[500];
	struct p *next;

}POET,*poet;

void locationN();
void locationK();
void poet_print(poet temp);
//int color_printf(COULEUR_TERMINAL fg, COULEUR_TERMINAL bg, const char * format, ...);
int getch();
//poet input_wenjian();
poet input_stdin();//可以选择每次写入文件，每次读出，以a方式。
void input();
void save(poet temp);

poet read();
void write(poet head);

void amend_fanhui();
void amend_command(poet head);
void amend_poetName(poet head);
void amend_creatTime(poet head);
void amend_poetMan(poet head);
void amend_poet(poet head);
void amend_build(poet head);
void amend();

void delt_fanhui();
void delt_poetName(poet temp);
void delt_poetMan(poet temp);
void delt();

void find_fanhui();
void find_poetName(poet temp);
void find_poetMan(poet temp);
void find_creatTime(poet temp);
void find();

void total_fanhui();
void total_poetName(poet temp);
void total_poetMan(poet temp);
void total();

//void sort_poetMan(poet head);
void sort();

void print();
void menu();
void menu1();
void menu2();

void lmenu();
void lmain();
void xinjian();
int match(int m,char a[20]);
void land();


void locationN()
{
	int i;
	for(i=0;i<7;i++)
	{
		printf("\n");
	}
}

void locationK()
{
	int i;
	for(i=0;i<30;i++)
	{
		printf(" ");
	}
}

//color函数的颜色属性
typedef enum
{
  BLACK,
  RED,
  GREEN,
  BROWN,
  BLUE,
  MAGENTA,
  CYAN,
  LIGHTGRAY,
  DARKGRAY,
  LIGHTRED,
  LIGHTGREEN,
  YELLOW,
  LIGHTBLUE,
  LIGHTMAGENTA,
  LIGHTCYAN,
  WHITE
} COULEUR_TERMINAL;

int color_printf(COULEUR_TERMINAL fg, COULEUR_TERMINAL bg, const char * format, ...)
{
  int res;
  va_list args;
  printf("\x1B[1;%02d;%02dm", fg + 30, bg + 40);
  va_start(args, format);
  res = vprintf(format, args);
  va_end(args);
  printf("\x1B[00m");
  //　关闭printf设置的颜色等属性
  CLOSE();
  return res;
}

//缓冲输入->非缓冲输入
int getch()
{
	struct termios oldt, newt;
	int ch;
	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	ch = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

	return ch;
}
void poet_print(poet temp)
{
			printf("%s\n",temp->poetName);
			printf("%s\n",temp->creatTime);
			printf("%s\n",temp->poetMan);
			printf("%s\n",temp->poet);
			printf("%s\n",temp->command);

}


poet input_wenjian()
{
	FILE *in;
	in=fopen("input.txt","r+");
	
	POET *phead,*pnew,*pend;

	phead=(poet)malloc(sizeof(POET));
	phead->next=NULL;
	pend=phead;

	
	while(!feof(in))
	{
		pnew=(poet)malloc(sizeof(POET));
		//fread(&pnew,sizeof(POET),1,in);
		fscanf(in,"%s",pnew->poetName);
		fscanf(in,"%s",pnew->creatTime);
		fscanf(in,"%s",pnew->poetMan);
		fscanf(in,"%s",pnew->poet);
		fscanf(in,"%s",pnew->command);
		poet_print(pnew);

		pnew->next=NULL;
		pend->next=pnew;
		pend=pnew;
	}
	save(phead);
	fclose(in);
	printf("输入成功\n");
	printf("按任意键返回主菜单\n");
	char t;
	t=getch();
	if(t)
	{
		menu;
	}
	return phead;
}
poet input_stdin()
{
	POET *phead,*pnew,*pend;
	phead=(poet)malloc(sizeof(POET));
	phead->next=NULL;
	pend=phead;

	pnew=(poet)malloc(sizeof(POET));
		printf("please input the poetName：");
	scanf("%s",pnew->poetName);
    printf("please input the creatTime：");
	scanf("%s",pnew->creatTime);
	printf("please input the poetMan：");
	scanf("%s",pnew->poetMan);
    printf("please input the poet：");
	scanf("%s",pnew->poet);
    printf("please input the command：");
	scanf("%s",pnew->command);
	while((strcmp(pnew->poetName,"qq"))!=0)
	{
		
		pnew->next=NULL;
		pend->next=pnew;
		pend=pnew;

		pnew=(poet)malloc(sizeof(POET));
		 printf("please input the poetName：");
	scanf("%s",pnew->poetName);
     printf("please input the creatTime：");
	scanf("%s",pnew->creatTime);
		printf("please input the poetMan：");
	scanf("%s",pnew->poetMan);
    printf("please input the poet：");
	scanf("%s",pnew->poet);
    printf("please input the command：");
	scanf("%s",pnew->command);
	}
	free(pnew);
	save(phead);
	printf("输入成功\n");
	getchar();
	printf("按任意键返回主菜单");
	char t;
	t=getch();
	if(t)
	{
		menu;
	}
	menu();
	return phead;
}

void input()
{
	do
	{
		CLEAR();
	locationN();
	locationK();
	printf("×××诗歌输入×××\n");
	locationK();
		printf("a.以文件形式输入.\n");
	locationK();
		printf("b.标准键盘输入.\n");
	locationK();
		printf("q.退出\n");
	char t;
	t=getch();
	
	switch(t)
	{
		case'a':input_wenjian();break;
		case'b':input_stdin();break;
		
		case'q':menu();break;
	}
		
	} while (1);
	
}

void save(poet head)
{
	
	FILE *out;
	out=fopen("output.txt","a+s");//以写模式打开，每次重新写入，会丢掉之前的数据；
	poet temp;
	temp=head->next;
	while(temp)
	{
		//fwrite(temp,sizeof(POET),1,out);
		fprintf(out,"%s\n",temp->poetName);
		fprintf(out,"%s\n",temp->creatTime);
		fprintf(out,"%s\n",temp->poetMan);
		fprintf(out,"%s\n",temp->poet);
		fprintf(out,"%s\n",temp->command);
		temp=temp->next;
	}
	fclose(out);
	printf("success");
}

poet read()
{
	FILE *fp;
	fp=fopen("output.txt","r");

	//fprintf(fp,"%s\n","qq");
	poet phead,pnew,pend;
	phead=(poet)malloc(sizeof(POET));
	phead->next=NULL;
	pend=phead;

	pnew=(poet)malloc(sizeof(POET));
	//fread(&pnew,sizeof(POET),1,fp);
		fscanf(fp,"%s",pnew->poetName);
		fscanf(fp,"%s",pnew->creatTime);
		fscanf(fp,"%s",pnew->poetMan);
		fscanf(fp,"%s",pnew->poet);
		fscanf(fp,"%s",pnew->command);
	while(!feof(fp))
	{
		pnew->next=NULL;
		pend->next=pnew;
		pend=pnew;
		pnew=(poet)malloc(sizeof(POET));
		//fread(&pnew,sizeof(POET),1,fp);
		
		fscanf(fp,"%s",pnew->poetName);
		fscanf(fp,"%s",pnew->creatTime);
		fscanf(fp,"%s",pnew->poetMan);
		fscanf(fp,"%s",pnew->poet);
		fscanf(fp,"%s",pnew->command);
	}
	free(pnew);
	fclose(fp);
	return phead;

}
void write(poet head)
{
	FILE *out;
	out=fopen("output.txt","w");//以写模式打开，每次重新写入，会丢掉之前的数据；
	poet temp;
	temp=head->next;
	while(temp)
	{
		//fwrite(temp,sizeof(POET),1,out);
		fprintf(out,"%s\n",temp->poetName);
		fprintf(out,"%s\n",temp->creatTime);
		fprintf(out,"%s\n",temp->poetMan);
		fprintf(out,"%s\n",temp->poet);
		fprintf(out,"%s\n",temp->command);
		temp=temp->next;
	}
	fclose(out);
}
void amend_fanhui()
{
	locationK();
  printf("按任意键返回上一层");
		char t;
		//getchar();
		t=getch();
		if(t)
		{
			amend();
		}
}
void amend_poetName(poet head)
{
	CLEAR();
	poet temp;
	temp=head->next;
	char input_s1[20];

	printf("please input the amending poetName:");
	scanf("%s",input_s1);

	while(temp)
	{
	
		if((strcmp(temp->poetName,input_s1))==0)
		{
		
			printf("\n是否确定修改？y/n");
			char t;
            getchar();
			t=getch();
           
			if(t=='y')
			{
				printf("\n请输入正确诗名:");
				char input_s[20];
			
				scanf("%s",input_s);
				strcpy(temp->poetName,input_s);
				poet_print(temp);
			}
			else
			{
				amend();
			}
		}
	
		temp=temp->next;
	}
	write(head);
	printf("修改成功");
	amend_fanhui();
}
void amend_creatTime(poet head)
{
	CLEAR();
	poet temp;
	temp=head->next;
	char input_s1[20];
	printf("please input the amending poetName:");
	scanf("%s",input_s1);
	while(temp)
	{
		
		if((strcmp(temp->poetName,input_s1))==0)
		{
	
			printf("\n是否确定修改？y/n");
			char t;
            getchar();
			t=getch();
			if(t=='y')
			{
				printf("\n请输入正确创作时间:");
				char input_s[20];
				scanf("%s",input_s);
				strcpy(temp->creatTime,input_s);
					poet_print(temp);
			}
			else
			{
				amend();
			}

		}
		temp=temp->next;
	}
    write(head);
	amend_fanhui();
}
void amend_poetMan(poet head)
{
	CLEAR();
	poet temp;
	temp=head->next;
	char input_s1[20];
	printf("please input the amending poetName:");
	scanf("%s",input_s1);
	while(temp)
	{
		if((strcmp(temp->poetMan,input_s1))==0)
		{
			
			printf("是否确定修改？y/n");
			char t;
            getchar();
			t=getch();
			if(t=='y')
			{
				printf("\n请输入正确诗人:");
				char input_s[20];
				scanf("%s",input_s);
				strcpy(temp->poetMan,input_s);
				poet_print(temp);
			}
			else
			{
				amend();
			}
		}
		temp=temp->next;
	}
    write(head);
	amend_fanhui();
}
void amend_poet(poet head)
{
	CLEAR();
	poet temp;
	temp=head->next;
	char input_s1[20];
	printf("please input the amending poetName:");
	scanf("%s",input_s1);
	while(temp)
	{
		if((strcmp(temp->poetName,input_s1))==0)
		{
			
			printf("是否确定修改？y/n");
			char t;
            getchar();
			t=getch();
			if(t=='y')
			{
				
				printf("\n请输入正确诗句");
				char input_s[200];
				scanf("%s",input_s);
				getchar();
				strcpy(temp->poet,input_s);
					poet_print(temp);
			}
			else
			{
				amend();
			}
		}
		temp=temp->next;
	}
    write(head);
	amend_fanhui();
}
void amend_command(poet head)
{
	CLEAR();
	poet temp;
	temp=head->next;
	char input_s1[20];//输入要修改的诗名
	printf("please input the amending poetName");
	scanf("%s",input_s1);
	while(temp)
	{
		if((strcmp(temp->poetName,input_s1))==0)
		{
			printf("\n是否确定修改？y/n");
			char t;
            getchar();
			t=getch();
			if(t=='y')
			{
			
				printf("\n请输入正确赏析:");
				char input_s[300];
				scanf("%s",input_s);
				strcpy(temp->command,input_s);
				poet_print(temp);
			}
			else
			{
				amend();
			}
		}
		temp=temp->next;
	}
    write(head);
	amend_fanhui();
}
void amend_build(poet head)
{

	poet pnew;
  
	pnew=(poet)malloc(sizeof(POET));
	scanf("%s",pnew->poetName);
	scanf("%s",pnew->poetMan);
	scanf("%s",pnew->creatTime);
	scanf("%s",pnew->poet);
	scanf("%s",pnew->command);
	getchar();
	printf("是否确定插入？y/n");
	char t;
	t=getch();
	if(t=='y')
	{
		pnew->next=head->next;
	  pnew=head->next;
		printf("添加成功");
		amend_fanhui();
	}
	else
	{
		amend();
	}
	
}
void amend()
{ 
	poet head;
	head=read();
	CLEAR();
	locationN();
	locationK();
				printf("***诗歌修改***\n");
				locationK();
						printf("a.修改诗名\n");
				locationK();
						printf("b.修改创作时间\n");
				
				locationK();
						printf("c.修改诗人\n");
				locationK();
						printf("d.修改诗句\n");
				locationK();
						printf("e.修改赏析\n");
				locationK();
						printf("f.插入数据\n");
				locationK();
						printf("q.退出\n");
	char t;
	t=getch();
	switch(t)
	{
		case'a':amend_poetName(head);break;
		case'b':amend_creatTime(head);break;
		case'c':amend_poetMan(head);break;
		case'd':amend_poet(head);break;
		case'e':amend_command(head);break;
		case'f':amend_build(head);break;
		case'q':menu();break;
	}
	//write(head);
}
void delt_fanhui()
{
	
			printf("按任意键返回上一层\n");
		char t;
		//getchar();
		t=getch();
		if(t)
		{
			delt();
		}
}
void delt_poetName(poet head)
{
	poet pnew,temp;
	CLEAR();
	
	char input_s[20];
	printf("please input the poetName to delete:");
	scanf("%s",input_s);
	temp=head->next;
    pnew=head;
	while(temp)
	{
		if((strcmp(input_s,temp->poetName))==0)
		{
			poet_print(temp);
			printf("是否确定删除？y/n\n");
			char t;
            getchar();
			t=getch();
			if(t=='y')
			{
				pnew->next=temp->next;
			  free(temp);
			  break;
			}
			else
			{
				 menu();
			}
			
		}
		pnew=temp;
		temp=temp->next;
	}
	write(head);
	printf("删除成功");
	delt_fanhui();
}
void delt_poetMan(poet head)
{
	poet pnew,temp;
	CLEAR();
	char input_s[20];
	printf("please input the poetMan to delete:");
	scanf("%s",input_s);

	temp=head->next;
    pnew=head;
	while(temp)
	{
		if((strcmp(input_s,temp->poetMan))==0)
		{
			poet_print(temp);
			printf("是否确定删除？y/n");
			char t;
			getchar();
			t=getch();
			if(t=='y')
			{
				pnew->next=temp->next;
			  free(temp);
			  break;
			}
		}
		else
			{
				 menu();
			}
		pnew=temp;
		temp=temp->next;
	}
	write(head);
	printf("删除成功\n");
	delt_fanhui();	
}

void delt()
{


	CLEAR();
	locationN();
	locationK();
	printf("***诗歌删除***\n");
	locationK();
		printf("a.按诗名删除\n");
	locationK();
		printf("b.按诗人删除\n");
	locationK();
		printf("q.退出\n");

	poet head;
	head=read();
	char t;
	t=getch();
	switch(t)
	{
		case'a':delt_poetName(head);break;
		case'b':delt_poetMan(head);break;
		case'q':menu();break;
	}
}

void find_fanhui()
{
	    locationK();
			printf("a.返回上一层\n");
			locationK();
			printf("q.返回主菜单\n");
		char t;
		getchar();
		t=getch();
		if(t=='a')
		{
			find();
		}
		else
		{
			menu();
		}
}
void find_poetName(poet temp)
{
	CLEAR();
	char input_s[20];
    
	printf("please input the poetName to find:");
	scanf("%s",input_s);
	//printf("%s\n",input_s);
	while(temp)
	{
	
		if(((strcmp(temp->poetName,input_s))==0))
		{
			poet_print(temp);
			break;
		}
		temp=temp->next;
	}
	find_fanhui();
}
void find_poetMan(poet temp)
{
	CLEAR();
	char input_s[20];
	printf("please input the poetMan to find:");
	scanf("%s",input_s);
	while(temp)
	{
		if((strcmp(temp->poetMan,input_s))==0)
		{

			poet_print(temp);

		}
		temp=temp->next;
	}
	find_fanhui();
}
void find_creatTime(poet temp)
{
	CLEAR();
	char input_s[20];
	printf("please input the creatTime to find:");
	scanf("%s",input_s);
	//poet_print(temp);
	while(temp)
	{
		if((strcmp(temp->creatTime,input_s))==0)
		{
			poet_print(temp);

		}
		temp=temp->next;
	}
	find_fanhui();
}

void find()
{
	CLEAR();
	locationN();
	locationK();
	printf("×××诗歌查找×××\n");
	locationK();
		printf("a.按诗名查找.\n");
	locationK();
		printf("b.按诗人查找.\n");
	locationK();
		printf("c.按年代查找.\n");
	locationK();
		printf("q.退出\n");
	poet head;
	head=read();
	poet temp;
	temp=head->next;
	char t;
	t=getch();
	switch(t)
	{
		case'a':find_poetName(temp);break;
		case'b':find_poetMan(temp);break;
		case'c':find_creatTime(temp);break;
		case'q':menu();break;
	}
}

void total_fanhui()
{
	locationK();
		printf("a.返回上一层\n");
	locationK();
		printf("q.返回主菜单\n");
	char t;
	t=getch();
	if(t=='a')
	{
		total();
	}
	else
	{
		menu();
	}
	
}
void total_poetName(poet temp)//添加查重功能
{
	CLEAR();
	locationN();
	int i=1;
	locationK();
	printf("%d:%s\n",i,temp->poetName);
	while(temp->next)
	{
		if((strcmp(temp->poetName,temp->next->poetName))!=0)
		{
			i++;
			locationK();
			printf("%d:%s\n",i,temp->next->poetName);
		}
	
		temp=temp->next;
	}
		locationK();
		printf("共有%d首诗\n",i);
	total_fanhui();
}
void total_poetMan(poet temp)
{
	CLEAR();
	locationN();
	locationK();
	int i=1;
	printf("%d:%s\n",i,temp->poetMan);
	while(temp->next)
	{
		if((strcmp(temp->poetMan,temp->next->poetMan))!=0)
		{
			i++;
			locationK();
			printf("%d:%s\n",i,temp->next->poetMan);
		}
		
		temp=temp->next;
	}
	locationK();
	printf("共有%d首诗人\n",i);
	total_fanhui();
}
void total()
{
	CLEAR();
	locationN();
	locationK();
	printf("***诗歌统计***\n");
	locationK();
		printf("a.按诗名统计\n");
	locationK();
		printf("b.按诗人统计\n");
	locationK();
		printf("q.退出\n");
	poet head;
	head=read();
	poet temp;
	temp=head->next;
	char t;
	t=getch();
	switch(t)
	{
		case'a':total_poetName(temp);break;
		case'b':total_poetMan(temp);break;
		case'q':menu();break;
	}
	
}




void sort()
{
	CLEAR();
	locationN();
	printf("***诗歌排序***\n");
	poet f,y,x,p,t,q;
	f=NULL;
	//printf("q");
    poet head;
	head=read();
	while(f!=head->next->next)
	{
		
		for(p=head;f!=p->next->next;p=p->next)
		{
			
			if((strcmp(p->next->poetName,p->next->next->poetName))>0)
			{
				x=p->next;
				y=p->next->next;
				p->next=y;
				x->next=y->next;
				y->next=x;
				
			}
			
		}
		f=p->next;
	}
//	write(head);
	
	
	t=head->next;
	while(t)
	{
		poet_print(t);
		 
		printf("\n\n");
	    t=t->next;
	}
//	printf("任意键返回主菜单\n");*/
	char g;
	g=getch();


}

void print()
{
	CLEAR();
	poet head;
	head=read();
	poet temp;
	temp=head->next;
	while(temp)
	{
		//printf("")
		  poet_print(temp);
			printf("\n\n");
	    temp=temp->next;
	}
	printf("任意键返回主菜单");
	char t;
	t=getch();

	if(t)
	{
		menu();
	}
}

void menu1()
{
do
	{

		CLEAR();

		locationN();
		locationK();
	    printf("诗歌信息管理系统\n\n");
		locationK();
			printf("  a.数据录入.\n");
		locationK();
			printf("  b.数据修改.\n");
		locationK();
			printf("  c.数据删除.\n");
		locationK();
            printf("  q.主菜单.\n");
	char t;
	t=getch();
	printf("cout: %c\n",t);
	switch(t)
	{
		case 'a': input();break;        //数据录入
		case 'b': amend();break;       //  修改
		case 'c': delt();break;       //  删除
		case 'q':menu();break;
		default:  break;
	}
	}while(1);
}
void menu2()
{
	do
	{

		CLEAR();

		locationN();
		locationK();
	    printf("诗歌信息查阅系统\n\n");
		
		locationK();
			printf("  a.数据查询.\n");
		locationK();
			printf("  b.数据统计.\n");
		locationK();
			printf("  c.数据排序.\n");
		locationK();
			printf("  d.打印报表.\n");
        locationK();
            printf("  q.主菜单.\n");
	
	char t;
	t=getch();
	printf("cout: %c\n",t);
	switch(t)
	{
		
		case 'a': find();break;         // 查找
		case 'b': total();break;     //统计
		case 'c': sort();break;      //排序
		case 'd': print();break;  
        case 'q':menu();  //  打印
		default:  break;
	}
	}while(1);

}
void menu()
{
	do
	{

		CLEAR();

		locationN();
        locationK();
	        printf("  ****诗歌系统****\n\n");
		locationK();
	        printf("  a.诗歌信息管理系统\n\n");
		locationK();
			printf("  b.诗歌信息查阅系统.\n");
		
	
	char t;
	t=getch();
	printf("cout: %c\n",t);
	switch(t)
	{
		case 'a': menu1();break;        //数据录入
		case 'b': menu2();break;       //  修改
		
		default:  break;
	}
	}while(1);

}



int main()
{
    
    lmain();
	menu();
	
	return 0;
}


void lmenu()//显示登录菜单
{


printf("\n\n\t    欢迎使用会员登录系统\n\n");
printf("**********************************************");
printf("\n\t\t1.登录系统\n\n");
printf("\n\t\t2.创建账号\n\n");
printf("\n\t\t3.退出系统\n\n");

printf("**********************************************");
return ;
}


void lmain()//登录功能函数
{
	void land();
	void xinjian();
	char choose;
	lmenu();
	choose=getch();
	switch(choose)//功能函数
  {
	  case'1':
	    land();
	    break;
	  case'2':
	  	xinjian();
	  	break;
	  	
	  
	  case'3':
	  	//system("cls");
          CLEAR();
    //getch();
  	//exit(0);
  	//system ("cls");
      CLEAR();
	break;
  }
	CLEAR();
}




void xinjian()//新建账户密码
{

	FILE *fp;
	int zhanghao;
	char password[20],password1[20];
	char hit=0;
	char ch;
	int i=0;
	if ((fp=fopen("land.txt","a+"))==NULL)//if语句：打开图书馆文件，不存在此文件则新建
	{
      fp=fopen("land.txt","w");
      fclose(fp);
    }
   // system("cls");
	 
	fp=fopen("land.txt","a");

		 CLEAR();
	   printf("\n请输入账户学号:");
	   scanf("%d",&zhanghao);
		printf("请输入账户密码：");
		getchar();
	 while((ch=getch())!='\n') //按回车键退出        
        {
          password[i++]=ch;
          putchar('*');
        }      password[i]='\0';
    fprintf(fp,"%d %s\n",zhanghao,password);
		  
   fclose(fp);
   printf("\n创建成功，按任意键返回");
   getch();
   //system("cls");
   CLEAR();
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
	 	//system("cls");
         CLEAR();
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
	int i=0,j,k,n;
	char hit=0;
	char ch;
	CLEAR();
	
	   printf("请输入账号:");
     scanf("%d",&zhanghao);
      
   
	 printf("请输入密码:");
	 //scanf("%s",password);
	 getchar();
	 while((ch=getch())!='\n') //按回车键退出        
        {
          password[i++]=ch;
          putchar('*');
        }      password[i]='\0';
     i=match(zhanghao,password);
     if(i==1)
	 {
       printf("\n登陆成功!按任意键继续");
	   getch();
	   menu();
	 }
	 else
	 {
	 	if(i==-1)
		 {
		 printf("\n密码错误!");
		 getch();
         land();
		 }
		 if(i==0)
		 printf("\n不存在此用户");
		 getch();
		 //system("cls");
		 CLEAR();
         lmain();
	 }
}


