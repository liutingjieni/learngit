#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include <windows.h>
#include <stdarg.h>
#include <unistd.h>
#include <termios.h>

#define CLEAR()     printf("\ec")     //����   
#define CLOSE()     printf("\e[0m")   //�ر���������


typedef struct p{
	char poetName[20];
	char creatTime[20];
	char poetMan[10];
	char poet[200];
	char command[300];
	struct p *next;

}POET,*poet;

void locationN();
void locationK();
int color_printf(COULEUR_TERMINAL fg, COULEUR_TERMINAL bg, const char * format, ...);
int getch();

poet input_wenjian();//�����⣬ѡ��һ�����뷽ʽ��Ҫ��Ȼ�ᴴ����������
poet input_stdin();//����ѡ��ÿ��д���ļ���ÿ�ζ�������a��ʽ��
void input();

void save(poet head);//ÿ�������޸���֮�����±���
void readWrite();//ÿ��������ʼ֮ǰ�����¶���

void amend_command(poet temp);
void amend_poetName(poet temp);
void amend_creatTime(poet temp);
void amend_poetMan(poet temp);
void amend_poet(poet temp);
void amend_build(poet head);
void amend();

void delt_poetName(poet temp);
void delt_poetMan(poet temp);
void delt(poet head);

void find_poetName(poet temp);
void find_poetMan(poet temp);
void find_creatTime(poet temp);
void find(poet head);

void total_poetName(poet temp);
void total_poetMan(poet temp);
void total(poet head);

void sort_creatTime(poet temp);
void sort(poet head);

void print(poet head);
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
	����ս��=0,
	�غ�=1,
	���ʮ��=2,
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

poet input_wenjian()
{
	FILE *in;
	in=fopen("input.txt","r");
	poet phead,pnew,pend;
	phead=(poet)malloc(sizeof(POET));
	phead->next=NULL;
	pend=phead;

	pnew=(poet)malloc(sizeof(POET));
	fread(&pnew,sizeof(POET),1,in);
	while(pnew->poetName!="#")
	{
		pnew->next=NULL;
		pnew=pend->next;
		pend=pnew;

		pnew=(poet)malloc(sizeof(POET));
		fread(&pnew,sizeof(POET),1,in);
		/*fscanf(in,"%s",pnew->poetName);
		fscanf(in,"%s",pnew->creatTime);
		fscanf(in,"%s",pnew->poetMan);
		fscanf(in,"%s",pnew->poet);
		fscanf(in,"%s",pnew->command);
	   */
	}

	return phead;
}
poet input_stdin()
{
	poet phead,pnew,pend;
	phead=(poet)malloc(sizeof(POET));
	phead->next=NULL;
	pend=phead;

	pnew=(poet)malloc(sizeof(POET));
	scanf("%s",pnew->poetName);
	scanf("%s",pnew->poetMan);
	scanf("%s",pnew->creatTime);
	scanf("%s",pnew->poet);
	scanf("%s",pnew->command);
	while(pnew->poetName!="#")
	{
		pnew->next=NULL;
		pnew=pend->next;
		pend=pnew;

		pnew=(poet)malloc(sizeof(POET));
		scanf("%s",pnew->poetName);
		scanf("%s",pnew->poetMan);
		scanf("%s",pnew->creatTime);
		scanf("%s",pnew->poet);
		scanf("%s",pnew->command);
	}

	return phead;
}

