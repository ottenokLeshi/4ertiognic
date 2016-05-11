#ifndef _PARAMETR_
#define _PARAMETR_
#include <string>
#include <vector>
#include "core.h"

using namespace std;

class parametr {
	string _s;
	double _value;
	Core *_Core;
public:
	parametr(string s, Core *_core) {
	_s = s; 
	_Core = _core;
	_value = calc(_s); 	
	}

	double get_val() { return _value; }

	bool delim(char c) {
		return c == ' ';
	}

	bool is_op(char c) {
		return c == '+' || c == '-' || 
			   c == '*' || c == '/' || 
			   c == '^' || c == 's';
	}
	/*
	bool isUnary(char c) {
	return c;
	}
	*/
	int priority(char op) {
		if (op < 0)
			return 4; // op == -'+' || op == -'-'
		return
			op == '+' || op == '-' ? 1 :
			op == '*' || op == '/' || 
			op == '^' || op == 's' ? 2 :
			-1;
	}

	void process_op(vector<double> & st, char op) {
		if (op < 0) {
			double l = st.back();  st.pop_back();
			switch (-op) {
			case '+':  st.push_back(l);  break;
			case '-':  st.push_back(-l);  break;
			}
		}
		else {
			double r = st.back();  st.pop_back();
			double l = st.back();  st.pop_back();
			switch (op) {
			case '+':  st.push_back(l + r);  break;
			case '-':  st.push_back(l - r);  break;
			case '*':  st.push_back(l * r);  break;
			case '/':  st.push_back(l / r);  break;
			case '^':
				double k = 1;
				for (int i = 0; i < r; i++)
					k = k*l;
				st.push_back(k);
			}
		}
	}

	double get_variable_val(string operand) {
		unsigned int id;
		string s = "";
		for (unsigned int i = 0; i < operand.length(); ++i) {//Here id is calculating
			switch ((char)operand[i]) {						 // a = 0, b = 1, c = 2 and so on
			case 'a': {										 // so, bba == 110 be careful
				s.push_back('0');
				break;
			}
			case 'b': {
				s.push_back('1');
				break;
			}
			case 'c': {
				s.push_back('2');
				break;
			}
			case 'd': {
				s.push_back('3');
				break;
			}
			case 'e': {
				s.push_back('4');
				break;
			}
			case 'f': {
				s.push_back('5');
				break;
			}
			case 'g': {
				s.push_back('6');
				break;
			}
			case 'h': {
				s.push_back('7');
				break;
			}
			case 'i': {
				s.push_back('8');
				break;
			}
			case 'j': {
				s.push_back('9');
				break;
			}
			default: {
				s = s;
				break;
			}
			}
		}
		id = atoi(s.c_str());
		if (id > _Core->sizeListRestr() || id < 1) return 0; // Add a mistake
		int type = _Core->searchIDRestr(id)->get_type();
		switch (type) {
		case 1: {
			RestrP2PDIST *newRestr = dynamic_cast<RestrP2PDIST*>(_Core->searchIDRestr(id));
			return newRestr->getDist();
			}
		case 2: {
			RestrP2SDIST *newRestr = dynamic_cast<RestrP2SDIST*>(_Core->searchIDRestr(id));
			return newRestr->getDist();
			}
		case 3:{
			RestrP2SDISTEX *newRestr = dynamic_cast<RestrP2SDISTEX*>(_Core->searchIDRestr(id));
			return newRestr->getDist();
			}
		case 4: {
			RestrS2SANGLE *newRestr = dynamic_cast<RestrS2SANGLE*>(_Core->searchIDRestr(id));
			return newRestr->getAngl();
			}
		case 5: {
			RestrS2SORTHO *newRestr = dynamic_cast<RestrS2SORTHO*>(_Core->searchIDRestr(id));
			return newRestr->getAngl();
			}
		case 6: {
			RestrS2SPARAL *newRestr = dynamic_cast<RestrS2SPARAL *>(_Core->searchIDRestr(id));
			return newRestr->getAngl();
			}
		case 7: {
			return 0;//Distance from segment to itself is null
			}
		}
		return 0;
	}


	double calc(string &s) {		 
		bool may_unary = true;
		vector<double> st;
		vector<char> op;
		for (size_t i = 0; i < s.length(); ++i)
			if (!delim(s[i]))
				if (s[i] == '(') {
					op.push_back('(');
					may_unary = true;
				}
				else if (s[i] == ')') {
					while (op.back() != '(')
						process_op(st, op.back()), op.pop_back();
					op.pop_back();
					may_unary = false;
				}
				else if (is_op(s[i])) {
					char curop = s[i];
					//if (may_unary && isUnary(curop))  curop = -curop;
					while (!op.empty() && (
						curop >= 0 && priority(op.back()) >= priority(curop)
						|| curop < 0 && priority(op.back()) > priority(curop))
						)
						process_op(st, op.back()), op.pop_back();
					op.push_back(curop);
					may_unary = true;
				}
				else {
					if (s[i] < 0 || s[i]>127) return 0;//ERROR
					string operand;
					while (i < s.length() && 
						isalnum(s[i]))
						operand += s[i++];
					--i;
					if (isdigit(operand[0]))
						st.push_back(atoi(operand.c_str()));
					else
						st.push_back(get_variable_val(operand));
					may_unary = false;
				}
				while (!op.empty())
					process_op(st, op.back()), op.pop_back();
				return st.back();
	}

};


#endif 