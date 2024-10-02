///Test 7
/*
#include <iostream>
#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");

int a[101][101], m, n, nrpozi, nrnegi, nrpozj, nrnegj;

void ordcresc (int l)
{
    for (int i = 1; i < n; i++)
        for (int j = i+1; j <= n; j++)
           if (a[l][i] > a[l][j])
           {
               int aux = a[l][i];
               a[l][i] = a[l][j];
               a[l][j] = aux;
           }
}

void numara (int L, int &nrpoz, int &nrneg)
{
    nrpoz = 0;
    nrneg = 0;
    for (int i = 1; i <= n; i++)
        if (a[L][i] >= 0)
           nrpoz++;
        else
            nrneg++;
}

int main()
{
    f >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
           f >> a[i][j];

    for (int i = 1; i < m; i++)
        for (int j = i+1; j <= m; j++)
        {
           numara(i, nrpozi, nrnegi);
           numara(j, nrpozj, nrnegj);
           if ((nrnegi + nrnegj) % 2 == 0)
           {
               g << i <<" " << j << endl;
               ordcresc(i);
               ordcresc(j);
           }

        }
    for (int i = 1; i <= m; i++, g << endl)
        for (int j = 1; j <= n; j++)
           g << a[i][j] << " ";

    return 0;
}
*/





///Test 8
/*
#include <iostream>
#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");

int n, maxi, cif;

void cmax (int a, int &b)
{
    b = 0;
    while (a != 0)
    {
        if (a%10 > b)
            b = a%10;
        a = a /10;
    }
}

int main ()
{
    while (f >> n)
    {
        cmax(n, cif);
        if (cif > maxi)
            maxi = cif;
    }
    g << maxi;
    return 0;
}
*/



///Test 9

///1
/*
#include <iostream>
#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");

int P (int n, int c)
{
    int a = 0, p = 1;
    while (n != 0)
    {
        if (n % 10 != c)
        {
            a = a + n % 10 * p;
            p = p *10;
        }
        n = n / 10;
    }
    return a;
}

int n, aux;

int main ()
{
    while (f >> n)
    {
       aux = n;
       for (int i = 1; i <= 9; i = i + 2)
            aux = P (aux, i);
       if (aux != 0)
        g << aux <<" ";
    }
    return 0;
}
*/





///2
/*
#include <iostream>
#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");

int p1 (int n)
{
    int sum = 0;
    while (n)
    {
        sum = sum + n % 10;
        n = n / 10;
    }
    return sum;
}

int p2 (int n)
{
    return n / 10;
}

int n, nr;

int main ()
{
    f >> n;
    while (n > 9)
    {
        if (p1(n) == p1(p2(n)))
            nr++;
        n = n /10;
    }
    g << nr;
}
*/



///3
/*
#include <iostream>
#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");

int cif (int a, int b)
{
    int nr = 0;
    while (a)
    {
        if (a % 10 == b)
            nr++;
        a = a /10;
    }
    return nr;
}

int n;

int main ()
{
    f >> n;

    for (int i = 1; i <= 9; i = i+ 2)
    {
        if (cif(n, i) != 0)
            for (int j = 1; j <= cif(n, i); j++)
            g <<i;
    }
}
*/




///Test 10

///2
/*
#include <iostream>
#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");

int sub (int v[101], int n, int a)
{
    int nr = 0;
    for (int i = 1; i <= n; i++)
        if (v[i] == a)
            nr++;
    return nr;
}

int v[101], n, ok = 1;
int main ()
{
    f >> n;
    for (int i = 1; i <= n; i++)
    {
        f >> v[i];
        if (sub(v, i, v[i]) != 1)
            ok = 0;
    }
    if (ok == 1)
        g << "Da";
    else
        g << "Nu";
    return 0;
}
*/





///3
/*
#include <iostream>
#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");

int divizor (int a, int b, int c)
{
    int mini = 9999999, nr = 0;

    if (a < mini)
        mini = a;
    if (b < mini)
        mini = b;
    if (c < mini)
        mini = c;

    for (int d = 1; d <= mini; d++)
        if (a % d == 0 && b % d == 0 && c % d == 0)
           nr++;

    return nr;
}

int a, b, c;
int main ()
{
    f >> a >> b >> c;
    g << divizor(a, b, c);
    return 0;
}
*/








