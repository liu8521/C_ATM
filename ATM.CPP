#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "login.h"//登陆函数模块
#include "Welcome.h"//界面欢迎模块
#include "client.h"//用户界面
int main()
{
	system("color 2a");
	wel();
	printf("\t\t\t确定登陆？Y/N   ");
	char c;
	scanf("%c",&c);
	getchar();
	if(c=='n'||c=='N')
	{
		exitsystem();
	}
	else
	{
		int f;
		system("cls");
		printf("\t\t\t进入中，请稍候.......\n\n");
		Sleep (500);
		f=login();
		system("cls");
		if(f==1)
		{
			printf("正在退出系统。。。。");
			Sleep(3000);
			exitsystem();
		}
		else
		{
			while(1)
			{
				menu();
				printf("\n\t请输入代号：");
				int m;
				scanf("%d",&m);
				getchar();
				if(m==1)
				{
				
					Sleep (500);
					showmoney();	
					system("cls");
				}
				else if(m==2)
				{
				
					Sleep (500);
					drawmoney();	
					system("cls");
				}
				else if(m==3)
				{
				
					Sleep (500);
					savemoney();	
					system("cls");
				}
				else if(m==4)
				{
				
					Sleep (500);
					updatekey();	
					system("cls");
				}
				else if(m==5)
				{
				
					Sleep (500);
					rename();	
					system("cls");
				}
				else if(m==6)
				{
				
					exitsystem();
					break;
				}
			}
		}	
	}	
	return 0;
}