struct client
{
	char name[50];
	char key[10];
	int money;
}user;
char *get_password()//�Ǻ������ȡ������
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

int login()//��½������
{
	FILE *fp;
	if((fp=fopen("data/client.dat","rb"))!=NULL)
	{
		fread(&user,sizeof(user),1,fp);
	}
	else
	{
		printf("���û���Ϣ����!\n");
	}
	char a[50];
	char b[50];
	int count=0,i,flag=0;
	while(1)
	{
		printf("\t�����������û�����");
		scanf("%s",a);
		printf("\t��������������  ��");
		strcpy(b,get_password());
		if(strcmp(a,user.name)!=0 || strcmp(b,user.key)!=0)
			printf("\t�û���������������������������룡\n");
		else 
		{
			printf("\t\t\t���ڵ�½  ���Ժ�\n");
			printf("\t\t\t");
			for(i=0;i<8;i++)
			{
				printf("��");
				Sleep(500);
			}
			printf("\n");
			break;
		}
		count++;
		if(count == 3)
		{
			printf("\t\t����������ѳ�������,ϵͳ���˳���\n");
			system("color 4a");
			flag=1;
			break;
		}
	}
	return flag;
}