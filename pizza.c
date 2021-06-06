/*
Sa taiem pizza!

Intr-o zi, Felix a fost rugat sa taie o pizza bucati, pentru a o distribui prietenilor. Dimensiunile bucatilor de pizza nu trebuie neaparat sa fie identice, deci putem obtine o bucata mai mare sau mai mica decat alta. El s-a gandit un pic si a ajuns la concluzia ca poate sa taie pizza  din trei taieturi drepte astfel incat sa rezulte sapte bucati. Incercati sa realizati o performanta similara cu ajutorul computerului! Adica, dat fiind numarul de linii drepte, calculati numarul maxim de bucati care se pot obtine.

Date de intrare: in fisierul pizza.in
se gasesc mai multe cazuri de test, cate unul pe linie (0 <= N <= 210.000.000), fiecare linie reprezentand numarul de linii drepte. Un numar negativ incheie lista cazurilor din fisierul de intrare.
Date de iesire: in fisierul pizza.out vor trebui scrise numarul maxim de bucati de pizza ce se pot obtine pentru fiecare numar din fisierul de intrare, in forma din exemplu:

pizza.in        pizza.out

0               0 taieturi -> 1 bucati.
1               1 taieturi -> 2 bucati.
2               2 taieturi -> 4 bucati.
5               5 taieturi -> 16 bucati.
7               7 taieturi -> 29 bucati.
8               8 taieturi -> 37 bucati.
9               9 taieturi -> 46 bucati.
10              10 taieturi -> 56 bucati.
210000000       210000000 taieturi -> 22050000105000001 bucati.
678             678 taieturi -> 230182 bucati
-100
*/

#include <stdio.h>
#define FIN "pizza.in"
#define FOUT "pizza.out"

unsigned int vec[200], k;

void multiply(long int a, long int b) {

    long int t = 1;
    k = 0;
    short c;

    while( a ) {

          c = a % 10;
          a /= 10;
          vec[k++] = (t + c * b) % 10;    
          t = (t + c * b) / 10;   
    }

    while(t) {
      vec[k++] = t % 10;
      t /= 10;
    }
 
}

void write() {
    for(int i = k - 1; i >= 0; i--) {
        printf("%d", vec[i]) ;
    }
    printf("\n");
}

int main() {
  long int n;
  freopen(FIN, "r", stdin);
  //freopen(FOUT, "w", stdout);
  while(scanf("%ld", &n) && n >= 0) {

       if(n % 2 == 0) {

           multiply(n / 2, ( n + 1 ) );                
       } else {

          multiply(n, ( n + 1) / 2);    
          
       }

       write();   
  }

  return(0);
}
