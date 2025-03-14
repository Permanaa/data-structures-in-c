#include <stdio.h>
#include <stdlib.h>

struct data
{
  int no_absen;
  struct data *next;
  struct data *prev;
} *head = NULL, *tail = NULL, *curr;

void push(int newNoAbsen)
{
  curr = (struct data *)malloc(sizeof(struct data));
  curr->no_absen = newNoAbsen;

  if (head == NULL)
  {
    head = curr;
    tail = curr;
    head->next = head;
    head->prev = head;
  }
  else
  {
    tail->next = curr;
    curr->prev = tail;
    curr->next = head;
    head->prev = curr;
    tail = curr;
  }

  printf("Data %d berhasil ditambahkan.\n", newNoAbsen);
}

void pop()
{
  if (head == NULL)
  {
    printf("Gagal menghapus, list masih kosong!\n");
    return;
  }

  if (head == tail)
  {
    printf("Menghapus data terakhir: %d\n", head->no_absen);
    free(head);
    head = NULL;
    tail = NULL;
  }
  else
  {
    struct data *temp = tail;
    printf("Menghapus data: %d\n", temp->no_absen);
    tail = tail->prev;
    tail->next = head;
    head->prev = tail;
    free(temp);
  }
}

void display()
{
  if (head == NULL)
  {
    printf("List kosong, tidak ada data yang ditampilkan.\n");
    return;
  }

  struct data *temp = head;
  printf("Isi Circular Doubly Linked List: ");
  do
  {
    printf("%d ", temp->no_absen);
    temp = temp->next;
  } while (temp != head);
  printf("\n");
}

int main()
{
  display();

  printf("\n");
  push(10);
  push(20);
  push(30);
  push(40);

  printf("\nSetelah menambahkan beberapa data:\n");
  display();

  printf("\nMelakukan penghapusan data...\n");
  pop();
  pop();

  printf("\nSetelah penghapusan:\n");
  display();

  return 0;
}
