#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Structure to represent a
typedef struct list_node
{
    uint32_t id;
    int data;               // Data associated with the
    struct list_node *next; // Pointer to the next  in the list
} list_node;

static list_node *t_storage = NULL;

static int insert_data( uint32_t id, int data)
{

    list_node *new_data;
    new_data = (list_node *)malloc(sizeof(list_node));

    if (new_data == NULL)
    {
        printf("Data is not allowed\n");
        return -1;
    }
    new_data->data = data;
    new_data->id = id;
    new_data->next = NULL;

    if (t_storage == NULL)
    {
        t_storage = new_data;

        return -1;
    }

    list_node *current = t_storage;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = new_data;

    return 0;
}

list_node *find_node(int id)
{
    list_node *temp = t_storage;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}

static int del_node(int id)
{
    list_node *prev = NULL;
    list_node *current = t_storage;

    while (current != NULL)
    {
        if (current->id == id)
        {
            if (prev == NULL)
            {
                t_storage = current->next;
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

int free_storage()
{
    list_node *temp = t_storage;

    while (temp != NULL)
    {
        list_node *t = temp;
        temp = temp->next;
        free(t);
    }
    t_storage = NULL;

    return 0;
}

static void print_all_data()
{
    if (t_storage == NULL)
    {
        printf("storage is Empty \n");
    }

    list_node *t = t_storage;
    while (t != NULL)
    {
        printf("id: %d data:%d\n", t->id, t->data);
        t = t->next;
    }
}

int main()
{
    

    insert_data( 1,1);
    insert_data( 2,2);
    insert_data( 3,3);
    insert_data( 4,4);

    print_all_data();

    del_node(3);
    printf("After deleting node 3\n");
    print_all_data(&t_storage);


    del_node(2);
    printf("After deleting node 2\n");
    print_all_data();

    free_storage();

    return 0;
}
