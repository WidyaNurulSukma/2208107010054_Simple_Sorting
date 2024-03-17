**Cara menjalankan code program**

1. Pertama-tama setelah code sudah dengan ekstensi “.c” kita lakukan compile dulu pada terminal, gcc 2208107010054_Simple_Sorting.c -o 2208107010054_Simple_Sorting
2. Selanjutkan jika compile telah selesai tanpa kesalahan, kita bisa menjalankan (run) code-nya dengan perintah ./2208107010054_Simple_Sorting
3. Setelah selesai di run, code akan menampilkan outputnya pada terminal, dan akan membuat 2 file otomatis dengan nama “unsorted.txt” dan “sorted.txt” yang dimana unsorted berisi data sebelum pengurutan dan sorted yang berisi data setelah pengurutan berdasarkan algoritma pengurutannya.
4.  Setelah file dijalankan, dapat dilihat pada kedua txt tersebut perbedaan sebelum dan sesudah pengurutan


**Fungsi yang digunakan pada code program**

1.	Fungsi generateRandomNumbers
Fungsi ini digunakan untuk menghasilkan bilangan acak dalam array. Menerima array sebagai parameter dan mengisi array tersebut dengan bilangan acak.	
2.	Fungsi bubbleSort
Fungsi ini menerapkan algoritma Bubble Sort untuk mengurutkan array. Bubble Sort adalah salah satu algoritma pengurutan sederhana yang berulang kali melintasi daftar, membandingkan setiap elemen berpasangan, dan menukar mereka jika berada dalam urutan yang salah.
3.	Fungsi selectionSort
Fungsi ini menerapkan algoritma Selection Sort untuk mengurutkan array. Selection Sort mencari elemen minimum dari daftar dan menukarnya dengan elemen pertama. Kemudian, itu mencari elemen minimum dari sisa daftar dan menukarnya dengan elemen kedua, dan begitu seterusnya.
4.	Fungsi insertionSort
Fungsi ini menerapkan algoritma Insertion Sort untuk mengurutkan array. Insertion Sort memisahkan array menjadi dua bagian, yaitu bagian yang sudah diurutkan dan bagian yang belum diurutkan. Pada setiap iterasi, algoritma memilih satu elemen dari bagian yang belum diurutkan dan menempatkannya ke posisi yang tepat dalam bagian yang sudah diurutkan.
5.	Fungsi copyArray
Fungsi ini menyalin isi dari array sumber ke array tujuan. Ini berguna untuk membuat salinan dari array, misalnya ketika ingin mempertahankan salinan array asli sebelum diurutkan untuk membandingkannya dengan array yang sudah diurutkan.
6.	Fungsi performSort
Fungsi ini bertanggung jawab untuk menjalankan algoritma pengurutan yang diberikan sebagai argumen dan mencatat waktu eksekusinya. Fungsi ini mencetak nama algoritma, ukuran array, dan waktu eksekusi ke layar dan juga mencatat array yang sudah diurutkan ke dalam file yang diberikan.
