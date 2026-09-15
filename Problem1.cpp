#include 

using namespace std;

int update_k(int k, int no_orang) {
    if (no_orang % 2 == 0) {
        k = k + 2;
    } else {
        k = k - 1;
    }

    if (k < 2) {
        k = 2;
    }

    return k;
}

int main() {
    int n, k;

    cout << "Masukkan jumlah astronot (N): ";
    cin >> n;

    cout << "Masukkan nilai awal K: ";
    cin >> k;

    if (k < 2) {
        k = 2;
    }

    int astronot[1000];
    for (int i = 0; i < n; i++) {
        astronot[i] = i + 1;
    }

    int sisa = n;
    int pos = 0;

    cout << "\nUrutan eliminasi:\n";

    while (sisa > 1) {
        int idx_hapus = (pos + k - 1) % sisa;
        int no_keluar = astronot[idx_hapus];

        cout << "Astronot " << no_keluar << " keluar (K sekarang: " << k << ")\n";

        for (int j = idx_hapus; j < sisa - 1; j++) {
            astronot[j] = astronot[j + 1];
        }
        sisa = sisa - 1;

        k = update_k(k, no_keluar);
        pos = idx_hapus;
    }

    cout << "\nAstronot terakhir: Astronot " << astronot[0] << endl;

    return 0;
}