#include<iostream>
using namespace std;

//����ö�����ͣ�����ͼƬ������
enum imageType{
	LSAT,SPOT
};
//����һ��ͼƬ������
class Image{
public:
	virtual void draw() = 0;
	//Ѱ�Ҹ����͵�ͼƬ����¡
	static Image* findAndClone(imageType);
protected:
	//��ȡͼƬ����
	virtual imageType returnType() = 0;
	//ʵ��ͼƬ��¡
	virtual Image *clone() = 0;

	//���ͼƬ��ԭ�͵�������
	static void addPrototype(Image *image){
		_prototypes[_nextSlot++] = image;
	}

private:
	//�洢��ͬ����ͼƬ������
	static Image *_prototypes[10];
	//������һ����λ��
	static int _nextSlot;
};

Image *Image::_prototypes[];
int Image::_nextSlot;

Image *Image::findAndClone(imageType type){

	//����������ͼƬ
	for (int i = 0; i < _nextSlot; i++){
		//����ҵ���ʵ�ֿ�¡
		if (_prototypes[i]->returnType() == type)
			return _prototypes[i]->clone();
	}

	return NULL;
}
//����һ��LandSatImage���͵�ͼƬ
class LandSatImage :public Image{
public:
	//��ȡͼƬ����
	imageType returnType(){

		return LSAT;
	}
	//ͼƬ��ʾ ����ʾ�ǵڼ�������¡
	void draw(){
		cout << "LandSatImage::draw\t ��" << _id<<"������copy" << endl;
	}
	//ʵ��ͼƬ��¡����
	Image *clone(){
		return new LandSatImage(1);
	}

protected:
	//������
	LandSatImage(int dummy){
		_id = _count++;
	}
private:
	//�������ڲ���̬����
	static  LandSatImage _landSatImage;

	LandSatImage(){
		//����ǰ����ָ����ӵ�����������
		addPrototype(this);
	}
	//˽������ID
	int _id;
	//��¼�������˶��ٴ�
	static int _count;
};

LandSatImage LandSatImage::_landSatImage;

int LandSatImage::_count = 1;
//����һ��SpotImage���͵�ͼƬ
class SpotImage :public Image{
public:
	//��ȡSpotImageͼ������
	imageType returnType(){
		
		return SPOT;
	}
	//��ʾͼƬ,����ʾ�ǵڼ�������¡
	void draw(){
		cout << "SpotImage::draw\t ��" << _id <<"������copy"<< endl;
	}
	//��¡һ��ͼƬ
	Image *clone(){
		return new SpotImage(1);
	}
protected:
	SpotImage(int dummy){
		_id = _count++;
	}
private:
	SpotImage(){
		addPrototype(this);
	}
	//�������ڲ���̬����
	static SpotImage _spotImage;
	//˽������ID
	int _id;
	//��¼�������˶��ٴ�
	static int _count;
};

SpotImage SpotImage::_spotImage;
int SpotImage::_count = 1;

const int NUM_IMAGES = 8;
//����һ��ͼ�����͵�����
imageType input[NUM_IMAGES] = {
	LSAT, LSAT, LSAT, SPOT, LSAT, SPOT, SPOT, LSAT
};

int main(){
	//����һ��ͼ������
	Image *images[NUM_IMAGES];

	//������ӦͼƬ���ͣ�������ڣ���¡һ��
	for (int i = 0; i < NUM_IMAGES; i++)
		images[i] = Image::findAndClone(input[i]);

	//���÷�������ʾ
	for (int j = 0; j < NUM_IMAGES; j++)
		images[j]->draw();
	//�������ٻ���
	for (int k = 0; k < NUM_IMAGES; k++)
		delete images[k];



	system("pause");
	return 0;
}