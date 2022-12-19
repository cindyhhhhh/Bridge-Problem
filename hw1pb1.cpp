#include<math.h>
#include <stdio.h>
#include<stdlib.h>
#include <algorithm>
#include <stdint.h>
#include <iostream> 
#include <inttypes.h>
#include<string.h>

using namespace std; 

struct city
{
    long long x;
    long long y;
};

long long Distance(city A, city B)
{
    long long d = sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
    return d;
}
long long Maxrevenue(city A, city B)
{
    long long D = (A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y);
    return D;
}

bool sorty(city A, city B)
{
    return A.y<B.y;
}

bool sortx(city A, city B)
{
    return A.x<B.x;
}
long long ClosestPoint(city input[],long long first, long long last,city output[])
{
    long long d1,d2,d3,d,dl,dr,dm;
    city P[last-first+1], Left[2], Right[2];
    if(last-first == 1)
    {
        output[0].x = input[first].x;
        output[0].y = input[first].y;
        output[1].x = input[last].x;
        output[1].y = input[last].y;
        return Distance(input[first], input[last]); 
    }
    if(last-first == 2)
    {
        d1=Distance(input[first], input[first+1]);
        d2=Distance(input[first+1], input[last]);
        d3=Distance(input[first], input[last]);
        if((d1<=d2)&&(d1<=d3))
        {
            output[0].x = input[first].x;
            output[0].y = input[first].y;
            output[1].x = input[first+1].x;
            output[1].y = input[first+1].y;
            return d1;
        } 
        else if ((d2<=d3)&&(d2<=d1))
        {
            output[0].x = input[first+1].x;
            output[0].y = input[first+1].y;
            output[1].x = input[last].x;
            output[1].y = input[last].y;
            return d2;
        }
        else
        {
            output[0].x = input[first].x;
            output[0].y = input[first].y;
            output[1].x = input[last].x;
            output[1].y = input[last].y;
            return d3;
        }
    }
    
    long long mid=(first+last)/2;
    dl=ClosestPoint(input,first,mid,Left);

    dr=ClosestPoint(input,mid+1,last,Right);

    if(dl<=dr)
    {
        d=dl;
        output[0] = Left[0];
        output[1] = Left[1];
    }
    else if (dr<dl)
    {
        d=dr;
        output[0] = Right[0];
        output[1] = Right[1];
    }
    
    int index=0;
    for(int i=mid;(i>=first)&&(abs(input[mid].x-input[i].x)<d);i--)
    {
        P[index++] = input[i];
    }
    for(int i=mid+1;(i<=last)&&(abs(input[i].x-input[mid].x)<d);i++)
    {
        P[index++] = input[i];
    }

    for(int i=0; i<index; i++)
    {
        for(int j=i+1; j<index && j>i; j++)
        {
            dm = Distance(P[i],P[j]);
            if(dm<d)
            {
                output[0].x=P[i].x;
                output[0].y=P[i].y;
                output[1].x=P[j].x;
                output[1].y=P[j].y;    
                d=dm;
            }
            
        } 
    }
    return d;
}

int main()
{
    long long N;
    long long maxrevenue;
    cin >> N;
    city Input[N];
    for(int i=0; i<N; i++)
    {
        scanf("%lld %lld", &Input[i].x, &Input[i].y); 
     } 
    sort(Input, Input+N, sortx);

    city Output[2];
    long long d = ClosestPoint(Input, 0, N-1, Output);
    maxrevenue = -Maxrevenue(Output[0], Output[1]);

    printf("%lld\n",maxrevenue);
    return 0;
}

