#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stock
{
    char code[10];
    char name[50];
    int amount;
    struct Stock *prev;
    struct Stock *next;
} Stock;

typedef struct StockList
{
    Stock *head;
} StockList;

void init(StockList *list)
{
    list->head = NULL;
}

void addStock(StockList *list, char *code, char *name, int amount)
{
    Stock *new_stock = (Stock *)malloc(sizeof(Stock));
    strcpy(new_stock->code, code);
    strcpy(new_stock->name, name);
    new_stock->amount = amount;
    new_stock->prev = NULL;
    new_stock->next = NULL;

    if (list->head == NULL)
    {
        list->head = new_stock;
    }
    else
    {
        Stock *temp = list->head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = new_stock;
        new_stock->prev = temp;
    }
    printf("Barang %s telah ditambahkan.\n", name);
}

void showStock(StockList *list)
{
    Stock *temp = list->head;
    printf("Daftar Barang:\n");
    while (temp)
    {
        printf("Kode: %s, Nama: %s, Stok: %d\n", temp->code, temp->name, temp->amount);
        temp = temp->next;
    }
}

int main()
{
    StockList stockList;
    init(&stockList);

    int selected, stockAmountInput;
    char stockCodeInput[10], stockNameInput[50];

    do
    {
        printf("\nMenu:\n");
        printf("1. Tambah Barang\n");
        printf("2. Hapus Barang\n");
        printf("3. Update Stok\n");
        printf("4. Tampilkan Barang\n");
        printf("5. Cari Barang\n");
        printf("6. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &selected);
        getchar();

        switch (selected)
        {
        case 1:
            printf("Masukkan kode barang: ");
            scanf("%s", stockCodeInput);
            printf("Masukkan nama barang: ");
            getchar();
            fgets(stockNameInput, sizeof(stockNameInput), stdin);
            stockNameInput[strcspn(stockNameInput, "\n")] = 0;
            printf("Masukkan stok barang: ");
            scanf("%d", &stockAmountInput);
            addStock(&stockList, stockCodeInput, stockNameInput, stockAmountInput);
            break;
        case 4:
            showStock(&stockList);
            break;
        default:
            printf("Pilihan tidak valid.\n");
        }
    } while (selected != 6);

    return 0;
}
