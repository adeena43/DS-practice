#include<iostream>
using namespace std;

int returnSum(int n){

    if(n == 0)
    {
        return 0;
    }
    return (n%10 + returnSum(n/10));
}

int main()
{
    cout<<returnSum(789);
}
