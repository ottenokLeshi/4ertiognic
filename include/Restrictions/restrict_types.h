#ifndef _RESTRICT_TYPES_H
#define _RESTRICT_TYPES_H

enum RestrictType{
	RT_FIX,
	RT_P2PDIST, // ���������� ����� �������
	RT_P2SDIST, // ���������� ����� ������ � ������, ���������� �������
	RT_P2SDISTEX, // ����������� ���������� ����� ������ � ������� �������

	RT_S2SANGLE, // ���� ����� ���������
	RT_S2SORTHO, // ������� ������������
	RT_S2SPARAL, // ������� �����������
	RT_S2SEQUALS, // ��������� ���� ��������	
	RT_UNFIX
};


#endif