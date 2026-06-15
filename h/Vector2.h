#pragma once
#include	<Windows.h>

struct Vector2 {
	public:
	int x;
	int y;

	Vector2() : x(0), y(0) {}

	Vector2(int x, int y) : x(x), y(y) {}

	Vector2(const Vector2& other) : x(other.x), y(other.y) {}

	void operator=(const Vector2& other) {
		if (this != &other) {
			x = other.x;
			y = other.y;
		}
	}

	void operator=(const COORD& other) {
		x = other.X;
		y = other.Y;
	}

	Vector2 operator+(const Vector2& other) const {
		return Vector2(x + other.x, y + other.y);
	}

	void operator+=(const Vector2& other) {
		x += other.x; y += other.y;
	}

	void operator-() { x *= -1; y *= -1; }

	Vector2 operator-() const { return Vector2(-x, -y); }

	Vector2 operator-(const Vector2& other) const {
		return Vector2(x - other.x, y - other.y);
	}

	Vector2 operator*(float scalar) const {
		return Vector2((int)(x * scalar), (int)(y * scalar));
	}

	Vector2 operator/(float scalar) const {
		return Vector2((int)(x / scalar), (int)(y / scalar));
	}
};


class Multi : Vector2 {
public:
	Multi() : Vector2() {}
	Multi(const Vector2& multi) : Vector2(multi) {}

	int Multiplication() const { return x * y; } //縦横
	int MultiplicationMargin() const { return (x + 1) * y + 1; } //縦横 + 余白
	int MultiplicationMargin_Multi() const { return (x + 2) * y + 1; } //縦横(日本語対応) + 余白

};

class Position : Vector2 {
public:
	Position() : Vector2(){}
	Position(const Vector2& position) : Vector2(position){}

	void SetPosition(const Vector2& position) { x = position.x; y = position.y; }
	void AddPosition(const Vector2& position) { x += position.x; y += position.y; }
};