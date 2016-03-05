#ifndef _CORE_H
#define _CORE_H
class Core{
public:
	Core();
	void addPoint(double x, double y);
	void addSegment(double x1, double y1,double x2, double y2);
	void addCircle(double x, double y,double r);

	

	void addPrimitive(int type, const Array<double> &params){
		if (type == 1 && params.size() <2) ///ACHTUNG!!!!
	}
private:

    void selectByRect(double x1,double y1,double x2,double y2);
};

#endif
