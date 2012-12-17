/***
This program generates the sequences used for branch prediction
***/
#include <stdio.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

int main (void)
{
const gsl_rng_type * T;
gsl_rng * r;
int i;
int n = 100;
double mu = 3.0;	

gsl_rng_env_setup();

T = gsl_rng_default;
r = gsl_rng_alloc (T);

for (i = 0; i < n; i++)
{
	unsigned int k = gsl_ran_poisson(r,mu);
	printf(" %u",k);
	

}
printf("\n");

gsl_rng_free(r);
return 0;
}
