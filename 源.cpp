#include<iostream>
using namespace std;
class Object
{
	private:
		int num;
		int quantity;
		static double discount;
		double price;
		static double sum;//�����ۼ۸�
		static double averagepri;//ƽ������
		static int sumq;//�ܼ���
	public:
		Object(int x, int y, double z): num(x), quantity(y), price(z){};
		static double outcount(Object *p,int n);//���������ۼ۸���ƽ������
		static void put(Object *p,int n);//�����������ƽ������
};
double Object::sum=0;
double Object::averagepri=0;
int Object::sumq=0;//�ܼ���
double Object::discount = 0.98;
int main()
{
	Object t[3] = { Object(101,5,23.5),Object(102,12,24.56),Object(103,100,21.5) };
	Object::put(t, 3);
	return 0;
}

double Object::outcount(Object *p,int n)//���������ۼ۸�,ƽ������
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
	cout << "ƽ�����ۣ�" << Object::outcount(p, n) << endl;
	cout << "�����ۼ۸�" << Object::sum << endl;
}

