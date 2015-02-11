#include"header.h"

int insertRec(emp *e,int num)
{
int i;
for(i=0;i<num;i++)
{
printf("Enter the emp id\n");
scanf("%d",&e[i].id);
printf("Enter the emp name\n");
scanf("%s",e[i].name);
printf("Enter the emp dept\n");
scanf("%s",e[i].dept);
printf("Enter the emp phone num\n");
scanf("%ld",&e[i].phno);
}
return SUCCESS;
}

int getRecByName(FILE *fp,char name[])
{
emp temp;
int status;
while(!feof(fp))
{
status =fread(&temp,sizeof(emp),1,fp);
printf("status=%d..\n",status);
if(1!=status)
{
printf("Record not exist..\n");
break;
}
if(strcmp(name,temp.name)==0)
{
printf("Details of employee are -\n");
printf("ID =%d\n Name=%s\n Dept=%s\n Ph No.-%ld\n",temp.id,temp.name,temp.dept,temp.phno); 
return SUCCESS;
}
}
return FAILURE;
}



int getRecById(FILE *fp,int id)
{
emp temp;
int status;
while(!feof(fp))
{
status =fread(&temp,sizeof(emp),1,fp);
printf("status=%d..\n",status);
if(1!=status)
{
printf("Record not exist..\n");
break;
}
if(id==temp.id)
{
printf("Details of employee are -\n");
printf("ID =%d\n Name=%s\n Dept=%s\n Ph No.-%ld\n",temp.id,temp.name,temp.dept,temp.phno); 
return SUCCESS;
}
}
return FAILURE;
}



int getRecByNum(FILE *fp,int rec_num)
{
emp temp;
int status;
status=fseek(fp,sizeof(emp) * (rec_num-1),SEEK_SET);
if(0==status)
{
printf("Seeking to record successfull..\n");
}
status =fread(&temp,sizeof(emp),1,fp);
printf("status=%d..\n",status);
if(1!=status)
{
printf("Record not exist..\n");
return FAILURE;
}
printf("Details of employee are -\n");
printf("ID =%d\n Name=%s\n Dept=%s\n Ph No.-%ld\n",temp.id,temp.name,temp.dept,temp.phno); 
return SUCCESS;

}






