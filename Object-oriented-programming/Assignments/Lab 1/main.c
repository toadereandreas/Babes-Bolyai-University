#include <stdio.h>

void ui_problem_a()
{
    printf("Enter sequences of numbers that end with 0, then the maximum of the sequence will be displayed. \nAfter you input the last sequence enter -1.\n>> ");
    int w = 0, locmax = 0, glomax = 0 ;
    while( w != -1 ){
        scanf_s("%d", &w);
        if (w > locmax)
            locmax = w;
        if (w == 0) {
            printf("The local maximum of the last sequence is %d.\n", locmax);
            if (locmax > glomax)
                glomax = locmax;
            locmax = 0;
        }
    }
    printf("The global maximum is %d.\n",glomax);
    printf("The problem a has been solved.\n");
}

void read_vector( int A[], int *l)
{/* This function reads a vector from the keyboard.
 *  Input : l - an integer which represents the lenght of the vector
 *          A - the array of integers
 *  Output: l - an integer which represents the lenght of the vector
 *          A - the array of integers
 */
    scanf_s("%d",l);
    for( int i = 0 ; i < l ; ++i ){
        scanf_s("%d",&A[i]);
    }
    printf_s("%d",l);
}

void ui_problem_b()
{
    printf("Enter a, b, n ( the number of elements ) and then the elements to recieve the longest sequence between a and b.\n>>");
    int A[1000], n, a, b;
    scanf_s("%d",&a);
    scanf_s("%d",&b);
    scanf_s("%d",&n);
    for( int i = 0 ; i < n ; ++i ){
        scanf_s("%d",&A[i]);
    }
    //read_vector(A,&n);
    int l = 0, lmax = 0, istart = 0, imax = 0, jmax = -1 ;
    for( int i = 0 ; i < n ; ++i )
    {
        if( A[i] > a && A[i] < b )
        {
            l += 1;
            if( l > lmax ) {
                lmax = l;
                imax = istart;
                jmax = i;
            }
        }
        else{
            l = 0;
            istart = i + 1 ;
        }
    }
    printf("The sequence starts at %d and ends at %d :\n",imax,jmax);
    for( int i = imax ; i <= jmax ; ++i )
        printf("%d ",A[i]);
    printf("\nThe problem b has been solved.\n");
}

int is_prime(int n)
{
    /* This function checks whether a integer is a prime number or not.
     * Input  : n - an integer
     * Output : 1, if n is prime
     *          0, if n is not prime
     */
    if( n < 2 ) return 0;
    if( n % 2 == 0 && n != 2 ) return 0;
    for( int i = 3 ; i < n ; i += 2 )
        if( n % i == 0 )
            return 0 ;
    return 1;
}

void ui_problem_c()
{
    int m, number = -1 ;
    printf("Enter an natural number n to print the first n prime numbers >>");
    scanf_s("%d",&m);
    for( int i = 0 ; i < m ; ++i ) {
        while (is_prime(number) == 0){
            number += 1;}
        printf("%d ", number);
        number += 1;
    }
    printf("The problem c has been solved.\n");
}

int main()
{
    char problem = 'x';
    while(1) {
        printf("Problem a : Enter sequences of numbers that end with 0, then the maximum of the sequence will be displayed. After you input the last sequence enter -1.\n") ;
        printf("Problem b : Enter a, b, n and then the n elements of an array. Then you recieve the longest sequence of numbers between a and b.\n");
        printf("Problem c : Enter an natural number n to print the first n prime numbers.\n");
        printf("Enter problem: a or b or c. To quit enter q.\n >> ");
        scanf_s("%c", &problem);
        if (problem == 'a') // problem 7.a from Assignment 2
            ui_problem_a();
        else if (problem == 'b') // problem 7.b from Assignment 2
            ui_problem_b();
        else if (problem == 'c') // problem 2 from Lab2_Activity
            ui_problem_c();
        else if (problem == 'q')
            return 0;
        else
            printf("Wrong input. Try again !");
    }
}