#include <stdio.h>

#include <conio.h>

typedef struct{
	char *nama;
	char *kelas;
	char *jurusan;
	
}
mahasiswa;

void pert1()
{
mahasiswa obj;

obj.nama = "Ajay Alfredo Almani";
obj.kelas = "2IA16";
obj.jurusan = "Teknik Informatika";

printf("%s \n", obj.nama);
printf("%s \n", obj.kelas);
printf("%s \n", obj.jurusan);
getch();

    int npm [8] = {5,0,4,2,0,0,9,3};
    int i;
    for (i=0;i<8;i++)
    {
        printf("%d", npm[i]);
    }
    printf("\n");
}
