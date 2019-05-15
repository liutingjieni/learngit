#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include <windows.h>
#include <stdarg.h>
#include <unistd.h>
#include <termios.h>

#define CLEAR()     printf("\ec")     //����   
#define CLOSE()     printf("\e[0m")   //�ر���������

//color��������ɫ����
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
	����ս��,
	�غ�,
	���ʮ��,
	��,
	��,
	��,
	Ԫ,
	��,
	��,
	����
}CREAT_TIME;

//color()����
int color_printf(COULEUR_TERMINAL fg, COULEUR_TERMINAL bg, const char * format, ...)
{
  int res;
  va_list args;
  printf("\x1B[1;%02d;%02dm", fg + 30, bg + 40);
  va_start(args, format);
  res = vprintf(format, args);
  va_end(args);
  printf("\x1B[00m");
  //���ر�printf���õ���ɫ������
  CLOSE();
  return res;
}

//��������->�ǻ�������
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
    in=fopen("input.txt","ab+");//��ֻ����ʽ���ļ�
	if(in==NULL)
	{
		printf("���ļ�����");
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
	out=fopen("output","a+");//�Զ�дģʽ�򿪣�
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
	printf("������ʫ����ҡ�����");
	locationK();
		printf("a.��ʫ������.");
	locationK();
		printf("b.��ʫ�˲���.");
	locationK();
		printf("c.���������.");
	locationK();
		printf("q.�˳�");
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
	printf("***ʫ��ͳ��***");
	locationK();
		printf("a.��ʫ��ͳ��");
	locationK();
		printf("b.��ʫ��ͳ��");
	locationK();
		printf("q.�˳�");
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
	printf("***ʫ���������***");
	locationK();
		printf("a.�������������");
	locationK();
		printf("a.�������������");
	locationK();
		printf("q.�˳�");
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
	    printf("ʫ����Ϣ����ϵͳ\n\n");
	locationK();
		printf("  a.����¼��.\n");
	locationK();
		printf("  b.���ݴ洢.\n");
	locationK();
		printf("  c.���ݶ�д.\n");
	locationK();
		printf("  d.�����޸�.\n");
	locationK();
		printf("  e.����ɾ��.\n");
	locationK();
		printf("  f.���ݲ�ѯ.\n");
	locationK();
		printf("  g.����ͳ��.\n");
	locationK();
		printf("  h.��������.\n");
	locationK();
		printf("  i.���ݱ���.\n");

	t=getch();

	switch(t)
	{
		case 'a': input();break;        //����¼��
		case 'b': save();break;        // ���ݴ洢
		case 'c': readWrite();break;   // ��д
		case 'd': amend();break;       //  �޸�
		case 'e': delt();break;       //  ɾ��
		case 'f': find();break;         // ����
		case 'g': total();break;     //ͳ��
		case 'h': sort();break;      //����
		case 'i': print();break;    //  ��ӡ
		default:  break;
	}
	}while(1);

}



int main()
{

	menu();

	return 0;
}
