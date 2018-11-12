#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

int main(void)
{
	int i,j;
	int pips,me;
	int seed;
	int d[6]={0};
	int numofstu = 100;
	int numofgroup = 16;
	int array[200]={0};
	int dice[6]={1,2,3,4,5,6};
	int group[numofgroup];
	int *SN;
	SN = (int *)calloc(numofgroup,sizeof(int));
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
		for(j=0; j<6; j++)
		{
			if(array[i]==dice[j])
			{
				d[j]=d[j]+1;
			}
		}
	}
	
	for(i=0; i<numofgroup; i++)
	{
		d[i]=SN[i];
		printf("group%d=%d\n",i+1,SN[i]);
	}
}