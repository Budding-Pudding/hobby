#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int i,j;
	int pips,me;
	int seed;
	int numofstu = 100;
	int numofgroup = 16;
	int array[200]={0};
	int *group;
	group = (int *)calloc(numofgroup,sizeof(int));
	printf("input the seed number\n");
	scanf("%d", &seed);
	srand(seed);
	for(i=0; i<numofstu; i++)
	{
		pips=rand()%6+1;
		for(me=0; me<6; me++)
		{
			if(pips==me+1)
			{
				array[i]=pips;
			}
		}
	}
	
	for(i=0; i<numofstu; i++)
	{	
		j=rand()%6+1;
		group[j]=group[j]+1;
	}
	
	FILE *fp;
	
	char name[] = "numofgroup.txt";
	
	fp = fopen(name,"w");
	
	for(i=0; i<numofgroup; i++)
	{
		fprintf(fp,"group%d=%d\n",i+1,group[i]);
	}
	free(group);
	fclose(fp);
	return 0;
}
