#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ROWS 1000
#define MAX_COLS_1 9
#define MAX_COLS_2 7
#define MAX_COLS_3 3
#define MAX_LEN 100

extern char satu[MAX_ROWS][MAX_COLS_1][MAX_LEN];
extern char dua[MAX_ROWS][MAX_COLS_2][MAX_LEN];
extern char tiga[MAX_ROWS][MAX_COLS_3][MAX_LEN];

int findPasien(const char* id) {
    for (int i = 0; i < MAX_ROWS; ++i) {
        if (strcmp(dua[i][2], id) == 0) {
            return i;
        }
    }
    return -1;  // Not found
}

#fungsi add
void addEntry() {
    char id[MAX_LEN];
    printf("Masukkan ID pasien: ");
    fgets(id, MAX_LEN, stdin);
    strtok(id, "\n");

    int i;
    for (i = 0; i < MAX_ROWS; ++i) {
        if (dua[i][0][0] == '\0') {
            break;
        }
    }
    if (i == MAX_ROWS) {
        printf("Informasi Pasien sudah terisi, tidak bisa ditambahkan!.\n");
        return;
    }

    char tanggal[MAX_LEN], diagnosis[MAX_LEN], tindakan[MAX_LEN], kontrol[MAX_LEN];
    int biaya_tindakan = 0;

    printf("Tanggal riwayat kedatangan pasien (dd-mm-yyyy): ");
    fgets(tanggal, MAX_LEN, stdin);
    strtok(tanggal, "\n");

    printf("Diagnosis yang dimiliki pasien:\n1. Dehidrasi\n2. Pusing\n3. Masuk Angin\n4. Keseleo\nPilih (1-4): ");
    int diag_choice;
    scanf("%d", &diag_choice);
    getchar();  // Consume newline

    switch (diag_choice) {
        case 1: strcpy(diagnosis, "Dehidrasi"); break;
        case 2: strcpy(diagnosis, "Pusing"); break;
        case 3: strcpy(diagnosis, "Masuk Angin"); break;
        case 4: strcpy(diagnosis, "Keseleo"); break;
        default: strcpy(diagnosis, ""); break;
    }

    printf("Tindakan yang diambil pasien:\n1. Vaksinasi\n2. Cek gula darah\n3. Pemasangan infus\n4. Pengobatan\nPilih (1-4): ");
    int tindakan_choice;
    scanf("%d", &tindakan_choice);
    getchar();  // Consume newline

    switch (tindakan_choice) {
        case 1: strcpy(tindakan, "Vaksinasi"); biaya_tindakan = 100000; break;
        case 2: strcpy(tindakan, "Cek gula darah"); biaya_tindakan = 25000; break;
        case 3: strcpy(tindakan, "Pemasangan infus"); biaya_tindakan = 125000; break;
        case 4: strcpy(tindakan, "Pengobatan"); biaya_tindakan = 125000; break;
        default: strcpy(tindakan, ""); biaya_tindakan = 0; break;
    }

    printf("Tanggal kontrol pasien (dd-mm-yyyy): ");
    fgets(kontrol, MAX_LEN, stdin);
    strtok(kontrol, "\n");

    int biaya_total = 15000 + 125000 + biaya_tindakan;

    snprintf(dua[i][0], MAX_LEN, "%d", i+1);
    strncpy(dua[i][1], tanggal, MAX_LEN);
    strncpy(dua[i][2], id, MAX_LEN);
    strncpy(dua[i][3], diagnosis, MAX_LEN);
    strncpy(dua[i][4], tindakan, MAX_LEN);
    strncpy(dua[i][5], kontrol, MAX_LEN);
    snprintf(dua[i][6], MAX_LEN, "%d", biaya_total);

    printf("Entry telah diupdate.\n");
}

