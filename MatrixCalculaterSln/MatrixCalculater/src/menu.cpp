#include "matrix.h"
#include "empty_buffer.h"

extern matrix mat_1, mat_2, mat_3, mat_4, mat_t1, mat_t2, mat_t3;

void choose(matrix** pp1, bool * pbreak)
{
	matrix* p1 = nullptr;
	system("cls");
	std::cout << "\tÑ¡ÔñÒ»¸ö¾ØÕó" << std::endl << std::endl
		<< "\t[0] ·µ»Ø\t"
		<< "\t[9] ÁÙÊ±¾ØÕó\n\n";

	std::cout << "\t[1] ¾ØÕó1\n";
	mat_1.show();
	std::cout << "\t[2] ¾ØÕó2\n";
	mat_2.show();
	std::cout << "\t[3] ¾ØÕó3\n";
	mat_3.show();
	std::cout << "\t[4] ¾ØÕó4\n";
	mat_4.show();

	std::cout << std::endl << ">>>";
	int menu;
	while (true)
	{
		if (std::cin >> menu)
		{
			if (menu >= 0 && menu <= 4 || menu == 9)
			{
				break;
			}
		}
		std::cout << "error" << std::endl;
	}

	emptybuffer();

	switch (menu)
	{
	case 0:
		*pbreak = true;
		break;

	case 9:
		mat_t1.get();
		p1 = &mat_t1;
		break;

	case 1:
		p1 = &mat_1;
		break;

	case 2:
		p1 = &mat_2;
		break;

	case 3:
		p1 = &mat_3;
		break;

	case 4:
		p1 = &mat_4;
		break;
	}
	*pp1 = p1;
}


void choose(matrix** pp1,matrix** pp2, bool* pbreak)
{
	matrix* p1 = nullptr;
	matrix* p2 = nullptr;

	system("cls");
	std::cout << "\tÑ¡ÔñµÚÒ»¸ö¾ØÕó" << std::endl << std::endl
		<< "\t[0] ·µ»Ø\t"
		<< "\t[9] ÁÙÊ±¾ØÕó\n\n";

	std::cout << "\t[1] ¾ØÕó1\n";
	mat_1.show();
	std::cout << "\t[2] ¾ØÕó2\n";
	mat_2.show();
	std::cout << "\t[3] ¾ØÕó3\n";
	mat_3.show();
	std::cout << "\t[4] ¾ØÕó4\n";
	mat_4.show(); 
	
	std::cout << std::endl << ">>>";

	int menu;
	while (true)
	{
		if (std::cin >> menu)
		{
			if (menu >= 0 && menu <= 4 || menu == 9)
			{
				break;
			}
		}
		std::cout << "error" << std::endl;
	}

	switch (menu)
	{
	case 0:
		*pbreak = true;
		return;

	case 9:
		mat_t1.get();
		p1 = &mat_t1;
		break;

	case 1:
		p1 = &mat_1;
		break;

	case 2:
		p1 = &mat_2;
		break;

	case 3:
		p1 = &mat_3;
		break;

	case 4:
		p1 = &mat_4;
		break;
	}

	system("cls");
	std::cout << "\tÑ¡ÔñµÚ¶þ¸ö¾ØÕó" << std::endl << std::endl
		<< "\t[0] ·µ»Ø\t"
		<< "\t[9] ÁÙÊ±¾ØÕó\n\n";

	std::cout << "\t[1] ¾ØÕó1\n";
	mat_1.show();
	std::cout << "\t[2] ¾ØÕó2\n";
	mat_2.show();
	std::cout << "\t[3] ¾ØÕó3\n";
	mat_3.show();
	std::cout << "\t[4] ¾ØÕó4\n";
	mat_4.show(); 

	std::cout << std::endl;
	p1->show();
	std::cout << std::endl << ">>>";

	while (true)
	{
		if (std::cin >> menu)
		{
			if (menu >= 0 && menu <= 4 || menu == 9)
			{
				break;
			}
		}
		std::cout << "error" << std::endl;
	}

	emptybuffer();

	switch (menu)
	{
	case 0:
		*pbreak = true;
		return;

	case 9:
		mat_t2.get();
		p2 = &mat_t2;
		break;

	case 1:
		p2 = &mat_1;
		break;

	case 2:
		p2 = &mat_2;
		break;

	case 3:
		p2 = &mat_3;
		break;

	case 4:
		p2 = &mat_4;
		break;
	}
	*pp1 = p1;
	*pp2 = p2;
}

void save()
{
	std::cout << "ÊÇ·ñ±£´æ£¿[y/n]" << std::endl << ">>>";
	char c;
	std::cin.get(c);
	emptybuffer();
	if (c == 'y' || c == 'Y')
	{
		matrix* p = nullptr;
		matrix** pp = &p;
		bool to_break = false;
		bool* pbreak = &to_break;
		choose(pp, pbreak);
		if (to_break) 
		{
			return;
		}
		*p = mat_t3;
		std::cout << "ÒÑ±£´æ" << std::endl;
	}
}