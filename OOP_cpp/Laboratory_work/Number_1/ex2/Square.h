class Square
{
	int side1, side2;
public:
	Square(const int a) :side1(a){};
	Square(const int a, const int b) :side1(a), side2(b){};
	int getSquareArea(const int a)const;
	int getSquareArea(const int a,const int b)const;
	int getSide1(){ return side1;}
	int getSide2(){ return side2; }
};
