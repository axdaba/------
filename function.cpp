#include"total.h"
int *temp=new int[2000000];
int bucket[10];
void BinsertSort(SqList& L, int& compare, int& move) {
    for (int i = 1; i < L.length; i++) {
        L.T[0] = L.T[i]; move++;
        int low = 1;
        int high = i - 1;
        while (low <= high) {
            compare++;
            int mid = (low + high) / 2;
            if (L.T[0].key < L.T[mid].key) high = mid - 1;
            else low = mid + 1;
        }
        for (int j = i - 1; j >= high + 1; j--) { L.T[j + 1] = L.T[j]; move++; }
        L.T[high + 1] = L.T[0]; move++;             //����Ҫ�����Ԫ��
    }
}
void HeapAdjust(SqList& R, int s, int m, int& comparecount, int& movecount) {
    int j;
    RedType rc = R.T[s];
    for (j = 2 * s; j <= m; j *= 2) {                   //�ҵ���ǰ�ڵ�����ӽڵ㡣
        if (j < m && R.T[j].key < R.T[j + 1].key)++j;       //��� j С�� m �����ӽڵ�ļ�ֵС�����ӽڵ�ļ�ֵ���� j ����1������Ϊ���ҵ������ӽڵ��м�ֵ�ϴ�Ľڵ㡣

        comparecount++;
        if (rc.key >= R.T[j].key)break;                         //�����ǰ�ڵ�ļ�ֵ���ڵ��������ӽڵ��м�ֵ�ϴ�Ľڵ㣬������ѭ����
        R.T[s] = R.T[j]; s = j;                                 //�������ӽڵ��м�ֵ�ϴ�Ľڵ��ֵ������ǰ�ڵ㡣���µ�ǰ�ڵ������Ϊ�����ӽڵ��м�ֵ�ϴ�Ľڵ��������
        movecount++;
    }
    R.T[s] = rc;                                                //��ԭʼ�ڵ��ֵ��������λ�õĽڵ㡣
}
void HeapSort(SqList& R, int n, int& comparecount, int& movecount) {
    int i;
    for (i = n / 2; i >= 1; i--)//�����һ����Ҷ�ӽڵ㿪ʼ�������ǰ���������յõ�һ���󶥶ѡ�
        HeapAdjust(R, i, n, comparecount, movecount);
    for (i = n; i > 1; i--) {
        Swap(R.T[1].key, R.T[i].key);
        movecount++;            //������߼���ÿ�ν��Ѷ������еĵ�һ��Ԫ�أ��뵱ǰ���һ��Ԫ�ؽ������������һ��Ԫ���ų����⣬�ٶ�ʣ�µĲ������µ���Ϊ�󶥶ѡ�ѭ��ֱ������Ԫ���������У����������̡�
        HeapAdjust(R, 1, i - 1, comparecount, movecount);
    }
}
void Swap(int& t1, int& t2) {
    int temp = t1;
    t1 = t2;
    t2 = temp;
    temp = 0;
}
int maxBit(SqList& data, int n, int& comparecount)
{
    //��n��Ԫ�ص����ֵ 
    int maxData = data.T[1].key;
    for (int i = 2; i < n; i++)
    {
        if (maxData < data.T[i].key)
            maxData = data.T[i].key;
        comparecount++;
    }

    //�����ֵ��λ���Ǽ�λ
    int d = 1;    //d�����������ֵ��λ����������1λ 
    while (maxData >= 10)  //����λ�� 
    {
        maxData /= 10;
        d++;
        comparecount++;
    }
    return d;
}

void radixsort(SqList& data, int n, int& comparecount, int& movecount)  //�������� 
{
    int d = maxBit(data, n, comparecount);  //������λ��
    int i, j, k;
    int radix = 1;
    for (i = 1; i <= d; i++)   //����d������
    {
        for (j = 0; j < 10; j++)   //��ռ�����
        {
            bucket[j] = 0;
        }
        for (j = 1; j < n; j++)    //ͳ��ÿ��Ͱ��Ԫ�ظ��� 
        {
            k = (data.T[j].key / radix) % 10;
            bucket[k]++;
        }


        for (j = 1; j < 10; j++)
            bucket[j] = bucket[j - 1] + bucket[j];      //����ÿ��Ͱ���ݵ��ۼӣ������Ͱ�����ĸ�������֮ǰ����Ͱ�ĸ�����������Ϊ���Ͱ���µĸ���

        for (j = n - 1; j >= 1; j--)
        {
            k = (data.T[j].key / radix) % 10;
            temp[bucket[k] - 1] = data.T[j].key;
            bucket[k]--;                                            //��ǰͰ�ĸ�����һ      //�ֱ�洢Ͱ��   temp������
            movecount++;
        }
        
        for (j = 1; j < n; j++) //����ʱ��������ݸ��Ƶ�data��
            data.T[j].key = temp[j - 1];  //����temp��0��ʼ�洢����data.T�Ǵ�1��ʼ�洢������Ҫ��j-1��ֵ��j
        movecount++;
        radix = radix * 10;
    }
}
void bubblesort(SqList& L, int& comparecount, int& movecount) {
    int i, j;
    RedType x;
    for (i = 1; i <= L.length - 1; i++) {
        for (j = 1; j <= L.length - i - 1; j++) {
            comparecount++;
            if (L.T[j].key > L.T[j + 1].key) {
                x = L.T[j]; L.T[j] = L.T[j + 1]; L.T[j + 1] = x;
                movecount += 3;
            }
        }
    }
}
int Partition(SqList& L, int low, int high, int& comparecount, int& movecount) {
    int pivotkey;
    L.T[0] = L.T[low]; pivotkey = L.T[low].key;
    while (low < high) {
        while (low < high && L.T[high].key >= pivotkey) {
            --high;
            comparecount++;
        }       //���Ҳ࿪ʼ���ҵ���һ��С�� pivotkey ��Ԫ�أ��������Ƶ���ࣨ��Ӧ low λ�ã���ÿ�αȽϵĽ���������ӡ�
        L.T[low] = L.T[high];
        movecount++;
        while (low < high && L.T[low].key <= pivotkey) {
            ++low;
            comparecount++;
        }//���Ŵ���࿪ʼ���ҵ���һ������ pivotkey ��Ԫ�أ��������Ƶ��Ҳࣨ��Ӧ high λ�ã���ͬ��������
        L.T[high] = L.T[low];
        movecount++;
    }//�ظ������������裬ֱ�� low >= high����ʾ���ַ���������
    L.T[low] = L.T[0];//����׼Ԫ�� pivotkey �����ڵ�ǰ low ��λ���ϣ����һ�η���������
    movecount++;
    return low;
}
void Qsort(SqList& L, int low, int high, int& comparecount, int& movecount) {
    //ԭ�ȵĵݹ��㷨�ڶ�ȡ�ļ�10000�����ݽ�������ʱ������ջ�������ȡβ�ݹ�ʵ�������㷨
    while (low < high) {
        int pivott = Partition(L, low, high, comparecount, movecount);      //ʹ�� Partition �����������Ϊ�����֣����õ���׼Ԫ�ص�λ�� pivott
        Qsort(L, low, pivott - 1, comparecount, movecount);     //�ݹ���� Qsort ���������������������򣬼� low �� pivott - 1 �Ĳ��֡�
        low = pivott + 1;       //���� low ��λ��Ϊ pivott + 1�����Ҳ���������������������β�ݹ�ķ�ʽ�����˳���ݹ���ɵ�ջ������⣬��Ϊ��ֻ��β�����õݹ麯��
 //       Qsort(L, pivott + 1, high, comparecount, movecount);
    }
}

