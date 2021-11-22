#pragma once

#ifndef VECTOR_2D_H
#define VECTOR_2D_H

#include <iostream>

class Vector2D 
{
public:
	float x;
	float y;

	Vector2D();
	Vector2D(float mX, float mY);

	// not changing the vec parameter, just using it as the right side of the operator
	Vector2D& Add(const Vector2D& mVec);
	Vector2D& Subtract(const Vector2D& mVec);
	Vector2D& Multiply(const Vector2D& mVec);
	Vector2D& Divide(const Vector2D& mVec);

	// vector 2 is const because we dont need to change it, just add it to vector 1
	friend Vector2D& operator+ (Vector2D& mV1, const Vector2D& mV2);	
	friend Vector2D& operator- (Vector2D& mV1, const Vector2D& mV2);	
	friend Vector2D& operator* (Vector2D& mV1, const Vector2D& mV2);	
	friend Vector2D& operator/ (Vector2D& mV1, const Vector2D& mV2);	

	// not changing the vec parameter, just using it as the right side of the operator
	Vector2D& operator+= (const Vector2D& mVec);
	Vector2D& operator-= (const Vector2D& mVec);
	Vector2D& operator*= (const Vector2D& mVec);
	Vector2D& operator/= (const Vector2D& mVec);

	// multiply the vector by a scaling number
	Vector2D& operator*(const int& mI);

	// zero out the vectors
	Vector2D& Zero();

	// override output stream
	friend std::ostream& operator<<(std::ostream& mStream, const Vector2D& mVec);
};

#endif // !VECTOR_2D_H