///Testul 1

///1
/*
#include <iostream>
#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a, b, maxi, nr;

int main ()
{
    f >> a >> b;
    for (int i = a; i <= b; i++)
    {
        int aux = i;
        nr = 0;
        for (int d = 2; d <= aux; d++)
        {
            if (aux % d == 0)
            {
                nr++;
                while (aux % d == 0)
                   aux = aux / d;
            }
        }
        if (nr > maxi)
           maxi = nr;
    }


    for (int i = a; i <= b; i++)
    {
        int aux = i;
        nr = 0;
        for (int d = 2; d <= aux; d++)
        {
            if (aux % d == 0)
            {
                nr++;
                while (aux % d == 0)
                   aux = aux / d;
            }
        }
        if (nr == maxi)
           g << i << " ";
    }
}
*/






///2
/*
#include <iostream>
#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");

int a, b, x = 1, y = 1, nr;

int main ()
{
    f >> a >> b;
    while (y < a)
    {
        int aux = y;
        y = y + x;
        x = aux;
    }

    while (y < b)
    {
        nr++;
        int aux = y;
        y = y + x;
        x = aux;
    }

    g << nr << " ";
}
*/





///3
/*
#include <iostream>
#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");

int a,b;

int main ()
{
    f >> a >> b;

    for (int i = a; i < b; i++)
    {
        for (int j = i + 1; j <= b; j++)
        {
            int auxi = i;
            int auxj = j;
            while(auxj != 0)
            {
                int r = auxi % auxj;
                auxi = auxj;
                auxj = r;
            }
            if (auxi == 1)
                g << i << " " << j << endl;
        }
    }
    return 0;
}
*/




///Testul 2


///1
/*
#include <iostream>
#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");

int n, mini = 99999, maxi, x;

int main ()
{
    f >> n;
    for (int i = 1; i <= n; i++)
    {
        f >> x;
        if (x > maxi)
            maxi = x;

        if (x < mini)
            mini = x;
    }

    int auxi = maxi;
    int auxj = mini;

    while (auxj != 0)
    {
        int r = auxi % auxj;
        auxi = auxj;
        auxj = r;
    }


  g << mini / auxi << " / " << maxi / auxi;


    return 0;
}
*/





///2
/*
#include <iostream>
#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");

int n;

int main ()
{
    f >> n;
    while (n != 0)
    {
        int x = 1;
        int y = 1;

        while (y + x <= n)
        {
            int aux = y;
            y = y + x;
            x = aux;
        }

        n = n - y;
        g << y <<" ";
    }

    return 0;
}
*/




///3
/*
#include <iostream>
#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");

int a,b;

int main ()
{
    f >> a >> b;

    for (int i = a; i < b; i++)
    {
        for (int j = i + 1; j <= b; j++)
        {
            int auxi = i;
            int auxj = j;
            while(auxj != 0)
            {
                int r = auxi % auxj;
                auxi = auxj;
                auxj = r;
            }
            if (auxi == 1)
                g << i << " " << j << endl;
        }
    }
    return 0;
}
*/








/*
#include <iostream>
#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");

int v[1001], n, a;

int dei (int s, int d)
{
    int m, x, y;
    if (s == d)
        if (v[s] == a)
            return 1;
        else
            return 0;

        else
        {
            m = (s + d) / 2;
            x = dei (s, m);
            y = dei (m+1, d);

            return (x || y);
        }
}

int main ()
{
    f >> n >> a;
    for (int i = 1; i <= n; i++)
        f >> v[i];

    g << dei(1, n);
}
*/



/*
#include <iostream>
#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");

int v[1001], n, a;

int dei (int s, int d)
{
    int m, x, y;
    if (s == d)
        if (v[s] % 2 == 0)
            return 1;
        else
            return 0;

        else
        {
            m = (s + d) / 2;
            x = dei (s, m);
            y = dei (m+1, d);

            return (x && y);
        }
}

int main ()
{
    f >> n >> a;
    for (int i = 1; i <= n; i++)
        f >> v[i];

    g << dei(1, n);
}
*/






