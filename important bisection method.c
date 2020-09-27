#include<stdio.h>
#include<math.h>

double F( double x)
{
    return (pow(x,3) - 2*x -5);
}

int main()
{
    double y1,y2;
    double x0,x1;
    int n=0;

    printf("Enter the first approximation to the root :  ");
    scanf("%lf",&x0);

    printf("Enter the second approximation to the root :   ");
    scanf("%lf",&x1);
    y1=x0;
    y2=x1;

    int iter;
    printf("Enter the number of iteration you want to perform :   ");
    scanf("%d",&iter);

    int ctr=1;
    double l1=x0;
    double l2=x1;
    double r,f1,f2,f3;

    //We check if the initial approximations are the root or not
    if(F(l1)==0)// it is a root
        r=l1;
    else if(F(l2)==0)
        r=l2;
    else //If the above two values are not the roots of the given function
    {
        printf("n ______ a(-) _________ b(+) ______________________ x=(a+b)/2 _________________________ f(x) ___\n");
        while(ctr<=iter) //Since, ctr is initialized to 1
        {
            //This is an implementation of the algorithm mentioned above
            f1=F(l1);
            r=(l1+l2)/2.0; //Returns a double value
            f2=F(r);
            f3=F(l2);

            if(f2==0)
            {
                r=f2;
                break; //Execution moves out of the while loop to the statement just after it
            }


            n++;
            printf("%02d. here a=%.5f and b=%.5f root afr %02d itrn is %lf   and the function is %.10f \n",n,y1,y2,ctr,r,F(r));
            if(F(r)<0)
            {
                y1=r;
            }
            else
            {
                y2=r;
            }


            if(f1*f2<0)//Both are of opposite sign
                l2=r;
            else if(f2*f3<0)
                l1=r;
            ctr++;
        }
    }

    printf("\n\n\nThe approximation to the root is %.5lf\n",r); //Gives the final value after mentioned iteration
    return 0;
}
