/**
*	Preco Helper Library
*	Copyright (C) by Plusb Preco
*
*/

template <typename T>
inline Vector2<T>::Vector2(T X, T Y) :
x{X},
y{Y}
{
}

template <typename T>
template <typename Y>
inline Vector2<T>::Vector2(const Vector2<Y>& other) :
Vector2<T>(static_cast<T>(other.x), static_cast<T>(other.y))
{
}

template <typename T>
inline Vector2<T> Vector2<T>::polar(float length, float rads)
{
	return {static_cast<T>(length * std::cos(rads)), static_cast<T>(length * std::sin(rads))};
}

template <typename T>
inline Vector2<T> Vector2<T>::polar(double length, double rads)
{
	return {static_cast<T>(length * std::cos(rads)), static_cast<T>(length * std::sin(rads))};
}

template <typename T>
inline bool Vector2<T>::isEmpty() const
{
	return !(x || y);
}

template <typename T>
inline void Vector2<T>::fillTo(T fill)
{
	x = fill;
	y = fill;
}

template <typename T>
inline void Vector2<T>::clear()
{
	x = T{};
	y = T{};
}

template <typename T>
inline double Vector2<T>::length() const
{
	return std::sqrt(x * x + y * y);
}

template <typename T>
inline double Vector2<T>::dotProduct(const Vector2<T>& other) const
{
	return x * other.x + y * other.y;
}

template <typename T>
inline double Vector2<T>::crossProduct(const Vector2<T>& other) const
{
	return x * other.y - y * other.x;
}

template <typename T>
double Vector2<T>::angle(const Vector2<T>& other) const
{
	double temp1{other.x - x};
	double temp2{other.y - y};

	double destAngle{std::atan2(temp2, temp1)};

	if (destAngle < 0)
		destAngle += PI * 2;

	return destAngle;
}

template <typename T>
inline double Vector2<T>::distance(const Vector2<T>& other) const
{
	T temp1{other.x - x};
	T temp2{other.y - y};

	return std::sqrt(temp1 * temp1 + temp2 * temp2);
}

template <typename T>
inline Vector2<T> Vector2<T>::interpolate(const Vector2<T>& other, float tweenFactor) const
{
	return {static_cast<T>(tweenFactor * (other.x - x) + x), static_cast<T>(tweenFactor * (other.y - y) + y)};
}

template <typename T>
inline void Vector2<T>::normalize(float scale)
{
	double invScale{scale / std::sqrt(x * x + y * y)};

	x *= invScale;
	y *= invScale;
}

template <typename T>
inline Vector2<T> operator -(const Vector2<T>& right)
{
	return {-right.x, -right.y};
}

template <typename T>
inline Vector2<T>& operator +=(Vector2<T>& left, const Vector2<T>& right)
{
	left.x += right.x;
	left.y += right.y;

	return left;
}

template <typename T>
inline Vector2<T>& operator +=(Vector2<T>& left, T right)
{
	left.x += right;
	left.y += right;

	return left;
}

template <typename T>
inline Vector2<T> operator +(const Vector2<T>& left, const Vector2<T> right)
{
	return {left.x + right.x, left.y + right.y};
}

template <typename T>
inline Vector2<T> operator +(const Vector2<T>& left, T right)
{
	return {left.x + right, left.y + right};
}

template <typename T>
inline Vector2<T>& operator -=(Vector2<T>& left, const Vector2<T>& right)
{
	left.x -= right.x;
	left.y -= right.y;

	return left;
}

template <typename T>
inline Vector2<T>& operator -=(Vector2<T>& left, T right)
{
	left.x -= right;
	left.y -= right;

	return left;
}

template <typename T>
inline Vector2<T> operator -(const Vector2<T>& left, const Vector2<T>& right)
{
	return {left.x - right.x, left.y - right.y};
}

template <typename T>
inline Vector2<T> operator -(const Vector2<T>& left, T right)
{
	return {left.x - right, left.y - right};
}

template <typename T>
inline Vector2<T>& operator *=(Vector2<T>& left, const Vector2<T>& right)
{
	left.x *= right.x;
	left.y *= right.y;

	return left;
}

template <typename T>
inline Vector2<T>& operator *=(Vector2<T>& left, T right)
{
	left.x *= right;
	left.y *= right;

	return left;
}

template <typename T>
inline Vector2<T> operator *(const Vector2<T>& left, const Vector2<T>& right)
{
	return {left.x * right.x, left.y * right.y};
}

template <typename T>
inline Vector2<T> operator *(const Vector2<T>& left, T right)
{
	return {left.x * right, left.y * right};
}

template <typename T>
inline Vector2<T>& operator /=(Vector2<T>& left, const Vector2<T>& right)
{
	left.x /= right.x;
	left.y /= right.y;

	return left;
}

template <typename T>
inline Vector2<T>& operator /=(Vector2<T>& left, T right)
{
	left.x /= right;
	left.y /= right;

	return left;
}

template <typename T>
inline Vector2<T> operator /(const Vector2<T>& left, const Vector2<T>& right)
{
	return {left.x / right.x, left.y / right.y};
}

template <typename T>
inline Vector2<T> operator /(const Vector2<T>& left, T right)
{
	return {left.x / right, left.y / right};
}

template <typename T>
inline bool operator <(const Vector2<T>& left, const Vector2<T>& right)
{
	return (left.x < right.x) && (left.y < right.y);
}

template <typename T>
inline bool operator <=(const Vector2<T>& left, const Vector2<T>& right)
{
	return !(right < left);
}

template <typename T>
inline bool operator >(const Vector2<T>& left, const Vector2<T>& right)
{
	return right < left;
}

template <typename T>
inline bool operator >=(const Vector2<T>& left, const Vector2<T>& right)
{
	return !(left < right);
}

template <typename T>
inline bool operator ==(const Vector2<T>& left, const Vector2<T>& right)
{
	return (left.x == right.x) && (left.y == right.y);
}

template <typename T>
inline bool operator !=(const Vector2<T>& left, const Vector2<T>& right)
{
	return !(left == right);
}