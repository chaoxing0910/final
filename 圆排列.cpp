#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAX = 130;
int n;//圆的数量 
double minLength=10000000,x[MAX],r[MAX],sorting[MAX];//最小圆排列长度，圆心横坐标，圆半径，最小圆排列的圆半径

double center(int t){//求第t个圆的圆心横坐标
	double temp = 0;
	//因为圆有可能与前面的任一圆相切，所以需要进行循环判断 
    for (int i = 1; i < t; ++i) {//计算第t个圆与前面已排列的第i个圆相切的距离
        double xT = x[i] + 2.0 * sqrt(r[i]*r[t]);
        if (xT > temp) {//最大的距离就是第t个圆的圆心横坐标
            temp = xT;
        }
    }//当t=1时，返回temp=0，可知x[1]=0
    return temp;
}
void compute(){//计算圆排列长度
    double left=0,right=0;
    for (int i = 1; i <= n; ++i) {//寻找最左坐标 
        if (x[i] - r[i] < left) {
            left = x[i] - r[i];
        }
        if (x[i] + r[i] > right) {//寻找最右坐标 
            right = x[i] + r[i];
        }
    }
    if (right - left < minLength) {//相减求出该圆排列的长度，并和最小的比较，若小于则更新替换。
        minLength = right - left;
        for (int i = 1; i <= n; ++i) { 
            sorting[i] = r[i];
        }
    }
}
void backtrack(int t){
    if (t > n)//t > n时算法搜索至叶节点，得到新的圆排列方案，计算当前圆排列的长度并更新最优值，否则选择下一个要排列的圆
        compute();
    else{
        for (int i = t; i <= n; ++i) {
            swap(r[t], r[i]);
            double centerT = center(t);//计算第t个圆的横坐标
            if (centerT + r[1] + r[t] < minLength) {//剪枝作用，先判断当前层是否在范围内，是则继续搜索下一层，否则直接回溯
                x[t] = centerT;//确定了加入第t个圆的圆排列长度
                backtrack(t + 1);//搜索下一个圆
            }
            swap(r[t], r[i]);
        }
    }
}
int main()
{	
    cout << "请输入圆的个数 n：";
    cin >> n;
    cout << "圆的半径分别为：";
    for (int i = 1; i <= n; ++i) {
        cin >> r[i];
    }
    backtrack(1);
    cout << "最小圆排列长度为：" << minLength <<endl;
    cout << "最小圆排列的圆半径分别为：";
    for (int i = 1; i <= n; ++i) {
        cout << sorting[i] << " ";
    }
    return 0;
} 
