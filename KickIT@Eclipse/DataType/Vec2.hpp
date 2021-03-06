#ifndef VEC2_HPP_
#define VEC2_HPP_

#include <iostream>
#include <math.h>

class Vec2 {
public:
	float x;
	float y;

	Vec2() {
		x = 0;
		y = 0;
	}

	Vec2(float _x, float _y) :
			x(_x), y(_y) {

	}
	void update(float newx, float newy) {
		x = newx;
		y = newy;
	}

	void update(Vec2* newp) {
		x = newp->x;
		y = newp->y;
		//delete newp;
	}

	float dot(const Vec2& v) const {
		//skalarprodukt = laenge1 * laenge2 * cos(winkel dazwischen)
		return this->x * v.x + this->y * v.y;
	}

	float cross(const Vec2& v) const {
		return this->x * v.y - v.x * this->y;
	}

	Vec2 operator+(const Vec2& v) const {
		Vec2 result;
		result.x = this->x + v.x;
		result.y = this->y + v.y;
		return result;
	}

	Vec2 operator-(const Vec2& v) const {
		Vec2 result;
		result.x = this->x - v.x;
		result.y = this->y - v.y;
		return result;
	}

	Vec2& operator+=(const Vec2& v) {
		this->x = this->x + v.x;
		this->y = this->y + v.y;
		return *this;
	}

	Vec2 operator*(float c) const {
		Vec2 result;
		result.x = this->x * c;
		result.y = this->y * c;
		return result;
	}

	Vec2 operator-() const {
		Vec2 result;
		result.x = this->x * (-1);
		result.y = this->y * (-1);
		return result;
	}

	float lengthSquared() const {
		float lengthSquared = this->x * this->x + this->y * this->y;
		return lengthSquared;
	}

	float length() const {
		return sqrtf(this->lengthSquared());
	}

	Vec2& normalize() {
		float length = this->length();
		if (!(length == 0)) {
			float factor = 1 / length;
			this->x = this->x * factor;
			this->y = this->y * factor;
		}
		//else std::cout << "nullVec2" << std::endl;
		return *this;
	}

	Vec2 reflection(const Vec2& normal) const {
		float lengthOfProjection = this->dot(normal);
		Vec2 reflectionImpulse = normal * lengthOfProjection;
		reflectionImpulse = reflectionImpulse * 2;
		Vec2 result = *this - reflectionImpulse;
		return result;
	}

};

#endif /* VEC2_HPP_ */
