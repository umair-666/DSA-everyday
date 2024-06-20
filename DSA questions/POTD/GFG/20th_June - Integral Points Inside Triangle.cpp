// Integral Points Inside Triangle
// https://www.geeksforgeeks.org/problems/integral-points-in-triangle5026/1

class Solution
{
     //Find the GCD(a,b).
    long gcd(long a,long b)
    {
        if(b==0)
        {
            return a;
        }
        return gcd(b,a%b);
    }
  public:
    long long int InternalCount(long long int p[], long long int q[],
                                long long int r[]) {
         long x1=p[0];
        long x2=q[0];
        long x3=r[0];
        long y1=p[1];
        long y2=q[1];
        long y3=r[1];
        
        //Calculate the Area.
        long area=abs((x1*(y2-y3))+(x2*(y3-y1))+(x3*(y1-y2)));
        
        long B1=gcd(abs((x1)-(x2)),abs((y1)-(y2)));
        long B2=gcd(abs((x2)-(x3)),abs((y2)-(y3)));
        long B3=gcd(abs((x3)-(x1)),abs((y3)-(y1)));
        
        //Calculate the Boundary Points.
        long B=B1+B2+B3;
        
        
        //Substitute the values.
        long internalPoints=((area)-B+2)/2;

        return internalPoints;
    }
};
