#include <stdio.h>

int main()
{
	int foo = 9;
	int *ptr = &foo;
	float foo2 = 5.7;
	*ptr = 2;
    printf ("At beginning foo1 is %d\n", foo);
    printf ("At beginning foo2 is %f\n", foo2);
	foo2 = foo - foo2;

    printf ("After subtraction foo1 is %d\n", foo);
    printf ("After subtraction ptr is %d\n", ptr);
    // printf ("After subtraction *ptr is %f\n", *ptr);
    printf ("After Subtraction foo2 is %f\n", foo2);


	if (foo > foo2){
        printf("Hello!\n");
    }
    else if (foo < foo2){
        printf("%f\n", foo2);
    }
    else{
       printf("%d\n", foo);
    }

    printf("\n");
     printf ("foo1 is %d\n", foo);
    printf ("foo2 is %f\n", foo2);
}