?*
계속 데이터가 큰 경우 틀리길래 확인해보니 자료형 범위 초과 였다. 
해결해서 기쁘다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, funcN;
int c;
int term;

class Poly
{
public:
    vector<pair<long long, long long>> v;

    void add(long long n, long long t)
    {
        bool NoTerm = false;
        for (int i = 0; i < v.size(); i++)
        {
            if (t == v[i].first)
            {
                v[i].second += n;
                if (v[i].second == 0)
                    v.erase(v.begin() + i);
                NoTerm = true;
            }
        }
        if (!NoTerm)
            v.push_back(make_pair(t, n));
        // for(int i = 0; i < v.size(); i++){
        //     cout<<v[i].second<<" "<<v[i].first<<"\n";
        // }
        sort(v.begin(), v.end());
    }

    void mult(Poly p)
    {
        Poly tempP;
        for (int i = 0; i < p.v.size(); i++)
        {
            for (int j = 0; j < v.size(); j++)
            {
                if (v[j].second * p.v[i].second != 0)
                {
                    tempP.add(v[j].second * p.v[i].second, v[j].first + p.v[i].first);
                } //0이면 그냥 넘어감
            }
        }
        v.clear();
        v = tempP.v;
        
    }

    void show()
    {
        if (v.size() == 0)
        {
            cout << "1\n0 0";
        }
        else
        {
            cout << v.size() << "\n";
        }
        for (int i = v.size() - 1; i >= 0; i--)
        {
            if (v[i].second == 0)
                continue;
            cout << v[i].second << " " << v[i].first << "\n";
        }
    }
};

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N;
    int termN;
    cin >> N;
    cin >> termN;
    N--;
    Poly poly;

    int n, t;
    while (termN--)
    {
        cin >> n >> t;
        poly.add(n, t);
    }

    while (N--)
    {
        cin >> termN;
        Poly tempPoly;
        while (termN--)
        {
            cin >> n >> t;
            tempPoly.add(n, t);
        }
        poly.mult(tempPoly);
    }
    
    poly.show();
}

