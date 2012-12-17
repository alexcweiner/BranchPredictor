/***
This program generates the sequences used for branch prediction.
USAGE: "distributions -poisson 10" generates ten samples of a poisson distribution.
The mean(standard deviation for gaussian) is hardcoded...as of now.
***/
#include <stdio.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

int main(int argc, char *argv[])
{

const gsl_rng_type * T;
gsl_rng * r;
int i;
int n = atoi(argv[2]);
double mu = 3.0;	

gsl_rng_env_setup();

T = gsl_rng_default;
r = gsl_rng_alloc (T);


	//select the poisson distribution
	if (strcmp(argv[1], "-poisson") == 0)  
        	{
		for (i = 0; i < n; i++)
			{
			unsigned int k = gsl_ran_poisson(r,mu);
			printf(" %u",k);
			}	
		}
	//select the exponential distribution
	if (strcmp(argv[1], "-exponential") == 0) 
        	{
		for (i = 0; i < n; i++)
			{
			unsigned int k = gsl_ran_exponential(r,mu);
			printf(" %u",k);
			}
		}
	//select the gaussian distribution
	if (strcmp(argv[1], "-gaussian") == 0)  
        	{
		for (i = 0; i < n; i++)
			{
			unsigned int k = gsl_ran_gaussian(r,mu);
			printf(" %u",k);
			}
		}


	
printf("\n");

gsl_rng_free(r);
return 0;
}
