#include <iostream>
#include <cmath>

using namespace std;

typedef double ll;

int main()
{
    double d=((sqrt(5.0)+1)/2.0);
    ll a,b;
    while(cin>>a>>b)
    {
        if((long long)(abs(a-b)*d)==min((long long)a,(long long)b))
            cout<<0<<endl;
        else
            cout<<1<<endl;
    }
//    cout << "Hello world!" << endl;
    return 0;
}
