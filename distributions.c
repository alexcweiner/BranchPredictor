/***
This program generates the sequences used for branch prediction
TODO: Add command line option to set the number of samples
***/
#include <stdio.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

int main(int argc, char *argv[])
{
int selector;
const gsl_rng_type * T;
gsl_rng * r;
int i;
int n = 100;
double mu = 3.0;	

gsl_rng_env_setup();

T = gsl_rng_default;
r = gsl_rng_alloc (T);

for (selector = 1; selector < argc; selector++)  /* Skip argv[0] (program name). */
	{

	//select the poisson distribution
	if (strcmp(argv[selector], "-poisson") == 0)  
        	{
	
		for (i = 0; i < n; i++)
			{
			unsigned int k = gsl_ran_poisson(r,mu);
			printf(" %u",k);
			}	
		}

	if (strcmp(argv[selector], "-uniform") == 0) 
        	{
		//TODO: add the uniform distribution
		}
	
	if (strcmp(argv[selector], "-other") == 0)  
        	{
		//TODO: add the third distribution
		}
	}	
printf("\n");

gsl_rng_free(r);
return 0;
}
