#include <iostream>
#include <string>


struct Point {
    unsigned long long const x, y;
    Point(unsigned long long x, unsigned long long y): x(x), y(y) {}

    Point minx(Point const &rha) const {
        return Point(rha.x < x ? rha.x : x, y );
    }

    Point miny(Point const &rha) const {
    return Point(x, rha.y < y ? rha.y : y);
    }

    Point maxx(Point const &rha) const {
    return Point(rha.x > x ? rha.x : x, y);
    }

    Point maxy(Point const &rha) const {
        return Point(x, rha.y > y ? rha.y : y);
    }

    void print() const {
        std::cout << '(' << x << ',' << y << ')' ;
    }
};

struct Rectangle {
    Point pt;

    Rectangle(): Rectangle(Point(0, 0)) {}
    Rectangle(const Point &pt): pt(pt) {}
    Rectangle operator+(Rectangle const &rha) const {
        return Rectangle(Point(pt.maxx(rha.pt).x, pt.maxy(rha.pt).y));
    }
    Rectangle operator*(Rectangle const &rha) const {
        return Rectangle(Point(pt.minx(rha.pt).x, pt.miny(rha.pt).y));
    }

    void print() const {
        std::cout << '(' << pt.x << ',' << pt.y << ')' ;
    }
};


void stringDel(std::string &st, int from, int to)
{
    std::string str = "";
    for (int i = 0; i < st.length(); i++)
    {
        if (i < from || i > to)
            str+=st[i];
    }
    st = str;
}

void stringInsert(std::string &st, int idx, std::string s)
{
    std::string str = "";
    for (int i = 0; i < st.length(); i++)
    {
        if (i == idx){
            str+=s;
        }
        str+=st[i];
    }
    st = str;
}


int main () {
    // reading the string
    std::string expression;
    std::getline(std::cin, expression);
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == ' ') {
            stringDel(expression, i, i);
            i--;
        }
    }

    int open = -1, close = -1, comma1 = -1, comma2 = -1; // indexes
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == '(') {
            open = i;
        }
        if (expression[i] == ',') {
            comma1 = i;
        }
        if (expression[i] == '*') { // firstly we do multiplication
            for (int j = i + 2; j < expression.length(); j++) {
                if (expression[j] == ',') {
                    comma2 = j;
                }
                if (expression[j] == ')') {
                    close = j;
                    break;
                }
            }

            std::string x1 = "", y1 = "", x2 = "", y2 = ""; // writing all coords to strings
            for (int j = open + 1; j < comma1; j++) {
                x1 += expression[j];
            }
            for (int j = comma1 + 1; j < i-1; j++) {
                y1 += expression[j];
            }
            for (int j = i + 2; j < comma2; j++) {
                x2 += expression[j];
            }
            for (int j = comma2 + 1; j < close; j++) {
                y2 += expression[j];
            }

            // multiplication at the object level
            Rectangle rect_temp = Rectangle(Point(std::stoi(x1),std::stoi(y1)))
                    * Rectangle(Point(std::stoi(x2),std::stoi(y2)));
            // changing (..,..)*(..,..) to answer (..,..)
            std::string str_ins = std::to_string(rect_temp.pt.x) + ',' + std::to_string(rect_temp.pt.y);
            stringDel(expression, open+1, close-1);
            stringInsert(expression, open+1, str_ins);
            i = open-1; //return to the position of the first bracket
            open = -1; close = -1; comma1 = -1; comma2 = -1;
        }
    }

    // repeat with '+'
    open = -1; close = -1; comma1 = -1; comma2 = -1;
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == '(') {
            open = i;
        }
        if (expression[i] == ',') {
            comma1 = i;
        }
        if (expression[i] == '+') {
            for (int j = i + 2; j < expression.length(); j++) {
                if (expression[j] == ',') {
                    comma2 = j;
                }
                if (expression[j] == ')') {
                    close = j;
                    break;
                }
            }

            std::string x1 = "", y1 = "", x2 = "", y2 = "";
            for (int j = open + 1; j < comma1; j++) {
                x1 += expression[j];
            }
            for (int j = comma1 + 1; j < i-1; j++) {
                y1 += expression[j];
            }
            for (int j = i + 2; j < comma2; j++) {
                x2 += expression[j];
            }
            for (int j = comma2 + 1; j < close; j++) {
                y2 += expression[j];
            }

            Rectangle rect_temp = Rectangle(Point(std::stoi(x1),std::stoi(y1)))
                                  + Rectangle(Point(std::stoi(x2),std::stoi(y2)));
            std::string str_ins = std::to_string(rect_temp.pt.x) + ',' + std::to_string(rect_temp.pt.y);
            stringDel(expression, open+1, close-1);
            stringInsert(expression, open+1, str_ins);
            i = open-1;
            open = -1; close = -1; comma1 = -1; comma2 = -1;
        }
    }
    std::cout << expression;

    return 0;
}