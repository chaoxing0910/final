#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAX = 130;
int n;//Բ������ 
double minLength=10000000,x[MAX],r[MAX],sorting[MAX];//��СԲ���г��ȣ�Բ�ĺ����꣬Բ�뾶����СԲ���е�Բ�뾶

double center(int t){//���t��Բ��Բ�ĺ�����
	double temp = 0;
	//��ΪԲ�п�����ǰ�����һԲ���У�������Ҫ����ѭ���ж� 
    for (int i = 1; i < t; ++i) {//�����t��Բ��ǰ�������еĵ�i��Բ���еľ���
        double xT = x[i] + 2.0 * sqrt(r[i]*r[t]);
        if (xT > temp) {//���ľ�����ǵ�t��Բ��Բ�ĺ�����
            temp = xT;
        }
    }//��t=1ʱ������temp=0����֪x[1]=0
    return temp;
}
void compute(){//����Բ���г���
    double left=0,right=0;
    for (int i = 1; i <= n; ++i) {//Ѱ���������� 
        if (x[i] - r[i] < left) {
            left = x[i] - r[i];
        }
        if (x[i] + r[i] > right) {//Ѱ���������� 
            right = x[i] + r[i];
        }
    }
    if (right - left < minLength) {//��������Բ���еĳ��ȣ�������С�ıȽϣ���С��������滻��
        minLength = right - left;
        for (int i = 1; i <= n; ++i) { 
            sorting[i] = r[i];
        }
    }
}
void backtrack(int t){
    if (t > n)//t > nʱ�㷨������Ҷ�ڵ㣬�õ��µ�Բ���з��������㵱ǰԲ���еĳ��Ȳ���������ֵ������ѡ����һ��Ҫ���е�Բ
        compute();
    else{
        for (int i = t; i <= n; ++i) {
            swap(r[t], r[i]);
            double centerT = center(t);//�����t��Բ�ĺ�����
            if (centerT + r[1] + r[t] < minLength) {//��֦���ã����жϵ�ǰ���Ƿ��ڷ�Χ�ڣ��������������һ�㣬����ֱ�ӻ���
                x[t] = centerT;//ȷ���˼����t��Բ��Բ���г���
                backtrack(t + 1);//������һ��Բ
            }
            swap(r[t], r[i]);
        }
    }
}
int main()
{	
    cout << "������Բ�ĸ��� n��";
    cin >> n;
    cout << "Բ�İ뾶�ֱ�Ϊ��";
    for (int i = 1; i <= n; ++i) {
        cin >> r[i];
    }
    backtrack(1);
    cout << "��СԲ���г���Ϊ��" << minLength <<endl;
    cout << "��СԲ���е�Բ�뾶�ֱ�Ϊ��";
    for (int i = 1; i <= n; ++i) {
        cout << sorting[i] << " ";
    }
    return 0;
} 
