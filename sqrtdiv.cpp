// Find divisors of a number O(sqrt(n))
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int sum = 0,count = 0;
    for(int i =1;i*i<=n;++i){
       if(n%i==0){

       cout<<i<<n/i<<endl;
        count+= 1;
        sum+= i;

       if(n/i!= i){
         count+= 1;
         sum+= n/i;
       }
      }
    }

    cout<<count<<sum<<endl;
}
