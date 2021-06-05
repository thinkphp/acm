/*
Ionut are o pasiune pentru jocurile cu cuburi. El le asaza unul peste altul si construieste coloane de diferite inaltimi. Ii arata surorii sale "opera", laudandu-se cu zidul pe care l-a construit, dar aceasta ii reproseaza: "ca sa fie zid", trebuie sa aiba toate coloanele de aceeasi inaltime!", moment in care Ionut s-a dat seama ca ea are dreptate. Asa ca s-a gandit sa rearanjeze cuburile, unul cate unul, astfel incat coloanele obtinute sa aiba aceeasi inaltime. Il puteti ajuta pe Ionut sa realizeze acest lucru printr-un numar minim de mutari?

Date de intrare: In fisierul cuburi.in se gasesc mai multe cazuri de n coloane pe care Ionut le-a construit. Pe o linie se afla numarul n de stive, pe urmatoarea linie se afla n numere naturale reprezentand inaltimile celor n stive. Consideram ca 1 <= n <= 50 si 1 <= hi <= 100. Numarul total de cuburi este divizibil cu numarul de stive, astfel incat vom putea sa construim n coloane de aceeasi inaltime. Datele de intrare se incheie la citirea lui n = 0. Acest set de date nu trebuie procesat.

Data de iesire: pentru fiecare caz, asa cum a fost prezentat mai sus, trebuie afisate doua propozitii: numarul cazului si numarul minim de mutari in forma din exemplu:

cuburi.in:

6
5 2 4 1 7 5
6
4 7 2 3 9 5
3
11 23 2
0

cuburi.out:

Cazul #1
Numarul minim de mutari este 5.
Cazul #2
Numarul minim de mutari este 6.
Cazul #3
Numarul minim de mutari este 11.

(ACM Southwestern European Regional Programming Contest 1997, enunt modificat)
*/

#include <stdio.h>
#define FIN "cuburi.in"
#define FOUT "cuburi.out"
typedef unsigned int uint;

uint s,  
     n, 
     v[100], 
     _case = 1;

void read() {     
     s = 0;
     for(int i = 0; i < n; ++i) {
         scanf("%d", &v[i]);
         s += v[i];
     } 
}

void solve() {

   uint aux = s / n, 
        sol = 0;        

   for(int i = 0; i < n; ++i) {
       if(v[i] < aux) sol += aux - v[i];
   }
   printf("cazul #%d\n", _case++);
   printf("Numarul minim de mutari este: %d\n", sol);
};

int main() {
     freopen(FIN, "r", stdin);  
     freopen(FOUT, "w", stdout);

    while(scanf("%d", &n) > 0 && n) {
      read ();
      solve ();
    }  

  return(0);
}
