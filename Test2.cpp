#include<iostream>
#include<vector>
using namespace std;

//定义一个抽象类
class Stooge{
public:
	virtual void slap_stick() = 0;
	//定义一个clone()方法
	virtual Stooge* clone() = 0;
};
//定义Larry类，继承Stooge
class Larry :public Stooge{
public:
	//实现clone()方法
	Stooge* clone(){
		return new Larry;
	}
	void slap_stick(){
		cout << "Larry:poke eyes\n";
	}
};
//定义Moe类，继承Stooge
class Moe :public Stooge{
public:
	//实现clone()方法
	Stooge* clone(){
		return new Moe;
	}
	void slap_stick(){
		cout << "Moe:slap head\n";
	}
};
//定义Curly类，继承Stooge
class Curly :public Stooge{
public:
	//实现克隆Curly对象的方法
	Stooge* clone(){
		return new Curly();
	}
	void slap_stick(){
		cout << "Curly:suffer abuse\n";
	}
};
//定义个生产产品的工厂
class Factory{
public:
	static Stooge* make_stooge(int choice);
private:
	static Stooge* s_prototypes[4];
};
//工厂变量的初始化，事先定义这些对象，就是为了方便调用类的clone(),实现clone()
Stooge* Factory::s_prototypes[] = {
	0, new Larry, new Moe, new Curly
};
//工厂方法的实现
Stooge* Factory::make_stooge(int choice){
	return s_prototypes[choice]->clone();
}

int main(){

	//定义一个集合，用来盛放对象
	vector<Stooge*> roles;
	int choice;

	while (true){
		cout << "Larry(1) Moe(2) Curly(3) Go(0):";
		cin >> choice;

		if (choice == 0)
			break;
		//调用工厂方法，根据choice的值进行clone不同的对象
		roles.push_back(Factory::make_stooge(choice));
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