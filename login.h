struct client
{
	char name[50];
	char key[10];
	int money;
}user;
char *get_password()//星号密码获取函数；
{
	int i=0;
	char a[50];
	char ch='\0';
	while(ch != '\r')
	{
		ch = getch();
		if(ch == 8)
		{
			a[--i]='\0';
			putchar(8);
			putchar(' ');
			putchar(8);
		}
		else
		{
			if(ch=='\r')
				break;
			a[i++] = ch;
			printf("*");
		}
	}
	a[i]='\0';
	printf("\n");
	return &a[0];
}  

int login()//登陆函数；
{
	FILE *fp;
	if((fp=fopen("data/client.dat","rb"))!=NULL)
	{
		fread(&user,sizeof(user),1,fp);
	}
	else
	{
		printf("该用户信息错误!\n");
	}
	char a[50];
	char b[50];
	int count=0,i,flag=0;
	while(1)
	{
		printf("\t请输入您的用户名：");
		scanf("%s",a);
		printf("\t请输入您的密码  ：");
		strcpy(b,get_password());
		if(strcmp(a,user.name)!=0 || strcmp(b,user.key)!=0)
			printf("\t用户名或者密码输入错误！请重新输入！\n");
		else 
		{
			printf("\t\t\t正在登陆  请稍后\n");
			printf("\t\t\t");
			for(i=0;i<8;i++)
			{
				printf("■");
				Sleep(500);
			}
			printf("\n");
			break;
		}
		count++;
		if(count == 3)
		{
			printf("\t\t您输入错误已超过三次,系统已退出！\n");
			system("color 4a");
			flag=1;
			break;
		}
	}
	return flag;
}