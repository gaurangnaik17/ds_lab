#include<iostream>
using namespace std;

int b_search(int p[], int l, int r, int t)
{
    int mid;

    while(l <= r)
    {
        mid = l + (r-l)/2;

        if(t == p[mid])
            return(mid);

        if(t < p[mid])
            r = mid-1;
        else
            l = mid+1;
    }

    return(-1);
}

int main()
{
    int x[20], n, key, i;

    cout<<"Enter number of elements: ";
    cin>>n;

    cout<<"Enter elements in sorted order: ";
    for(i=0; i<n; i++)
        cin>>x[i];

    cout<<"Enter element to search: ";
    cin>>key;

    int pos = b_search(x, 0, n-1, key);

    if(pos != -1)
        cout<<"Element found at position: "<<pos+1<<endl;
    else
        cout<<"Element not found"<<endl;

    return 0;
}