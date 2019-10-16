#include "datum/flonum.hpp"

#include "shape.hpp"
#include "text.hpp"
#include "math.hpp"

using namespace WarGrey::SCADA;

using namespace Windows::Foundation;
using namespace Windows::Foundation::Numerics;

using namespace Microsoft::Graphics::Canvas;
using namespace Microsoft::Graphics::Canvas::Text;
using namespace Microsoft::Graphics::Canvas::Geometry;

static inline Rect smart_rect(float x, float y, float width, float height) {
	if (width < 0.0F) {
		x = x + width;
		width = -width;
	}

	if (height < 0.0F) {
		y = y + height;
		height = -height;
	}

	return Rect(x, y, width, height);
}

/*************************************************************************************************/
CanvasGeometry^ WarGrey::SCADA::blank() {
	static auto singleton = CanvasGeometry::CreatePath(ref new CanvasPathBuilder(CanvasDevice::GetSharedDevice()));
    
	return singleton;
}

CanvasGeometry^ WarGrey::SCADA::paragraph(CanvasTextLayout^ tl, TextExtent* te, bool adjust) {
    CanvasGeometry^ layout = CanvasGeometry::CreateText(tl);
	float x = tl->LayoutBounds.X;
	float y = tl->LayoutBounds.Y;
    
	if (te != nullptr) {
		(*te) = get_text_extent(tl, true);
	}

    if (adjust && ((x < 0.0F) || (y < 0.0F))) {
		float xoff = (x >= 0.0F) ? x : -x;
		float yoff = (y >= 0.0F) ? y : -y;

        layout = geometry_union(blank(), layout, xoff, yoff);
    }

	return layout;
}

CanvasGeometry^ WarGrey::SCADA::paragraph(Platform::String^ text, CanvasTextFormat^ font, TextExtent* te, bool adjust) {
	return paragraph(make_text_layout(text, font), te, adjust);
}

CanvasGeometry^ WarGrey::SCADA::paragraph(Platform::String^ text, double degrees, float radius, CanvasTextFormat^ font, bool adjust) {
	TextExtent te;
	auto p = paragraph(text, font, &te, adjust);

	return geometry_rotate(geometry_translate(p, -te.width * 0.5F, -radius - te.height * 0.5F), degrees + 90.0, 0.0F, 0.0F);
}

CanvasGeometry^ WarGrey::SCADA::line(float sx, float sy, float ex, float ey, float th, CanvasStrokeStyle^ style) {
	auto line = ref new CanvasPathBuilder(CanvasDevice::GetSharedDevice());

	line->BeginFigure(sx, sy);
	line->AddLine(ex, ey);
	line->EndFigure(CanvasFigureLoop::Open);

	return geometry_stroke(CanvasGeometry::CreatePath(line), th, style);
}

CanvasGeometry^ WarGrey::SCADA::line(float ex, float ey, float th, CanvasStrokeStyle^ style) {
	return line(0.0F, 0.0F, ex, ey, th, style);
}

CanvasGeometry^ WarGrey::SCADA::hline(float x, float y, float l, float th, CanvasStrokeStyle^ style) {
	return line(x, y, x + l, y, th, style);
}

CanvasGeometry^ WarGrey::SCADA::hline(float l, float th, CanvasStrokeStyle^ style) {
    return hline(0.0F, 0.0F, l, th, style);
}

CanvasGeometry^ WarGrey::SCADA::vline(float x, float y, float l, float th, CanvasStrokeStyle^ style) {
	return line(x, y, x, y + l, th, style);
}

CanvasGeometry^ WarGrey::SCADA::vline(float l, float th, CanvasStrokeStyle^ style) {
    return vline(0.0F, 0.0F, l, th, style);
}

CanvasGeometry^ WarGrey::SCADA::bezier(float sx, float sy, float cx, float cy, float ex, float ey, float th, CanvasStrokeStyle^ style) {
	auto quadratic = ref new CanvasPathBuilder(CanvasDevice::GetSharedDevice());

	quadratic->BeginFigure(sx, sy);
	quadratic->AddQuadraticBezier(float2(cx, cy), float2(ex, ey));
	quadratic->EndFigure(CanvasFigureLoop::Open);

	return geometry_stroke(CanvasGeometry::CreatePath(quadratic), th, style);
}

