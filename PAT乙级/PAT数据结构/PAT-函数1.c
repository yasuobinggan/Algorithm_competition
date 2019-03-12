Position BinarySearch( List L, ElementType X )
{
	int start=1,end=L->Last;
	while(start<end)
	{
		int mid=(start+end)/2;	
		if(L->Data[mid]==X)
			return mid;
		else if(X>L->Data[mid])
		{
			start=mid+1;
		}
		else
		{
			end=mid;
		}	
	}
	return 0;
}