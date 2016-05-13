#ifndef _RESTRICT_TYPES_H
#define _RESTRICT_TYPES_H

enum RestrictType{
	RT_FIX,
	RT_P2PDIST, // Расстояние между точками
	RT_P2SDIST, // Расстояние между точкой и прямой, содержащей отрезок
	RT_P2SDISTEX, // Минимальное расстояние между точкой и точками отрезка

	RT_S2SANGLE, // Угол между отрезками
	RT_S2SORTHO, // Отрезки ортогональны
	RT_S2SPARAL, // Отрезки параллельны
	RT_S2SEQUALS, // Равенство длин отрезков	
	RT_UNFIX
};


#endif