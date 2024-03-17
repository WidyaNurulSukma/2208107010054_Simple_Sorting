//WIDYA NURUL SUKMA
//2208107010054
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fungsi untuk menghasilkan bilangan acak dalam array
void generateRandomNumbers(int *array, int size);
// Fungsi algoritma pengurutan Bubble Sort
void bubbleSort(int *array, int size);
// Fungsi algoritma pengurutan Selection Sort
void selectionSort(int *array, int size);
// Fungsi algoritma pengurutan Insertion Sort
void insertionSort(int *array, int size);
// Fungsi untuk menyalin isi array sumber ke array tujuan
void copyArray(int *source, int *destination, int size);
// Fungsi untuk menjalankan algoritma pengurutan dan mencatat waktu eksekusi
void performSort(const char *sortName, void (*sortFunction)(int*, int), int *data, int size, FILE *file);

int main() {
    int sizes[] = {100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000, 1000000};
    int n = sizeof(sizes) / sizeof(sizes[0]);

    srand(time(NULL)); // Inisialisasi seed RNG dengan waktu saat ini

    //Menampilkan tabel
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("|         Jenis Algoritma      |     Jumlah Bilangan     |           Waktu Eksekusi (ms)         |\n");
    printf("--------------------------------------------------------------------------------------------------\n");

    int max_size = sizes[n - 1];
    int *data = (int*)malloc(max_size * sizeof(int));
    generateRandomNumbers(data, max_size);

    // Membuka file untuk menyimpan data yang belum diurutkan dan yang telah diurutkan
    FILE *unsortedFile = fopen("unsorted.txt", "w");
    FILE *sortedFile = fopen("sorted.txt", "w");
    if (unsortedFile == NULL || sortedFile == NULL) {
        printf("Error opening file.\n");
        free(data);
        return -1;
    }

    for (int i = 0; i < n; i++) {
        int size = sizes[i];
        int *array = (int*)malloc(size * sizeof(int));
        copyArray(data, array, size);

        // Menulis data yang belum diurutkan ke file
        fprintf(unsortedFile, "\nSize: %d\n\n", size);
        fprintf(unsortedFile, "Unsorted:\n");
        for (int j = 0; j < size; j++) {
            fprintf(unsortedFile, "%d\n", array[j]);
        }

        // Pengurutan dengan algoritma Bubble Sort
        fprintf(sortedFile, "Size: %d\n", size);
        performSort("Bubble Sort", bubbleSort, array, size, sortedFile);

        // Mengembalikan array ke keadaan semula
        copyArray(data, array, size);

        // Pengurutan dengan algoritma Selection Sort
        performSort("Selection Sort", selectionSort, array, size, sortedFile);

        // Mengembalikan array ke keadaan semula
        copyArray(data, array, size);

        // Pengurutan dengan algoritma Insertion Sort
        performSort("Insertion Sort", insertionSort, array, size, sortedFile);

        free(array);
    }

    //Menutup file
    fclose(unsortedFile);
    fclose(sortedFile);
    free(data);
    return 0;
}
// Fungsi untuk menghasilkan bilangan acak dalam array
void generateRandomNumbers(int *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand();
    }
}

// Fungsi algoritma pengurutan Bubble Sort
void bubbleSort(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Fungsi algoritma pengurutan Selection Sort
void selectionSort(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[minIdx]) {
                minIdx = j;
            }
        }
        int temp = array[minIdx];
        array[minIdx] = array[i];
        array[i] = temp;
    }
}

// Fungsi algoritma pengurutan Insertion Sort
void insertionSort(int *array, int size) {
    for (int i = 1; i < size; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}
// Fungsi untuk menyalin isi array sumber ke array tujuan
void copyArray(int *source, int *destination, int size) {
    for (int i = 0; i < size; i++) {
        destination[i] = source[i];
    }
}

// Fungsi untuk menjalankan algoritma pengurutan dan mencatat waktu eksekusi
void performSort(const char *sortName, void (*sortFunction)(int*, int), int *data, int size, FILE *file) {
    clock_t start, end;
    double cpu_time_used;

    // Menulis nama algoritma ke file
    fprintf(file, "\n%s:\n", sortName);

    // Memulai penghitungan waktu eksekusi
    start = clock();
    sortFunction(data, size);
    end = clock();

    // Menghitung waktu eksekusi dalam milidetik
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC * 1000.0;
    // Menampilkan informasi waktu eksekusi ke layar
    printf("|       %-15s        |          %-7d        |           %-15f ms          |\n", sortName, size, cpu_time_used);
    printf("---------------------------------------------------------------------------------------------------\n");
    
    // Menulis data yang telah diurutkan ke file
    for (int i = 0; i < size; i++) {
        fprintf(file, "%d\n", data[i]);
    }
    // Menambahkan spasi sebelum data selanjutnya
    fprintf(file, "\n"); 
}
