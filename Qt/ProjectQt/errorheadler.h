#ifndef ERRORHEADLER_H
#define ERRORHEADLER_H
#include <QString>

enum ErrorType{
    CHOICE_RESTR,
    CHOICE_OBJ,
    ADD_OBJ,
    ADD_RESTR,
    FATAL_ADD_OBJ,
    FATAL_ADD_RESTR,
    UNCORRECT_RESTR,
    UNCORRECT_OBJ,
};




class ErrorHeadler {
public:

    ErrorHeadler(){}

    QString errorMessage(ErrorType type)
    {
        switch(type)
        {
        case CHOICE_RESTR: return "Выберите одно и ограничений"; break;
        case CHOICE_OBJ: return "Выберите один из объектов"; break;
        case FATAL_ADD_OBJ: return "Создание объекта с параметрами по умолчанию"; break;
        case ADD_OBJ: return "Объект создан";break;
        case UNCORRECT_RESTR: return "Некорректный ввод ограничений"; break;
        case ADD_RESTR: return "Ограничение добавлено"; break;
        case FATAL_ADD_RESTR: return "Ограничение не может быть добавлено"; break;
        case UNCORRECT_OBJ: return "Введите корректные параметры объекта";break;
        }
    }


};

#endif // ERRORHEADLER_H
