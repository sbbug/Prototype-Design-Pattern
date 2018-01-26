#include<iostream>
#include<vector>
using namespace std;

//定义一个抽象类
class Stooge{
public:
	virtual void slap_stick() = 0;
};
//定义Larry类，继承Stooge
class Larry :public Stooge{
public:
	void slap_stick(){
		cout << "Larry:poke eyes\n";
	}
};
//定义Moe类，继承Stooge
class Moe :public Stooge{
public:
	void slap_stick(){
		cout << "Moe:slap head\n";
	}
};
//定义Curly类，继承Stooge
class Curly :public Stooge{
public:
	void slap_stick(){
		cout << "Curly:suffer abuse\n";
	}
};

int main(){

	//定义一个集合，用来盛放对象
	vector<Stooge*> roles;
	int choice;

	while (true){
		cout << "Larry(1) Moe(2) Curly(3) Go(0):";
		cin >> choice;

		if (choice == 0){
			break;
		}
		else if (choice == 1){
			roles.push_back(new Larry);
		}
		else if (choice == 2){
			roles.push_back(new Moe);
		}
		else{
			roles.push_back(new Curly);
		}
	}

	//遍历roles集合里的每一个对象，执行slap_stick()操作
	for (int i = 0; i < roles.size(); i++){
		roles[i]->slap_stick();
	}
	//手动释放内存
	for (int j = 0; j < roles.size(); j++){
		delete roles[j];
	}

	system("pause");
	return 0;
}