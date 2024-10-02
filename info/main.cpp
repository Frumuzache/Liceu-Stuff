#include <iostream>
#include <fstream> 

using namespace std;
ifstream f("date.in");
ofstream g("date.out");

int n , m , a[1001][9001] , s;

int main()
{
    cin >> n >> s;

    for(int i = 1 ; i <= 9 ; i++)
        a[1][i] = 1;

    for(int i = 1 ; i < n ; i++)
        for(int j = 1 ; j <= s ; j++)
            if(a[i][j])
                for(int k = 0 ; k <= 9 ; k++)
                {
                    a[i + 1][j + k] = a[i + 1][j + k] + a[i][j];
                    a[i + 1][j + k] = a[i + 1][j + k] % 666013;
                }

    cout << a[n][s];

    for (int i = 1; i <= n; i++, g << endl)
        for (int j = 1; j <= s; j++, g <<" ")
            g << a[i][j];
           
}