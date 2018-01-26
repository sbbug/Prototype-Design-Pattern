#include<iostream>
using namespace std;

//定义枚举类型，保存图片的类型
enum imageType{
	LSAT,SPOT
};
//定义一个图片抽象类
class Image{
public:
	virtual void draw() = 0;
	//寻找该类型的图片并克隆
	static Image* findAndClone(imageType);
protected:
	//获取图片类型
	virtual imageType returnType() = 0;
	//实现图片克隆
	virtual Image *clone() = 0;

	//添加图片的原型到数组中
	static void addPrototype(Image *image){
		_prototypes[_nextSlot++] = image;
	}

private:
	//存储不同类型图片的数组
	static Image *_prototypes[10];
	//数组下一个空位置
	static int _nextSlot;
};

Image *Image::_prototypes[];
int Image::_nextSlot;

Image *Image::findAndClone(imageType type){

	//搜索该类型图片
	for (int i = 0; i < _nextSlot; i++){
		//如果找到便实现克隆
		if (_prototypes[i]->returnType() == type)
			return _prototypes[i]->clone();
	}

	return NULL;
}
//定义一个LandSatImage类型的图片
class LandSatImage :public Image{
public:
	//获取图片类型
	imageType returnType(){

		return LSAT;
	}
	//图片显示 并显示是第几个被克隆
	void draw(){
		cout << "LandSatImage::draw\t 第" << _id<<"个对象被copy" << endl;
	}
	//实现图片克隆方法
	Image *clone(){
		return new LandSatImage(1);
	}

protected:
	//构造器
	LandSatImage(int dummy){
		_id = _count++;
	}
private:
	//定义类内部静态对象
	static  LandSatImage _landSatImage;

	LandSatImage(){
		//将当前对象指针添加到父类数组中
		addPrototype(this);
	}
	//私有属性ID
	int _id;
	//记录被拷贝了多少次
	static int _count;
};

LandSatImage LandSatImage::_landSatImage;

int LandSatImage::_count = 1;
//定义一个SpotImage类型的图片
class SpotImage :public Image{
public:
	//获取SpotImage图像类型
	imageType returnType(){
		
		return SPOT;
	}
	//显示图片,并显示是第几个被克隆
	void draw(){
		cout << "SpotImage::draw\t 第" << _id <<"个对象被copy"<< endl;
	}
	//克隆一个图片
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
	//定义类内部静态对象
	static SpotImage _spotImage;
	//私有属性ID
	int _id;
	//记录被拷贝了多少次
	static int _count;
};

SpotImage SpotImage::_spotImage;
int SpotImage::_count = 1;

const int NUM_IMAGES = 8;
//定义一个图像类型的数组
imageType input[NUM_IMAGES] = {
	LSAT, LSAT, LSAT, SPOT, LSAT, SPOT, SPOT, LSAT
};

int main(){
	//定义一个图像数组
	Image *images[NUM_IMAGES];

	//搜索对应图片类型，如果存在，克隆一份
	for (int i = 0; i < NUM_IMAGES; i++)
		images[i] = Image::findAndClone(input[i]);

	//调用方法并显示
	for (int j = 0; j < NUM_IMAGES; j++)
		images[j]->draw();
	//对象销毁回收
	for (int k = 0; k < NUM_IMAGES; k++)
		delete images[k];



	system("pause");
	return 0;
}