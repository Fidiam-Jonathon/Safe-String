#include "string.h"
using namespace std;


/**********************************
* OPERATOR +
* adds two string objects together
***********************************/
String operator + (const String &s1, const String &s2)
{
    String s3;
    s3.append(s1);
    s3.append(s2);
    return s3;
}

String operator + (const String &s1, char c1[])
{
    String s2;
    s2.append(s1);
    s2.append(c1);

    return s2;
}

/*****************************************
* OPERATOR +=
* appends a second string onto the first
*****************************************/
String& String ::  operator += (const String &s2)
{
    append(s2);

    return *this;
}

String& String ::  operator += (char c1[])
{
    append(c1);

    return *this;
}

/*********************************************
* OPERATOR <<
* outputs the contents of the string objects
* to the console
*********************************************/
ostream & operator << (std::ostream &out, const String &s1){
    int i = 0;
    while (s1.text[i]){
        cout << s1.text[i];
        i++;
    }
    return out;
}

/*********************************
* OPERATOR >>
* accepts input from the keyboard
**********************************/
istream & operator >> (istream &in, String &s1)
{

    if (in.peek() == '\n')
        in.ignore();
    char c = 0;
    int i = 0;

    while (c != '\n')
    {
        if (c == ' ')
        break;

        s1.text[i] = in.get();
        i++;
        s1.size++;
        c = in.peek();
    }

    if (in.peek() == '\n')
        in.ignore();
    if (in.peek() == ' ')
        in.ignore();
    s1.text[s1.size] = 0;


    return in;
}

/*******************************************************
* OPERATOR >
* greater than comparison
* works for comparing string objects or c-string
******************************************************/
bool operator > (const String &s1, const String &s2)
{
    return s1.getStringTotal() > s2.getStringTotal();
}

bool operator > (char c1[], const String &s1)
{
    int num = 0;
    for (char* p = c1; *p; p++)
        num += *p;
    return num > s1.getStringTotal();
}

bool operator > (const String &s1, char c1[])
{
    int num = 0;
    for (char* p = c1; *p; p++)
        num += *p;
    return s1.getStringTotal() > num;
}

/***************************************************
* OPERATOR >=
* greater than or equal to comparison
* works for string objects or c-string comparisons
***************************************************/
bool operator >= (const String &s1, const String &s2)
{
    return s1.getStringTotal() >= s2.getStringTotal();
}

bool operator >= (char c1[], const String &s1)
{
    int num = 0;
    for (char* p = c1; *p; p++)
        num += *p;
    return num >= s1.getStringTotal();
}

bool operator >= (const String &s1, char c1[])
{
    int num = 0;
    for (char* p = c1; *p; p++)
        num += *p;
    return s1.getStringTotal() >= num;
}

/***************************************************
* OPERATOR ==
* equivelence comparison
* works for string objects and c-string comparisons
****************************************************/
bool operator == (const String &s1, const String &s2)
{
    return s1.getStringTotal() == s2.getStringTotal();
}

bool operator == (char c1[], const String &s1)
{
    int num = 0;
    for (char* p = c1; *p; p++)
        num += *p;
    return num == s1.getStringTotal();
}

bool operator == (const String &s1, char c1[])
{
    int num = 0;
    for (char* p = c1; *p; p++)
        num += *p;
    return s1.getStringTotal() == num;
}

/***************************************************
* OPERATOR !=
* not equals comparison
* works for string objects or c-string comparisons
***************************************************/
bool operator != (const String &s1, const String &s2)
{
    return s1.getStringTotal() != s2.getStringTotal();
}

bool operator != (char c1[], const String &s1)
{
    int num = 0;
    for (char* p = c1; *p; p++)
        num += *p;
    return num != s1.getStringTotal();
}

bool operator != (const String &s1, char c1[])
{
    int num = 0;
    for (char* p = c1; *p; p++)
        num += *p;
    return s1.getStringTotal() != num;
}