/*
#include <iostream>
#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");

int v[1001], n, a;

int cmmdc (int a, int b)
{
    while (b)
    {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int dei (int s, int d)
{
    int m, x, y;
    if (s == d)
        if (v[s] % 2 == 1)
            return v[s];
        else
            return 0;

        else
        {
            m = (s + d) / 2;
            x = dei (s, m);
            y = dei (m+1, d);

            return cmmdc(x, y);
        }
}

int main ()
{
    f >> n;
    for (int i = 1; i <= n; i++)
        f >> v[i];

    g << dei(1, n);
}
*/









/*
#include <iostream>
#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");

int a[100], L[100], poz[100], i, j, n, k, maxi;

int main()
{
    f >> n;
    for(int i=1; i <= n; i++)
        f >> a[i];

    L[n] = 1;
    poz[n] = n;

    for(i = n - 1; i >= 1; i--)
    {
        L[i] = 1;
        poz[i] = i;

        for(j = i + 1; j <= n; j++)
            if(a[i] < a[j] && L[i] <= L[j])
            {
                L[i] = L[j] +1;
                poz[i] = j;
            }
    }

    for(i = 1; i <= n; i++)
        if(L[i] > maxi)
        {
            maxi = L[i];
            k = i;
        }
    g << "Lungimea maxima este "<<maxi<<endl;
    for(i = 1, j = k; i <= L[k]; i++, j=poz[j])
        g<< a[j] <<" ";

    return 0;
}
*/








/*
#include <iostream>
#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");

int a[101][101], x[101], y[101], v[101], k, m, n;

int main ()
{
    f >> n;
    for (int i = 1; i <= n; i++)
        f >> x[i];

    f >> m;
    for (int i = 1; i <=m; i++)
        f >> y[i];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (x[i] == y[j])
                a[i][j] = a[i-1][j-1] + 1;
            else
            {
                if (a[i-1][j] > a[i][j-1])
                    a[i][j] = a[i-1][j];
                else
                    a[i][j] = a[i][j-1];
            }
        }

    g << "Lungimea maxima este " << a[n][m] << endl;

    int i = n;
    int j = m;

    while (i != 0 && j != 0)
    {
        if (x[i] == y[j])
        {
            v[k++] = x[i];
            i--;
            j--;
        }
        else
        {
            while (a[i][j] == a[i-1][j])
                i--;
            while (a[i][j] == a[i][j-1])
                j--;
        }
    }

    for (i = k - 1; i >= 0; i--)
        g << v[i] << " ";
}
*/







/*
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");

char x[50], y[50], v[50];
int a[50][50], n, m, k;

int main ()
{
    f.get(x, 50);
    f.get();
    f.get(y, 50);

   // strncat(x, x, 1);
    //strncat(y, y, 1);

    for (int i = strlen(x) - 1; i >= 0; i--)
    {
        x[i+1] = x[i];
    }

    for (int i = strlen(y) - 1; i >= 0; i--)
    {
        y[i+1] = y[i];
    }


   n = strlen(x);
   m = strlen(y);

    for (int i = 0; i < n; i++)
        g << x[i];

    g << endl;

    for (int i = 0; i < m; i++)
        g << y[i];

    g << endl;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (x[i] == y[j])
                a[i][j] = a[i-1][j-1] + 1;
            else
            {
                if (a[i-1][j] > a[i][j-1])
                    a[i][j] = a[i-1][j];
                else
                    a[i][j] = a[i][j-1];
            }
        }



    g << "Lungimea maxima este " << a[n][m] << endl;

    int i = n;
    int j = m;

    while (i != 0 && j != 0)
    {
        if (x[i] == y[j])
        {
            v[k++] = x[i];
            i--;
            j--;
        }
        else
        {
            while (a[i][j] == a[i-1][j])
                i--;
            while (a[i][j] == a[i][j-1])
                j--;
        }
    }

    for (i = k - 1; i >= 0; i--)
        g << v[i] << " ";
}
*/







/*
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");

int a[101][101], n, m, viz[101], sum, nr, x, y, z;


void df (int i, int nr)
{
    viz[i] = nr;
    for (int j = 1; j <= n; j++)
        if (viz[j] == 0 && a[i][j] == 1)
            df(j, nr);
}



int main ()
{
    f >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        f >> x >> y >> z;
        a[x][y] = a[y][x] = 1;
        sum = sum + z;
    }

    g << "a) " << sum;
    g << endl << endl << "b) ";

    f >> x >> y;
    a[x][y] = a[y][x] = 0;

    for (int i = 1; i <= n; i++)
        if (viz[i] == 0)
        {
            nr++;
            df(i, nr);
        }

    if (nr == 1)
        g <<"Nu este srada prinipala";
    else
        g <<"Este strada principala";

    g << endl << endl <<"c) ";

     f >> x >> y;
     if (viz[x] == viz[y])
        g << "Poate ajunge";
    else
        g <<"Nu poate ajunge";

    return 0;
}
*/