CanvasGeometry^ WarGrey::SCADA::bezier(float sx, float sy, float cx1, float cy1, float cx2, float cy2, float ex, float ey, float th, CanvasStrokeStyle^ style) {
	auto cubic = ref new CanvasPathBuilder(CanvasDevice::GetSharedDevice());

	cubic->BeginFigure(sx, sy);
	cubic->AddCubicBezier(float2(cx1, cy1), float2(cx2, cy2), float2(ex, ey));
	cubic->EndFigure(CanvasFigureLoop::Open);

	return geometry_stroke(CanvasGeometry::CreatePath(cubic), th, style);
}

CanvasGeometry^ WarGrey::SCADA::arc(double start, double end, float radiusX, float radiusY, float th, CanvasStrokeStyle^ style) {
	return arc(0.0F, 0.0F, start, end, radiusX, radiusY, th, style);
}

CanvasGeometry^ WarGrey::SCADA::arc(float cx, float cy, double start, double end, float radiusX, float maybe_radiusY
	, float th, CanvasStrokeStyle^ style) {
	auto arc_path = ref new CanvasPathBuilder(CanvasDevice::GetSharedDevice());
	float radiusY = (maybe_radiusY <= 0.0F) ? radiusX : maybe_radiusY;
	float rstart = degrees_to_radians(start);
	float rsweep = degrees_to_radians(end - start);
	float startx, starty;

	ellipse_point(radiusX, radiusY, start, &startx, &starty);

	arc_path->BeginFigure(cx + startx, cy + starty);
	arc_path->AddArc(float2(cx, cy), radiusX, radiusY, rstart, rsweep);
	arc_path->EndFigure(CanvasFigureLoop::Open);

	return geometry_stroke(CanvasGeometry::CreatePath(arc_path), th, style);
}

CanvasGeometry^ WarGrey::SCADA::short_arc(double start, double end, float radiusX, float maybe_radiusY, float th, CanvasStrokeStyle^ style) {
	float radiusY = (maybe_radiusY <= 0.0F) ? radiusX : maybe_radiusY;
	float sx, sy, ex, ey;
	
	ellipse_point(radiusX, radiusY, start, &sx, &sy);
	ellipse_point(radiusX, radiusY, end, &ex, &ey);

	return short_arc(sx, sy, ex, ey, radiusX, radiusY, th, style);
}

CanvasGeometry^ WarGrey::SCADA::short_arc(float sx, float sy, float ex, float ey, float rx, float maybe_ry, float th, CanvasStrokeStyle^ style) {
    auto arc = ref new CanvasPathBuilder(CanvasDevice::GetSharedDevice());
	float ry = (maybe_ry <= 0.0F) ? rx : maybe_ry;
    
    arc->BeginFigure(sx, sy);
    arc->AddArc(float2(ex, ey), rx, ry, 0.0F, CanvasSweepDirection::Clockwise, CanvasArcSize::Small);
    arc->EndFigure(CanvasFigureLoop::Open);

    return geometry_stroke(CanvasGeometry::CreatePath(arc), th, style);
}

CanvasGeometry^ WarGrey::SCADA::long_arc(double start, double end, float radiusX, float maybe_radiusY, float th, CanvasStrokeStyle^ style) {
	float radiusY = (maybe_radiusY <= 0.0F) ? radiusX : maybe_radiusY;
	float sx, sy, ex, ey;

	ellipse_point(radiusX, radiusY, start, &sx, &sy);
	ellipse_point(radiusX, radiusY, end, &ex, &ey);

	return long_arc(sx, sy, ex, ey, radiusX, radiusY, th, style);
}

CanvasGeometry^ WarGrey::SCADA::long_arc(float sx, float sy, float ex, float ey, float rx, float maybe_ry, float th, CanvasStrokeStyle^ style) {
    auto arc = ref new CanvasPathBuilder(CanvasDevice::GetSharedDevice());
	float ry = (maybe_ry <= 0.0F) ? rx : maybe_ry;

    arc->BeginFigure(sx, sy);
    arc->AddArc(float2(ex, ey), rx, ry, 0.0F, CanvasSweepDirection::Clockwise, CanvasArcSize::Large);
    arc->EndFigure(CanvasFigureLoop::Open);

    return geometry_stroke(CanvasGeometry::CreatePath(arc), th, style);
}

CanvasGeometry^ WarGrey::SCADA::omega(double sdegrees, float radius, float th, CanvasStrokeStyle^ style, float extent) {
	return omega(0.0F, 0.0F, sdegrees, radius, th, style, extent);
}

