#include <iostream>
//#include <queue> 
//#define STACK_SIZE          10
#include <cstdlib>
using namespace std;
/*
struct Queue
{
    int data[N]; //массив данных
    int first;
    int last; //указатель на конец
};*/
#define QMAX 100
struct queue {
    int qu[QMAX];
    int rear, frnt;
};
void init(struct queue* q) {
    q->frnt = 1;
    q->rear = 0;
    return;
}
void insert(struct queue* q, int x) {
    if (q->rear < QMAX - 1) {
        q->rear++;
        q->qu[q->rear] = x;
    }
    else
        printf("Очередь полна!\n");
    return;
}
int isempty(struct queue* q) {
    if (q->rear < q->frnt)    return 1;
    else  return 0;
}
void print(struct queue* q) {
    int h;
    if (isempty(q) == 1) {
        printf("Очередь пуста!\n");
        return;
    }
    for (h = q->frnt; h <= q->rear; h++)
        printf("%d ", q->qu[h]);
    return;
}
int remove(struct queue* q) {
    int x;
    if (isempty(q) == 1) {
        printf("Очередь пуста!\n");
        return(0);
    }
    x = q->qu[q->frnt];
    q->frnt++;
    return x;
}
void Add(struct queue* q, int value) //добавление элемента
{
    if (q->frnt < QMAX - 1) {
        q->frnt--;
        q->qu[q->frnt] = value;
    }
   else
       printf("Очередь полна!\n");
    return;
   
    cout << endl << "Элемент добавлен в очередь\n\n";
    return;
}

void lvl1() {
    /*   Дано число D и указатели P1 и P2 на начало и конец очереди, содержащей не менее двух элементов.
        Добавить элемент со значением D в конец очереди и извлечь из очереди первый(начальный) элемент.
        Вывести значение извлеченного элемента и новые адреса начала и конца очереди.
        После извлечения элемента из очереди освободить память, занимаемую этим элементом.
        */
    struct queue* q;
    int a,value;
    system("chcp 1251");
    system("cls");
    q = (queue*)malloc(sizeof(queue));
    init(q);
    print(q);
    printf("Введите элемент очереди: ");
    for (int i = 0; i < 8; i++) {
        cin >> a;
        insert(q, a);
    }
    cout << "\nВведите новое первое значение: ";
    cin >> value;
    Add(q, value);
    print(q);
        a = remove(q);
        printf("\nУдален элемент %d\n", a);
        print(q);
}

int main() {
    lvl1();
}


/*
setlocale(LC_ALL, "Rus");
   queue <int> num;
    int size, new_number, D = 0, firstElement;
restartSize:
    cout << "Введите кол-во чисел для ввода: ";
    while (!(cin >> size))
    {
        cout << "Wrong input" << endl;
        cin.clear();
        cin.ignore(65535, '\n');
    }
    cout << endl;
    cout << "Введите число D: ";
    while (!(cin >> D))
    {
        cout << "Wrong input" << endl;
        cin.clear();
        cin.ignore(65535, '\n');
    }
    cout << endl;
    if (size >= 2) {
        for (int i = 0; i < size; i++)
        {
            cout << "Число " << i + 1 << ": ";
            cin >> new_number;

           num.push(new_number);


            cout << endl;
        }
        for (int i = 0; i < size; i++)
        {
            cout << num.front() << " ";
            num.pop();
        }
        cout << "Самый первый элемент в очереди: " << num.front() << endl;
        num.pop();  // удаляем элемент из очереди

        cout << "Новый первый элемент (после удаления): " << num.front() << endl;
    }
    else {
        cout << "Размер должен быть больше или равен 2";
        goto restartSize;
    }







void Creation(Queue* Q) {  // инициализация очереди
    //Queue* Q;
    Q->last = 0;
    //return
}

bool Full(Queue* Q) //проверка очереди на пустоту
{
    if (Q->last == 0)
        return true;
    else
        return false;
}
void Add(Queue* Q) //добавление элемента
{
    if (Q->last == N) {
        cout << "\nОчередь заполнена\n\n"; return;
    }
    int value;
    cout << "\nЗначение > "; cin >> value;
    Q->data[Q->last++] = value;
    cout << endl << "Элемент добавлен в очередь\n\n";
}

bool Delete(Queue* Q) //удаление элемента
{
    for (int i = 0; i < Q->last && i < N; i++) //смещение элементов
        Q->data[i] = Q->data[i + 1]; Q->last--;
    return true;
}

void Top(Queue* Q) // вывод очереди
{
    int i = 0;
    while (i < Q->last) {
        cout << Q->data[i++] << " ";
    }
    cout << endl << endl;
}
struct Node
{
    //Item item;
    int Data;
    Node* Next;
    // TNode* Prev;
};
//typedef Node* PNode;
Node* front;    //начало очереди
Node* rear;     //конец очереди

struct Stack {
    int inf;
    Stack* next;
};

 Queue* Q;
    Creation(Q);
    char number;
    do {
        cout << "1. Добавить элемент" << endl;
        cout << "2. Удалить элемент" << endl;
        cout << "3. Вывести очередь" << endl;
        cout << "0. Выйти\n\n";
        cout << "Номер команды > ";
        cin >> number;

        switch (number)
        {
        case '1':
            Add(Q);
            break;

        case '2':
            if (Full(Q))
                cout << endl << "Очередь пуста\n\n";
            else {
                if (Full(Q)) cout << endl << "Очередь пуста\n\n";
                else
                    Delete(Q);
                cout << endl << "Элемент удален из очереди\n\n";
            }
            break;

        case '3':
            if (Full(Q))
                cout << endl << "Очередь пуста\n\n";
            else {
                cout << "\nОчередь: ";
                Top(Q);
                break;
            }

        case '0':
            break;

        default:
            cout << endl << "Команда не определена\n\n";
            break;
        }
    } while (number != '0');



void push(Stack*& head, int what) {
    Stack* new_el = new Stack();

    new_el->inf = what;

    if (head)
        new_el->next = head;

    head = new_el;
}

int pop(Stack*& head) {
    int what;

    auto del = head;

    what = head->inf;

    head = head->next;

    delete del;

    return what;
}

*/