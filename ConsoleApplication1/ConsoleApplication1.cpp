#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("date.in");
ifstream gin("date1.in");
ifstream zin("datez.in");

bool ocupat(int n) {
    if (n == -1) return false; 
    if (n == 0) return true;
}


int main()
{
    int cerinta;
    int nr_clienti;
    int count_camere_l1 = 0;
    int suma_totala = 0;
    int k1 = 0, k2 = 0, k3 = 0, k4 = 0;
    cin >> cerinta;
    int nr_l, nr_c, l, c;
    int mat_hotel[200][200], count_camere_l = 0;
    int mat_camere[200][200], nr_cl, nr_ll, cl, ll;
    int mat_hotel_liber[200][200], nr_cz, nr_lz, lz, cz;
    zin >> nr_lz >> nr_cz;
    gin >> nr_ll >> nr_cl;
    fin >> nr_l >> nr_c;
    for (lz = 1; lz <= nr_lz; lz++) {
        for (cz = 1; cz <= nr_cz; cz++) {
            zin >> mat_hotel_liber[lz][cz];
        }
    }
    for (l = 1; l <= nr_l; l++) {
        for (c = 1; c <= nr_c; c++) {
            fin >> mat_hotel[l][c];
        }
    }
    for (ll = 1; ll <= nr_ll; ll++) {
        for (cl = 1; cl <= nr_cl; cl++) {
            gin >> mat_camere[ll][cl];
        }
    }
    switch (cerinta) {
    case 1:
        for (l = 1; l <= nr_l; l++) {
            for (c = 1; c <= nr_c; c++) {
                if (mat_hotel[l][c] == 0) {
                    count_camere_l++;
                    cout << "nivelul" << "  " << l << "  camera" << "  " << c << " " << "Liber" << '\n';
                }
                if (mat_hotel[l][c] == -1) cout << "nivelul  " << l << "  camera  " << c << " " << "Ocupat" << '\n';
            }
        }
        cout << "Camere disponibile sunt:  " << count_camere_l << '\n';
        cout << "Numar de locuri disponibile:  " << count_camere_l * 4 << '\n';

        break;
    case 2:

        cout << "introduceti numarul de clienti" << '\n';
        cin >> nr_clienti;
        cout << "camerele ocupate sunt" << '\n';
        for (l = 1; l <= nr_l && nr_clienti > 0; l++) {
            for (c = 1; c <= nr_c && nr_clienti > 0; c++) {
                if (mat_hotel[l][c] == 0) {
                    if (nr_clienti > 3) nr_clienti -= 4;
                    else nr_clienti -= nr_clienti;
                    mat_hotel[l][c] = -1;
                    cout << "nivelul  " << l << " " << "camera  " << c << '\n';
                }
            }
        }
        for (l = 1; l <= nr_l; l++) {
            for (c = 1; c <= nr_c; c++) {
                if (mat_hotel[l][c] == 0) {
                    count_camere_l1++;
                }
            }
        }
        cout << "Mai sunt  " << count_camere_l1 << "  camere libere,";
        cout << " iar noua disponibilitate a camerelor este: " << '\n';
        for (l = 1; l <= nr_l; l++) {
            for (c = 1; c <= nr_c; c++) {
                cout << mat_hotel[l][c] << " ";
            }
            cout << '\n';
        }
        break;

    case 3:

        for (ll = 1; ll <= nr_ll; ll++) {
            for (cl = 1; cl <= nr_cl; cl++) {
                if (mat_camere[ll][cl] == 1) k1++;
                if (mat_camere[ll][cl] == 2) k2++;
                if (mat_camere[ll][cl] == 3) k3++;
                if (mat_camere[ll][cl] == 4) k4++;
            }
        }
        suma_totala = k1 * 15 + k2 * 25 + k3 * 40 + k4 * 70;

        cout << "Suma de la finalul zilei este :   " << suma_totala;

        break;
    case 4:
        int persoane;
        cout << "Introduceti numarul de persoane care vin intr-o zi la hotel" << '\n';
        for (int i = 1; i < 7; i++) {
            cin >> persoane;
            for (lz = 1; lz <= nr_lz && persoane > 0; lz++) {
                for (cz = 1; cz <= nr_cz && persoane > 0; cz++) {
                    if (mat_hotel_liber[lz][cz] == 0) {
                        if (persoane > 3) persoane -= 4;
                        else persoane -= persoane;
                        mat_hotel_liber[lz][cz] = -1;
                    }
                }
            }
            for (lz = 1; lz <= nr_lz; lz++) {
                for (cz = 1; cz <= nr_cz; cz++) {
                    cout << mat_hotel_liber[lz][cz] << " ";
                }
                cout << endl;
            }
        }

            break;
    }
}