CanvasGeometry^ WarGrey::SCADA::omega(float cx, float cy, double sdegrees, float radius, float th, CanvasStrokeStyle^ style, float extent) {
	auto omega_path = ref new CanvasPathBuilder(CanvasDevice::GetSharedDevice());
	double edegrees = sdegrees + 180.0;
	float ext_radius = flmax(radius, (extent < 0.0F) ? (-extent * radius) : extent);
	float rstart = degrees_to_radians(sdegrees);
	float rsweep = degrees_to_radians(edegrees - sdegrees);
	float startx, starty, ext_sx, ext_sy, ext_ex, ext_ey;

	circle_point(radius, sdegrees, &startx, &starty);
	circle_point(ext_radius, sdegrees, &ext_sx, &ext_sy);
	circle_point(ext_radius, edegrees, &ext_ex, &ext_ey);

	omega_path->BeginFigure(cx + ext_sx, cx + ext_sy);
	omega_path->AddLine(cx + startx, cy + starty);
	omega_path->AddArc(float2(cx, cy), radius, radius, rstart, rsweep);
	omega_path->AddLine(cx + ext_ex, cy + ext_ey);
	omega_path->EndFigure(CanvasFigureLoop::Open);

	return geometry_stroke(CanvasGeometry::CreatePath(omega_path), th, style);
}

CanvasGeometry^ WarGrey::SCADA::circle(float r) {
	return circle(0.0F, 0.0F, r);
}

CanvasGeometry^ WarGrey::SCADA::circle(float cx, float cy, float r) {
    return CanvasGeometry::CreateCircle(CanvasDevice::GetSharedDevice(), cx, cy, r);
}

CanvasGeometry^ WarGrey::SCADA::ellipse(float rx, float ry) {
	return ellipse(0.0F, 0.0F, rx, ry);
}

CanvasGeometry^ WarGrey::SCADA::ellipse(float cx, float cy, float rx, float ry) {
    return CanvasGeometry::CreateEllipse(CanvasDevice::GetSharedDevice(), cx, cy, rx, ry);
}

CanvasGeometry^ WarGrey::SCADA::sector(double start, double end, float radiusX, float radiusY) {
	return sector(0.0F, 0.0F, start, end, radiusX, radiusY);
}

CanvasGeometry^ WarGrey::SCADA::sector(float cx, float cy, double start, double end, float radiusX, float maybe_radiusY) {
	return masked_sector(cx, cy, start, end, 0.0, radiusX, maybe_radiusY);
}

CanvasGeometry^ WarGrey::SCADA::masked_sector(double start, double end, double ratio, float radiusX, float radiusY) {
	return masked_sector(0.0F, 0.0F, start, end, ratio, radiusX, radiusY);
}

CanvasGeometry^ WarGrey::SCADA::masked_sector(float cx, float cy, double start, double end, double ratio, float radiusX, float maybe_radiusY) {
	auto sector_path = ref new CanvasPathBuilder(CanvasDevice::GetSharedDevice());
	float radiusY = (maybe_radiusY <= 0.0F) ? radiusX : maybe_radiusY;
	float mradiusX = radiusX * float(ratio);
	float mradiusY = radiusY * float(ratio);
	float rstart = degrees_to_radians(start);
	float rsweep = degrees_to_radians(end - start);
	float startx, starty, mendx, mendy;

	ellipse_point(radiusX, radiusY, start, &startx, &starty);
	ellipse_point(mradiusX, mradiusY, end, &mendx, &mendy);

	sector_path->BeginFigure(cx + startx, cy + starty);
	sector_path->AddArc(float2(cx, cy), radiusX, radiusY, rstart, rsweep);
	sector_path->AddLine(cx + mendx, cy + mendy);
	sector_path->AddArc(float2(cx, cy), mradiusX, mradiusY, rstart + rsweep, -rsweep);
	sector_path->AddLine(cx + startx, cy + starty);
	sector_path->EndFigure(CanvasFigureLoop::Closed);

	return CanvasGeometry::CreatePath(sector_path);
}

CanvasGeometry^ WarGrey::SCADA::segment(double start, double end, float radiusX, float radiusY) {
	return segment(0.0F, 0.0F, start, end, radiusX, radiusY);
}

