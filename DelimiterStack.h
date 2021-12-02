//
// Created by jshbs on 11/10/2021.
//

#ifndef PROJECT_4_DELIMITERSTACK_H
#define PROJECT_4_DELIMITERSTACK_H
class DelimiterStack{
private:
    struct DelimiterNode{
        char character;
        int lineNumber;
        int charCount;
        DelimiterNode *nextNode;
    };

    DelimiterNode *top;

public:

    //constructor
    DelimiterStack(){top = nullptr;}

    //destructor
    ~DelimiterStack();

    //stack operations
    void push(char, int, int);
    void popDelimiter(char&, int&, int&);
    bool isEmpty();

};

#endif //PROJECT_4_DELIMITERSTACK_H
