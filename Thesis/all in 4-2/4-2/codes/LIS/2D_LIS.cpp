#include <bits/stdc++.h>

#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<30
#define infinity 1<<30
#define mp make_pair
#define pi acos(-1)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define fs first
#define sc second
#define cffi ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define make_flush  cout << flush; //    fflush(stdout);
#define pob pop_back
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define eps 1E-7
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define sz(a) (int)a.size()
#define ll long long
#define ull unsigned long long
#define dd double
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define repa(i,n) for(auto i: n)
#define fop freopen("input_for_LIS.txt","r",stdin);freopen("Lis_result.txt","w",stdout);
using namespace std;

template<class T1> void deb(T1 e)
{
    cout<<e<<endl;
}
template<class T1,class T2> void deb(T1 e1,T2 e2)
{
    cout<<e1<<" "<<e2<<endl;
}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3)
{
    cout<<e1<<" "<<e2<<" "<<e3<<endl;
}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;
}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;
}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;
}




#define mt
#define mod

pii sequence[1010], I[1010];
int L[1010];

int lislength;

void lis(int n)
{
    int i, low, high, mid;
    lislength = 0;
    for(i = 0; i < n; i++)
    {
        low = 0, high = lislength;
        while(low <= high)
        {
            mid = low + high >> 1;
            if(I[mid].fs < sequence[i].fs && I[mid].sc < sequence[i].sc)
                low = mid + 1;
            else
                high = mid - 1;
        }
        I[low] = sequence[i];
        L[i] = low;
        if(lislength < low)
            lislength = low;
    }
}

void printseq(int n)
{
    int pos, i, j, val = lislength;
    pii arr[lislength];
    pos=-1;
    for(i = n-1; i >= 0; i--)
    {
        if(L[i] == val && pos == -1)
        {
            arr[val - 1] = sequence[i];
            val--;
            pos = i;
        }
        else if(L[i]==val && sequence[pos].fs > sequence[i].fs&& sequence[pos].sc > sequence[i].sc)
        {
            arr[val - 1] = sequence[i];
            val--;
            pos = i;
        }
    }
    deb(lislength);
    rep(i,lislength)
    deb(arr[i].fs,arr[i].sc);
}

int main ()
{
    cffi;
    fop;
    int i,j,test,n,t=1;
    while(cin>>n)
    {
        rep(i,n)
        cin>>sequence[i].fs>>sequence[i].sc;
        I[0] = {-infinity,-infinity};
        for(i = 1; i <= n; i++)I[i] = {infinity,infinity};
        lis(n);
        printseq(n);
    }

    return 0;
}