/*
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");

int a[101][101], n, m, viz[101], sum, nr, x, y, z, aciclic = 1;

void df (int i, int nr)
{
    viz[i] = nr;
    for (int j = 1; j <= n; j++)
        if (a[i][j] == 1)
        {
            if (viz[j] == 0)
            {
                dad[j] = i;
                df(j, nr);
            }

            else if (tata[i] != j)
                aciclic = 0;
        }
}

int main ()
{
    f >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        f >> x >> y;
        a[x][y] = a[y][x] = 1;
    }

    g << "a) ";
    int ok = 1;
    for (int i = 1; i <=n ; i++)
    {
        sum = 0;
        for (int j = 1; j <= n; j++)
            if (a[i][j] == 1)
                sum++;

        if (sum == 0)
        {
            ok = 0;
            g << i <<" ";
        }
    }
    if (ok == 1)
        g <<"Nu exista noduri izolate";

    g << endl << endl << "b) ";

    for (int i = 1; i <= n; i++)
        if (viz[i] == 0)
        {
            nr++;
            df(i, nr);
        }

    f >> x;
    for (int i = 1; i <= n; i++)
        if (viz[x] == viz[i])
            g << i << " ";

    g << endl << endl << "c) ";

    if (aciclic == 1)
        g <<"GRAF ACICLIC";
    else
        g << "GRAFUL CONTINE CEL PUTIN UN CICLU";

    g << endl << endl;

    return 0;
}
*/





/*
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");

int s[101], x;

int produs (int k)
{
    int p = 1;
    for (int i = 1; i <= k; i++)
        p = p * s[i];
    return p;
}

void tipar (int k)
{
    for (int i = 1; i <= k; i++)
        g << s[i] <<" ";
    g << endl;
}

int valid (int k)
{
    if (k > 5)
        return 0;
    if (x % s[k] != 0)
        return 0;
    return 1;
}

void bk(int k)
{
    for (int i = 2; i <= x / 2; i++)
    {
        s[k] = i;
        if (valid(k) != 0)
        {
            if (produs(k) == x)
                tipar(k);
            else
                bk(k+1);
        }
    }
}

int main ()
{
    f >> x;
    bk(1);

    return 0;
}
*/





/*
#include <iostream>
#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");

int n , m , a[1001][9001] , s;

int main()
{
    f >> n >> s;

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

    g << a[n][s] << endl << endl;

    for (int i = 1; i <= n; i++, g << endl)
        for (int j = 1; j <= s; j++, g <<" ")
            g << a[i][j];

}
*/



/*
#include <iostream>
#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");

int a[100][100], n, m, v[100], d[100], viz[100], k, l;

int main ()
{
    f >> n >> m;
    f >> k >> l;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j)
                a[i][j] = 9999999;

    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        f >> x >> y >> z;
        a[x][y] = a[y][x] = z;
    }

    for (int i = 2; i <= n; i++)
        d[i] = 9999999;


    for (int i = 1; i <= n; i++, g << endl)
        for (int j = 1; j <= n; j++, g <<" ")
            g << a[i][j];

    int i = 1;
    while (v[i] == 0)
    {
        v[i] = 1;
        int mini = 10000;
        int nodmin = 10000;
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] > 0)
            {
                if (d[j] < d[i] + a[i][j])
                    d[j] = a[i][j] + d[i];

                if (mini <d[j] && v[j] == 0)
                {
                    mini = d[j];
                    nodmin = j;
                }
            }
        }
        if (nodmin > 0)
            i = nodmin;
    }

    g << endl << endl;
    for (int i = 1; i <= n; i++)
        g << v[i] << " ";
    g << endl;

    for (int i = 1; i <= n; i++)
        g << d[i] << " ";
    g << endl;

    g << d[l];

    return 0;
}
*/



