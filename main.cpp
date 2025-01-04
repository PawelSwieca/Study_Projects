#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;


// Funkcja wypisująca macierz A oraz wektor b
void wyswietl_tablice(const vector<vector<double>> &A, const vector<double> &b) {
    int n = (int)A.size();
    cout << "\nAktualny stan macierzy A i wektora b:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(10) << fixed << setprecision(4) << A[i][j] << " ";
        }
        cout << " | " << setw(10) << fixed << setprecision(4) << b[i] << endl;
    }
    cout << "--------------------------------------------\n\n";
}
// Funkcja licząca wektor rozwiązań od ostatniego wiersza
vector<double> postepowanie_odwrotne(int n, vector<vector<double>> A, vector<double> b){
    vector<double> x(n);
    for (int i = n - 1; i >= 0; --i) {
        double sum = 0;
        for (int j = i + 1; j < n; ++j) {
            sum += A[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / A[i][i];
    }
    return x;
}

// Funkcja wypisująca wektor rozwiązania
void rozwiazania(const vector<double> &x) {
    cout << "\nRozwiazanie ukladu rownan:\n";
    for (int i = 0; i < x.size(); ++i) {
        cout << "x" << i + 1 << " = "<< setw(7) << fixed << setprecision(4) << x[i] << endl;
    }
}

// Funkcja eliminacji Gaussa bez wyboru elementu maksymalnego
vector<double> podstawowy_gauss(vector<vector<double>> A, vector<double> b) {
    int n = (int)A.size();

    for (int k = 0; k < n; ++k) {
        if (abs(A[k][k]) < exp(-9)) {
            cerr << "Blad: dzielenie przez zero (element jest zbyt maly).\n";
            exit(1);
        }
        for (int i = k + 1; i < n; ++i) {
            double p = A[i][k] / A[k][k];
            for (int j = k; j < n; ++j) {
                A[i][j] -= p * A[k][j];
            }
            b[i] -= p * b[k];
        }
        cout<<"Koniec kroku nr."<<k+1;
        wyswietl_tablice(A, b);
    }

    // Postępowanie odwrotne
    vector<double> x(n);
    x = postepowanie_odwrotne(n, A, b);

    return x;
}

// Funkcja eliminacji Gaussa z częściowym wyborem elementu maksymalnego - kolumny
vector<double> gauss_wybor_czesciowy(vector<vector<double>> A, vector<double> b) {
    int n = (int)A.size();

    for (int k = 0; k < n; ++k) {
        int max_row = k;
        for (int i = k + 1; i < n; ++i) {
            if (abs(A[i][k]) > abs(A[max_row][k])) {
                max_row = i;
            }
        }

        swap(A[k], A[max_row]);
        swap(b[k], b[max_row]);

        if (abs(A[k][k]) < exp(-9)) {
            cerr << "Blad: element na przekatnej glownej jest rowny zero (element jest zbyt maly).\n";
            exit(1);
        }

        for (int i = k + 1; i < n; ++i) {
            double p = A[i][k] / A[k][k];
            for (int j = k; j < n; ++j) {
                A[i][j] -= p * A[k][j];
            }
            b[i] -= p * b[k];
        }
        cout<<"Koniec kroku nr."<<k+1;
        wyswietl_tablice(A, b);
    }

    // Postępowanie odwrotne
    vector<double> x(n);
    x = postepowanie_odwrotne(n, A, b);

    return x;
}

// Funkcja eliminacji Gaussa z pełnym wyborem elementu maksymalnego
vector<double> gauss_wybor_pelny(vector<vector<double>> A, vector<double> b) {
    int n = (int)A.size();
    vector<int> zamiany(n);
    for (int i = 0; i < n; ++i) zamiany[i] = i;

    for (int k = 0; k < n; ++k) {
        int max_row = k, max_col = k;
        for (int i = k; i < n; ++i) {
            for (int j = k; j < n; ++j) {
                if (abs(A[i][j]) > abs(A[max_row][max_col])) {
                    max_row = i;
                    max_col = j;
                }
            }
        }

        swap(A[k], A[max_row]);
        swap(b[k], b[max_row]);
        for (int i = 0; i < n; ++i) swap(A[i][k], A[i][max_col]);
        swap(zamiany[k], zamiany[max_col]);

        if (abs(A[k][k]) < exp(-9)) {
            cerr << "Blad: element na przekatnej glownej jest rowny zero (element jest zbyt maly).\n";
            exit(1);
        }

        for (int i = k + 1; i < n; ++i) {
            double p = A[i][k] / A[k][k];
            for (int j = k; j < n; ++j) {
                A[i][j] -= p * A[k][j];
            }
            b[i] -= p * b[k];
        }
        cout<<"Koniec kroku nr."<<k+1;
        wyswietl_tablice(A, b);
    }

    // Postępowanie odwrotne
    vector<double> x(n);
    x = postepowanie_odwrotne(n, A, b);


    // Przywracanie kolejności zmiennych
    vector<double> x_finalne(n);
    for (int i = 0; i < n; ++i) {
        x_finalne[zamiany[i]] = x[i];
    }
    return x_finalne;
}

// Funkcja pobierająca dane od użytkownika
void pobiez_dane(vector<vector<double>> &A, vector<double> &b) {
    int n;
    cout << "Podaj liczbe rownan (i niewiadomych): ";
    cin >> n;
    if(n<=0){
        cout<<"Liczba elementow musi byc wieksza od 0!\n";
        exit(1);
    }
    A.resize(n, vector<double>(n));
    b.resize(n);

    cout << "Podaj macierz wspolczynnikow (wiersz po wierszu, liczby oddzielaj spacja):\n";
    for (int i = 0; i < n; ++i) {
        cout<<"Wiersz "<<(i+1)<<endl;
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    cout << "Podaj wektor wyrazow wolnych (liczby oddzielaj spacja):\n";
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
}

int main() {
    int wybor_metody, wybor_danych;
    cout << "Wybierz metode eliminacji Gaussa:\n";
    cout << "1 - Podstawowa eliminacja Gaussa\n";
    cout << "2 - Eliminacja Gaussa z czesciowym wyborem elementu maksymalnego\n";
    cout << "3 - Eliminacja Gaussa z pelnym wyborem elementu maksymalnego\n";
    cin >> wybor_metody;

    vector<vector<double>> A, C;
    vector<double> b, c;

    cout << "Czy chcesz podac wlasne dane wejsciowe?\n";
    cout << "1 - Tak\n";
    cout << "2 - Nie, uzyj pierwszego zestawu danych\n";
    cout << "3 - Nie, uzyj drugiego zestawu danych\n";
    cout << "4 - Nie, uzyj trzeciego zestawu danych\n";
    cout << "5 - Nie, uzyj czwartego zestawu danych\n";
    cout << "6 - Nie, uzyj piatego zestawu danych\n";
    cout << "7 - Nie, uzyj szostego zestawu danych\n";
    cin >> wybor_danych;

    switch(wybor_danych){
        case 1:
            pobiez_dane(A, b);
            wyswietl_tablice(A, b);
            break;
        case 2:
            A = {{2, -1, 1},
                 {1, 3,  2},
                 {1, -1, 2}};
            b = {1, 12, 5};
            wyswietl_tablice(A, b);
            break;
        case 3:
            A = {{3, 4, 5},
                 {0, 2,  3},
                 {1, 1, 3}};
            b = {2, 4, 8};
            wyswietl_tablice(A, b);
            break;
        case 4:
            A = {{4, 6, 7, 8},
                 {0, 5, 4, 10},
                 {0, 0, 9, 12},
                 {1, -2, 6, 7}
            };
            b = {-2, 4, 8, 12};
            wyswietl_tablice(A, b);
            break;
        case 5:
            A = {{1, 1, 1, 1},
                 {2, 0, 8, 5},
                 {0, 7, 0, -7},
                 {3, -2, 6, 0}
            };
            b = {2, 7, 3, 8};
            wyswietl_tablice(A, b);
            break;
        case 6:
            A = {{0.4, 1.5, 2, 3},
                 {0.33, 0.25, 0.6, 8},
                 {0, -6, -1, 4},
                 {1.5, 3, 7, 9}
            };
            b = {7.89, 1.67, -3, 3.45};
            wyswietl_tablice(A, b);
            break;
        case 7:
            A = {{2.25, -2.5, 4, -5.25},
                 {-3, -7.5, 6.5, 0},
                 {-6.25, -12.5, 0.25, 5.25},
                 {9, 10, 7, -21}
            };
            b = {-1, 17, 24.25, -33};
            wyswietl_tablice(A, b);
            break;
        default:
            exit(1);
    }

    vector<double> x;
    switch (wybor_metody) {
        case 1:
            x = podstawowy_gauss(A, b);
            break;
        case 2:
            x = gauss_wybor_czesciowy(A, b);
            break;
        case 3:
            x = gauss_wybor_pelny(A, b);
            break;
        default:
            cout << "Niepoprawny wybor metody.\n";
            return 1;
    }

    rozwiazania(x);
    return 0;
}