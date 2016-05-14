# include <stdio.h>
# include <math.h>

int main()
{
	double i,j,k,flag=3;
	for(i=1;flag>0;i+=1)
	{
		k=i*(2*i-1);
		if(1+24*k==pow(floor(sqrt(1+24*k)),2) && (1+floor(sqrt(1+24*k)))/6==floor((1+floor(sqrt(1+24*k)))/6) && 2*k==floor(sqrt(2*k))*(floor(sqrt(2*k))+1))
		{
			printf("%f %f %f %f\n",floor(sqrt(2*k)),(1+floor(sqrt(1+24*k)))/6,i,k);
			flag--;
		}
	}
	return 0;
}
