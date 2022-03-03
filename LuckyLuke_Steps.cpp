#include <iostream>
using namespace std;

const long base = 14062008;
long n, k, t, f[150000];
bool go[150000] = { true };

int main()
{
    freopen("input.txt", "r", stdin);
    scanf("%li %li", &n, &k);
    for (long i = 0; i <= n; i++) 
    {
        go[i] = true;
    }
    for (long i = 1; i <= k; i++)
    {
        scanf("%li", &t);
        go[t] = false;
    }

    f[0] = 0; 
    f[1] = 1; 

    if (go[2]) {
        f[2] = 1;
    }
    else {
        f[2] = 0;
    }

    for (long i = 3; i <= n; i++)
    {
        /*if (!(go[i]))
        {
            f[i] = 0;
        }
        else if ((!(go[i - 1])) && (go[i - 2]))
        {
            f[i] = f[i - 2] % base;
        }
        else if ((!(go[i - 2])) && (go[i - 1]))
        {
            f[i] = f[i - 1] % base;
        }
        else
        {
            f[i] = (f[i - 1] % base + f[i - 2] % base) % base;
        }*/
  
        if (!(go[i]))
        {
            f[i] = 0;
        }
        else {
            f[i] = (f[i - 1] % base + f[i - 2] % base) % base;
        }
    }
    printf("%li", f[n]);
    return 0;
}