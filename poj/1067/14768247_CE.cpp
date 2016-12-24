#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

int main()
{
    double d=((sqrt(5.0)+1)/2.0);
    ll a,b;
    while(cin>>a>>b)
    {
        if((ll)(abs(a-b)*d)==min(a,b))
            cout<<0<<endl;
        else
            cout<<1<<endl;
    }
//    cout << "Hello world!" << endl;
    return 0;
}
