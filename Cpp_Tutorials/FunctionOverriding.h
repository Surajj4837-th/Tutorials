#include<iostream>

class animal
{
public:
	void Sound();
};

class dog : public animal
{
public:
	void Sound();
};

class cat : public animal
{
public:
	void Sound();
};

class human : public animal
{
public:
	void Sound();
};