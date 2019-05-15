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

void sort_poetMan(poet temp);
void sort();

void print();
void menu();

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
/*
typedef enum{
	春秋战国=0,
	秦汉=1,
	五国十代=2,
	隋=3,
	唐=4,
	宋=5,
	元=6,
	明=7,
	清=8,
	近代=9
}CREAT_TIME;*/

//color()函数
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

	pnew=(poet)malloc(sizeof(POET));
	//printf("分配成功3");
	//fread(&pnew,sizeof(POET),1,in);
	fscanf(in,"%s",pnew->poetName);
		fscanf(in,"%s",pnew->creatTime);
		fscanf(in,"%s",pnew->poetMan);
		fscanf(in,"%s",pnew->poet);
		fscanf(in,"%s",pnew->command);
	poet_print(pnew);
	while(!feof(in))
	{
		pnew->next=NULL;
		pend->next=pnew;
		pend=pnew;
		
		pnew=(poet)malloc(sizeof(POET));
		//fread(&pnew,sizeof(POET),1,in);
		fscanf(in,"%s",pnew->poetName);
		fscanf(in,"%s",pnew->creatTime);
		fscanf(in,"%s",pnew->poetMan);
		fscanf(in,"%s",pnew->poet);
		fscanf(in,"%s",pnew->command);
		poet_print(pnew);
	}
	free(pnew);
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

	printf("please input the amending poetNyame:");
	scanf("%s",input_s1);
//	getchar();

	while(temp)
	{
	
		if((strcmp(temp->poetName,input_s1))==0)
		{
		
			poet_print(temp);
			printf("\n是否确定修改？y/n");
			char t;
			t=getch();
			if(t=='y')
			{
				printf("\n请输入正确诗名:");
				char input_s[20];
				getchar();
				scanf("%s",input_s);
				printf("%s\n",input_s);
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
	
//	write(head);
	
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
	getchar();
	while(temp)
	{
		printf("[%s][%s]\n", input_s1, temp->poetName);
		if(strcmp(temp->poetName,input_s1)==0)
		{
			CLEAR();
			poet_print(temp);
			printf("\n是否确定修改？y/n");
			char t;
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
	getchar();
	while(temp)
	{
		if(strcmp(temp->poetName,input_s1)==0)
		{
			CLEAR();
			poet_print(temp);
			printf("是否确定修改？y/n");
			char t;
			t=getch();
			if(t=='y')
			{
				printf("\n请输入正确诗人");
				char input_s[20];
				scanf("%s",input_s);
				getchar();
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
	amend_fanhui();
}
void amend_poet(poet head)
{
	CLEAR();
	poet temp;
	temp=head->next;
	char input_s1[20];
	printf("%s",temp->poetName);
	printf("please input the amending poetName:");
	scanf("%s",input_s1);
	getchar();
	while(temp)
	{
		if(strcmp(temp->poetName,input_s1)==0)
		{
			CLEAR();
			poet_print(temp);
			printf("是否确定修改？y/n");
			char t;
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
	getchar();
	while(temp)
	{
		if(strcmp(temp->poetName,input_s1)==0)
		{
			CLEAR();
			printf("\n是否确定修改？y/n");
			char t;
			t=getch();
			if(t=='y')
			{
				CLEAR();
				locationN();
				locationK();
				printf("请输入正确赏析");
				char input_s[300];
				scanf("%s",input_s);
				getchar();
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
	//CLEAR();
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
	poet_print(temp);
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

/*void sort_creatTime(poet temp)	//桶排序
{
	int a[10];
	CREAT_TIME i;
	for(i=春秋战国;i<=近代;i++)
	{
		a[i]=0;
	}
	while(temp)
	{
		for(i=春秋战国;i<=近代;i++)
		{
			if(temp->creatTime)
			{
				a[i]++;
			}
		}
		temp=temp->next;
	}
}*/
void sort_poetMan(poet temp)
{
	CLEAR();
	int i=0,j,n;
	char a[20][20];
	char t[20];
	while(temp)
	{
		strcpy(a[i],temp->poetMan);
		temp=temp->next;
		i++;
	}

	n=i;
	for(i=0;i<=n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
				if((strcmp(a[j],a[j+1]))>0)
				{
					strcpy(t,a[j]);
					strcpy(a[j],a[j+1]);
					strcpy(a[j+1],t);
				}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%s\n",a[i]);
	}
	printf("任意键返回主菜单\n");

	char g;
	g=getch();
	if(t)
	{
		menu();
	}
}


void sort()
{
	CLEAR();
	locationN();
	locationK();
	printf("***诗歌排序***\n");
	locationK();
		printf("a.按诗人的首写字母排序\n");
	locationK();
		printf("q.退出\n");
	//int count=0;
	poet head;
	head=read();
	poet temp;
	temp=head->next;

	char t;
	t=getch();
	switch(t)
	{
		case'a':sort_poetMan(temp);break;
		case'q':menu();break;
	}
	
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

void menu()
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
			printf("  d.数据查询.\n");
		locationK();
			printf("  e.数据统计.\n");
		locationK();
			printf("  f.数据排序.\n");
		locationK();
			printf("  g.打印报表.\n");
	
	char t;
	t=getch();
	printf("cout: %c\n",t);
	switch(t)
	{
		case 'a': input();break;        //数据录入
		case 'b': amend();break;       //  修改
		case 'c': delt();break;       //  删除
		case 'd': find();break;         // 查找
		case 'e': total();break;     //统计
		case 'f': sort();break;      //排序
		case 'g': print();break;    //  打印
		default:  break;
	}
	}while(1);

}



int main()
{

	menu();
	
	return 0;
}
