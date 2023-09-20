#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
int f[50], p,i, st, len, j, c, k, a;
char filename[50];

for(i=0;i<50;i++)
f[i]=0;
printf("Enter how many blocks already allocated: ");
scanf("%d",&p);
printf("Enter blocks already allocated: ");
for(i=0;i<p;i++)
{
scanf("%d",&a);
f[a]=1;
}
x: printf("Enter name , index of starting block and length: ");
scanf("%s",filename);
getchar();
scanf("%d%d", &st,&len);
k=len;
int arr[len],ind=0;
if(f[st]==0)
{
for(j=st;j<(st+k);j++)
{
if(f[j]==0)
{
f[j]=1;
arr[ind++]=j;

}
else
{
//printf("%d Block is already allocated \n",j);
k++;
}
}
printf("The blocks alloted to '%s' file are",filename);
for(int l=0;l<ind;l++){
    printf("%d\t",arr[l]);
}
}
else
printf("%d starting block is already allocated \n",st);
printf("Do you want to enter more file(Yes - 1/No - 0)");
scanf("%d", &c);
if(c==1)
goto x;
else
exit(0);
getchar();
}