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
