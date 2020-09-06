#include <iostream> // ������� 7 (������� �������)
#include <string> 
#include <windows.h>
using namespace std;
#undef max
class  technic
{
protected:
	string designation;// ��������
	string model;// c����� ������������
public:
	technic() {};
	bool isTypeCorrect();
	int inputNum(int, int);
	int insert();
	void enter() {
		cout << "������� �������� �������:" << endl;
		getline(cin, designation);
		cout << "������ ������� ������� : " << endl;
		getline(cin, model);
	}
	void Draw()
	{
		cout << "-------------------------------���������� � �������-------------------------------------------------------" << endl;
		cout << "\n�������� �������: " << designation << "\n������ �������: " << model << endl;
	}
};
int technic::insert()
{
	int l;
	while (true)
	{
		cin >> l;
		if (cin.get() == '\n') {
			if (l > 0) {
				break;
			}

			else
			{
				cout << "������������ ���� ! ������� ������������� �����: \n";
			}
		}
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "������������ ���� ! ������� ������: \n";
		}

	}
	return l;
}
bool technic::isTypeCorrect()
{
	if (cin.get() == '\n')
		return true;
	else
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return false;
	}
}
int technic::inputNum(int left_range, int right_range)
{
	int number;
	while (true)
	{
		cin >> number;
		if (isTypeCorrect() && (number >= left_range) && (number <= right_range))
		{
			return number;
		}
		else
		{
			cout << "\n\n\t������� ������������ �����(�)!";
			if ((number <= left_range) || (number >= right_range))
				cout << "\t ����� ����� ���� ������ �� " << left_range << " � �� " << right_range << " !";
			cout << "\n\t\t���������� ��� ���: ";
		}
	}
}
class organization : public technic // �������� �����
{
protected:
	string company;// ��������
	string country;// c����� ������������
	int rz;
public:
	void enter() {
		cout << "������� �������� �������� ������������ ������ �������: " << endl;
		getline(cin, company);
		cout << "������ ������������: " << endl;
		getline(cin, country);
	}
	void Draw()
	{
		cout << " \n�������� �������� ������������ ������ ������� : " << company << "\n������ ������������: " << country << endl;
	}
	void inlet()
	{
		cout << " -------------����������� ���� ------------ " << endl
			<< "1.������� 1, ���� ������� ��������� � ������� ������� " << endl
			<< "2.������� 2, ���� ������� ��������� � ������� ������������� " << endl
			<< "3.������� 3, ���� ������� ��������� � ������� ������ " << endl
			<< "��� �����:";
		rz = inputNum(1, 3);
	}
	void See()
	{
		switch (rz)
		{
		case 1:
		{cout << "\n���:������� ������� ������� " << endl; break; }
		case 2:
		{cout << "\n���:������������� ������� " << endl; break; }
		case 3:
		{ cout << "\n���:������ ������� ������� " << endl; break; }
		}
	}
};
class amount :public technic // �������� �����
{
protected:
	int n;// ���������� ������� ������ �������
	int k;// ������ ���������� ��������������� ��������
public:
	void enter()
	{
		cout << "���������� ������� ������ �������: " << endl;
		n = insert();
		cout << "������ ���������� ��������������� ��������: " << endl;
		k = insert();
	}
	void Draw()
	{
		cout << "\n���������� ������� ������ ������� " << n << endl;
		cout << "\n������ ���������� ��������������� �������� " << k << endl;
	}
};
class Logo : public organization, public amount
{
public:
	void DrawLogo() {
		technic::enter();// ���� �������� � ������
		organization::enter(); // ���� �������� � ������
		amount::enter();// ���� ���������� ������� ������� � ���������� ��������������� ��������
		organization::inlet();
		technic::Draw(); // ����� �������� � ������
		organization::Draw();// ���� �������� � ������
		amount::Draw();// ���� ���������� ������� ������� � ���������� ��������������� ��������
		organization::See();
	}

};
int main(void)
{
	setlocale(LC_ALL, "RUS");
	technic l;
	Logo logo;
	logo.DrawLogo();
	while (true)
	{
		cout << " ----------����� ����------------ " << endl
			<< "1.������ ��� ���� ������ ��� ������� �������" << endl
			<< "0.����� �� ���������" << endl
			<< "��� �����:";
		int choice;
		choice = l.inputNum(0, 1);
		switch (choice)
		{
		case 0:system("cls");
		case 1:logo.DrawLogo();
		}
	}
	system("pause");
	return 0;
}
/* ��� ������ � ������ 161 � 173 ����� ��������� ��� �� ����� , ���� ������� Draw ���������� � ��� ������� , ������� ����� �������� ��������� �������:
��������:logo.organization:: Draw() ��� logo.amount:: Draw() ��� logo.technic :: Draw(), �� �� ����� � � �������� enter()(logo.organization:: enter()
��� logo.amount:: enter() ��� logo.technic :: enter() . �������������� logo.DrawLogo() ������� �������� �� ������� ����->logo.organization:: enter() ,
logo.technic :: Draw() � �.� */