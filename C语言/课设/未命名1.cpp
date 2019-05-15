#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include <windows.h>
#include <stdarg.h>
#include <unistd.h>
#include <termios.h>

#define CLEAR()     printf("\ec")     //清屏   
#define CLOSE()     printf("\e[0m")   //关闭所有属性

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

typedef enum{
	春秋战国,
	秦汉,
	五国十代,
	隋,
	唐,
	宋,
	元,
	明,
	清,
	近代
}CREAT_TIME;

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

poet ss()
{
    FILE *in;
	poet phead,pnew,pend;
    in=fopen("input.txt","ab+");//以只读方式打开文件
	if(in==NULL)
	{
		printf("打开文件错误");
	}
	rewind(in);

	phead=(poet)malloc(sizeof(POET));
	phead->next=NULL;
	pend=phead;
	pnew=(poet)malloc(sizeof(POET));
	fscanf(in,"%s",pnew->poetName);
	fscanf(in,"%s",pnew->creatTime);
	fscanf(in,"%s",pnew->poetMan);
	fscanf(in,"%s",pnew->poet);
	fscanf(in,"%s",pnew->command);

	while(pnew->poetName!="#")
	{
		pnew->next=NULL;
		pnew=pend->next;
		pend=pnew;

		pnew=(poet)malloc(sizeof(POET));
		fscanf(in,"%s",pnew->poetName);
		fscanf(in,"%s",pnew->creatTime);
		fscanf(in,"%s",pnew->poetMan);
		fscanf(in,"%s",pnew->poet);
		fscanf(in,"%s",pnew->command);
	
	}


   // out=fopen("output","a+");   //
	return phead;

}

void input()
{
	do{
	
	system("clear");
	// 	system("color a0");
    //	    printf


	} while(1);
}

void save(poet head)
{
	
	FILE *out;
	out=fopen("output","a+");//以读写模式打开；
	poet temp;
	temp=head->next;
	while(temp)
	{
		fwrite(temp,sizeof(POET),1,out);
		/*fprintf(out,"%s",temp->poetName);
		fprintf(out,"%s",temp->creatTime);
		fprintf(out,"%s",temp->poetMan);
		fprintf(out,"%s",temp->poet);
		fprintf(out,"%s",temp->command);*/
		temp=temp->next;
	}
}

void readWrite()
{

}

void amend()
{
}

void delt()
{
}
void find_poetName(poet temp)
{
	char input_s[20];
	scanf("%s",input_s);
	while(temp)
	{
		if(strcmp(temp->poetName,input_s)==0)
		{

			printf("%s\n",temp->poetName);
			printf("%s\n",temp->poetMan);
			printf("%s\n",temp->creatTime);
			printf("%s\n",temp->poet);
			printf("%s\n",temp->command);
			break;
		}
		temp=temp->next;
	}
}
void find_poetMan(poet temp)
{
	char input_s[20];
	scanf("%s",input_s);
	while(temp)
	{
		if(strcmp(temp->poetMan,input_s)==0)
		{

			printf("%s\n",temp->poetName);
			printf("%s\n",temp->poetMan);
			printf("%s\n",temp->creatTime);
			printf("%s\n",temp->poet);
			printf("%s\n",temp->command);

		}
		temp=temp->next;
	}
}

void find_creatTime(poet temp)
{
	char input_s[20];
	scanf("%s",input_s);
	while(temp)
	{
		if(strcmp(temp->creatTime,input_s)==0)
		{

			printf("%s\n",temp->poetName);
			printf("%s\n",temp->poetMan);
			printf("%s\n",temp->creatTime);
			printf("%s\n",temp->poet);
			printf("%s\n",temp->command);

		}
		temp=temp->next;
	}
}

void find(poet head)
{
	CLEAR();
	locationN();
	locationK();
	printf("×××诗歌查找×××");
	locationK();
		printf("a.按诗名查找.");
	locationK();
		printf("b.按诗人查找.");
	locationK();
		printf("c.按年代查找.");
	locationK();
		printf("q.退出");
	char t;
	t=getch();
	poet temp;
	temp=head->next;
	switch(t)
	{
		case'a':find_poetName(temp);break;
		case'b':find_poetMan(temp);break;
		case'c':find_creatTime(temp);break;
		case'q':menu();break;
	}
}

void total_poetName()
{

}
void total_poetMan()
{

}
void total(poet head)
{
	CLEAR();
	locationN();
	locationK();
	printf("***诗歌统计***");
	locationK();
		printf("a.按诗名统计");
	locationK();
		printf("b.按诗人统计");
	locationK();
		printf("q.退出");
	int count=0;
	poet temp;
	temp=temp->next;
	char t;
	t=getch();
	switch(t)
	{
		case'a':total_poetName(temp);break;
		case'b':total_poetMan(temp);break;
		case'q':menu();break;
	}
	

	
}

void sort_creatTime(poet temp)
{
	
}
void sort()
{
	CLEAR();
	locationN();
	locationK();
	printf("***诗歌年代排序***");
	locationK();
		printf("a.按年代升序排序");
	locationK();
		printf("a.按年代降序排序");
	locationK();
		printf("q.退出");
	//int count=0;
	poet temp;
	temp=temp->next;
	char t;
	t=getch();
	switch(t)
	{
		case'a':sort_creatTime(temp);break;
		case'b':sort_creatTime(temp);break;
		case'q':menu();break;
	}
	
}

void print(poet head)
{
	poet temp;
	temp=head->next;
	while(temp)
	{
	
		temp=temp->next;
	}
}


typedef struct poet{
	char poetName[20];
	char creatTime[20];
	char poetMan[10];
	char poet[200];
	char command[300];
	struct poet *next;

}POET,*poet;

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


void menu()
{
	do
	{
		char t;
	system("clear");
	//system("CLS");
	//system("color 1f");

	locationN();
	locationK();
	    printf("诗歌信息管理系统\n\n");
	locationK();
		printf("  a.数据录入.\n");
	locationK();
		printf("  b.数据存储.\n");
	locationK();
		printf("  c.数据读写.\n");
	locationK();
		printf("  d.数据修改.\n");
	locationK();
		printf("  e.数据删除.\n");
	locationK();
		printf("  f.数据查询.\n");
	locationK();
		printf("  g.数据统计.\n");
	locationK();
		printf("  h.数据排序.\n");
	locationK();
		printf("  i.数据报表.\n");

	t=getch();

	switch(t)
	{
		case 'a': input();break;        //数据录入
		case 'b': save();break;        // 数据存储
		case 'c': readWrite();break;   // 读写
		case 'd': amend();break;       //  修改
		case 'e': delt();break;       //  删除
		case 'f': find();break;         // 查找
		case 'g': total();break;     //统计
		case 'h': sort();break;      //排序
		case 'i': print();break;    //  打印
		default:  break;
	}
	}while(1);

}



int main()
{

	menu();

	return 0;
}
