#include"total.h"
#include<chrono>
#include <map>
void InitQueue(LinkQueue& Q) {
    Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
    Q.front->next = NULL;
    Q.rear->next = NULL;
}
void EnQueue(LinkQueue& Q, SqList e) {
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    p->S = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
}
void Dequeue(LinkQueue& Q, SqList& e) {
    if (Q.front == Q.rear) printf("�ն���");
    QueuePtr p = Q.front->next;
    e = p->S;
    Q.front->next = p->next;
    if (p == Q.rear) Q.rear = Q.front;
    free(p);
}
bool iskong(LinkQueue Q) {
    if (Q.front == Q.rear)
        return true;
    else return false;
}
void DeepCopySqList(const SqList& src, SqList& dest) {
    dest.length = src.length;  // ���Ƴ�����Ϣ

    dest.T = new RedType[src.length];  // ΪĿ��T�����µ��ڴ�ռ�

    for (int i = 0; i < src.length; i++) {
        dest.T[i] = src.T[i];  // �������RedType������
    }
}


void generateRandomData(const char* filename, int num)
{
    ofstream outFile(filename);
    if (outFile.is_open())
    {
        srand(time(NULL));
        for (int i = 0; i < num; ++i)
        {
            int val = rand() % 1000;
            outFile << val << endl;
        }
        outFile.close();
    }
    else {
        std::cout << "�޷��򿪻򴴽��ļ���" << std::endl;
    }


}