/*
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");



const int INF = 1e9; // a very large number
const int MAXN = 100; // maximum number of nodes in the graph
int n; // number of nodes in the graph
int dist[MAXN]; // distance from the source node to each node in the graph
bool vis[MAXN]; // boolean array to keep track of which nodes have been visited
int graph[MAXN][MAXN]; // adjacency matrix to represent the graph

void init()
{

    for (int i = 0; i < n; i++)
    {
        dist[i] = INF;
        vis[i] = false;
    }
    dist[0] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = INF;
        }
    }
}

void dijkstra()
{
    for (int i = 0; i < n; i++)
    {
        // find the node with the smallest distance that has not been visited
        int min_dist = INF;
        int min_node = -1;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && dist[j] < min_dist)
            {
                min_dist = dist[j];
                min_node = j;
            }
        }
        if (min_node == -1)
        {
            // all nodes have been visited
            break;
        }
        // mark the node as visited
        vis[min_node] = true;
        // update the distances of its neighbors
        for (int j = 0; j < n; j++)
        {
            if (graph[min_node][j] != INF)
            {
                dist[j] = min(dist[j], dist[min_node] + graph[min_node][j]);
            }
        }
    }
}

int main()
{

    cin >> n;
    init();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            if (x != -1)
            {
                graph[i][j] = x;
            }
        }
    }
   dijkstra();
    return 0;
}
*/







/*
#include <bits/stdc++.h>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");

int d[101], v[100], n, p[100], k, I[100];

int main ()
{
    f >> n;
    for (int i = 1; i <= n; i++)
        f >> v[i];

    k = 1;
    d[k] = v[1];

    for(int i = 2 ; i <= n ; i++)
    {
        if(v[i] >= d[k])
        {
            d[++k] = v[i];
            p[i] = k;
        }

        else
        {
            int st = 1, dr = k, poz = k + 1;
            while(st <= dr)
            {
                int m = (st + dr) / 2;
                if (d[m] > v[i])
                    poz = m, dr = m - 1;
                else
                    st = m + 1;
            }
            d[poz] = v[i];
            p[i] = poz;
        }
    }
    g << k << endl;

    int j = n;
    for(int i = k ; i >= 1 ; i --)
    {
        while(p[j] != i)
            j --;
        I[i] = j;
    }

    for (int i = 1; i <= k; i++)
        g <<v[I[i]] <<" ";
    return 0;
}
*/




/*
#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");

int a[101][101], m, n, p, k;

int main ()
{
    f >> m >> n;

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
           f >> a[i][j];

    ///a)
    f >> k;

    int ok = 1;
    for (int i = 1; i < n; i++)
        if (a[k][i] != a[k][i+1])
           ok = 0;

    if (ok == 1)
        g << "DA" << endl;
    else
        g << "NU" << endl;

    ///b)
    f >> p;

    ok = 1;
    for (int i = 1; i < m; i++)
        if (a[i][p] % 2 == a[i+1][p] % 2)
           ok = 0;

    if (ok == 1)
        g << "DA" << endl;
    else
        g << "NU" << endl;

    ///c)

    int suma;
    for (int i = 1; i <= m; i++)
    {
        suma = 0;
        for (int j = 1; j <= n; j++)
            suma = suma + a[j][i];
        if (suma % 2 == 0)
            g << i <<" ";
    }
    g << endl;


    ///d
    int mini = 999999;
    int maxi = 0;

    for (int i = 1; i <= m; i++)
        if (a[i][1] > maxi)
            maxi = a[i][1];
        else if (a[i][1] < mini)
            mini = a[i][1];

    for (int i = 1; i <= n; i++)
        if (a[1][i] > maxi)
            maxi = a[1][i];
        else if (a[1][i] < mini)
            mini = a[1][i];

    for (int i = 1; i <= m; i++)
        if (a[n][i] > maxi)
            maxi = a[n][i];
        else if (a[n][i] < mini)
            mini = a[n][i];

    for (int i = 1; i <= n; i++)
        if (a[i][m] > maxi)
            maxi = a[i][m];
        else if (a[i][m] < mini)
            mini = a[i][m];


    g << maxi << " " << mini;
}
*/







