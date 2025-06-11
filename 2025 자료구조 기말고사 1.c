#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp1, *fp2;

	fp1 = fopen(argv[1], "r");
	fp2= fopen(argv[3], "w");
	if(fp1==NULL)
	{
		printf("fail to open 1.\n");
		return 1;
	}
	if(fp2==NULL)
	{
		printf("fail to open 2.\n");
		return 1;
	}

	char tmp[2];

	while((fread(tmp,sizeof(char), 1, fp1))>0)
	{
		if(strcmp(tmp,argv[2])!=0)
		{
			fwrite(tmp,sizeof(char), 1, fp2);
		}
	}

	return 0;
}
