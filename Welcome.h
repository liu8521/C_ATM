void wel()//欢迎界面；
{
	FILE *fp;
	if((fp=fopen("data/welcome.txt","r"))!=NULL)
	{
		char ch[10000];
		while(!feof(fp))
		{
			fgets(ch,100,fp);
			printf(ch);
			Sleep(200);
		}
		printf("\n\n");
		fclose(fp);
	}
}
void menu()//主菜单；
{
	
	FILE *fp;
	if((fp=fopen("data/menu.txt","r"))!=NULL)
	{
		char ch[100];
		while(!feof(fp))
		{
			fgets(ch,100,fp);
			printf(ch);
		}
		fclose(fp);
	}
}