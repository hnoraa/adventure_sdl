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
	Vector2D(float x, float y);

	// not changing the vec parameter, just using it as the right side of the operator
	Vector2D& Add(const Vector2D& vec);
	Vector2D& Subtract(const Vector2D& vec);
	Vector2D& Multiply(const Vector2D& vec);
	Vector2D& Divide(const Vector2D& vec);

	// vector 2 is const because we dont need to change it, just add it to vector 1
	friend Vector2D& operator+ (Vector2D& v1, const Vector2D& v2);	
	friend Vector2D& operator- (Vector2D& v1, const Vector2D& v2);	
	friend Vector2D& operator* (Vector2D& v1, const Vector2D& v2);	
	friend Vector2D& operator/ (Vector2D& v1, const Vector2D& v2);	

	// not changing the vec parameter, just using it as the right side of the operator
	Vector2D& operator+= (const Vector2D& vec);
	Vector2D& operator-= (const Vector2D& vec);
	Vector2D& operator*= (const Vector2D& vec);
	Vector2D& operator/= (const Vector2D& vec);

	// multiply the vector by a scaling number
	Vector2D& operator*(const int& i);

	// zero out the vectors
	Vector2D& Zero();

	// override output stream
	friend std::ostream& operator<<(std::ostream& stream, const Vector2D& vec);
};

#endif // !VECTOR_2D_H