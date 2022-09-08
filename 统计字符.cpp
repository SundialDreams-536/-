#include<stdio.h>
#include<string.h>
int main()
{
	char s[1000],w[100];
	int i,j,slen,wlen,cnt=0;
	printf("本程序可以根据你输入的单词查询在句子中有几个这样的单词。\n");
	printf("请输入一句英文句子:\n");
	gets(s);
	printf("请输入你要查询的单词:\n");
	gets(w);
	strlwr(s);
	strlwr(w);
	slen=strlen(s);
	wlen=strlen(w);
	for(i=0;i<=slen-wlen;i++)
	{
		char tempw[1000];
		tempw[wlen]='\0';
		for(j=0;j<wlen;j++)
			tempw[j]=s[i+j];
		if(strcmp(tempw,w)==0)
			cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}
