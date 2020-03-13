#include<iostream>
using namespace std;
class Object
{
	private:
		int num;
		int quantity;
		static double discount;
		double price;
		static double sum;//总销售价格
		static double averagepri;//平均单价
		static int sumq;//总件数
	public:
		Object(int x, int y, double z): num(x), quantity(y), price(z){};
		static double outcount(Object *p,int n);//计算总销售价格与平均单价
		static void put(Object *p,int n);//输出总销售与平均单价
};
double Object::sum=0;
double Object::averagepri=0;
int Object::sumq=0;//总件数
double Object::discount = 0.98;
int main()
{
	Object t[3] = { Object(101,5,23.5),Object(102,12,24.56),Object(103,100,21.5) };
	Object::put(t, 3);
	return 0;
}

double Object::outcount(Object *p,int n)//计算总销售价格,平均单价
{
	Object* q;
	q = p;
	for (; q<p+n; q++)
	{
		if (q->quantity > 10)
		{
			(q->price)*=discount;
		}
		sum +=((q->quantity) * (q->price) );
		sumq += q->quantity;
	}
	averagepri = sum / sumq;
	return averagepri;
}
void Object::put(Object* p, int n)
{
	cout << "平均单价：" << Object::outcount(p, n) << endl;
	cout << "总销售价格：" << Object::sum << endl;
}

