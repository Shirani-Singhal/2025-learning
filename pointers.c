#include<stdio.h>
main()
{
	int a=10;
	int *p;
	p=&a;
	printf("\n value of p which is add of a=%d",p);
	printf("\n add of a=%u",&a);
	printf("\n add of p=%u",&p);
	printf("\n value of p at a=%d",*p);

}
