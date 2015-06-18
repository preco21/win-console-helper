/**
*	Preco Helper Library
*	Copyright (C) by Plusb Preco
*
*/

#ifndef PRECO_VECTOR_2_HPP
#define PRECO_VECTOR_2_HPP

#include "MathHelper.hpp"
#include <cmath>

namespace preco
{
	template <typename T>
	class Vector2
	{
	public :
	
		// 기본생성자
		Vector2() = default;

		// 2개의 인자를 받아 Vector2를 생성
		Vector2(T X, T Y);

		// 다른타입의 Vector2를 복사
		template <typename Y>
		explicit Vector2(const Vector2<Y>& other);
	
		// (0, 0)부터 length를 길이로 하고 rads만큼 회전한 점을 Vector2로 반환
		// rads는 라디안 단위
		// Vector2 전용
		static Vector2<T> polar(float length, float rads);

		// (0, 0)부터 length를 길이로 하고 rads만큼 회전한 점을 Vector2로 반환
		// rads는 라디안 단위
		// Vector2 전용
		static Vector2<T> polar(double length, double rads);

		// 비어있는지 체크 x, y가 0이면 true를 반환
		bool isEmpty() const;

		// Vector2의 x, y를 하나의 값으로 지정
		void fillTo(T fill);

		// Vector2를 초기화
		void clear();

		// (0, 0)으로 부터의 길이를 측정
		double length() const;

		// Vector2 내적을 구함
		double dotProduct(const Vector2<T>& other) const;

		// Vector2 외적을 구함
		double crossProduct(const Vector2<T>& other) const;

		// 두 점의 각도를 반환 (라디안 단위)
		// 반환하는 각도계는 0 ~ -180
		// 만약 360분법의 각도를 구하고 싶다면 이 함수의 값이 0 이하일 경우 360도를 더해준다
		double angle(const Vector2<T>& other) const;
	
		// other 사이의 거리를 반환
		double distance(const Vector2<T>& other) const;

		// 두 Vector2 사이의 점을 반환
		// tweenFactor는 보간지수
		Vector2<T> interpolate(const Vector2<T>& other, float tweenFactor = 0.5f) const;

		// 점을 (0, 0)으로 부터 정규화 (scale 만큼의 단위백터로 만듭니다)
		void normalize(float scale = 1.0f);

		// 멤버데이터
		T x{}; // X
		T y{}; // Y
	};

	// -단항연산자
	template <typename T>
	Vector2<T> operator -(const Vector2<T>& right);

	// +연산자
	template <typename T>
	Vector2<T>& operator +=(const Vector2<T>& left, const Vector2<T>& right);
	template <typename T>
	Vector2<T>& operator +=(const Vector2<T>& left, T right);
	template <typename T>
	Vector2<T> operator +(const Vector2<T>& left, const Vector2<T> right);
	template <typename T>
	Vector2<T> operator +(const Vector2<T>& left, T right);

	// -연산자
	template <typename T>
	Vector2<T>& operator -=(const Vector2<T>& left, const Vector2<T>& right);
	template <typename T>
	Vector2<T>& operator -=(const Vector2<T>& left, T right);
	template <typename T>
	Vector2<T> operator -(const Vector2<T>& left, const Vector2<T> right);
	template <typename T>
	Vector2<T> operator -(const Vector2<T>& left, T right);

	// *연산자
	template <typename T>
	Vector2<T>& operator *=(const Vector2<T>& left, const Vector2<T>& right);
	template <typename T>
	Vector2<T>& operator *=(const Vector2<T>& left, T right);
	template <typename T>
	Vector2<T> operator *(const Vector2<T>& left, const Vector2<T>& right);
	template <typename T>
	Vector2<T> operator *(const Vector2<T> left, T right);

	// /연산자
	template <typename T>
	Vector2<T>& operator /=(const Vector2<T>& left, const Vector2<T>& right);
	template <typename T>
	Vector2<T>& operator /=(const Vector2<T>& left, T right);
	template <typename T>
	Vector2<T> operator /(const Vector2<T>& left, const Vector2<T>& right);
	template <typename T>
	Vector2<T> operator /(const Vector2<T>& left, T right);

	// 비교연산자
	template <typename T>
	bool operator <(const Vector2<T>& left, const Vector2<T>& right);
	template <typename T>
	bool operator <=(const Vector2<T>& left, const Vector2<T>& right);
	template <typename T>
	bool operator >(const Vector2<T>& left, const Vector2<T>& right);
	template <typename T>
	bool operator >=(const Vector2<T>& left, const Vector2<T>& right);
	template <typename T>
	bool operator ==(const Vector2<T>& left, const Vector2<T>& right);
	template <typename T>
	bool operator !=(const Vector2<T>& left, const Vector2<T>& right);

	// 구현파일 포함
	#include "Vector2.inl"

	// 타입정의
	using Vector2i = Vector2<int>;
	using Vector2u = Vector2<unsigned int>;
	using Vector2f = Vector2<float>;
	using Vector2d = Vector2<double>;

} // namespace preco

#endif // PRECO_VECTOR_2_HPP