CanvasGeometry^ WarGrey::SCADA::segment(float cx, float cy, double start, double end, float radiusX, float maybe_radiusY) {
	auto segment_path = ref new CanvasPathBuilder(CanvasDevice::GetSharedDevice());
	float radiusY = (maybe_radiusY <= 0.0F) ? radiusX : maybe_radiusY;
	float rstart = degrees_to_radians(start);
	float rsweep = degrees_to_radians(end - start);
	float startx, starty;

	ellipse_point(radiusX, radiusY, start, &startx, &starty);

	segment_path->BeginFigure(cx + startx, cy + starty);
	segment_path->AddArc(float2(cx, cy), radiusX, radiusY, rstart, rsweep);
	segment_path->AddLine(cx + startx, cy + starty);
	segment_path->EndFigure(CanvasFigureLoop::Closed);

	return CanvasGeometry::CreatePath(segment_path);
}

CanvasGeometry^ WarGrey::SCADA::triangle(float x1, float y1, float x2, float y2) {
	auto ra_triangle = ref new CanvasPathBuilder(CanvasDevice::GetSharedDevice());

	ra_triangle->BeginFigure(x1, y1);
	ra_triangle->AddLine(x1, y2);
	ra_triangle->AddLine(x2, y2);
	ra_triangle->AddLine(x1, y1);
	ra_triangle->EndFigure(CanvasFigureLoop::Closed);

	return CanvasGeometry::CreatePath(ra_triangle);
}

CanvasGeometry^ WarGrey::SCADA::rectangle(Rect& region) {
	return CanvasGeometry::CreateRectangle(CanvasDevice::GetSharedDevice(), region);
}

CanvasGeometry^ WarGrey::SCADA::rectangle(float x, float y, float w, float h) {
	return rectangle(smart_rect(x, y, w, h));
}

CanvasGeometry^ WarGrey::SCADA::rectangle(float w, float h) {
    return rectangle(smart_rect(0.0F, 0.0F, w, h));
}

CanvasGeometry^ WarGrey::SCADA::rounded_rectangle(float x, float y, float w, float h, float rx, float ry) {
    float radius_x = (rx < 0.0F) ? -(w * rx) : rx;
    float radius_y = (ry < 0.0F) ? -(h * ry) : ry;

    return CanvasGeometry::CreateRoundedRectangle(CanvasDevice::GetSharedDevice(), smart_rect(x, y, w, h), radius_x, radius_y);
}

CanvasGeometry^ WarGrey::SCADA::rotate_rectangle(float w, float h, double d) {
    return rotate_rectangle(0.0F, 0.0F, w, h, d);
}

CanvasGeometry^ WarGrey::SCADA::rotate_rectangle(float x, float y, float w, float h, double d) {
	return rotate_rectangle(x, y, w, h, d, x + w * 0.5F, y + h * 0.5F);
}

CanvasGeometry^ WarGrey::SCADA::rotate_rectangle(float x, float y, float w, float h, double d, float cx, float cy) {
    return geometry_rotate(rectangle(x, y, w, h), d, cx, cy);
}

CanvasGeometry^ WarGrey::SCADA::rotate_rectangle(float w, float h, double d, float cx, float cy) {
    return rotate_rectangle(0.0F, 0.0F, w, h, d, cx, cy);
}

CanvasGeometry^ WarGrey::SCADA::double_arrow(float x, float y, float arrow_size, float head_size, float spacing, float thickness, CanvasStrokeStyle^ style) {
	auto arrow = ref new CanvasPathBuilder(CanvasDevice::GetSharedDevice());
	float arrowheadsize = head_size * thickness;
	float alignoff = thickness * 1.0F;
	float wingsize = arrowheadsize * 0.5F;
	float out_y = y + wingsize;
	float in_y = out_y + wingsize * ((spacing >= 0.0F) ? spacing : (-spacing * wingsize));
	float end_x = x + arrow_size;

	arrow->BeginFigure(x + arrowheadsize, y);
	arrow->AddLine(x + alignoff, out_y);
	arrow->AddLine(end_x, out_y);
	arrow->EndFigure(CanvasFigureLoop::Open);

	arrow->BeginFigure(x, in_y);
	arrow->AddLine(end_x - alignoff, in_y);
	arrow->AddLine(end_x - arrowheadsize, in_y + wingsize);
	arrow->EndFigure(CanvasFigureLoop::Open);

	return geometry_stroke(CanvasGeometry::CreatePath(arrow), thickness);
}

