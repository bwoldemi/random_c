#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Structure to represent a
typedef struct list_node
{
    uint32_t id; 
    void* data;                  // Data associated with the
    struct list_node *next; // Pointer to the next  in the list
} list_node;

static int insert_data(list_node **t_storage, uint32_t id , void *data)
{

    list_node *new_data;
    new_data = (list_node *)malloc(sizeof(list_node));

    if (new_data == NULL)
    {
        printf("Data is not allowed\n");
        return -1;
    }
    new_data->data = data;
    new_data->next = NULL;

    if (*t_storage == NULL)
    {
        *t_storage = new_data;

        return -1;
    }

    list_node *current = *t_storage;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = new_data;

    return 0;
}

list_node *find_node(list_node **t_storage, int id)
{
    list_node *temp = *t_storage;

    while (temp != NULL)
    {
        if (temp->data == id)
        {
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}

static int del_node(list_node **t_storage, int id)
{
    list_node *prev = NULL;
    list_node *current = *t_storage;

    while (current != NULL)
    {
        if (current->data == id)
        {
            if (prev == NULL)
            {
                *t_storage = current->next;
            }
            else
            {
                prev->next = current->next;
            }

            free(current);
            return 0;
        }

        prev = current;
        current = current->next;
    }

    return -1;
}

int free_storage(list_node **t_storage)
{
    list_node *temp = *t_storage;

    while (temp != NULL)
    {
        list_node *t = temp;
        temp = temp->next;
        free(t);
    }
    *t_storage = NULL;

    return 0;
}

static void print_all_data(list_node **t_storage)
{
    if (*t_storage == NULL)
    {
        printf("storage is Empty \n");
    }

    list_node *t = *t_storage;
    while (t != NULL)
    {
        printf("%d\n", t->data);
        t = t->next;
    }
}

int main()
{
    list_node *t_storage = NULL;

    printf("is complted \n");
    for (int i = 0; i < 10; i++)
    {
        add_timer_list(&t_storage, i);
    }
    print_t_storage(&t_storage);
    del_timer(&t_storage, 2);

    printf("\n");

    print_t_storage(&t_storage);

    list_node * temp ;
    temp  = find_node(&t_storage, 2);

     if(temp != NULL){
         printf("\n Node found %d\n", temp->data);
     }

    temp = find_node(&t_storage, 2);
    print_t_storage(&t_storage);
    if(temp != NULL){
        printf("Node found %d\n", temp->data);
    }else{
        printf("Not found\n");
    }

    free_storage(&t_storage);

    return 0;
}
