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

bool WarGrey::SCADA::rectangle_contain(float tlx, float tly, float brx, float bry, float2& pt) {
	return rectangle_contain(tlx, tly, brx, bry, pt.x, pt.y);
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

double WarGrey::SCADA::points_distance_squared(double x1, double y1, double x2, double y2) {
	double dx = x2 - x1;
	double dy = y2 - y1;

	return (dx * dx + dy * dy);
}

double WarGrey::SCADA::points_distance(double x1, double y1, double x2, double y2) {
	return flsqrt(points_distance_squared(x1, y1, x2, y2));
}

void WarGrey::SCADA::point_rotate(double x, double y, double degrees, double* rx, double* ry) {
	point_rotate(x, y, quick_degrees_to_radians(degrees), 0.0, 0.0, rx, ry);
}

void WarGrey::SCADA::point_rotate(double x, double y, float radians, double* rx, double* ry) {
	point_rotate(x, y, radians, 0.0, 0.0, rx, ry);
}

void WarGrey::SCADA::point_rotate(double x, double y, double degrees, double ox, double oy, double* rx, double* ry) {
	point_rotate(x, y, quick_degrees_to_radians(degrees), ox, oy, rx, ry);
}

void WarGrey::SCADA::point_rotate(double x, double y, float radians, double ox, double oy, double* rx, double* ry) {
	float cosr = flcos(radians);
	float sinr = flsin(radians);
	double dx = x - ox;
	double dy = y - oy;

	SET_BOX(rx, dx * cosr - dy * sinr + ox);
	SET_BOX(ry, dx * sinr + dy * cosr + oy);
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

void WarGrey::SCADA::line_point(float2& pt0, float2& pt1, double ratio, float* x, float* y) {
	line_point(pt0.x, pt0.y, pt1.x, pt1.y, ratio, x, y);
}

/*************************************************************************************************/
double WarGrey::SCADA::dot_product(double ax, double ay, double bx, double by) {
	return ax * bx + ay * by;
}

double WarGrey::SCADA::cross_product(double ax, double ay, double bx, double by) {
	return ax * by - ay * bx; 
}

void WarGrey::SCADA::cross_product(double ax, double ay, double az, double bx, double by, double bz, double* x, double* y, double* z) {
	SET_BOX(x, ay * bz - az * by);
	SET_BOX(y, az * bx - ax * bz);
	SET_BOX(z, ax * by - ay * bx);
}

void WarGrey::SCADA::point_foot_on_segment(double px, double py, double Ax, double Ay, double Bx, double By, double* fx, double* fy) {
	// Find the perpendicular foot F(fx, fy) of Point P(px, py) on Segment AB.

	/** Theorem
	 * In Euclidean Vector Space, the dot product of two vectors is a kind of scalar multiplication
	 * which takes direction into account. Any result of dot products has one of the three geometric
	 * meanings:
	 *   > 0: the two vectors have an acute angle.
	 *   = 0: the two vectors are perpendicular.
	 *   < 0: the two vectors have an obtuse angle.
	 *
	 * This theorem also works when the point and the segment are collinear.
	 *
	 * a). F = A + uAB
	 * b). FP·AB = 0
	 *  ==> [AP - uAB]·AB = 0
	 *  ==> u = AP·AB / ‖B - A‖²
	 */

	double ABx = Bx - Ax;
	double ABy = By - Ay;
	double u = dot_product(px - Ax, py - Ay, ABx, ABy) / points_distance_squared(Ax, Ay, Bx, By);

	SET_BOX(fx, Ax + u * ABx);
	SET_BOX(fy, Ay + u * ABy);
}

void WarGrey::SCADA::parallel_segment(double Ax, double Ay, double Bx, double By, double d, double* pAx, double* pAy, double* pBx, double* pBy) {
	// find the parallel segment pAB which is distance |d| apart from the segment AB, and
	//   should be on the left side(d > 0.0) or right side(d < 0.0) of the segment.

	/** Theorem
	* In Euclidean Vector Space, the dot product of two vectors is a kind of scalar multiplication
	* which takes direction into account. Any result of dot products has one of the three geometric
	* meanings:
	*   > 0: the two vectors have an acute angle.
	*   = 0: the two vectors are perpendicular.
	*   < 0: the two vectors have an obtuse angle.
	*
	* While, the cross product of two vectors in a plane produces a pseudovector whose i and j components are 0s
	* and whose k component can just be used as the determinant of the constructed Matrix[AP, AB]. Geometrically
	* speaking, the determinant means signed area in a plane, more precisely:
	*   > 0: positive area, P is on the left side of segment AB.
	*   = 0: P lies on segment AB.
	*   < 0: negative area, P is on the right side of segment AB.
	*
	* a). AP·AB = BP·AB = 0
	* b). ‖AP‖² = ‖BP‖² = d²
	*  ==> Px = ±d·ABy/‖AB‖
	*      Py = ∓d·ABx/‖AB‖
	*      Px = -Py * By / Bx
	*/

	double abs_d_div_AB = flabs(d) / points_distance(Ax, Ay, Bx, By);
	double abs_APx = (By - Ay) * abs_d_div_AB;
	double abs_APy = (Bx - Ax) * abs_d_div_AB;

	if (d > 0.0) {
		SET_BOX(pAx, Ax + abs_APx);
		SET_BOX(pAy, Ay - abs_APy);
		SET_BOX(pBx, Bx + abs_APx);
		SET_BOX(pBy, By - abs_APy);
	} else {
		SET_BOX(pAx, Ax - abs_APx);
		SET_BOX(pAy, Ay + abs_APy);
		SET_BOX(pBx, Bx - abs_APx);
		SET_BOX(pBy, By + abs_APy);
	}
}

bool WarGrey::SCADA::is_foot_on_segment(double px, double py, double Ax, double Ay, double Bx, double By) {
	// Test if the foot of Point P(px, py) on Segment AB actually lies on the segment.

	/** Theorem
	 * In Euclidean Vector Space, the dot product of two vectors is a kind of scalar multiplication
	 * which takes direction into account. Any result of dot products has one of the three geometric
	 * meanings:
	 *   > 0: the two vectors have an acute angle.
	 *   = 0: the two vectors are perpendicular.
	 *   < 0: the two vectors have an obtuse angle.
	 *
	 * This theorem also works when the point and the segment are collinear.
	 *
	 * Thus, the predicate is true when (AP·AB)(BP·BA) >= 0
	 */

	double AP_AB = dot_product(px - Ax, py - Ay, Bx - Ax, By - Ay);
	double BP_BA = dot_product(px - Bx, py - By, Ax - Bx, Ay - By);

	return (AP_AB * BP_BA) >= 0.0;
}

double WarGrey::SCADA::point_segment_distance_squared(double px, double py, double Ax, double Ay, double Bx, double By) {
	double fx, fy;

	point_foot_on_segment(px, py, Ax, Ay, Bx, By, &fx, &fy);

	return points_distance_squared(fx, fy, px, py);
}

double WarGrey::SCADA::point_segment_distance(double px, double py, double Ax, double Ay, double Bx, double By) {
	return flsqrt(point_segment_distance_squared(px, py, Ax, Ay, Bx, By));
}

bool WarGrey::SCADA::lines_intersection(double x11, double y11, double x12, double y12, double x21, double y21, double x22, double y22
	, double* px, double* py, double* t1, double* t2) {
	// find the intersection point P(px, py) of L1((x11, y11), (x12, y12)) and L2((x21, y21), (x22, y22))

	/** Theorem
	 * In Euclidean Vector Space, A line can be represented in vector form as L = v0 + tv,
	 * the parameter `t` can be used to detect the interval of line. More precisely, for `t`:
	 *   -inf < t < +inf, L is an infinitely long line.
	 *   0 <= t <= 1, L is a line segment.
	 *   0 <= t < +inf, L is a ray.
	 *
	 * a). L1 = (x11, y11) + t1(x12 - x11, y12 - y11)
	 * b). L2 = (x21, y21) + t2(x22 - x21, y22 - x21)
	 *  ==> t1 = + [(x11 - x21)(y21 - y22) - (y11 - y21)(x21 - x22)] / [(x11 - x12)(y21 - y22) - (y11 - y12)(x21 - x22)]
	 *      t2 = - [(x11 - x12)(y11 - y21) - (y11 - y12)(x11 - x21)] / [(x11 - x12)(y21 - y22) - (y11 - y12)(x21 - x22)]
	 *  ==> P(x11 + t1(x12 - x11), y11 + t1(y12 - y11)) or
	 *      P(x21 + t2(x22 - x21), y21 + t2(y22 - y21))
	 */

	double denominator = ((x11 - x12) * (y21 - y22) - (y11 - y12) * (x21 - x22));
	bool intersected = (denominator != 0.0);

	if (intersected) {
		double T1 = +((x11 - x21) * (y21 - y22) - (y11 - y21) * (x21 - x22)) / denominator;
		double T2 = -((x11 - x12) * (y11 - y21) - (y11 - y12) * (x11 - x21)) / denominator;

		// WARNING: client applications should check the flonum relevant errors when two lines are almost parallel 

		SET_VALUES(t1, T1, t2, T2);
		SET_BOX(px, x21 + T2 * (x22 - x21));
		SET_BOX(py, y21 + T2 * (y22 - y21));
	}

	return intersected;
}