CanvasGeometry^ WarGrey::SCADA::double_arrow(float arrow_size, float arrowhead_size, float spacing, float thickness, CanvasStrokeStyle^ style) {
	return double_arrow(0.0F, 0.0F, arrow_size, arrowhead_size, spacing, thickness, style);
}

CanvasGeometry^ WarGrey::SCADA::stadium(float length, float radius) {
	return stadium(0.0F, 0.0F, length, radius);
}

CanvasGeometry^ WarGrey::SCADA::stadium(float x, float y, float length, float radius) {
	auto discorectangle = ref new CanvasPathBuilder(CanvasDevice::GetSharedDevice());
	float lx = x + radius;
	float rx = lx + length;
	float by = y + radius + radius;

	discorectangle->BeginFigure(lx, y);
	discorectangle->AddLine(rx, y);
	discorectangle->AddArc(float2(rx, by), radius, radius, 0.0F, CanvasSweepDirection::Clockwise, CanvasArcSize::Small);
	discorectangle->AddLine(lx, by);
	discorectangle->AddArc(float2(lx, y), radius, radius, 0.0F, CanvasSweepDirection::Clockwise, CanvasArcSize::Small);
	discorectangle->EndFigure(CanvasFigureLoop::Closed);

	return CanvasGeometry::CreatePath(discorectangle);
}

CanvasGeometry^ WarGrey::SCADA::trapezoid(float x, float y, float ubase, float bbase, float height) {
	auto trapezium = ref new CanvasPathBuilder(CanvasDevice::GetSharedDevice());
	float width = (ubase > bbase) ? ubase : bbase;
	float ux = x + (width - ubase) * 0.5F;
	float bx = x + (width - bbase) * 0.5F;
	float by = y + height;

	trapezium->BeginFigure(ux, y);
	trapezium->AddLine(ux + ubase, y);
	trapezium->AddLine(bx + bbase, by);
	trapezium->AddLine(bx, by);
	trapezium->AddLine(ux, y);
	trapezium->EndFigure(CanvasFigureLoop::Closed);

	return CanvasGeometry::CreatePath(trapezium);
}

CanvasGeometry^ WarGrey::SCADA::trapezoid(float ubase, float bbase, float height) {
	return trapezoid(0.0F, 0.0F, ubase, bbase, height);
}

CanvasGeometry^ WarGrey::SCADA::stadipe(float length, float radius) {
	return stadipe(0.0F, 0.0F, length, radius);
}

CanvasGeometry^ WarGrey::SCADA::stadipe(float x, float y, float length, float radius) {
	auto ship = ref new CanvasPathBuilder(CanvasDevice::GetSharedDevice());
	float lx = x + radius * 0.5F;
	float rx = lx + length;
	float by = y + radius + radius;
	float tx = x;
	float ty = y + radius;

	ship->BeginFigure(lx, y);
	ship->AddLine(rx, y);
	ship->AddArc(float2(rx, by), radius, radius, 0.0F, CanvasSweepDirection::Clockwise, CanvasArcSize::Small);
	ship->AddLine(lx, by);
	ship->AddLine(tx, ty);
	ship->AddLine(lx, y);
	ship->EndFigure(CanvasFigureLoop::Closed);

	return CanvasGeometry::CreatePath(ship);
}

CanvasGeometry^ WarGrey::SCADA::radiation(float long_radius, float short_radius
	, double start_degrees, double end_degrees, size_t count, float thickness, CanvasStrokeStyle^ style) {
	return radiation(0.0F, 0.0F, long_radius, short_radius, start_degrees, end_degrees, count, thickness, style);
}

CanvasGeometry^ WarGrey::SCADA::radiation(float cx, float cy, float long_radius, float short_radius
	, double start_degrees, double end_degrees, size_t count, float thickness, CanvasStrokeStyle^ style) {
	CanvasPathBuilder^ radar = ref new CanvasPathBuilder(CanvasDevice::GetSharedDevice());
	double step = (end_degrees - start_degrees) / double(count - 1);
	float start_x, start_y, end_x, end_y;

	for (double degrees = start_degrees; degrees <= end_degrees; degrees += step) {
		circle_point(long_radius, degrees, &start_x, &start_y);
		circle_point(short_radius, degrees, &end_x, &end_y);

		radar->BeginFigure(cx + start_x, cy + start_y);
		radar->AddLine(cx + end_x, cy + end_y);
		radar->EndFigure(CanvasFigureLoop::Open);
	}

	return geometry_stroke(CanvasGeometry::CreatePath(radar), thickness, style);
}
