#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define _USE_MATH_DEFINES

extern double p_stdnorm(double z);

int main(void)
{
    double val;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    double L1=1,L2=1;
    double mu_A=170.8;
    double s_A=5.43;
    double mu_B=169.7;
    double s_B=5.5;
    double z1,z2,y1,y2=0;
    

    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);
        double x=val;
z1=(x-mu_A)/s_A;
y1=p_stdnorm(z1);
z2=(x-mu_B)/s_B;
y2=p_stdnorm(z2);
L1=L1*y1;
L2=L2*y2;


    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("L_A: %f\n",L1);
    printf("L_B: %f\n",L2);

    return 0;


}

double p_stdnorm(double z)
{
    return 1/sqrt(2*M_PI) * exp(-z*z/2);
}

