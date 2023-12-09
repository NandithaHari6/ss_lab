#include <stdio.h>
#include <math.h>
void FCFS(int arr[],int head,int n)
{
	int seek_count = 0;
	int cur_track, distance;
	for(int i=0;i<n;i++)
	{
		cur_track = arr[i];
		distance = fabs(head - cur_track);
		seek_count += distance;
		head = cur_track;
	}
printf("Total number of seek operations: %d\n",seek_count);
	printf("Seek Sequence is\n");

	for (int i = 0; i < n; i++) {
		printf("%d\n",arr[i]);
	}
}
void main()
{int n,head;
	printf("Enter no of requests\n");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the request array");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Enter head position\n");
	scanf("%d",&head);
	FCFS(arr,head,n);
}

