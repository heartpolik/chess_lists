#include <iostream>
#include <stdio.h>

using namespace std;

enum letters
{
    a = 0,
    b,
    c,
    d,
    e,
    f,
    g,
    h
};

struct element
{
    int x = 0;
    int y = 0;
    char type = '!';
    element* next = NULL;
};

 element* const whiteHead = new element;
 element* const blackHead = new element;

void push()
{

}

void pop(){}

void printList(element* head)
{
    while(head->next!=NULL)
    {
        printf("%c %i x %i\n",head->type,head->x,head->y);
        head=head->next;
    };
    printf("%c %i x %i\n",head->type,head->x,head->y);
}

void append(element* head, char val, int x, int y)
{
    while (head->next!=NULL)
    {
        head=head->next;
    };
    element *temp = new element;
    head->next = temp;
    temp->type=val;
    temp->x=x;
    temp->y=y;
}

void clearList(element* head)
{
    element* prevHead = NULL;
    element* mainHead = NULL;
    mainHead = head;
    while(head->next!=NULL)
    {
        prevHead=head;
        head=head->next;
        delete(prevHead);
    };
    delete(head);
    mainHead = new element;
}

bool readMap()
{
    static FILE *task = fopen("d:/projects/clion/chess_lists/desks.txt","r");
    static bool endFlag;
    char tmp;
    int h = 8;
    int w = 8;
    element* tmpPtr = whiteHead;

    endFlag=true;

    for (int i=0;i<h;++i)
    {
        for (int j=0;j<w;++j)
        {
            fscanf(task,"%c",&tmp);
            if (tmp!='.')
            {
                endFlag=false;
                //===lists=magic===
                if ((int)tmp>96)
                {
                    tmpPtr = blackHead;
                }
                else
                {
                    tmpPtr = whiteHead;
                };
                if (tmp == 'K' || tmp == 'k')
                {
                    tmpPtr->x = j;
                    tmpPtr->y = i;
                    tmpPtr->type = tmp;
                    continue;
                };
                append(tmpPtr,tmp,j,i);
            };

        };
        fscanf(task,"%c",&tmp);
    };
    fscanf(task,"%c",&tmp);
    return endFlag;
};
int main() {
    cout << "Hello, World!" << endl;

    while(!readMap())
    {
        printList(whiteHead);
        printf("\n");
        printList(blackHead);
        printf("\n\n\n");
        clearList(whiteHead);
        clearList(blackHead);

    };
    getchar();
    return 0;
}