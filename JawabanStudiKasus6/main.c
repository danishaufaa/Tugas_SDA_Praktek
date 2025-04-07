#include <stdio.h>
#include "kota.h"

int main() {
    NodeKota* listKota = NULL;

    insertKota(&listKota, "Jakarta");
    insertKota(&listKota, "Bandung");
    insertKota(&listKota, "Surabaya");

    insertOrang(listKota, "Jakarta", "Budi");
    insertOrang(listKota, "Jakarta", "Siti");
    insertOrang(listKota, "Bandung", "Andi");
    insertOrang(listKota, "Surabaya", "Dewi");
    insertOrang(listKota, "Surabaya", "Rudi");

    printf("\nData Awal:\n");
    tampilkanSemua(listKota);

    printf("\nMenghapus orang 'Siti' dari Jakarta...\n");
    hapusOrang(listKota, "Jakarta", "Siti");
    tampilkanSemua(listKota);

    printf("\nMenghapus kota 'Bandung'...\n");
    hapusKota(&listKota, "Bandung");
    tampilkanSemua(listKota);

    printf("\nMenghapus semua data...\n");
    hapusSemua(&listKota);

    return 0;
}
