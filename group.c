#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
/////////////////////////////////////////////////////
	int i,j;
/////////////////////////////////////////////////////
	//for remember the number of pips
	int pips,me;
/////////////////////////////////////////////////////
	//for remember the seed
	int seed;
/////////////////////////////////////////////////////
	//to hold the number of students
	int numofstu = 100;
/////////////////////////////////////////////////////
	//to hold the number of groups
	int numofgroup = 16;
/////////////////////////////////////////////////////
	//to remember the pips&students
	int array[200]={0};
/////////////////////////////////////////////////////
	//to make ensur of memories(maybe don't need)
	int *group;
	group = (int *)calloc(numofgroup,sizeof(int));
/////////////////////////////////////////////////////
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
		j=rand()%numofgroup;
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
