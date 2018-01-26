#include<iostream>
#include<vector>
using namespace std;

//����һ��������
class Stooge{
public:
	virtual void slap_stick() = 0;
};
//����Larry�࣬�̳�Stooge
class Larry :public Stooge{
public:
	void slap_stick(){
		cout << "Larry:poke eyes\n";
	}
};
//����Moe�࣬�̳�Stooge
class Moe :public Stooge{
public:
	void slap_stick(){
		cout << "Moe:slap head\n";
	}
};
//����Curly�࣬�̳�Stooge
class Curly :public Stooge{
public:
	void slap_stick(){
		cout << "Curly:suffer abuse\n";
	}
};

int main(){

	//����һ�����ϣ�����ʢ�Ŷ���
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