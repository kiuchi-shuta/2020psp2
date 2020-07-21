#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct{
     int id;
     int gender;
     double height;
     
} studentdata;

int main(void)
{
    studentdata data[14];
    char fname[FILENAME_MAX];
    FILE* fp;
    char buf[256];
    int i = -1;
    int idset;

    printf("Input the filename of sample height:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n", fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n", stderr);
        exit(EXIT_FAILURE);
    }

      while(fgets(buf,sizeof(buf),fp) != NULL){
        if(i == -1){
            i++;
            continue;
        }
        sscanf(buf,"%d,%lf", &data[i].gender, &data[i].height);
        i++;
    }

    if(fclose(fp) == EOF){
        fputs("file close error\n", stderr);
        exit(EXIT_FAILURE);
    }

    printf("Input the filename of sample ID:");
    fgets(fname,sizeof(fname), stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n", fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("file open error\n", stderr);
        exit(EXIT_FAILURE);
    }

    i=0;
    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%d",&data[i].id);
        i++;
    }
    if(fclose(fp) == EOF){
        fputs("file close error\n", stderr);
       exit(EXIT_FAILURE);
    }
 printf("Which ID's data do you want? :");
    scanf("%d",&idset);

     
    for(i = 0; i < 14 ; i++)
    {
        if(data[i].id == idset)
        {
            printf("ID : %d\n",data[i].id);
            if(data[i].gender == 1)
            {
                printf("gender : male\n");
            }
            else
            {
                printf("gender : female\n");
            }
            printf("height : %.1lf\n",data[i].height);
            return 0;
        }
    }
   
     printf("No data\n");
     return 0;
}