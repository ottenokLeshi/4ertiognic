#ifndef COLOR_H
#define COLOR_H
#define COLORSELECTED 0x3560d6
#define COLORDEF 0x000000
class Color
{
private:
    unsigned _color;
public:
    Color();
    Color(unsigned);
    ~Color();
    void setColor(unsigned long);
    void setColor(const Color&);
    void setColor(unsigned char, unsigned char, unsigned char);
    unsigned getColor(char mode = 0) const;
    unsigned red() const;
    unsigned green() const;
    unsigned blue() const;
};
#endif // COLOR_H
