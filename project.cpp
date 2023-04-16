#include "bankaccount.h"
int main()
{
	cout << ">>Welcome back , enter account number to check your balance." << endl;
	int number;
	cin >> number;
	cout << endl;
	Bank ba(number);

MENU:
	//基本窗口
	system("cls");
	ba.show();
	//菜单窗口：
	cout << "MENU" << endl;
	cout << "1. Deposit" << endl;
	cout << "2. Withdraw" << endl;
	cout << "3. Store" << endl;
	cout << "4. My Bag" << endl;
	cout << "5. Quit system" << endl;
	cout << endl;
	int choose;
	cin >> choose;

	//功能--------------------------------------------------------------------------------------------------------------------------------------------------------------
	if (choose == 1)      
	{
		DEPOSIT:
		//基本窗口
		system("cls");
		ba.show();
		//功能系统：
		cout << "Please enter the amount you want to deposit." << endl;
		int in;
		cin >> in;
		ba.deposit(in);
		//基本窗口
		system("cls");
		ba.show();
		//休息
		cout << "Deposited successfully.\t" << in << endl;
		cout << "*Press '0' to the MENU" << endl;
		cout << "*Press '1' to keep depositing." << endl;
		int end;
		cin >> end;
		if (end == 0) goto MENU;
		if (end == 1) goto DEPOSIT;
	}
	if (choose == 2)
	{
		WITHDRAW:
		//基本窗口
		system("cls");
		ba.show();
		//功能系统：
		AGAIN:
		cout << "Please enter the amount you want to withdraw." << endl;
		int in;
		cin >> in;
		//判断是否执行成功：          
		double total = ba.getbalance() - in;
		if( total < 0)
		{
			cout << "Insufficient Balance!" << endl; 
			goto AGAIN;
		}
		if (total >= 0)
		{
			ba.withdraw(in);
		}
		//基本窗口
		system("cls");
		ba.show();
		//休息
		cout << "Withdrew successfully.\t" << in << endl;
		cout << "*Press '0' to the MENU" << endl;
		cout << "*Press '1' to keep withdrawing." << endl;
		int end;
		cin >> end;
		if (end == 0) goto MENU;
		if (end == 1) goto WITHDRAW;
	}

	//商店系统---------------------------------------------------------------------------------------------------------------------------------------------------
	if (choose == 3)
	{
	STORE:
		//基本窗口
		system("cls");
		ba.show();
		//功能系统：
		cout << "This is all the good stuff today." << endl;
		cout << "Press the number of stuff you want to purchase." << endl;
		cout << "1. Apple\t" << "20$" << endl;
		cout << "2. Melon\t" << "40$" << endl;
		cout << endl;
		cout << "0.Quit" << endl;
		AGAstore:
		int stuff;
		int pay;
		cin >> stuff;
																																														//苹果菜单
		if (stuff == 1) 
		{ 
			cout << "Press the amount of Apple you want to purchase." << endl;
			int num;
			cin >> num;
			pay = 20 * num;
			//设置购买失败机制
			double total = ba.getbalance() - pay;
			if (total < 0)
			{
				cout << "Insufficient Balance!" << endl;
				cout << "Press '0' to quit." << endl;
				goto AGAstore;
			}
			if (total >= 0)
			{
				ba.withdraw(pay);
				ba.buyapple(num);
				cout << "Purchased Apple successfully.\t" << pay << endl;
			}
			cout << endl;
		}
																																											//西瓜菜单
		if (stuff == 2) 
		{
			cout << "Press the amount of Melon you want to purchase." << endl;
			int num;
			cin >> num;
			pay = 20 * num;
			//设置购买失败机制
			double total = ba.getbalance() - pay;
			if (total < 0)
			{
				cout << "Insufficient Balance!" << endl;
				cout << "Press '0' to quit." << endl;
				goto AGAstore;
			}
			if (total >= 0)
			{
				ba.withdraw(pay);
				ba.buymelon(num);
				cout << "Purchased Melon successfully.\t" << pay << endl;
			}

			cout << endl;
		}


		//退出商店
		if (stuff == 0)
		{
			goto MENU;
		}
		//基本窗口
		ba.show();
		//休息
		cout << "*Press '0' to the MENU" << endl;
		cout << "*Press '1' to keep shopping." << endl;
		int end;
		cin >> end;
		if (end == 0) goto MENU;
		if (end == 1) goto STORE;
	}
	//仓库系统-------------------------------------------------------------------------------------------------------------------------------------------------------
	if (choose == 4)
	{
		//基本窗口
		system("cls");
		ba.show();
		//功能系统：
		cout << "There is all you have." << endl;
		int a = ba.getapple();
		int m = ba.getmelon();
		if (a > 0) { cout << "Apple\t" << "*\t" << a << endl; }
		if (m > 0) { cout << "Melon\t" << "*\t" << m << endl; }
		if (a == 0 && m == 0) { cout << "You have no shit." << endl; }
		//休息
		cout << endl;
		cout << "*Press '0' to the MENU" << endl;
		cout << "*Press '1' to keep depositing." << endl;
		int end;
		cin >> end;
		if (end == 0) goto MENU;
		if (end == 1) goto DEPOSIT;
	}


	//退出---------------------------------------------------------------------------------------------------------------------------------------------------------
	if (choose == 5)            
	{
		//基本窗口
		system("cls");
		ba.show();
		//休息
		cout << "Quit.\t" << endl;
		goto END;
	}
	END:
	return 0;
}