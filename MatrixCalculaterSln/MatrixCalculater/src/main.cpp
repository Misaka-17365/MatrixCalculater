// 矩阵计算器 v3.3
#include "menu.h"

std::string author = "jj_t";
std::string version = "3.3";

matrix mat_1, mat_2, mat_3, mat_4, mat_t1, mat_t2, mat_t3;



int main()
{
	bool running = true;
	while (running)
	{
		std::cout << "\t\t\t\t\t++++++++++++++" << std::endl
			<< "\t******************" << "\t\t+ 矩阵计算器 +" << std::endl
			<< "\t*    功能列表    *" << "\t\t* 版本 " << version << "   +" << std::endl
			<< "\t******************" << "\t\t+ 作者 " << author << "  +" << std::endl
			<< "\t\t\t\t\t++++++++++++++"
			<< std::endl;
		std::cout << std::endl
			<< "\t[0] " << "退出\n"
			<< "\t[1] " << "定义矩阵\n"
			<< "\t[2] " << "矩阵加法\n"
			<< "\t[3] " << "矩阵乘法\n"
			<< "\t[4] " << "行列式\n"
			<< "\t[5] " << "秩\n"
			<< "\t[6] " << "解线性方程组\n"

			<< "\n>>>";

		int menu = -1;
		bool menu_run = true;
		while (true)
		{
			if (std::cin >> menu)
				if (menu >= 0 && menu <= 6) break;
			std::cout << "error" << std::endl;
		}
		// 清空缓冲区
		emptybuffer();
		// 主界面结束
		//////////////////////////////////////////////////////////////////// 

		matrix* p1 = nullptr, * p2 = nullptr;
		matrix** pp1 = &p1, ** pp2 = &p2;
		bool to_break = false;
		bool* pbreak = &to_break;
		// 与choose函数交互
		/////////////////////////////////////////////////////////////////////

		switch (menu)
		{
		case 0:					// 退出
			running = false;
			break;

		case 1:					// 定义矩阵
			while (true)
			{
				int menu;
				system("cls");
				std::cout << "\t选择编辑的矩阵" << std::endl
					<< std::endl
					<< "\t[0] 返回\n";

				std::cout << "\t[1] 矩阵1\n";
				mat_1.show();
				std::cout << "\t[2] 矩阵2\n";
				mat_2.show();
				std::cout << "\t[3] 矩阵3\n";
				mat_3.show();
				std::cout << "\t[4] 矩阵4\n";
				mat_4.show();
				std::cout << std::endl << ">>>";

				while (true)
				{
					if (std::cin >> menu)
					{
						if (menu >= 0 && menu <= 4)
						{
							break;
						}
					}
					std::cout << "error" << std::endl;
				}

				switch (menu)
				{

				case 0:
					goto final_end;

				case 1:
					mat_1.get();
					std::cout << "输入矩阵为" << std::endl;
					break;
				case 2:
					mat_2.get();
					std::cout << "输入矩阵为" << std::endl;\
					break;
				case 3:
					mat_3.get();
					std::cout << "输入矩阵为" << std::endl;
					break;
				case 4:
					mat_4.get();
					std::cout << "输入矩阵为" << std::endl;
					break;

				}
			}
			break;					// 定义矩阵结束
		/// ////////////////////////////////////////////////////////

		case 2:						// 加法
			
			choose(pp1, pp2, pbreak);

			if (to_break == true)
			{
				break;
			}

			if (! ((p1->num_i == p2->num_i) && (p1->num_j == p2->num_j)))
			{
				std::cout << "error" << std::endl;
				std::cin.get();
				std::cin.get();
				break;
			}

			mat_t3 = *p1 + *p2;

			system("cls");
			std::cout << "结果为" << std::endl;
			mat_t3.show();
			std::cin.get();
			save();
			break;

		case 3:						// 矩阵乘法
			choose(pp1, pp2, pbreak);

			if (to_break == true)
			{
				break;
			}

			if (!(p1->num_j == p2->num_i))
			{
				std::cout << "error" << std::endl;
				break;
			}
			mat_t3 = *p1 * *p2;

			std::cout << "结果为" << std::endl;
			mat_t3.show();
			std::cin.get();
			std::cin.get();
			break;

		case 4:						// 行列式
			choose(pp1, pbreak);

			if (to_break == true)
			{
				break;
			}
			if (p1->num_i != p1->num_j)
			{
				std::cout << "error" << std::endl;
				emptybuffer();

				break;
			}
			p1->cal_determinant();
			std::cout << "\t行列式为>" << p1->determinant;
			std::cin.get();
			break;

		case 5:					// 秩
			choose(pp1, pbreak);

			if (to_break == true)
			{
				break;
			}
			p1->cal_rank();
			std::cout << "\t秩为>" << p1->rank;
			emptybuffer();			
			break;

		case 6:
			choose(pp1, pbreak);

			if (to_break) break;

			p1->cal_solution();

			emptybuffer();
			std::cin.get();
		}
		final_end:
		system("cls");
	}
	return 0;
}




