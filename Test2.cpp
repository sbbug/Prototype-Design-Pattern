#include<iostream>
#include<vector>
using namespace std;

//����һ��������
class Stooge{
public:
	virtual void slap_stick() = 0;
	//����һ��clone()����
	virtual Stooge* clone() = 0;
};
//����Larry�࣬�̳�Stooge
class Larry :public Stooge{
public:
	//ʵ��clone()����
	Stooge* clone(){
		return new Larry;
	}
	void slap_stick(){
		cout << "Larry:poke eyes\n";
	}
};
//����Moe�࣬�̳�Stooge
class Moe :public Stooge{
public:
	//ʵ��clone()����
	Stooge* clone(){
		return new Moe;
	}
	void slap_stick(){
		cout << "Moe:slap head\n";
	}
};
//����Curly�࣬�̳�Stooge
class Curly :public Stooge{
public:
	//ʵ�ֿ�¡Curly����ķ���
	Stooge* clone(){
		return new Curly();
	}
	void slap_stick(){
		cout << "Curly:suffer abuse\n";
	}
};
//�����������Ʒ�Ĺ���
class Factory{
public:
	static Stooge* make_stooge(int choice);
private:
	static Stooge* s_prototypes[4];
};
//���������ĳ�ʼ�������ȶ�����Щ���󣬾���Ϊ�˷���������clone(),ʵ��clone()
Stooge* Factory::s_prototypes[] = {
	0, new Larry, new Moe, new Curly
};
//����������ʵ��
Stooge* Factory::make_stooge(int choice){
	return s_prototypes[choice]->clone();
}

int main(){

	//����һ�����ϣ�����ʢ�Ŷ���
	vector<Stooge*> roles;
	int choice;

	while (true){
		cout << "Larry(1) Moe(2) Curly(3) Go(0):";
		cin >> choice;

		if (choice == 0)
			break;
		//���ù�������������choice��ֵ����clone��ͬ�Ķ���
		roles.push_back(Factory::make_stooge(choice));
	}

	//����roles�������ÿһ������ִ��slap_stick()����
	for (int i = 0; i < roles.size(); i++){
		roles[i]->slap_stick();
	}
	//�ֶ��ͷ��ڴ�
	for (int j = 0; j < roles.size(); j++){
		delete roles[j];
	}

	system("pause");
	return 0;
}