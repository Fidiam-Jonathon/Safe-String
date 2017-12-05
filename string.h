/*********************
* Final Project
* Secure String Class
* Author: Jonathon Fidiam
* Summary: this file contains a secure version of the STL string class
* display, accept input, append and compare features are implemented
* in an efficient way
**********************/
#include <iostream>

class String{
	private:
	int size;
	int capacity;
	char* text;

	public:
	int getSize() const {return size;}
	char* getString() const {return text;}
	int getStringTotal() const;

	String(){
		size = 0;
		capacity = 2;
		text = new char[capacity];

		for (int i = 0; i < capacity; i++){
            text[i] = 0;
		}

	}

	String(char* txt){

		size = 0;
		capacity = 2;
		text = new char[capacity];
		for (char* p = txt; *p; p++){
            if (size == capacity)
            expand();

			text[size] = *p;
			size++;
		}
		text[size] = 0;

	}
	~String(){

	    delete [] text;
	    size = 0;
	}


	void clear(){
	    for (int i = 0; i < capacity; i++)
            text[i] = '\0';
        size = 0;
	}
	String& operator = (const String &s1);
	String& operator = (char* c1);
	String& operator = (char c1);

	std::istream & getline(std::istream &in);

	bool isEqual(const String &s1);
	bool isEqual (char c1[]);

	void expand();
	void append(const String &s1);
	void append(char txt[]);

	friend std::ostream & operator << (std::ostream &out, const String &s1);
	friend std::istream & operator >> (std::istream &in, String &s1);

	String& operator += (const String &s2);
	String& operator += (char c1[]);

};

String operator + (const String &s1, const String &s2);
String operator + (const String &s1, char c1[]);

bool operator > (const String &s1, const String &s2);
bool operator > (char c1[], const String &s1);
bool operator > (const String &s1, char c1[]);
bool operator >= (const String &s1, const String &s2);
bool operator >= (char c1[], const String &s1);
bool operator >= (const String &s1, char c1[]);
bool operator == (const String &s1, const String &s2);
bool operator == (char c1[], const String &s1);
bool operator == (const String &s1, char c1[]);
bool operator != (const String &s1, const String &s2);
bool operator != (char c1[], const String &s1);
bool operator != (const String &s1, char c1[]);
bool operator < (const String &s1, const String &s2);
bool operator < (char c1[], const String &s1);
bool operator < (const String &s1, char c1[]);
bool operator <= (const String &s1, const String &s2);
bool operator <= (char c1[], const String &s1);
bool operator <= (const String &s1, char c1[]);