/*
#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");

int a[101][101], m, n, p, k;

int main ()
{
    f >> m >> n;    /// Citesti nr de linii si nr de coloane

    for (int i = 1; i <= m; i++)    /// Citesti matricea
        for (int j = 1; j <= n; j++)
           f >> a[i][j];


    ///1)

    for (int i = 1; i <= m; i++)        /// Trebuie sa trecem prin toate elementele matricei asa cafolosim 2 for-uri, unul care trece prin linii si unul care trece prin elementele fiecareii linii fiecarei linii
        for (int j = 1; j <= n; j++)
        {

            if (i % 2 == j % 2 && i % 2 == a[i][j] % 2)    ///Verifica daca indicele liniei si cel al coloanei unui element si elementul a[i][j] au toate aceeasi paritate (dau acelasi rest la 2)
                g << a[i][j] <<" ";     /// Afisam elementele care respecta conditia
        }
    g << endl;

    ///2)
    f >> k; ///Citesti linia care trebuie verificata

    int ok = 1;      /// Luam variabila ok. Daca la sfarsit ok = 1 inseamna ca toate numerele sunt in progreesie aritmetica
    for (int j = 1; j < n - 1; j++)      /// Trecem prin toate elementele (coloanele) liniei k
    {
        if (a[k][j+1] != (a[k][j] + a[k][j+2]) / 2)      ///Daca luam pe rand elementele j, j+1 si j+2 putem verifica daca sunt in progresie daca elementul de pe poz j+1 este egal cu media aritmetica a elementelor de pe poz j si j + 2.
            ok = 0;     /// Daca nu sunt egale inseamna ca nu este progreise aritmetica
    }

    if (ok == 1)
        g << "DA" << " " << a[k][2] - a[k][1] << endl;    ///Daca este progresie afisam "DA" si ratia care este diferenta dintre 2 termeni consecutivi din progresie
    else
         g <<"NU" << endl;    ///Daca nu este progresie afisam "NU"

    ///3)

    f >> p;    /// Citim coloana P
    int maxi = 0; ///Declaram un maxim care initial este 0

    for (int i = 1; i <= m; i++)      /// Trecem prin toate elementele (liniile) coloanei p
        if (a[i][p] > maxi)  /// Daca gasim un nr mai mare decat maximul gasit pana atunci
           maxi = a[i][p];   /// Actulizam valoarea lui maxi
    g << maxi << endl; /// Afisam valoarea maxima

    ///4)

    int suma;   /// Declaram variabila suma
    for (int i = 1; i <= m; i++)  /// Trecem prin toate liniile matricei
    {
        suma = 0; /// Resetam suma pentru fiecare linie
        for (int j = 1; j <= n; j++) /// Trecem  Trecem prin toate elementele (coloanele) liniei i
            suma = suma + a[i][j]; /// Adunam la suma curenta toate elementele liniei
        if (suma % 2 == 0) ///Daca suma este un numar par
            g << i <<" "; /// Afisam indicele liniei
    }
    g << endl;

    /// 5)

    int s, d; /// Declaram 2 variabile care sa fie capetele intervalelor (stanga si dreapta)

    if (a[1][1] < a[m][n] ) /// Daca  elementul din stanga sus este mai mic ca cel din dreapta jos
    {
        s = a[1][1]; /// Termenul din stanga al intervalului devine cel mai mic dintre cele 2 nr
        d = a[m][n]; /// Termenul din dreapta al intervalului devine cel mai mare dintre cele 2 nr
    }
    else /// Daca este invers si elementul a[1][1] este mai mare ca elementul a[m][n] doar inversam ordinea de mai sus
    {
        d = a[1][1]; /// Termenul din dreapta al intervalului devine cel mai mare dintre cele 2 nr
        s = a[m][n]; /// Termenul din stanga al intervalului devine cel mai mic dintre cele 2 nr
    }

    for (int i = 1; i <= m; i++) /// Trecem prin marginea din stanga a matricei (colona 1 si linii de la 1 la m)
        if (a[i][1] >= s && a[i][1] <= d) /// Daca elementul apartine intervalului (este mai mare sau egal decat termenul din stanga si mai mic sau egal decat cel din dreapta)
            g << a[i][1] << " "; /// Afisam elementul

    /// La toate if-urile urmatoare se aplica aceeasi conditie, doar termenii din matricea a se schimba

    for (int j = 2; j <= n - 1; j++) /// Trecem prin marginea de sus a matricei (linia 1 si coloane de la 2 la n - 1 ca sa nu afisam colturile matricei de 2 ori)
        if (a[1][j] >= s && a[1][j] <= d)
           g << a[1][j] <<" ";

    for (int j = 2; j <= n - 1; j++) /// Trecem prin marginea de jos a matricei (linia m si coloane de la 2 la n - 1 ca sa nu afisam colturile matricei de 2 ori)
        if (a[m][j] >= s && a[m][j] <= d)
            g << a[m][j] << " ";

    for (int i = 1; i <= m; i++) /// Trecem prin marginea din dreapta a matricei (coloana n si liniile de la 1 la m)
        if (a[i][n] >= s && a[i][n] <= d)
            g << a[i][n] <<" ";


    return 0;
}
*/