#funfsi ubah
void updateEntry() {
    char id[MAX_LEN];
    printf("Masukkan ID pasien: ");
    fgets(id, MAX_LEN, stdin);
    strtok(id, "\n");

    int row = findPasien(id);
    if (row == -1) {
        printf("ID Pasien tidak ditemukan.\n");
        return;
    }

    char tanggal[MAX_LEN], diagnosis[MAX_LEN], tindakan[MAX_LEN], kontrol[MAX_LEN];
    int biaya_tindakan = 0;

    printf("Tanggal riwayat kedatangan pasien (dd-mm-yyyy): ");
    fgets(tanggal, MAX_LEN, stdin);
    strtok(tanggal, "\n");

    printf("Diagnosis yang dimiliki pasien:\n1. Dehidrasi\n2. Pusing\n3. Masuk Angin\n4. Keseleo\nPilih (1-4): ");
    int diag_choice;
    scanf("%d", &diag_choice);
    getchar();  // Consume newline

    switch (diag_choice) {
        case 1: strcpy(diagnosis, "Dehidrasi"); break;
        case 2: strcpy(diagnosis, "Pusing"); break;
        case 3: strcpy(diagnosis, "Masuk Angin"); break;
        case 4: strcpy(diagnosis, "Keseleo"); break;
        default: strcpy(diagnosis, ""); break;
    }

    printf("Tindakan yang diambil pasien:\n1. Vaksinasi\n2. Cek gula darah\n3. Pemasangan infus\n4. Pengobatan\nPilih (1-4): ");
    int tindakan_choice;
    scanf("%d", &tindakan_choice);
    getchar();  // Consume newline

    switch (tindakan_choice) {
        case 1: strcpy(tindakan, "Vaksinasi"); biaya_tindakan = 100000; break;
        case 2: strcpy(tindakan, "Cek gula darah"); biaya_tindakan = 25000; break;
        case 3: strcpy(tindakan, "Pemasangan infus"); biaya_tindakan = 125000; break;
        case 4: strcpy(tindakan, "Pengobatan"); biaya_tindakan = 125000; break;
        default: strcpy(tindakan, ""); biaya_tindakan = 0; break;
    }

    printf("Tanggal kontrol (dd-mm-yyyy): ");
    fgets(kontrol, MAX_LEN, stdin);
    strtok(kontrol, "\n");

    int biaya_total = 15000 + 125000 + biaya_tindakan;

    strncpy(dua[row][1], tanggal, MAX_LEN);
    strncpy(dua[row][3], diagnosis, MAX_LEN);
    strncpy(dua[row][4], tindakan, MAX_LEN);
    strncpy(dua[row][5], kontrol, MAX_LEN);
    snprintf(dua[row][6], MAX_LEN, "%d", biaya_total);

    printf("Entry telah diupdate.\n");
}

#fungsi delete
void deleteEntry() {
    char id[MAX_LEN];
    printf("Masukkan ID pasien: ");
    fgets(id, MAX_LEN, stdin);
    strtok(id, "\n");

    int row = findPasien(id);
    if (row == -1) {
        printf("ID Pasien tidak ditemukan.\n");
        return;
    }

    for (int i = 0; i < MAX_COLS_2; ++i) {
        dua[row][i][0] = '\0';
    }

    printf("Entry telah diupdate.\n");
}

#fungsi display
void displayEntry() {
    char id[MAX_LEN];
    printf("Masukkan ID pasien: ");
    fgets(id, MAX_LEN, stdin);
    strtok(id, "\n");

    int row = findPasien(id);
    if (row == -1) {
        printf("ID Pasien tidak ditemukan.\n");
        return;
    }

    printf("RIWAYAT PASIEN %s\n", id);
    printf("Pasien datang di klinik X pada tanggal : %s\n", dua[row][1]);
    printf("Diagnosis yang dimiliki pasien: %s\n", dua[row][3]);
    printf("Tindakan yang diberikan ke pasien: %s\n", dua[row][4]);
    printf("Tanggal kontrol: %s\n", dua[row][5]);
}

#main dari file ini
void crud_ket_pasien() {
    printf("Pilih operasi apa yang akan dilakukan:\n1. Penambahan\n2. Pengubahan\n3. Penghapusan\n4. Menampilkan informasi\nPilihan: ");
    int choice;
    scanf("%d", &choice);
    getchar();  // Consume newline

    switch (choice) {
        case 1: addEntry(); break;
        case 2: updateEntry(); break;
        case 3: deleteEntry(); break;
        case 4: displayEntry(); break;
        default: printf("Operasi tidak valid.\n"); break;
    }
}
