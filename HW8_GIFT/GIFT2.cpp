#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, r, C;
int total = 0;
int arr[22];
int rtmp = 0;
vector<vector<int>> v;

void poly(int x, int sum, vector<int> ans, int cnt)
{

    for (int i = C / arr[x]; i >= 0; i--)
    {
        int num = arr[x] * i + sum;
        ans.push_back(i);
        if (num == C)
        {
            vector<int> tv;

           for (int k = 0; k < n - ans.size(); k++)
                tv.push_back(1);

            for (int j = ans.size() - 1; j >= 0; j--)
                tv.push_back(ans[j] + 1);

            v.push_back(tv);
            ans.pop_back();
        }
        else if (num > C)
        {
            ans.pop_back();
            continue;
        }
        else
        {
            if (x == 0)
                return;
            poly(x - 1, num, ans, cnt + 1);
            ans.pop_back();
        }
    }
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> r;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr[i] = temp; 
        total += temp;
    }
    cin >> C;
    C -= total; 
    vector<int> tempV;
    poly(n-1, 0, tempV, 0);
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        rtmp++;
        if (rtmp == r)
        {
            for (int j = 0; j < n; j++)
                cout << v[i][j] << " ";
            return 0;
        }
    }
    cout<<"NONE";
}