/*
#include <cstring>
#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");

int n;
char s[1001], voc[] = "aeiou";

int main ()
{

    f >> s;

    for (int i = 0; i < strlen(s); i++)
    {
        int ok = 0;
        for (char a = s[i]; ok == 0; a--)
        if (strchr("aeiou", a))
        {
            ok = 1;
            g <<a;
        }

    }
    return 0;

}
*/





/*
#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");

struct nod
{
    int nr;
    nod *s, *d;
};
nod *r;
int n;

void creare (nod *&r, int n)
{
    if (r != NULL)
    {
        if (n < r->nr)
            creare(r->s, n);
        else if (n > r->nr)
            creare(r->d, n);
        else
            g <<"Nr exista deja";
    }
    else
    {
        r = new nod;
        r -> nr = n;
        r -> s = NULL;
        r -> d = NULL;
    }
}

void rsd (nod *r)
{
    if (r != NULL)
    {
        g << r -> nr <<" ";
        rsd (r -> s);
        rsd (r -> d);
    }
}

void srd (nod *r)
{
    if (r != NULL)
    {
        srd (r -> s);
        g << r -> nr<<" ";
        srd (r -> d);
    }
}

void sdr (nod *r)
{
    if (r != NULL)
    {
        sdr (r -> s);
        sdr (r -> d);
        g << r -> nr <<" ";
    }
}

int minim (nod *r)
{
    if (r -> s != NULL)
        return minim (r -> s);
    else
        return r -> nr;
}

int maxim (nod *r)
{
    if (r -> d != NULL)
        return maxim (r -> d);
    else
        return r -> nr;
}

void inserare (int k, nod *&r)
{
    if (r != NULL)
    {
        if (r -> nr == k)
            g <<"Exista deja";
        else if (k < r -> nr)
            inserare(k, r -> s);
        else
            inserare(k, r -> d);
    }
    else
    {
        r = new nod;
        r -> nr = k;
        r -> s = NULL;
        r -> d = NULL;
    }

}

void stergeNod (nod *&r, nod *&c) /// r este nodul radacina al subarborelui si c este nodul curent
{
    if (c -> d != NULL)
        stergeNod(r, c-> d);
    else
    {
        r -> nr = c -> nr; /// copiezi informatia
        nod *p = c -> s;
        delete c;
        c = p;
    }
}

void stergere (nod *&r, int k)
{
    nod *c;
    if (r != NULL)
    {
        if (r -> nr == k) ///Daca am gasit nodul
        {
            if (r -> s == NULL && r -> d == NULL) /// Daca este nod terminal
            {
                delete r;
                r = NULL;
            }

            else if (r -> s == NULL) /// Are doar succesor drept
            {
                c = r -> d;
                delete r;
                r = c;
            }

            else if (r -> d == NULL) /// Are doar succesor stang
            {
                c = r -> s;
                delete r;
                r = c;
            }

            else ///Daca are ambii succesori
            {
                stergeNod(r, r -> s);
            }
        }

        else
        {
            if (k > r -> nr)
                stergere(r -> d, k);
            else
                stergere(r -> s, k);
        }

    }
}

int main ()
{
    r = NULL;
    f >> n;
    while (n != 0)
    {
        creare(r, n);
        f >> n;
    }

    rsd(r);
    g << endl;

    srd(r);
    g << endl;

    sdr(r);
    g << endl;

    g << minim(r) <<" " << maxim(r) << endl;

    int x;
    f >> x;
    g << x << endl;

    inserare(x, r);
    srd(r);
    g << endl;

    int o;
    f >> o;

    stergere(r, o);
    srd(r);
    return 0;
}
*/



