#include<stdio.h>
#include<stdlib.h>

#define node_range 51 
#define edge_range 201  

int edge[edge_range][3];  
int dis[node_range]={0},dis_save[node_range]={0},node_p[node_range]={0};

int node_num=0,edge_num=0,source=0; 
void dijkstra(); 

int main()
{
	for(int i=0;i<node_range;i++)
	{
		dis[i]=10000;//每點由source到達Vi的距離，初值皆為無限大
		dis_save[i]=-1;//未確定s到i的最短路徑距離，初值為-1
	}  

	scanf("%d%d",&node_num,&edge_num);//輸入點的個數、邊的個數

	for(int i=1;i<=edge_num;i++)
		scanf("%d%d%d",&edge[i][0],&edge[i][1],&edge[i][2]);//輸入第k個有向邊及其權重(ik,jk,wk)

	scanf("%d",&source);//輸入source vertex number  

	dijkstra();

	printf("\n");
	for(int i=1;i<=node_num;i++)
		printf("%d ",dis_save[i]);
	printf("\n");  
                                                                                                                                                                                                                                               
	for(int i=1;i<=node_num;i++)
		printf("%d ",node_p[i]);
	printf("\n"); 

	system("pause");
	return 0;
}

void dijkstra()//主程式呼叫的dijkstra副程式
{
	dis[source]=0;//source vertex自己到自己的距離為0
	node_p[source]=0;//父點之號碼為0

	int c_loop=0;  
	while(c_loop!=node_num)  
	{
		int min=1; 
		for(int i=1;i<=node_num;i++)//vertex的index為1~n,所以先讓min=1開始找source是哪點
		{
			if(dis[i]<dis[min])//dis[i]除了source是0，其他都是無限大
				min = i;
		}

		dis_save[min]=dis[min];//source的距離已確定可以存至dist_save[min]

		for(int i=1;i<=edge_num;i++)
		{
			if(edge[i][0]==min)  
			{
				if(dis_save[edge[i][1]]==-1) 
				{
				    if(dis[edge[i][1]]>dis[edge[i][0]]+edge[i][2]) 
					{
					    dis[edge[i][1]] = dis[edge[i][0]]+edge[i][2];  
						node_p[edge[i][1]]=min;  
					}
				}
			}
		}

		dis[min]=10000;//要將已確定的dis[min]設為無限大，避免run2時一起比
		c_loop++; 
	}
}
