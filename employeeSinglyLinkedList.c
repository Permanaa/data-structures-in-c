#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 5

typedef struct Employee
{
  int id;
  char name[31];
  char birthPlace[31];
  char birthDate[11];
  char position[51];
  struct Employee *next;
} Employee;

Employee *head = NULL;
int count = 0;

Employee *createEmployee(int id, char name[], char birthPlace[], char birthDate[], char position[])
{
  Employee *newEmployee = (Employee *)malloc(sizeof(Employee));
  newEmployee->id = id;
  strcpy(newEmployee->name, name);
  strcpy(newEmployee->birthPlace, birthPlace);
  strcpy(newEmployee->birthDate, birthDate);
  strcpy(newEmployee->position, position);
  newEmployee->next = NULL;
  return newEmployee;
}

void pushEmployee()
{
  printf("\n");
  if (count >= MAX_EMPLOYEES)
  {
    printf("!!! Database penuh! Maksimal %d karyawan. !!!\n", MAX_EMPLOYEES);
    return;
  }

  int id;
  char name[31], birthPlace[31], birthDate[11], position[51];

  printf("Masukkan Employee ID (max 5 angka): ");
  scanf("%d", &id);
  if (id < 0 || id > 99999)
  {
    printf("\n");
    printf("!!! Employee ID tidak valid! !!!\n");
    return;
  }
  getchar();

  printf("Masukkan Nama Lengkap (max 30 karakter): ");
  fgets(name, sizeof(name), stdin);
  name[strcspn(name, "\n")] = 0;

  printf("Masukkan Tempat Lahir (max 30 karakter): ");
  fgets(birthPlace, sizeof(birthPlace), stdin);
  birthPlace[strcspn(birthPlace, "\n")] = 0;

  printf("Masukkan Tanggal Lahir (dd-mm-yyyy): ");
  scanf("%10s", birthDate);
  getchar();

  printf("Masukkan Jabatan (max 50 karakter): ");
  fgets(position, sizeof(position), stdin);
  position[strcspn(position, "\n")] = 0;

  Employee *newEmployee = createEmployee(id, name, birthPlace, birthDate, position);

  if (!head || head->id > id)
  {
    newEmployee->next = head;
    head = newEmployee;
  }
  else
  {
    Employee *temp = head;
    while (temp->next && temp->next->id < id)
    {
      temp = temp->next;
    }
    newEmployee->next = temp->next;
    temp->next = newEmployee;
  }
  count++;
  printf("\n");
  printf("=== Data karyawan berhasil ditambahkan! ===\n");
}

void displayEmployees()
{
  printf("\n");
  if (!head)
  {
    printf("!!! Database kosong! !!!\n");
    return;
  }
  printf("+-------+------------------------------+------------------------------+------------+----------------------------------------------------+\n");
  printf("|  ID   | Nama                         | Tempat Lahir                 | Tgl Lahir  | Jabatan                                            |\n");
  printf("+-------+------------------------------+------------------------------+------------+----------------------------------------------------+\n");
  Employee *temp = head;
  while (temp)
  {
    printf("| %-5d | %-28s | %-28s | %-10s | %-50s |\n", temp->id, temp->name, temp->birthPlace, temp->birthDate, temp->position);
    temp = temp->next;
  }
  printf("+-------+------------------------------+------------------------------+------------+----------------------------------------------------+\n");
}

void deleteEmployee()
{
  printf("\n");
  if (!head)
  {
    printf("!!! Database kosong! !!!\n");
    return;
  }

  int id;
  printf("Masukkan Employee ID yang akan dihapus: ");
  scanf("%d", &id);

  if (!head)
    return;
  if (head->id == id)
  {
    Employee *temp = head;
    head = head->next;
    free(temp);
    count--;
    printf("\n");
    printf("=== Data karyawan berhasil dihapus! ===\n");
    return;
  }

  Employee *curr = head;
  while (curr->next && curr->next->id != id)
  {
    curr = curr->next;
  }

  if (!curr->next)
  {
    printf("\n");
    printf("!!! Karyawan dengan ID %d tidak ditemukan! !!!\n", id);
    return;
  }

  Employee *temp = curr->next;
  curr->next = temp->next;
  free(temp);
  count--;
  printf("\n");
  printf("=== Data karyawan berhasil dihapus! ===\n");
}

void deleteAllEmployees()
{
  Employee *temp;
  while (head)
  {
    temp = head;
    head = head->next;
    free(temp);
  }
  count = 0;
  printf("\n");
  printf("=== Semua data karyawan telah dihapus! ===\n");
}

int main()
{
  int choice;
  do
  {
    printf("\nMenu:\n");
    printf("1. Tambah Karyawan\n");
    printf("2. Tampilkan Karyawan\n");
    printf("3. Hapus Karyawan\n");
    printf("4. Hapus Semua Data Karyawan\n");
    printf("5. Keluar\n");
    printf("Pilihan Anda: ");
    scanf("%d", &choice);
    getchar();

    switch (choice)
    {
    case 1:
      pushEmployee();
      break;
    case 2:
      displayEmployees();
      break;
    case 3:
      deleteEmployee();
      break;
    case 4:
      deleteAllEmployees();
      break;
    case 5:
      printf("\n");
      printf("=== Keluar dari program... ===\n");
      break;
    default:
      printf("\n");
      printf("!!! Pilihan tidak valid! !!!\n");
    }
  } while (choice != 5);

  return 0;
}
