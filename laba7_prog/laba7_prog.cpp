#include <iostream>
#include <stack> 
//#define STACK_SIZE          10
#include <cstdlib>
using namespace std;
struct list {
    int field;
    struct list* ptr;
};
struct Queue {
    struct list* frnt, * rear;
};
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


void lvl2() {
    /*Создать стек целочисленных значений, используя односвязные списки. Реализовать операции добавления (push) и удаления (pop) элемента из стека.
    Добавьте в стек числа 1, 2, 3, 4, 5 и распечатайте содержимое стека.
    Удалите 3 элемента из стека, и распечатайте содержимое стека еще раз. 
    Найдите сумму элементов из стека.*/
    setlocale(LC_ALL, "Russian");
    stack <int> Numbers;

    int arr[5],  sum=0;

    Numbers.push(1);  
    Numbers.push(2);
    Numbers.push(3);
    Numbers.push(4);
    Numbers.push(5);

    // проверка стека на пустоту;
    if (Numbers.empty())
    {
        cout << "Стек чист" << endl << endl;
    }

    else
    {
        cout << "Числа стека: ";

        // выводим значения стека, перед удалением записываем элемент в массив;
        for (int i = 0; i < 5;)
        {
            cout << Numbers.top() << " ";
            arr[i] = Numbers.top();
            Numbers.pop();
            i++;
        }

        cout << endl << endl;

        // считываем элементы массива в стек
        for (int i = 0; i < 5;)
        {
            Numbers.push(arr[i]);
            i++;
            
        }
        Numbers.pop();
        Numbers.pop();
        Numbers.pop();

        if (Numbers.empty())
        {
            cout << "Стек чист" << endl << endl;
        }

        else
        {
           
            for (int i = 0; i < 2;)
            {
                cout << Numbers.top() << " ";
                arr[i] = Numbers.top();
                Numbers.pop();
                i++;
            }
            cout << endl << endl;
            /*
            for (int i = 0; i < 2;)
            {
                Numbers.push(arr[i]);
                i++;
            }*/
            for (int i = 0; i < 2;i++)
            {
                sum += arr[i];
            }
            cout << "Сумма элементов: " << sum << endl << endl;
        }   
    }
   

}
int main() {
    //lvl1();
    lvl2();
    system("pause");
    return 0;
}

