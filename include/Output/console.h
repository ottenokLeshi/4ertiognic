#ifndef _CONSOLE_H_
#define _CONSOLE_H_
#include <iostream>
#include <stdlib.h>


using namespace std;

class Console {
	char c;
public:
	Console() {}
	~Console() {}

	bool screen() {
		Core Cor;
		while (true) {
			system("cls");
			cout << "a. Add graph primitive" << endl;
			cout << "b. Add restriction" << endl;
			cout << "c. Write all objects" << endl;
			cout << "q. Exit" << endl;

			cin >> c;

			switch (c) {

			case 'c':
				outputAll(&Cor);
				cout << "Write any symbol to return to main menu" << endl;
				cin >> c;
				break;
			case 'q':
				return 0;				

			case 'a':{
				system("cls");
				cout << "a. Point" << endl;
				cout << "b. Segment" << endl;
				cout << "c. Circle" << endl;
				cout << "q. Cancel" << endl;

				cin >> c;

				switch (c) {

				case 'a': {
					system("cls");
					cout << "Write coordinates: x and y" << endl;
					double x, y;
					cin >> x >> y;
					Array <double> Arr(0);
					Arr.push_back(x);
					Arr.push_back(y);
					Cor.addObject(Arr, IsPoint);
					break;}
				case 'b': {
					system("cls");
					cout << "Write coordinates: x1, y1, x2 and y2" << endl;
					double x1, y1, x2, y2;
					cin >> x1 >> y1 >> x2 >> y2;
					Array <double> Arr(0);
					Arr.push_back(x1);
					Arr.push_back(y1);
					Arr.push_back(x2);
					Arr.push_back(y2);
					Cor.addObject(Arr, IsSegment);
					break;}
				case 'c': {
					system("cls");
					cout << "Write coordinates: x1, y1 and radius" << endl;
					double x, y, r;
					cin >> x >> y >> r;
					Array <double> Arr(0);
					Arr.push_back(x);
					Arr.push_back(y);
					Arr.push_back(r);
					break;
					Cor.addObject(Arr, IsCircle);}
				}
				break;
			}//end of addition

			case 'b': {
				system("cls");
				cout << "a. RT_FIX" << endl;
				cout << "b. RT_P2PDIST" << endl;
				cout << "c. RT_P2SDIST" << endl;
				cout << "d. RT_P2SDISTEX" << endl;
				cout << "e. RT_S2SANGLE" << endl;
				cout << "f. RT_S2SEQUALS" << endl;
				cout << "g. RT_S2SPARAL" << endl;
				cout << "h. RT_S2SORTHO" << endl;
				cout << "q. Cancel" << endl;

				cin >> c;
				switch (c) {
				case 'a': {
					system("cls");
					int id;
					outputPoint(&Cor);
					cout << "Write id of point" << endl;
					cin >> id;
					List <unsigned> List_;
					List_.push_back(id);
					Cor.addRestriction(&List_, 0, RT_FIX);
					break;
				}
				case 'b': {
					system("cls");
					int id1, id2;
					double d;
					cout << "Point:" << endl;
					outputPoint(&Cor);
					cout << "Write id of 2 points and distance" << endl;
					List <unsigned> List_;
					cin >> id1 >> id2 >> d;
					List_.push_back(id1);
					List_.push_back(id2);
					Cor.addRestriction(&List_, &d, RT_P2PDIST);
					break;
				}
				case 'c': {
					system("cls");
					int id1, id2;
					double d;
					cout << "Points:" << endl;
					outputPoint(&Cor);
					cout << "Segment:" << endl;
					outputSegment(&Cor);
					List <unsigned> List_;
					cout << "Write id of point, segment and distance" << endl;
					cin >> id1 >> id2 >> d;
					List_.push_back(id1);
					List_.push_back(id2);
					Cor.addRestriction(&List_, &d, RT_P2SDIST);
					break;
				}
				case 'd': {
					int id1, id2;
					double d;
					cout << "Segment:" << endl;
					outputSegment(&Cor);
					List <unsigned> List_;
					cout << "Write id of two segments and distance" << endl;
					cin >> id1 >> id2 >> d;
					List_.push_back(id1);
					List_.push_back(id2);
					Cor.addRestriction(&List_, &d, RT_P2SDISTEX);
					break;
				}
				case 'e': {
					int id1, id2;
					double d;
					cout << "Segment:" << endl;
					outputSegment(&Cor);
					List <unsigned> List_;
					cout << "Write id of two segments and angle" << endl;
					cin >> id1 >> id2 >> d;
					List_.push_back(id1);
					List_.push_back(id2);
					Cor.addRestriction(&List_, &d, RT_S2SANGLE);
					break;
				}
				case 'f': {
					int id1, id2;
					cout << "Segment:" << endl;
					outputSegment(&Cor);
					List <unsigned> List_;
					cout << "Write id of two segments" << endl;
					cin >> id1 >> id2;
					List_.push_back(id1);
					List_.push_back(id2);
					Cor.addRestriction(&List_, 0, RT_S2SEQUALS);
					break;
				}
				case 'g': {
					int id1, id2;
					cout << "Segment:" << endl;
					outputSegment(&Cor);
					List <unsigned> List_;
					cout << "Write id of two segments" << endl;
					cin >> id1 >> id2;
					List_.push_back(id1);
					List_.push_back(id2);
					Cor.addRestriction(&List_, 0, RT_S2SPARAL);
					break;
				}
				case 'h': {
					int id1, id2;
					cout << "Segment:" << endl;
					outputSegment(&Cor);
					List <unsigned> List_;
					cout << "Write id of two segments" << endl;
					cin >> id1 >> id2;
					List_.push_back(id1);
					List_.push_back(id2);
					Cor.addRestriction(&List_, 0, RT_S2SORTHO);
					break;
						}
					}
				}
			}

		}

	}

	void outputPoint(Core *Cor) {
		List<GraphPrimitive*>::Marker mar(Cor->objects);
		for (size_t i = 0; i < Cor->objects.sizeList();i++){
			if (mar.get_current()->object_type() == IsPoint) {
				//cout << "hello" << endl;
				Point *newpoint = dynamic_cast<Point*>(mar.get_current());
				cout << "id = " << newpoint->showId() << "   x = " << newpoint->getX() << "   y = " << newpoint->getY() << endl;
			}
				mar.move_next();
		}
	}

	void outputSegment(Core *Cor) {
		List<GraphPrimitive*>::Marker mar(Cor->objects);
		for (size_t i = 0;i < Cor->objects.sizeList();i++) {
			if (mar.get_current()->object_type() == IsSegment) {
				Segment *newsegment = dynamic_cast<Segment*>(mar.get_current());
				cout << "id = " << newsegment->showId() << "   x1 = " << newsegment->x1() << "   y1 = " << newsegment->y1() << "   x2 = " << newsegment->x2() << "   y2 = " << newsegment->y2() << endl;
			}
			mar.move_next();
		}
	}

	void outputAll(Core *Cor) {
		List<GraphPrimitive*>::Marker mar(Cor->objects);
		for (size_t i = 0; i < Cor->objects.sizeList(); i++) {
			cout << mar.get_current()->showId() <<"       " << mar.get_current()->object_type() << endl;
			mar.move_next();
		}
	}

	void outputRestr(Core *Cor) {
		List<BasicRestriction*>::Marker mar(Cor->restrictions);
		for (size_t i = 0; i < Cor->restrictions.sizeList(); i++) {
		//	cout << mar.get_current->get_type() << endl;
			mar.move_next();
		}
	}
};
#endif
