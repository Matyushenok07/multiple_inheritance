#include <iostream> // Вариант 7 (бытовая техника)
#include <string> 
#include <windows.h>
using namespace std;
#undef max
class  technic
{
protected:
	string designation;// компания
	string model;// cтрана изготовитель
public:
	technic() {};
	bool isTypeCorrect();
	int inputNum(int, int);
	int insert();
	void enter() {
		cout << "Введите название техники:" << endl;
		getline(cin, designation);
		cout << "Модель бытовой техники : " << endl;
		getline(cin, model);
	}
	void Draw()
	{
		cout << "-------------------------------ИНФОРМАЦИЯ О ПРИБОРЕ-------------------------------------------------------" << endl;
		cout << "\nНазвание техники: " << designation << "\nМодель техники: " << model << endl;
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
				cout << "Некорректный ввод ! Введите положительное число: \n";
			}
		}
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Некорректный ввод ! Введите заново: \n";
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
			cout << "\n\n\tВведено некорректное число(№)!";
			if ((number <= left_range) || (number >= right_range))
				cout << "\t Число может быть только от " << left_range << " и до " << right_range << " !";
			cout << "\n\t\tПопробуйте ещё раз: ";
		}
	}
}
class organization : public technic // Дочерний класс
{
protected:
	string company;// компания
	string country;// cтрана изготовитель
	int rz;
public:
	void enter() {
		cout << "Введите название компании изготовившей данную технику: " << endl;
		getline(cin, company);
		cout << "Страна изготовитель: " << endl;
		getline(cin, country);
	}
	void Draw()
	{
		cout << " \nНазвание компании изготовившей данную технику : " << company << "\nСтрана Изготовления: " << country << endl;
	}
	void inlet()
	{
		cout << " -------------Определение вида ------------ " << endl
			<< "1.Введите 1, если техника относится к разряду Крупной " << endl
			<< "2.Введите 2, если техника относится к разряду Климатической " << endl
			<< "3.Введите 3, если техника относится к разряду Мелкой " << endl
			<< "Ваш выбор:";
		rz = inputNum(1, 3);
	}
	void See()
	{
		switch (rz)
		{
		case 1:
		{cout << "\nВид:Крупная бытовая техника " << endl; break; }
		case 2:
		{cout << "\nВид:Климатическая техника " << endl; break; }
		case 3:
		{ cout << "\nВид:Мелкая бытовая техника " << endl; break; }
		}
	}
};
class amount :public technic // Дочерний класс
{
protected:
	int n;// количество моделей данной техники
	int k;// нужное количество вспомогательных приборов
public:
	void enter()
	{
		cout << "Количество моделей данной техники: " << endl;
		n = insert();
		cout << "Нужное количество вспомогательных приборов: " << endl;
		k = insert();
	}
	void Draw()
	{
		cout << "\nКоличество моделей данной техники " << n << endl;
		cout << "\nНужное количество вспомогательных приборов " << k << endl;
	}
};
class Logo : public organization, public amount
{
public:
	void DrawLogo() {
		technic::enter();// ввод названия и модели
		organization::enter(); // ввод компании и строны
		amount::enter();// ввод количества бытовой техники и количества вспомогательных приборов
		organization::inlet();
		technic::Draw(); // вывод названия и модели
		organization::Draw();// ввод компании и строны
		amount::Draw();// ввод количества бытовой техники и количества вспомогательных приборов
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
		cout << " ----------Выбор пути------------ " << endl
			<< "1.Ввести ещё одни данные для бытовой техники" << endl
			<< "0.Выйти из программы" << endl
			<< "Ваш выбор:";
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
/* При защите в строке 161 и 173 нужно указывать так же класс , ведь функция Draw определена в трёх классах , поэтому нужно оформить следующим образом:
Например:logo.organization:: Draw() или logo.amount:: Draw() или logo.technic :: Draw(), то же самое и с функцией enter()(logo.organization:: enter()
или logo.amount:: enter() или logo.technic :: enter() . СООТВЕТСТВЕННО logo.DrawLogo() следует заменить на функции типа->logo.organization:: enter() ,
logo.technic :: Draw() и т.д */