void input()
{
	do
	{
		CLEAR();
	locationN();
	locationK();
	printf("������ʫ�����������");
	locationK();
		printf("a.���ļ���ʽ����.");
	locationK();
		printf("b.��׼��������.");
	locationK();
		printf("q.�˳�");
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
	out=fopen("output","w+");//��дģʽ�򿪣�ÿ������д�룬�ᶪ��֮ǰ�����ݣ�
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
		CLEAR();
	locationN();
	locationK();


}
void amend_poetName(poet temp)
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

			printf("�Ƿ�ȷ���޸ģ�y/n");
			char t;
			t=getch();
			if(t=='y')
			{
				CLEAR();
				locationN();
				locationK();
				printf("��������ȷʫ��");
				char input_s[20];
				scanf("%s",input_s);
				strcpy(temp->poetName,input_s);
			}
			else
			{
				amend();
			}
		}
		temp=temp->next;
	}
}
void amend_creatTime(poet temp)
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

			printf("�Ƿ�ȷ���޸ģ�y/n");
			char t;
			t=getch();
			if(t=='y')
			{
				CLEAR();
				locationN();
				locationK();
				printf("��������ȷ����ʱ��");
				char input_s[20];
				scanf("%s",input_s);
				strcpy(temp->creatTime,input_s);
			}
			else
			{
				amend();
			}
		}
		temp=temp->next;
	}
}
void amend_poetMan(poet temp)
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

			printf("�Ƿ�ȷ���޸ģ�y/n");
			char t;
			t=getch();
			if(t=='y')
			{
				CLEAR();
				locationN();
				locationK();
				printf("��������ȷʫ��");
				char input_s[20];
				scanf("%s",input_s);
				strcpy(temp->poetName,input_s);
			}
			else
			{
				amend();
			}
		}
		temp=temp->next;
	}
}
void amend_poet(poet temp)
{
	char input_s[200];
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

			printf("�Ƿ�ȷ���޸ģ�y/n");
			char t;
			t=getch();
			if(t=='y')
			{
				CLEAR();
				locationN();
				locationK();
				printf("��������ȷʫ��");
				char input_s[20];
				scanf("%s",input_s);
				strcpy(temp->poetName,input_s);
			}
			else
			{
				amend();
			}
		}
		temp=temp->next;
	}
}
void amend_command(poet temp)
{
	char input_s[300];
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

			printf("�Ƿ�ȷ���޸ģ�y/n");
			char t;
			t=getch();
			if(t=='y')
			{
				CLEAR();
				locationN();
				locationK();
				printf("��������ȷ����");
				char input_s[20];
				scanf("%s",input_s);
				strcpy(temp->poetName,input_s);
			}
			else
			{
				amend();
			}
		}
		temp=temp->next;
	}
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
	printf("�Ƿ�ȷ�����룿y/n");
	char t;
	t=getch();
	if(t=='y')
	{
		pnew->next=head->next;
	  pnew=head->next;
		printf("���ӳɹ�");
	}
	else
	{
		amend();
	}
	
}
void amend()
{ 
	CLEAR();
	locationN();
	locationK();
				printf("***ʫ���޸�***");
				locationK();
						printf("a.�޸�ʫ��");
				locationK();
						printf("b.�޸Ĵ���ʱ��");
				
				locationK();
						printf("c.�޸�ʫ��");
				locationK();
						printf("d.�޸�ʫ��");
				locationK();
						printf("e.�޸�����");
				locationK();
						printf("f.��������");
				locationK();
						printf("q.�˳�");

	char t;
	t=getch();

	poet head;
	head=read();
	poet temp;
	temp=head->next;
	switch(t)
	{
		case'a':amend_poetName(temp);break;
		case'b':amend_creatTime(temp);break;
		case'c':amend_poetMan(temp);break;
		case'd':amend_poet(temp);break;
		case'e':amend_command(temp);break;
		case'f':amend_build(head);break;
		case'q':menu();break;
	}

}
void delt_poetName(poet temp)
{
	poet pnew;
	CLEAR();
	locationN();
	locationK();
	char input_s[20];
	scanf("%s",input_s);

	while(temp)
	{
		if(strcmp(input_s,temp->poetName)==0)
		{
			printf("%s\n",temp->poetName);
			printf("%s\n",temp->poetMan);
			printf("%s\n",temp->creatTime);
			printf("%s\n",temp->poet);
			printf("%s\n",temp->command);
			printf("�Ƿ�ȷ��ɾ����y/n");
			char t;
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
}
void delt_poetMan(poet temp)
{
	poet pnew;
	CLEAR();
	locationN();
	locationK();
	char input_s[20];
	scanf("%s",input_s);
	while(temp)
	{
		if(strcmp(input_s,temp->poetMan)==0)
		{
			pnew->next=temp->next;
			free(temp);
			break;
		}
		pnew=temp;
		temp=temp->next;
	}
}

void delt(poet head)
{
	CLEAR();
	locationN();
	locationK();
	printf("***ʫ��ɾ��***");
	locationK();
		printf("a.��ʫ��ɾ��");
	locationK();
		printf("b.��ʫ��ɾ��");
	locationK();
		printf("q.�˳�");
	
	poet temp;
	temp=head->next;
	char t;
	t=getch();
	switch(t)
	{
		case'a':delt_poetName(temp);break;
		case'b':delt_poetMan(temp);break;
		case'q':menu();break;
	}

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

void total_poetName(poet temp)//���Ӳ��ع���
{
	int i;
	while(temp)
	{
		i++;
		temp=temp->next;
	}
	printf("%d",i);
}
void total_poetMan(poet temp)
{
		int i;
		while(temp)
		{
			i++;
			temp=temp->next;
		}
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

void sort_creatTime(poet temp)	//Ͱ����
{
	int a[10];
	CREAT_TIME i;
	for(i=����ս��;i<=����;i++)
	{
		a[i]=0;

	}
	while(temp)
	{
		for(i=����ս��;i<=����;i++)
		{
				{
					
				}
		}
		temp=temp->next;
	}

}
void sort(poet head)
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
	temp=head->next;
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
		  printf("%s\n",temp->poetName);
			printf("%s\n",temp->poetMan);
			printf("%s\n",temp->creatTime);
			printf("%s\n",temp->poet);
			printf("%s\n",temp->command);

	    temp=temp->next;
	}
}




void menu()
{
	do
	{
		char t;
		CLEAR();
//	system("clear");
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
  poet head;
	
	return 0;
}
