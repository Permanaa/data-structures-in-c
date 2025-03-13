#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int no_absen;
  struct Node *next;
};

struct Queue
{
  struct Node *front, *rear;
};

struct Queue *createQueue()
{
  struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
  q->front = q->rear = NULL;
  return q;
}

void push(struct Queue *q, int newNoAbsen)
{
  printf("Menambahkan no absen: %d\n", newNoAbsen);
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->no_absen = newNoAbsen;
  temp->next = NULL;

  if (q->rear == NULL)
  {
    q->front = q->rear = temp;
    return;
  }

  q->rear->next = temp;
  q->rear = temp;
}

void pop(struct Queue *q)
{
  if (q->front == NULL)
  {
    printf("Queue kosong! Tidak ada yang bisa dihapus.\n");
    return;
  }

  struct Node *temp = q->front;
  q->front = q->front->next;

  if (q->front == NULL)
  {
    q->rear = NULL;
  }

  printf("Menghapus no absen: %d\n", temp->no_absen);
  free(temp);
}

void display(struct Queue *q)
{
  struct Node *temp = q->front;
  if (temp == NULL)
  {
    printf("Queue kosong!\n");
    return;
  }
  printf("Isi queue: ");
  while (temp != NULL)
  {
    printf("%d ", temp->no_absen);
    temp = temp->next;
  }
  printf("\n");
}

int main()
{
  struct Queue *q = createQueue();

  printf("\n");
  display(q);

  printf("\n");
  push(q, 10);
  push(q, 20);
  push(q, 30);

  printf("\n");
  display(q);

  printf("\n");
  pop(q);

  printf("\n");
  display(q);

  return 0;
}
