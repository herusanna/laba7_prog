#include <iostream>
#include <stack> 
#include <queue> 
//#define STACK_SIZE          10
#include <cstdlib>
using namespace std;

#define QMAX 100
struct Queue {
    int qu[QMAX];
    int rear, frnt;
};
void init(struct Queue* q) {
    q->frnt = 1;
    q->rear = 0;
    return;
}
void insert(struct Queue* q, int x) {
    if (q->rear < QMAX - 1) {
        q->rear++;
        q->qu[q->rear] = x;
    }
    else
        printf("Очередь полна!\n");
    return;
}
int isempty(struct Queue* q) {
    if (q->rear < q->frnt)    return 1;
    else  return 0;
}
void print(struct Queue* q) {
    int h;
    //if (isempty(q) == 1) {
    //    printf("Очередь пуста!\n");
    //    return;
    //}
    for (h = q->frnt; h <= q->rear; h++)
        printf("%d ", q->qu[h]);
    return;
}
int remove(struct Queue* q) {
    int x;
    if (isempty(q) == 1) {
        printf("Очередь пуста!\n");
        return(0);
    }
    x = q->qu[q->frnt];
    q->frnt++;
    return x;
}
void Add(struct Queue* q, int value) //добавление элемента
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
    struct Queue* q;
    int a,value;
    int first, last;
    setlocale(LC_ALL, "Russian");
    q = (Queue*)malloc(sizeof(Queue));
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
        first = q->frnt;
        last = q->rear;

        cout << "Новые первый и последний элементы очереди: " << first << ", " << last << endl;

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
            for (int i = 0; i < 2;i++)
            {
                sum += arr[i];
            }
            cout << "Сумма элементов: " << sum << endl << endl;
        }   
    }
}
void lvl3() {
    /*Данo число (N>0) 2 непустые очереди, адреса их первого и последнего элементов P1, P2 и P3, P4 соответственно.
    Переместить N начальных элементов первой очереди в конец второй очереди.
    Если первая очередь содержит меннее N элементов, то переместить из первой очереди во вторую все элементы.
    Вывести новые адреса начала и конца первой, а затем второй очереди( для пустой дважды вывести null).
    Операции выделения и освобождения памяти не использовать.*/
    setlocale(LC_ALL, "Russian");
    queue <int> Numbers_1, Numbers_2;

    int* P1, * P2, * P3, * P4, arr[10], count = 0;
    for (int i = 0; i < 10; i++)
    {
        Numbers_1.push(rand() % 3);
        if (i == 0)
        {
            cout << "Элементы 1-ой очереди: ";
        }
        cout << Numbers_1.back() << " ";
    }
    cout << endl << endl;
    for (int i = 0; i < 10; i++)
    {
        Numbers_2.push(rand() % 3 + 3);
        if (i == 0)
        {
            cout << "Элементы 2-ой очереди: ";
        }
        cout << Numbers_2.back() << " ";
    }
    //присваиваем адреса и выводим их;
    P1 = &Numbers_1.front();
    P2 = &Numbers_1.back();
    P3 = &Numbers_2.front();
    P4 = &Numbers_2.back();

    cout << endl << endl << "Адреса первого и последнего элементов обеих очередей соответственно: " << P1 << ", " << P2 << ", " << P3 << ", " << P4 << endl << endl;
    //считаем кол-во четных элементов первой очереди;
    int N;
    cin >> N;

        for (int i = 0; i < N; i++)
        {
            arr[i] = Numbers_1.back();
            Numbers_1.pop();
        }
        for (int i = 0; i < N; i++)
        {
            Numbers_2.push(arr[i]);
        }
        for (int i = 0; i < 10+N;i++)
        {
            cout << Numbers_2.back() << " ";
            arr[i] = Numbers_2.back();
            Numbers_2.pop();
            i++;
            if (sizeof(arr[i]) > N)
                goto next;
            else break;
        }
       
        do
        {
            Numbers_2.push(Numbers_1.front());
            Numbers_1.pop();
        } while (!Numbers_1.empty());
    next:
    if (Numbers_1.empty())
    {
        P1 = nullptr;
        P2 = nullptr;

        cout << "Первая очередь пуста, адреса первого и последнего элементов: " << P1 << ", " << P2 << endl << endl;
    }
    else
    {
        P1 = &Numbers_1.front();
        P2 = &Numbers_1.back();

        cout << "Адреса нового первого и последнего элементов 1-ой очереди: " << P1 << ", " << P2 << endl;
        cout << "Элементы первой очереди после изменений: ";

        do
        {
            cout << Numbers_1.front() << " ";
            Numbers_1.pop();
        } while (!Numbers_1.empty());

        cout << endl << endl;
    }

    P3 = &Numbers_2.front();
    P4 = &Numbers_2.back();

    cout << "Адреса нового первого и последнего элементов 2-ой очереди: " << P3 << ", " << P4 << endl;
    cout << "Элементы второй очереди после изменений: ";

    do
    {
        cout << Numbers_2.front() << " ";
        Numbers_2.pop();
    } while (!Numbers_2.empty());

    cout << endl << endl;
}
int main() {
    
    setlocale(LC_ALL, "Russian");
    int varForSwitch;
    cout << "Выберите уровень сложности :" << endl << "1. Легкий" << endl << "2. Базовый" << endl << "3. Сложный \n";
    cin >> varForSwitch;
    switch (varForSwitch)
    {
    case 1:
        lvl1();
        break;
    case 2:
        lvl2();
        break;
    case 3:
        lvl3();
        break;
    default:
        cout << "Error 404! Action not found." << endl;
        break;
    }
    system("pause");
    return 0;
}