/*
#include <iostream>
#include <fstream>

using namespace std;
int x, y;


void f(int x)
{
    x = x + 1;
    y = 2*x +3;
}

void g(int x)
{
    int a, b;
    a = x+y;
    b = x-y;
    f(a);
    f(b);
    y = y + b;
}

int main ()
{
    x = 1;
    y = -3;

    g(x);
    cout << x << " " << y;
}
*/



///2
/*
#include <iostream>
#include <fstream>

using namespace std;
ifstream f("test.in");

int a, n, x;

int sumdiv (int x)
{
    int s = 0;
    for (int d = 1; d <= x; d++)
        if (x % d == 0)
          s = s + d;
    return s;
}

void invers (int &a)
{
    int inv = 0;
    while (a != 0)
    {
        inv = inv * 10 + a % 10;
        a = a / 10;
    }
    a = inv;
}

int main ()
{
    cout << "a) " << sumdiv(42) << endl;
    a = 1234;
    invers(a);
    cout <<"b) " << a << endl;

    f >> n;
    int ok = 1;

    for (int i = 1; i <= n; i++)
    {
        f >> x;
        if (sumdiv(x) != x + 1)
            ok = 0;
        invers(x); // x = 54321
        if (sumdiv(x) != x + 1)
            ok = 0;
    }
    if (ok == 1)
         cout << "c) Da";
    else
        cout <<"c) Nu";
}
*/

///3

/*
#include <iostream>
#include <fstream>

using namespace std;
ifstream f("date.in");

int n, minim, maxim;

void minimax (int n, int &minim, int &maxim)
{
    minim = 10;
    maxim = -1;
    while (n != 0)
    {
        if (n % 10 > maxim)
            maxim = n % 10;
        if (n % 10 < minim)
            minim = n % 10;
        n = n /10;
    }
}

void replace (int &n, int a, int b)
{
    int n1 = 0, p = 1;
    while (n != 0)
    {
        if (n % 10 == a)
            n1 = n1 + b * p;
        else if (n % 10 == b)
            n1 = n1 + a * p;
        else
            n1 = n1 + (n % 10) * p;

        p = p * 10;
        n = n / 10;
    }
    n = n1;
}

int main ()
{
    n = 220442;
    minimax (n, minim, maxim);
    cout << "a) minim: " << minim <<", maxim: " << maxim << endl;

    n = 220442;
    replace(n, 2, 4);
    cout << "b) " << n << endl;

    cout <<"c) ";
    while (f >> n)
    {
        minimax (n, minim, maxim);
        replace (n, minim, maxim);
        cout << n <<" ";
    }


}
*/

/*
#include <iostream>
#include <fstream>
using namespace std;

int x;
void functie (int a, int b)
{
    a=a*10;
    b=b-4;
    cout<< " " << a << " " <<b;
}
int main()
{
    int y;
    x=15;
    y=8;

    functie(x,y);
    cout <<" "<<x <<" " <<y<<endl;

    functie(y,x);
    cout <<" "<<x <<" "<<y<<endl;

    functie (x,x);
    cout <<" "<<x <<" "<<y<<endl;

    int a=12,b=50;
    functie(b,a);
    cout<<" "<<a<<" "<<b<<endl;

    functie(b,b);
    cout<<" "<<a<<" "<<b<<endl;
}
*/



/*
#include <iostream>
#include <fstream>
using namespace std;

int ceva(int m, int a[100])
{
    return m+2;
}

int b[1001];
int main()
{
    int g = 13;
    cout << ceva (g, b);
}
*/






#include <iostream>
#include <fstream>
using namespace std;

int nrtot;
int main ()
{

    for (int i = 1; i <= 1000000, i++)
    {
        int x1 = i % 1000;
        int x2 = i / 1000;

        int nr1 = 0, nr2 = 0;

        while (x1)
        {
            nr1 = nr1 + x1 % 10;
            x1 = x1 / 10;
        }

        while (x2)
        {
            nr2 = nr2 + x2 % 10;
            x2 = x2 / 10;
        }

        if (nr1 == nr2)
            nrtot++;

    }
    cout << nrtot;

    return 0;

}
