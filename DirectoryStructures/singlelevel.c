#include <string.h>
#include<stdio.h>
#include <stdlib.h>
struct
{
char dname[10],fname[10][10];
int fcnt;
}dir;
void main()
{
int i,ch;
char file[30];

dir.fcnt = 0;
printf("\nEnter name of directory -- ");
scanf("%s", dir.dname);
while(1)
{
printf("\n\n 1. Create File\t2. Delete File\t3. Search File \n 4. Display Files\t5. Exit\nEnter your choice -- ");
scanf("%d",&ch);
getchar();
switch(ch)
{
case 1: printf("\n Enter the name of the file -- ");
scanf("%s",file);
for(i=0;i<dir.fcnt;i++)
{
if(strcmp(file, dir.fname[i])==0)
{
printf("File with same name exsists");
goto jmp;
}}
strcpy(dir.fname[dir.fcnt],file);


dir.fcnt++;
jmp:break;
case 2: printf("\n Enter the name of the file -- ");
scanf("%s",file);
for(i=0;i<dir.fcnt;i++)
{
if(strcmp(file, dir.fname[i])==0)
{
printf("File %s is deleted ",file);
strcpy(dir.fname[i],dir.fname[dir.fcnt-1]);
break;
}
}
if(i==dir.fcnt)
printf("File %s not found",file);
else
dir.fcnt--;
break;
case 3: printf("\n Enter the name of the file -- ");
scanf("%s",file);
for(i=0;i<dir.fcnt;i++)
{
if(strcmp(file, dir.fname[i])==0)
{
printf("File %s is found ", file);
break;
}
}
if(i==dir.fcnt)
printf("File %s not found",file);
break;
case 4: if(dir.fcnt==0)
printf("\n Directory Empty");
else
{
printf("\n The Files are -- ");
for(i=0;i<dir.fcnt;i++)
printf("\t%s",dir.fname[i]);
}
break;
default: exit(0);
}
}
getchar();
}