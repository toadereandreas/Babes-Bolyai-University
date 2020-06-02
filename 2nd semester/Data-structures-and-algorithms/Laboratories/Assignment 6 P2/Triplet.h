#ifndef ASSIGNMENT_6_P2_TRIPLET_H
#define ASSIGNMENT_6_P2_TRIPLET_H
typedef int TElem;

class Triplet{
private:
    int line;
    int column;
    TElem value;
public:
    // Default constructor
    Triplet(){}

    // Contructor
    Triplet( int _line, int _column, TElem _value ): line{_line}, column{_column}, value{_value} {}

    // Getters
    TElem getValue() const { return this->value; }
    int getLine() const { return this->line; }
    int getColumn() const { return this->column; }

    // Setters
    void setValue( int _value ) { this->value = _value; }
    void setColumn( int _column ) { this->column = _column; }
    void setLine( int _line ) { this->line = _line; }

    // Create an triplet with i and j equal to -1 and value = 0
    void initialize() { this->setLine(-1);
                        this->setColumn(-1);
                        this->setValue(0);}

    // Prints a triplet if it's valid
    void print() {
        //if( this->line != -1 && this->column != -1)
            std::cout << this->getLine() << ' ' << this->getColumn() << ' ' << this->getValue() << '\n'; }
};

#endif //ASSIGNMENT_6_P2_TRIPLET_H