/****************************************************
* OPERATOR <
* less than comparison
* works for string objects and c-string comparisons
****************************************************/
bool operator < (const String &s1, const String &s2)
{
    return s1.getStringTotal() < s2.getStringTotal();
}

bool operator < (char c1[], const String &s1)
{
    int num = 0;
    for (char* p = c1; *p; p++)
        num += *p;
    return num < s1.getStringTotal();
}

bool operator < (const String &s1, char c1[])
{
    int num = 0;
    for (char* p = c1; *p; p++)
        num += *p;
    return s1.getStringTotal() < num;
}

/***************************************************
* OPERATOR <=
* less than or equal to comparison
* works for string objects or c-strings comparisons
***************************************************/
bool operator <= (const String &s1, const String &s2)
{
    return s1.getStringTotal() <= s2.getStringTotal();
}

bool operator <= (char c1[], const String &s1)
{
    int num = 0;
    for (char* p = c1; *p; p++)
        num += *p;
    return num <= s1.getStringTotal();
}

bool operator <= (const String &s1, char c1[])
{
    int num = 0;
    for (char* p = c1; *p; p++)
        num += *p;
    return s1.getStringTotal() <= num;
}

/******************************
* GETLINE
* reads an entire line of text
*******************************/
istream & String :: getline(istream &in)
{

    char c = 0;

    int i = 0;
    while (c != '\n')
    {
        text[i] = in.get();
        size++;
        i++;
        c = in.peek();
        if (size == capacity)
            expand();

    }
    text[size] = 0;
    in.ignore(256, '\n');
    in.clear();

    return in;

}

/******************************************
* IS equal
* returns TRUE if the param is the same
* as the string, if not FALSE is returned
******************************************/
bool String :: isEqual(const String &s1)
{
    for (int i = 0; i < size; i++)
    {
        if (text[i] != s1.text[i])
            return false;
    }
    return true;
}

bool String :: isEqual(char c1[])
{
    for (int i = 0; i < size; i++)
    {
        if (text[i] != c1[i])
            return false;
    }
    return true;
}

/**********************************************
* GET STRING TOTAL
* this adds up all the characters in a string
* and returns it as an int
**********************************************/
int String :: getStringTotal() const
{
    int total = 0;
    int i = 0;
    while (text[i]){
        total += text[i];
        i++;
    }

    return total;
}

/*******************************************
* EXPAND
* if the size == capacity time to allocate
* a new string
*******************************************/
void String :: expand(){


    capacity *= 2;
    char* newText = new char[capacity];

    for (int i = 0; i < size; i++)
        newText[i] = text[i];

    delete [] text;
    text = newText;
}

/******************************
* APPEND
* adds one string onto another
******************************/
void String :: append(const String &s1){

    int i = 0;

    while (s1.text[i]){
        if (size == capacity)
            this->expand();

        this->text[size] = s1.text[i];
        size++;
        i++;
    }
    this->text[size] = 0;
}

void String :: append(char txt[]){

    int i = 0;

    while (txt[i])
    {
        if (size == capacity)
            expand();

        text[size] = txt[i];
        i++;
        size++;
    }

  text[size] = 0;
}

/*************************
* OPERATOR =
* assigns rhs to the lhs
*************************/
String& String :: operator = (const String &s1){
    if (this->capacity < s1.capacity){
        delete [] this->text;
        this->capacity = s1.capacity;

        text = new char[capacity];

    }
    this->clear();
    this->append(s1);

    return *this;
}

String& String :: operator = (char* c1){

    // clear the string
    for (int i = 0; i < capacity; i++)
        text[i] = 0;

    // copy over c1 to text and find size
    int num = 0;
    for (char * p = c1; *p; p++){
        text[num] = *p;
        num++;
    }
    size = num;

    return *this;

}

String& String :: operator = (char c1){

    //copy over a single character

    for (int i = 0; i < size; i++)
        text[i] = 0;

    size = 1;
    text[0] = c1;

    return *this;

}
