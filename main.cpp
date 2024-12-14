#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;


// Funkcja wypisująca macierz A oraz wektor b
void wyswietl_tablice(const vector<vector<double>> &A, const vector<double> &b) {
    int n = A.size();
    cout << "\nAktualny stan macierzy A i wektora b:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(10) << fixed << setprecision(4) << A[i][j] << " ";
        }
        cout << " | " << setw(10) << fixed << setprecision(4) << b[i] << endl;
    }
    cout << "--------------------------------------------\n";
}

// Funkcja wypisująca wektor rozwiązania
void rozwiazania(const vector<double> &x) {
    cout << "\nRozwiazanie ukladu rownan:\n";
    for (size_t i = 0; i < x.size(); ++i) {
        cout << "x" << i + 1 << " = " << fixed << setprecision(6) << x[i] << endl;
    }
}

// Funkcja eliminacji Gaussa bez wyboru elementu maksymalnego
vector<double> podstawowy_gauss(vector<vector<double>> A, vector<double> b) {
    int n = A.size();

    for (int k = 0; k < n; ++k) {
        if (abs(A[k][k]) < 1e-9) {
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
        wyswietl_tablice(A, b);
    }

    // Rozwiązanie przez podstawianie wsteczne
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

// Funkcja eliminacji Gaussa z częściowym wyborem elementu maksymalnego - wiersz
vector<double> gauss_wybor_czesciowy(vector<vector<double>> A, vector<double> b) {
    int n = A.size();

    for (int k = 0; k < n; ++k) {
        int max_row = k;
        for (int i = k + 1; i < n; ++i) {
            if (abs(A[i][k]) > abs(A[max_row][k])) {
                max_row = i;
            }
        }

        swap(A[k], A[max_row]);
        swap(b[k], b[max_row]);

        for (int i = k + 1; i < n; ++i) {
            double p = A[i][k] / A[k][k];
            for (int j = k; j < n; ++j) {
                A[i][j] -= p * A[k][j];
            }
            b[i] -= p * b[k];
        }
        wyswietl_tablice(A, b);
    }

    // Rozwiązanie przez podstawianie wsteczne
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

// Funkcja eliminacji Gaussa z pełnym wyborem elementu maksymalnego
vector<double> gauss_wybor_pelny(vector<vector<double>> A, vector<double> b) {
    int n = A.size();
    vector<int> swaps(n);
    for (int i = 0; i < n; ++i) swaps[i] = i;

    for (int k = 0; k < n; ++k) {
        int max_row = k, max_col = k;
        for (int i = k; i < n; ++i) {
            for (int j = k; j < n; ++j) {
                if (abs(A[i][j]) > abs(A[max_row][max_col])) {
                    max_row = i;
                    max_col = j;
                }
            }
            wyswietl_tablice(A, b);
        }

        swap(A[k], A[max_row]);
        swap(b[k], b[max_row]);
        for (int i = 0; i < n; ++i) swap(A[i][k], A[i][max_col]);
        swap(swaps[k], swaps[max_col]);

        for (int i = k + 1; i < n; ++i) {
            double p = A[i][k] / A[k][k];
            for (int j = k; j < n; ++j) {
                A[i][j] -= p * A[k][j];
            }
            b[i] -= p * b[k];
        }
    }

    // Rozwiązanie przez podstawianie wsteczne
    vector<double> x(n);
    for (int i = n - 1; i >= 0; --i) {
        double sum = 0;
        for (int j = i + 1; j < n; ++j) {
            sum += A[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / A[i][i];
    }

    // Przywracanie kolejności zmiennych
    vector<double> x_finalne(n);
    for (int i = 0; i < n; ++i) {
        x_finalne[swaps[i]] = x[i];
    }
    return x_finalne;
}

// Funkcja pobierająca dane od użytkownika
void pobiez_dane(vector<vector<double>> &A, vector<double> &b) {
    int n;
    cout << "Podaj liczbe rownan (i niewiadomych): ";
    cin >> n;
    A.resize(n, vector<double>(n));
    b.resize(n);

    cout << "Podaj macierz wspolczynnikow (wiersz po wierszu):\n";
    for (int i = 0; i < n; ++i) {
        cout<<"Wiersz "<<(i+1)<<endl;
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    cout << "Podaj wektor wyrazow wolnych:\n";
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
    int choice;
    cin >> wybor_metody;

    vector<vector<double>> A, C;
    vector<double> b, c;

    cout << "Czy chcesz podac wlasne dane wejsciowe?\n";
    cout << "1 - Tak\n";
    cout << "2 - Nie, uzyj pierwszego zestawu danych\n";
    cout << "3 - Nie, uzyj drugiego zestawu danych\n";
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
            break;
        case 3:
            A = {{3, 4, 5},
                 {0, 2,  3},
                 {1, 1, 3}};
            b = {2, 4, 8};
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