//
//


//lower_bound
//×ó±ÕÓÒ±Õ:0,n
int lower_bound(int A[],int left,int right,int x)
{
    int mid;
    while(left<right)
    {
        mid=(left+right)/2;
        if(A[mid]>=x)
        {
            right=mid;
        }
        else
        {
            left=mid+1;
        }
    }
    return left;
}

//upper_bound
//×ó±ÕÓÒ±Õ:0,n
int upper_bound(int A[],int left,int right,int x)
{
    int mid;
    while(left<right)
    {
        mid=(left+right)/2;
        if(A[mid]>x)
        {
            right=mid;
        }
        else
        {
            left=mid+1;
        }
    }
    return left;
}

//ÎÊÌâÄ£°å
//×ó±ÕÓÒ±Õ
int solve(int left,int right)
{
    int mid;
    while(left<right)
    {
        mid=(left+right)/2;
        if(Ìõ¼ş³ÉÁ¢)
        {
            right=mid;
        }
        else
        {
            left=mid+1;
        }
    }
    return left;
}
