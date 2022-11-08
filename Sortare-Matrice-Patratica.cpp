#include <iostream>

using namespace std;

int CitesteN() {
    int n;

    cout << "Introdu valoare lui \nn=";
    cin >> n;

    return n;
}

int main()
{
    int a[20][20], n, c[100], k, mini, aux;
    // Citeste N
    n = CitesteN();

    // Citeste matricea
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    // Scrie matricea sub forma de vector
    k = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            c[k++] = a[i][j];



    // Luam fiecare element pe rand din vector si il comparam cu restul de elemente pentru a gasi minimul
    for (int i = 1; i <= n * n - 1; i++) {
        mini = i;

        // Search for the index of the minimum value in the array
        for (int j = i + 1; j <= n * n; j++) {
            // compar valoarea curenta din vector cu valoare minima gasit pana acum 
            if (c[j] < c[mini]) {
                // Salvezi in mini indexul valorii minime gasite ** pana acum
                mini = j;
            }
        }
        // Interschimbi valoarea elementului curent cu valoarea minimia gasita dupa i
        aux = c[i];
        c[i] = c[mini];
        c[mini] = aux;
    }

    // Printeaza vectorul sortat in consola
    for (int i = 1; i <= n * n; i++) {
        if ((i - 1) % n == 0) {
            cout << "\n";
        }
        cout << c[i] << " ";
    }

}