void readDataFromFile(const char* filename, SqList& s)
{
    ifstream inFile(filename);
    if (inFile.is_open())
    {
        for (int i = 1; i < s.length; i++)
        {
            inFile >> s.T[i].key; // ���ļ��ж�ȡÿ����������洢��������
        }

        inFile.close(); // �ر��ļ�
    }
    else {
        std::cout << "�޷����ļ���" << std::endl;
    }

    inFile.close();
}
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}
int main() {
    map<double, string> numToString;
    map<int, string>T1;
    map<int, string>T2;
    srand(time(0)); 
    static int i = 0;
    SqList Q1, Q2, Q3, Q4, Q5, Q6, Q7, Q8, Q9, Q10;
    Q1.T = new RedType[2000000];
    Q2.T = new RedType[2000000];
    Q3.T = new RedType[2000000];
    Q4.T = new RedType[2000000];
    Q5.T = new RedType[2000000];
    Q6.T = new RedType[2000000];
    Q7.T = new RedType[2000000];
    Q8.T = new RedType[2000000];
    Q9.T = new RedType[2000000];
    Q10.T = new RedType[2000000];
    SqList N1, N2, N3;
    N1.length = 1001;
    N2.length = 10001;
    N3.length = 100001;
    N1.T = new RedType[2000000];
    N2.T = new RedType[2000000];
    N3.T = new RedType[2000000];
    int t1[100];
    int t2[100];
    static int a = 0;
    static int b = 0;
    string s = "yes";
    cout << "��ѡ������������ݻ����ļ��ڵ����ݣ�1/2):";
    int flag = 0;
    cin >> flag;
    if (flag == 1) {
        Q1.length = Q2.length = Q3.length = Q4.length = Q5.length = Q6.length = Q7.length = Q8.length = Q9.length = Q10.length = 501;
        for (int j = 0; j < 500; j++) {
            Q1.T[j + 1].key = rand() % 1000;
            Q2.T[j + 1].key = rand() % 1000;
            Q3.T[j + 1].key = rand() % 1000;
            Q4.T[j + 1].key = rand() % 1000;
            Q5.T[j + 1].key = rand() % 1000;
            Q6.T[j + 1].key = rand() % 1000;
            Q7.T[j + 1].key = rand() % 1000;
            Q8.T[j + 1].key = rand() % 1000;
            Q9.T[j + 1].key = rand() % 1000;
            Q10.T[j + 1].key = rand() % 1000;
        }



        int compareCount = 0;
        int moveCount = 0;

        LinkQueue Q;
        InitQueue(Q);
        //    cout << 666;
        EnQueue(Q, Q1);

        EnQueue(Q, Q2);
        EnQueue(Q, Q3);
        EnQueue(Q, Q4);
        EnQueue(Q, Q5);
        EnQueue(Q, Q6);
        EnQueue(Q, Q7);
        EnQueue(Q, Q8);
        EnQueue(Q, Q9);
        EnQueue(Q, Q10);
        cout << "<1�����۰��������,2�����������,3����ð������,4���������,5�����������>"<<endl;
        while (s == "yes") {
            SqList M;
            Dequeue(Q, M);
            int choice;
            cout << "������1/2/3/4/5��ѡ����Ҫʹ�õ����򷽷�:";
            cin >> choice;
            switch (choice) {
            case 1:
                cout << "�۰��������������:" << endl;
                BinsertSort(M, compareCount, moveCount);
                for (int t = 1; t <= 500; t++) {
                    cout << M.T[t].key << " ";
                    if (t % 10 == 0) cout << endl;
                }
                t1[a] = compareCount;
                T1[t1[a]] = "�۰��������";
                    a++;
                t2[b] = moveCount;
                T2[t2[b]] = "�۰��������";
                    b++;
                break;
            case 2:
                cout << "��������������:" << endl;
                Qsort(M, 1, M.length - 1, compareCount, moveCount);
                for (int t = 1; t <= 500; t++) {
                    cout << M.T[t].key << " ";
                    if (t % 10 == 0) cout << endl;
                }
                t1[a] = compareCount;
                T1[t1[a]] = "��������";
                a++;
                t2[b] = moveCount;
                T2[t2[b]] = "��������";
                b++;
                break;
            case 3:
                cout << "ð������������:" << endl;
                bubblesort(M, compareCount, moveCount);
                for (int t = 1; t <= 500; t++) {
                    cout << M.T[t].key << " ";
                    if (t % 10 == 0) cout << endl;
                }
                t1[a] = compareCount;
                T1[t1[a]] = "ð������";
                a++;
                t2[b] = moveCount;
                T2[t2[b]] = "ð������";
                b++;
                break;
            case 4:
                cout << "������������:" << endl;
                HeapSort(M, M.length - 1, compareCount, moveCount);
                for (int t = 1; t <= 500; t++) {
                    cout << M.T[t].key << " ";
                    if (t % 10 == 0) cout << endl;
                }
                t1[a] = compareCount;
                T1[t1[a]] = "������";
                a++;
                t2[b] = moveCount;
                T2[t2[b]] = "������";
                b++;
                break;
            case 5:
                cout << "��������������:" << endl;
                radixsort(M, M.length, compareCount, moveCount);
                for (int t = 1; t <= 500; t++) {
                    cout << M.T[t].key << " ";
                    if (t % 10 == 0) cout << endl;
                }
                t1[a] = compareCount;
                T1[t1[a]] = "��������";
                a++;
                t2[b] = moveCount;
                T2[t2[b]] = "��������";
                b++;
                break;
            }

            cout << "Group " << ++i << ":" << endl;
            cout << "Compare Count: " << compareCount << endl;
            cout << "Move Count: " << moveCount << endl;
            cout << endl;
            compareCount = 0;
            moveCount = 0;
            cout << "�Ƿ���Ҫ��������(yes/no)(���ɳ���ʮ��):";
            cin >> s;
        }
        selectionSort(t1, a);
        selectionSort(t2, b);
        cout << "���ڵ�ǰ������������㷨��'�Ƚϴ���'�û�����:";
        for (int i = 0; i < a; i++) {
            cout << T1[t1[i]] << " ";
        }
        cout << endl;
        cout << "���ڵ�ǰ������������㷨��'�ƶ�����'�û�����:";
        for (int i = 0; i < b; i++) {
            cout << T2[t2[i]] << " ";
        }
        cout << endl;
        system("pause");
    }
    else {
        static int f = 1;
        const char* filename1 = "E:\\���ݽṹ\\data1.txt";
        generateRandomData(filename1, 1000);
        const char* filename2 = "E:\\���ݽṹ\\data2.txt";
        generateRandomData(filename2, 10000);
        const char* filename3 = "E:\\���ݽṹ\\data3.txt";
        generateRandomData(filename3, 100000);
        readDataFromFile(filename1, N1);
        readDataFromFile(filename2, N2);
        readDataFromFile(filename3, N3);
        LinkQueue Q;
        InitQueue(Q);
        EnQueue(Q, N1);
        EnQueue(Q, N2);
        EnQueue(Q, N3);
        int compareCount = 0;
        int moveCount = 0;
       
        while (s == "yes"&& !iskong(Q)) {
            cout << endl;
            cout << "��" << f << "���ļ�������ͳ��:" << endl;
            SqList M;
            SqList M1;
            Dequeue(Q, M);
            DeepCopySqList(M, M1);
            auto start = std::chrono::steady_clock::now();
            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double> elapsed_seconds = end - start;
            
            


                cout << "1)�۰����������Խ������:" << endl;
                start = std::chrono::steady_clock::now();
                BinsertSort(M, compareCount, moveCount);
                end = std::chrono::steady_clock::now();
                elapsed_seconds = end - start;
                std::cout << "�۰������������ʱ�䣺" << elapsed_seconds.count() << " ��" << std::endl;
             //   M.t1 = std::chrono::duration_cast<std::chrono::duration<double>>(elapsed_seconds);
             //   numToString[static_cast<double>(M.t1.count())] = "�۰��������";
                M.t1 = elapsed_seconds.count();
                numToString[M.t1] = "�۰��������";
             DeepCopySqList(M1, M);
          
                cout << "2)����������Խ������:" << endl;
               
                start = std::chrono::steady_clock::now();
                Qsort(M, 1, M.length - 1, compareCount, moveCount);
                end = std::chrono::steady_clock::now();
                elapsed_seconds = end - start;
                std::cout << "������������ʱ�䣺" << elapsed_seconds.count() << " ��" << std::endl;
                M.t2 = elapsed_seconds.count();
               
                numToString[M.t2] = "��������";
                DeepCopySqList(M1, M);
                cout << "3)ð��������Խ������:" << endl;
                
                start = std::chrono::steady_clock::now();
                bubblesort(M, compareCount, moveCount);
                end = std::chrono::steady_clock::now();
                elapsed_seconds = end - start;
                std::cout << "ð����������ʱ�䣺" << elapsed_seconds.count() << " ��" << std::endl;
                M.t3 = elapsed_seconds.count();
          
                numToString[M.t3] = "ð������";
                DeepCopySqList(M1, M);
                cout << "4)��������Խ������:" << endl;
                start = std::chrono::steady_clock::now();
                HeapSort(M, M.length - 1, compareCount, moveCount);
                end = std::chrono::steady_clock::now();
                elapsed_seconds = end - start;
                std::cout << "����������ʱ�䣺" << elapsed_seconds.count() << " ��" << std::endl;
           
                M.t4 = elapsed_seconds.count();
                numToString[M.t4] = "������";
                DeepCopySqList(M1, M);
             
                cout << "5)����������Խ������:" << endl;
                start = std::chrono::steady_clock::now();
                radixsort(M, M.length, compareCount, moveCount);
                end = std::chrono::steady_clock::now();
                elapsed_seconds = end - start;
                std::cout << "������������ʱ�䣺" << elapsed_seconds.count() << " ��" << std::endl;
                M.t5 = elapsed_seconds.count();
                numToString[M.t5] = "��������";
             
                f++;
               
                double record[5] = { M.t1, M.t2, M.t3, M.t4, M.t5 };
                for (int i = 0; i < 4; i++) {
                    int minIndex = i;
                    for (int j = i + 1; j < 5; j++) {
                        if (record[j] < record[minIndex]) {
                            minIndex = j;
                        }
                    }
                    if (minIndex != i) {
                      
                        double temp = record[i];
                        record[i] = record[minIndex];
                        record[minIndex] = temp;
                    //    string tempName = numToString[record[i]];
                    //    numToString[record[i]] = numToString[record[minIndex]];
                    //    numToString[record[minIndex]] = tempName;
                    }
                }
           //     cout << record[2]<<endl;
           //     cout << numToString[record[2]]<<endl;
                cout << "���ڵ�ǰ�����ļ������㷨�û�����Ϊ:";
                for (int i = 0; i < 5; i++) {
                    cout << numToString[record[i]]<<" ";
                }
                cout << endl;
            }
            
        system("pause");
        }
       
    delete[]Q1.T;
    delete[]Q2.T;
    delete[]Q3.T;
    delete[]Q4.T;
    delete[]Q5.T;
    delete[]Q6.T;
    delete[]Q7.T;
    delete[]Q8.T;
    delete[]Q9.T;
    delete[]Q10.T;
    delete[]N1.T;
    delete[]N2.T;
    delete[]N3.T;
    return 0;
}
