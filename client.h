void showmoney()//����1����ѯ���
{
	printf("\t�û���  ��%s\n",user.name);
	printf("\t�˻���%d\n",user.money);
	printf("\t�밴Enter������\n");
	getchar();
}

void drawmoney()//����2��ȡ��ҵ��
{
	FILE *fp;
	int a,i;
	char c;
	while(1){
	printf("\t����������ȡ���");
	scanf("%d",&a);
	if(a>user.money)
		printf("\t�˻����㣬���������룡\n");
	else if(a<0)
		printf("\t�����������������룡\n");
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
	printf("\tȡ��ɹ�,���պ����ĳ�Ʊ��\n");
	printf("\t�Ƿ��ӡƾ����  y/n  ");
	scanf("%c",&c);
	getchar();
	if(c=='Y' || c=='y')
	{
		printf("\t���ڴ�ӡ���Ժ󡣡�������\n\t\t");
		for(i=0;i<10;i++)
		{
			printf("��");
			Sleep(400);
		}
		printf("\n");
		printf("\t��ӡ��ɣ����պ�����ƾ��\n");
		printf("\t�밴Enter���˳�\n");
		getchar();
		
	}
	else
	{
		printf("\t�밴Enter���˳�\n");
		getchar();
		
	}
	
}

void savemoney()//����3�����ҵ��
{
	FILE *fp;
	int a,i;
	char c;
	printf("\t���������Ĵ�����");
	scanf("%d",&a);
	getchar();
	user.money+=a;
	if((fp=fopen("data/client.dat","wb"))!=NULL)
	{
		fwrite(&user, sizeof(client), 1 ,fp);
		fclose(fp);
	}
	printf("\t���ɹ�\n");
	printf("\t�Ƿ��ӡƾ����  y/n  ");
	scanf("%c",&c);
	getchar();
	if(c=='Y' || c=='y')
	{
		printf("\t���ڴ�ӡ���Ժ��������\n\t\t");
		for(i=0;i<10;i++)
		{
			printf("��");
			Sleep(400);
		}
		printf("\n");
		printf("\t��ӡ��ɣ����պ�����ƾ��\n");
		printf("\t�밴Enter���˳�\n");
		getchar();
	}
	else
	{
		printf("\t�밴Enter���˳�\n");
		getchar();
	}
}

void updatekey()//����5������ҵ��
{
	char ch[10];
	char str[10];
	FILE *fp;
	printf("\t���������ĳ�ʼ���� ��");
	strcpy(ch,get_password());
	while(1)
	{
		if(strcmp(ch,user.key) != 0)
		{
			printf("\t���ĳ�ʼ��������������������룺\n");
			strcpy(ch,get_password());
		}
		else 
			break;
	}
	while(1){
		printf("\t��������Ҫ�޸ĵ����룺");
		strcpy (ch,get_password());
		printf("\t���ٴ�����Ҫ�޸ĵ����룺");
		strcpy(str,get_password());
		if(strcmp(ch,str)==0)
		{
			strcpy(user.key,ch);
			printf("\t����Ϊ���޸ģ����Ժ�\n");
			Sleep(200); 
			if((fp=fopen("data/client.dat","wb"))!=NULL)
			{
				fwrite(&user, sizeof(client), 1 ,fp);
				fclose(fp);
			}
			printf("\t�����޸ĳɹ�\n");
			printf("\t�밴�س����˳�\n");
			getchar();
			break;
		}
		else
			printf("\t�������������벻һ�£����������룡\n");
	}
}
void rename()//����5���޸��û���
{
	FILE *fp;
	char name[30];
	char mame[30];
	while(1)
	{
		printf("\t��������Ҫ�޸ĵ��û�����");
		scanf("%s",&name);
		printf("\t��ȷ�������û���      ��");
		scanf("%s",&mame);
		if(strcmp(name,mame)==0)
		{
			strcpy(user.name,name);
			if((fp=fopen("data/client.dat","wb"))!=NULL)
			{
				fwrite(&user, sizeof(client), 1 ,fp);
				fclose(fp);
			}
			printf("\t�ѳɹ��޸������û��������μǣ�");
			printf("\t�밴�س����˳�\n");
			getchar();
			break;
		}
		else
			printf("\t������������û�����һ�£����������룡\n");
	}
}
void exitsystem()//����6���˳�ϵͳ
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
	printf("�밴Enter���˳�\n");
	getchar();
}
