#include "datum/box.hpp"
#include "datum/flonum.hpp"

#include "math.hpp"

using namespace WarGrey::SCADA;

using namespace Windows::Foundation;
using namespace Windows::Foundation::Numerics;

inline static float quick_degrees_to_radians(double degrees) {
	return float(degrees * pi / 180.0);
}

/*************************************************************************************************/
float WarGrey::SCADA::viewport_fit_scaling(Size& src_size, float target_width, float target_height) {
	return viewport_fit_scaling(src_size.Width, src_size.Height, target_width, target_height);
}

float WarGrey::SCADA::viewport_fit_scaling(float src_width, float src_height, float target_width, float target_height) {
	return flmin(src_width / target_width, src_height / target_height);
}

bool WarGrey::SCADA::rectangle_inside(float tlx1, float tly1, float brx1, float bry1, float tlx2, float tly2, float brx2, float bry2) {
	return flin(tlx2, tlx1, brx2) && flin(tlx2, brx1, brx2) && (flin(tly2, tly1, bry2) && flin(tly2, bry1, bry2));
}

bool WarGrey::SCADA::rectangle_overlay(float tlx1, float tly1, float brx1, float bry1, float tlx2, float tly2, float brx2, float bry2) {
	return !((brx1 < tlx2) || (tlx1 > brx2) || (bry1 < tly2) || (tly1 > bry2));
}

bool WarGrey::SCADA::rectangle_contain(float tlx, float tly, float brx, float bry, float x, float y) {
	return flin(tlx, x, brx) && flin(tly, y, bry);
}

void WarGrey::SCADA::region_fuse_point(double* lx, double* ty, double* rx, double* by, double x, double y) {
	if (lx != nullptr) {
		(*lx) = flmin(*lx, x);
	}

	if (rx != nullptr) {
		(*rx) = flmax(*rx, x);
	}

	if (ty != nullptr) {
		(*ty) = flmin(*ty, y);
	}

	if (by != nullptr) {
		(*by) = flmax(*by, y);
	}
}

void WarGrey::SCADA::region_fuse_point(float2* lt, float2* rb, float x, float y) {
	if (lt != nullptr) {
		lt->x = flmin(lt->x, x);
		lt->y = flmin(lt->y, y);
	}

	if (rb != nullptr) {
		rb->x = flmax(rb->x, x);
		rb->y = flmax(rb->y, y);
	}
}

void WarGrey::SCADA::region_fuse_point(float* lx, float* ty, float* rx, float* by, float x, float y) {
	float2 lt, rb;
	
	region_fuse_point(&lt, &rb, x, y);
	SET_VALUES(lx, lt.x, ty, lt.y);
	SET_VALUES(rx, rb.x, by, rb.y);
}

double WarGrey::SCADA::radians_to_degrees(double radians) {
	return (radians / pi) * 180.0;
}

float WarGrey::SCADA::degrees_to_radians(double degrees) {
	return quick_degrees_to_radians(degrees);
}

double WarGrey::SCADA::degrees_normalize(double degrees, double degrees_start) {
	double degrees_end = degrees_start + 360.0;

	while (degrees < degrees_start) degrees += 360.0;
	while (degrees >= degrees_end) degrees -= 360.0;

	return degrees;
}

float WarGrey::SCADA::radians_normalize(float radians, double degrees_start) {
	float double_pi = pi_f * 2.0f;
	float radians_start = quick_degrees_to_radians(degrees_start);
	float radians_end = radians_start + double_pi;

	while (radians < radians_start) radians += double_pi;
	while (radians >= radians_end) radians -= double_pi;

	return radians;
}

double WarGrey::SCADA::points_angle(float2& pt1, float2& pt2) {
	return points_angle(pt1.x, pt1.y, pt2.x, pt2.y);
}

double WarGrey::SCADA::points_angle(float x1, float y1, float x2, float y2) {
	return radians_to_degrees(flatan(double(y2 - y1), double(x2 - x1)));
}

double WarGrey::SCADA::points_angle(double x1, double y1, double x2, double y2) {
	return radians_to_degrees(flatan(y2 - y1, x2 - x1));
}

float WarGrey::SCADA::points_distance(float2& pt1, float2& pt2) {
	return points_distance(pt1.x, pt1.y, pt2.x, pt2.y);
}

float WarGrey::SCADA::points_distance(float x1, float y1, float x2, float y2) {
	float dx = x2 - x1;
	float dy = y2 - y1;

	return flsqrt(dx * dx + dy * dy);
}

double WarGrey::SCADA::points_distance(double x1, double y1, double x2, double y2) {
	double dx = x2 - x1;
	double dy = y2 - y1;

	return flsqrt(dx * dx + dy * dy);
}

double WarGrey::SCADA::arc_length(float r, double deg0, double degn) {
	double theta = flabs(degn - deg0);

	return (theta >= 360.0) ? circle_perimeter(r) :  (pi * r * theta / 180.0);
}

double WarGrey::SCADA::circle_perimeter(float r) {
	return 2.0 * pi * double(r);
}

double WarGrey::SCADA::ellipse_perimeter(float a, float b) {
	return (a == b)
		? 2.0 * pi * a
		: pi * (3.0F * (a + b) - flsqrt((3.0 * a + b) * (a + 3.0 * b)));
}

void WarGrey::SCADA::circle_point(float radius, double degrees, float* x, float* y) {
	circle_point(radius, quick_degrees_to_radians(degrees), x, y);
}

void WarGrey::SCADA::circle_point(float radius, float radians, float* x, float* y) {
	SET_BOX(x, radius * flcos(radians));
	SET_BOX(y, radius * flsin(radians));
}

void WarGrey::SCADA::ellipse_point(float radiusX, float radiusY, double degrees, float* x, float* y) {
	ellipse_point(radiusX, radiusY, quick_degrees_to_radians(degrees), x, y);
}

void WarGrey::SCADA::ellipse_point(float radiusX, float radiusY, float radians, float* x, float* y) {
	SET_BOX(x, radiusX * flcos(radians));
	SET_BOX(y, radiusY * flsin(radians));
}

void WarGrey::SCADA::line_point(float x0, float y0, float x1, float y1, double ratio, float* x, float* y) {
	float flratio = float(ratio);

	SET_BOX(x, (x0 - x1) * flratio + x1);
	SET_BOX(y, (y0 - y1) * flratio + y1);
}
