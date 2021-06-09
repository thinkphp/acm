/*
Factorial.

Se da un numar intreg P. Sa se gaseasca cel mai mic numar natural strict pozitiv N
pentru care N! are exact P cifre de 0 la sfarsit. Se stie ca
N! = 1 * 2 * 3 * ...* (N-1) * N;

Date de intrare:

Fisierul fact.in va contine pe prima linie numarul intreg P

Date de iesire:

Pe prima linie a fisierului fact.out se va scrie acel numar N care indeplineste conditiile
impuse sau -1 daca nu exista un astfel de N.

Restrictii:

0 <= P <= 10^8

Exemple:
fact.in       fact.out
0             1
2             10
10            45
*/

#include <iostream>
#include <fstream>
#define int long long
#define FIN "fact.in"
#define FOUT "fact.out"

int nrzeros(int n) {

    int nr = 0;

    while(n) {

      nr += n / 5;

      n /= 5;
    }

    return nr;
}

int searchBin(int p ) {

    int lo = 1, hi = 1000000000000000LL, m, sol = -1;

    while(lo <= hi) {

        m = (lo + hi) >> 1;

        if(p == nrzeros( m )) {

           sol = m;

           break;
        }

        if(p < nrzeros(m)) {

           hi = m - 1;

        } else {

           lo = m + 1;
        }
    }
    return sol;
}

signed main(int argc, char const *argv[]) {

  int p;

  freopen(FIN, "r", stdin);

  freopen(FOUT, "w", stdout);

  std::cin>>p;

  int res = searchBin( p );

  int m = nrzeros( res );

  while(m == p) {

      res--;

      m = nrzeros(res);
  }

  if(p == 0) std::cout<<1<<'\n';

      else if(res != -1)

             std::cout<<(res+1)<<'\n';
      else
             std::cout<<-1<<'\n';

  return 0;
}
