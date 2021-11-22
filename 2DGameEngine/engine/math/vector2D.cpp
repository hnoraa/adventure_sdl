#include "vector2D.h"

Vector2D::Vector2D()
{
	x = 0.0f;
	y = 0.0f;
}

Vector2D::Vector2D(float mX, float mY)
{
	x = mX;
	y = mY;
}

Vector2D& Vector2D::Add(const Vector2D& mVec)
{
	x += mVec.x;
	y += mVec.y;

	return *this;
}

Vector2D& Vector2D::Subtract(const Vector2D& mVec)
{
	x -= mVec.x;
	y -= mVec.y;

	return *this;
}

Vector2D& Vector2D::Multiply(const Vector2D& mVec)
{
	x *= mVec.x;
	y *= mVec.y;

	return *this;
}

Vector2D& Vector2D::Divide(const Vector2D& mVec)
{
	x /= mVec.x;
	y /= mVec.y;

	return *this;
}

Vector2D& Vector2D::operator+=(const Vector2D& mVec)
{
	return Add(mVec);
}

Vector2D& Vector2D::operator-=(const Vector2D& mVec)
{
	return Subtract(mVec);
}

Vector2D& Vector2D::operator*=(const Vector2D& mVec)
{
	return Multiply(mVec);
}

Vector2D& Vector2D::operator/=(const Vector2D& mVec)
{
	return Divide(mVec);
}

Vector2D& operator+(Vector2D& mV1, const Vector2D& mV2)
{
	return mV1.Add(mV2);
}

Vector2D& operator-(Vector2D& mV1, const Vector2D& mV2)
{
	return mV1.Subtract(mV2);
}

Vector2D& operator*(Vector2D& mV1, const Vector2D& mV2)
{
	return mV1.Multiply(mV2);
}

Vector2D& operator/(Vector2D& mV1, const Vector2D& mV2)
{
	return mV1.Divide(mV2);
}

Vector2D& Vector2D::operator*(const int& mI)
{
	x *= mI;
	y *= mI;

	return *this;
}

Vector2D& Vector2D::Zero()
{
	x = 0.0f;
	y = 0.0f;

	return *this;
}

std::ostream& operator<<(std::ostream& mStream, const Vector2D& mVec)
{
	mStream << "(" << mVec.x << "," << mVec.y << ")";
	return mStream;
}