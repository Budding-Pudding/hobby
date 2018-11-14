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
	int numofstu;
/////////////////////////////////////////////////////
	//to hold the number of groups
	int numofgroup;
/////////////////////////////////////////////////////
	printf("input the number of students\n");
	scanf("%d", &numofstu);
	printf("input the number of groups\n");
	scanf("%d", &numofgroup);
	printf("input the seed number\n");
	scanf("%d", &seed);
/////////////////////////////////////////////////////
	//to remember the pips&students
	int *array;
	array = (int *)calloc(numofstu,sizeof(int));
/////////////////////////////////////////////////////
	//to make ensur of memories(maybe don't need)
	int *group;
	group = (int *)calloc(numofgroup,sizeof(int));
/////////////////////////////////////////////////////
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
	free(array);
	fclose(fp);
	return 0;
}
 
