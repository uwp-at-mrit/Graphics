#pragma once

namespace WarGrey::SCADA {
	float viewport_fit_scaling(Windows::Foundation::Size& src_size, float target_width, float target_height);
	float viewport_fit_scaling(float src_width, float src_height, float target_width, float target_height);

	bool rectangle_inside(float tlx1, float tly1, float brx1, float bry1, float tlx2, float tly2, float brx2, float bry2);
	bool rectangle_overlay(float tlx1, float tly1, float brx1, float bry1, float tlx2, float tly2, float brx2, float bry2);
	bool rectangle_contain(float tlx1, float tly1, float brx1, float bry1, float x, float y);

	void region_fuse_point(double* lx, double* ty, double* rx, double* by, double x, double y);
	void region_fuse_point(Windows::Foundation::Numerics::float2* lt, Windows::Foundation::Numerics::float2* rb, float x, float y);
	void region_fuse_point(float* lx, float* ty, float* rx, float* by, float x, float y);

	double radians_to_degrees(double degrees);
	float degrees_to_radians(double degrees);
	double degrees_normalize(double degrees, double degrees_start = 0.0);
	float radians_normalize(float radians, double degrees_start = 0.0);

	double points_angle(Windows::Foundation::Numerics::float2& pt1, Windows::Foundation::Numerics::float2& pt2);
	double points_angle(float x1, float y1, float x2, float y2);
	float points_distance(Windows::Foundation::Numerics::float2& pt1, Windows::Foundation::Numerics::float2& pt2);
	float points_distance(float x1, float y1, float x2, float y2);

	double arc_length(float radius, double degrees0, double degreesn);

	double circle_perimeter(float radius);
	double ellipse_perimeter(float radiusX, float radiusY);

	void circle_point(float radius, float radians, float* x, float* y);
	void circle_point(float radius, double degrees, float* x, float* y);

	void ellipse_point(float radiusX, float radiusY, float radians, float* x, float* y);
	void ellipse_point(float radiusX, float radiusY, double degrees, float* x, float* y);
	
	void line_point(float x0, float y0, float x1, float y1, double ratio, float* x, float* y);
}
