#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stud_node {
     int    num;
     char   name[20];
     int    score;
     struct stud_node *next;
};

struct stud_node *createlist();
struct stud_node *deletelist( struct stud_node *head, int min_score );

int main()
{
    int min_score;
    struct stud_node *p, *head = NULL;

    head = createlist();
    scanf("%d", &min_score);
    head = deletelist(head, min_score);
    for ( p = head; p != NULL; p = p->next )
        printf("%d %s %d\n", p->num, p->name, p->score);

    system("pause");
    return 0;
}

/* 你的代码将被嵌在这里 */
struct stud_node* createlist()
{
    struct stud_node* dummy = (struct stud_node*)malloc(sizeof(struct stud_node));
    dummy->next = NULL;
    struct stud_node* curr = dummy;

    while(1)
    {
        char tempName[20] = {'0'};
        int tempNum = 0, tempScore = 0;
        scanf("%d", &tempNum);
        if(tempNum == 0)
        {
            break;
        }
        scanf("%s %d", &tempName, &tempScore);

        struct stud_node* newNd = (struct stud_node*)malloc(sizeof(struct stud_node));
        newNd->num = tempNum;
        newNd->score = tempScore;
        strcpy(newNd->name, tempName);
        newNd->next = NULL;
    
        curr->next = newNd;
        curr = curr->next;
    }

    struct stud_node* head = dummy->next;
    free(dummy);
    return head;
}

struct stud_node *deletelist( struct stud_node *head, int min_score )
{
    struct stud_node* dummy = (struct stud_node*)malloc(sizeof(struct stud_node));
    dummy->next = head;
    struct stud_node* prev = dummy;
    struct stud_node* curr = dummy->next;

    while(curr != NULL)
    {
        if(curr->score < min_score)
        {
            struct stud_node* temp = curr;
            curr = curr->next;
            prev->next = curr;
            temp->next = NULL;
            free(temp);
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }

    struct stud_node* newHead = dummy->next;
    free(dummy);
    return newHead;
}