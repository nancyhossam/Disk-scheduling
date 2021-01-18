#include <stdio.h>
#include <stdlib.h>
 int DiskSize,requests,temp,head,direction;
    char type[10];
    int *arr;
    void arrange(int *a)
    {for (int i = 0; i < requests; i++)                     //Loop for ascending ordering
	{
		for (int j = 0; j < requests; j++)             //Loop for comparing other values
		{
			if (a[j] > a[i])                //Comparing other array elements
			{
				int tmp = a[i];         //Using temporary variable for storing last value
				a[i] = a[j];            //replacing value
				a[j] = tmp;             //storing last value
			}
		}
	}
    }
   void CSCAN(){
   printf("\nCSCAN\n");
    arrange(arr);
    int total=0;
    printf("%d",head);
      int i,j=requests-1,k;
    for(i=0;i<requests;i++)
    {
    if(arr[i]>=head)
    {
    j=i-1;
    break;
    }

    }
    if(i==requests)
    i=0;
    if(direction==1)
    {
    total+=abs(head-arr[i]);
    k=i;
    int t=requests;
    while(t>1)
    {printf("->");
    printf("%d",arr[k%(requests)]);
    total+=abs(arr[k%(requests)]-arr[(k+1)%(requests)]);

    k++;
    t--;
    }printf("->");
    printf("%d",arr[k%(requests)]);


    }else if(direction==0)
    { k=j;
    total+=abs(head-arr[(k+requests)%(requests)]);

    int t=requests;

    while(t>1)
    {printf("->");
    printf("%d",arr[(k+requests)%(requests)]);
    total+=abs(arr[(k+requests)%(requests)]-arr[(k-1+requests)%(requests)]);
    k--;
    t--;
    }printf("->");
    printf("%d",arr[(k+requests)%(requests)]);
    }printf("\n");
    printf("Total head movments: %d\n",total);
    printf("Average head movments: %f\n",total/(requests*1.0));

    }

    void SCAN()
    {arrange(arr);
    int total=0;
printf("SCAN\n");
    int i,j=-1;
    for(i=0;i<requests;i++)
    {
    if(arr[i]>head)
    {j=i-1;
    break;
    }
    }if(i==requests)
    i=0;
    int k;
    if(direction==1){
    total+=abs(head-arr[i]);
printf("%d",head);
    for( k=i;k<requests-1;k++)
    {printf("->");
    printf("%d",arr[k]);
    total+=abs(arr[k]-arr[k+1]);

    }
printf("->");
     printf("%d",arr[k]);

if(j>0){
total+=abs(arr[j]-arr[k]);
 for( k=j;k>0;k--)
    {printf("->");
    printf("%d",arr[k]);
    total+=abs(arr[k]-arr[k-1]);

    }
printf("->%d\n",arr[0]);}

    }
if(direction==0)

{printf("%d",head);

if(j>=0){

total+=abs(head-arr[j]);
 for( k=j;k>0;k--)
    {printf("->");
    printf("%d",arr[k]);
    total+=abs(arr[k]-arr[k-1]);

    }
printf("->%d",arr[0]);
 total+=abs(arr[0]-arr[i]);
 for( k=i;k<requests-1;k++)
    {printf("->");
    printf("%d",arr[k]);
    total+=abs(arr[k]-arr[k+1]);

    }
printf("->");
printf("%d",arr[k]);
    }
else{
i=requests-1;
total+=abs(head-arr[i]);
for( k=i;k>0;k--)
    {printf("->");
    printf("%d",arr[k]);
    total+=abs(arr[k]-arr[k-1]);

    }
printf("->");
printf("%d",arr[k]);


}




}printf("\n");
    printf("Total head movments: %d\n",total);
    printf("Average head movments: %f\n",total/(requests*1.0));
    }
    void FIFO()
    {printf("\nFIFO:\n");
    int total=0;
    total+=abs(head-arr[0]);
    printf("%d->",head);
int i=0;
    for(i=0;i<requests-1;i++)
    {
    printf("%d->",arr[i]);
    total+=abs(arr[i]-arr[i+1]);
    }
    printf("%d\n",arr[i]);
    printf("Total head movments: %d\n",total);
    printf("Average head movments: %f\n",total/(requests*1.0));
    }
int main()
{
    printf("Enter Disk size:\n");
    scanf("%d",&DiskSize);
    printf("Enter number of requests:\n");
    scanf("%d",&requests);
    arr=malloc(sizeof(int)*requests);
    printf("Enter the request:\n");
    for(int i=0;i<requests;i++)
    {scanf("%d",&temp);
    if(temp>DiskSize)
  {  printf("requests should be less than Disk Size.");
  i--;
 return 0;
  }
    arr[i]=temp;
    }while(1){
        printf("Enter the head position:\n");
    scanf("%d",&head);
    if(head<=DiskSize)
    break;
    }



    printf("Enterthe head Direction:\n");
    scanf("%d",&direction);

    printf("\n");

    FIFO();
     printf("\n");
    SCAN();
    printf("\n");

    CSCAN();


    return 0;
}
