#pragma once

namespace WarGrey::SCADA {
	float viewport_fit_scaling(Windows::Foundation::Size& src_size, float target_width, float target_height);
	float viewport_fit_scaling(float src_width, float src_height, float target_width, float target_height);

	bool rectangle_inside(float tlx1, float tly1, float brx1, float bry1, float tlx2, float tly2, float brx2, float bry2);
	bool rectangle_overlay(float tlx1, float tly1, float brx1, float bry1, float tlx2, float tly2, float brx2, float bry2);
	bool rectangle_contain(float tlx, float tly, float brx, float bry, float x, float y);
	bool rectangle_contain(float tlx, float tly, float brx, float bry, Windows::Foundation::Numerics::float2& pt);

	void region_fuse_point(double* lx, double* ty, double* rx, double* by, double x, double y);
	void region_fuse_point(Windows::Foundation::Numerics::float2* lt, Windows::Foundation::Numerics::float2* rb, float x, float y);
	void region_fuse_point(float* lx, float* ty, float* rx, float* by, float x, float y);

	double radians_to_degrees(double degrees);
	float degrees_to_radians(double degrees);
	double degrees_normalize(double degrees, double degrees_start = 0.0);
	float radians_normalize(float radians, double degrees_start = 0.0);

	double points_angle(Windows::Foundation::Numerics::float2& pt1, Windows::Foundation::Numerics::float2& pt2);
	double points_angle(float x1, float y1, float x2, float y2);
	double points_angle(double x1, double y1, double x2, double y2);
	float points_distance(Windows::Foundation::Numerics::float2& pt1, Windows::Foundation::Numerics::float2& pt2);
	float points_distance_squared(float x1, float y1, float x2, float y2);
	float points_distance(float x1, float y1, float x2, float y2);
	double points_distance_squared(double x1, double y1, double x2, double y2);
	double points_distance(double x1, double y1, double x2, double y2);

	void point_rotate(double x, double y, double degrees, double* rx = nullptr, double* ry = nullptr);
	void point_rotate(double x, double y, float radians, double* rx = nullptr, double* ry = nullptr);
	void point_rotate(double x, double y, double degrees, double ox, double oy, double* rx = nullptr, double* ry = nullptr);
	void point_rotate(double x, double y, float radians, double ox, double oy, double* rx = nullptr, double* ry = nullptr);

	double arc_length(float radius, double degrees0, double degreesn);

	double circle_perimeter(float radius);
	double ellipse_perimeter(float radiusX, float radiusY);

	void circle_point(float radius, float radians, float* x, float* y);
	void circle_point(float radius, double degrees, float* x, float* y);

	void ellipse_point(float radiusX, float radiusY, float radians, float* x, float* y);
	void ellipse_point(float radiusX, float radiusY, double degrees, float* x, float* y);
	
	void line_point(float x0, float y0, float x1, float y1, double ratio, float* x, float* y);
	void line_point(Windows::Foundation::Numerics::float2& pt0, Windows::Foundation::Numerics::float2& pt1, double ratio, float* x, float* y);

	double dot_product(double ax, double ay, double bx, double by);
	double cross_product(double ax, double ay, double bx, double by);
	void cross_product(double ax, double ay, double az, double bx, double by, double bz, double* x, double* y, double* z);

	void point_foot_on_segment(double px, double py, double Ax, double Ay, double Bx, double By, double* fx, double* fy);
	bool is_foot_on_segment(double px, double py, double Ax, double Ay, double Bx, double By);
	double point_segment_distance_squared(double px, double py, double Ax, double Ay, double Bx, double By);
	double point_segment_distance(double px, double py, double Ax, double Ay, double Bx, double By);

	void line_normal0_vector(double Ax, double Ay, double Bx, double By, double distance, double* nvx = nullptr, double* nvy = nullptr, double ox = 0.0, double oy = 0.0);
	void parallel_segment(double Ax, double Ay, double Bx, double By, double distance,
		double* pAx = nullptr, double* pAy = nullptr, double* pBx = nullptr, double* pBy = nullptr);

	bool lines_intersection(double x11, double y11, double x12, double y12, double x21, double y21, double x22, double y22,
		double* px, double* py, double* t1 = nullptr, double* t2 = nullptr);
}
