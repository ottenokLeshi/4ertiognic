//#include "core.h"

void AddPrimitive(int type, const Array<double> &params) {
	switch (type)
	{
	case 1:
		if (params.size() != 2) { return; }
		else
		{
			Point p(params[0], params[1]);
			ListPoint.add_back(p);
		}
		break;
	case 2:
		if (params.size() != 4) { return; }
		else
		{
			Segment s(params[0], params[1], params[2], params[3]);
			ListSegment.add_back(s);
		}
		break;
	case 3:
		if (params.size() != 3) { return; }
		else
		{
			Circle c(params[0], params[1], params[3])
				ListCircle.add_back(c);
		}
		break;
	default:
		return;
	}
}