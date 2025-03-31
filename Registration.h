#pragma once
#define _CRT_SECURE_NO_WARNINGS 

class Registration {
public:
	char num[9];
	bool IsValid(const char* str);
	bool areEqual(const char* str1) const;
	bool IsEmpty(const char* str);

	Registration() = delete;
	Registration(const char* str);
	Registration& operator=(const char* str);
	bool operator==(const Registration& rhs) const;
	const char* toString() const;

};
