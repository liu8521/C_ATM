void showmoney()//功能1：查询余额
{
	printf("\t用户名  ：%s\n",user.name);
	printf("\t账户余额：%d\n",user.money);
	printf("\t请按Enter键返回\n");
	getchar();
}

void drawmoney()//功能2：取款业务
{
	FILE *fp;
	int a,i;
	char c;
	while(1){
	printf("\t请输入您的取款金额：");
	scanf("%d",&a);
	if(a>user.money)
		printf("\t账户余额不足，请重新输入！\n");
	else if(a<0)
		printf("\t输入有误，请重新输入！\n");
	else
		break;

	}
	getchar();
	user.money-=a;
	if((fp=fopen("data/client.dat","wb"))!=NULL)
	{
		fwrite(&user, sizeof(client), 1 ,fp);
		fclose(fp);
	}
	printf("\t取款成功,请收好您的钞票！\n");
	printf("\t是否打印凭条？  y/n  ");
	scanf("%c",&c);
	getchar();
	if(c=='Y' || c=='y')
	{
		printf("\t正在打印请稍后。。。。。\n\t\t");
		for(i=0;i<10;i++)
		{
			printf("■");
			Sleep(400);
		}
		printf("\n");
		printf("\t打印完成，请收好您的凭条\n");
		printf("\t请按Enter键退出\n");
		getchar();
		
	}
	else
	{
		printf("\t请按Enter键退出\n");
		getchar();
		
	}
	
}

void savemoney()//功能3：存款业务
{
	FILE *fp;
	int a,i;
	char c;
	printf("\t请输入您的存款数额：");
	scanf("%d",&a);
	getchar();
	user.money+=a;
	if((fp=fopen("data/client.dat","wb"))!=NULL)
	{
		fwrite(&user, sizeof(client), 1 ,fp);
		fclose(fp);
	}
	printf("\t存款成功\n");
	printf("\t是否打印凭条？  y/n  ");
	scanf("%c",&c);
	getchar();
	if(c=='Y' || c=='y')
	{
		printf("\t正在打印请稍侯。。。。。\n\t\t");
		for(i=0;i<10;i++)
		{
			printf("■");
			Sleep(400);
		}
		printf("\n");
		printf("\t打印完成，请收好您的凭条\n");
		printf("\t请按Enter键退出\n");
		getchar();
	}
	else
	{
		printf("\t请按Enter键退出\n");
		getchar();
	}
}

void updatekey()//功能5：改密业务
{
	char ch[10];
	char str[10];
	FILE *fp;
	printf("\t请输入您的初始密码 ：");
	strcpy(ch,get_password());
	while(1)
	{
		if(strcmp(ch,user.key) != 0)
		{
			printf("\t您的初始密码输入错误请重新输入：\n");
			strcpy(ch,get_password());
		}
		else 
			break;
	}
	while(1){
		printf("\t请输入您要修改的密码：");
		strcpy (ch,get_password());
		printf("\t请再次输入要修改的密码：");
		strcpy(str,get_password());
		if(strcmp(ch,str)==0)
		{
			strcpy(user.key,ch);
			printf("\t正在为您修改，请稍候\n");
			Sleep(200); 
			if((fp=fopen("data/client.dat","wb"))!=NULL)
			{
				fwrite(&user, sizeof(client), 1 ,fp);
				fclose(fp);
			}
			printf("\t密码修改成功\n");
			printf("\t请按回车键退出\n");
			getchar();
			break;
		}
		else
			printf("\t您两次密码输入不一致，请重新输入！\n");
	}
}
void rename()//功能5：修改用户名
{
	FILE *fp;
	char name[30];
	char mame[30];
	while(1)
	{
		printf("\t请输入您要修改的用户名：");
		scanf("%s",&name);
		printf("\t请确认您的用户名      ：");
		scanf("%s",&mame);
		if(strcmp(name,mame)==0)
		{
			strcpy(user.name,name);
			if((fp=fopen("data/client.dat","wb"))!=NULL)
			{
				fwrite(&user, sizeof(client), 1 ,fp);
				fclose(fp);
			}
			printf("\t已成功修改您的用户名，请牢记！");
			printf("\t请按回车键退出\n");
			getchar();
			break;
		}
		else
			printf("\t您两次输入的用户名不一致，请重新输入！\n");
	}
}
void exitsystem()//功能6：退出系统
{
	system("cls");
	FILE *fp;
	char ch;
	fp=fopen("data/exit.txt","r");
	while(!feof(fp))
	{
		ch=fgetc(fp);
		putchar(ch);
	}
	fclose(fp);
	printf("\n");
	printf("请按Enter键退出\n");
	getchar();
}
