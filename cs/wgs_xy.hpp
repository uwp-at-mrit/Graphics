#pragma once

#include "datum/flonum.hpp"

namespace WarGrey::DTPM {
	private struct GCSParameter {
		double a = 0.0; // Ellipsoid Axis
		double f = 0.0; // Ellipsoid Flatness
		double cm = 0.0; // Center Meridian

		// Cartographic Coordinate Reference System
		double cs_tx = 0.0;
		double cs_ty = 0.0;
		double cs_tz = 0.0;
		double cs_s  = 1.0;
		double cs_rx = 0.0;
		double cs_ry = 0.0;
		double cs_rz = 0.0;

		// Gauss-Krüger Projection
		double gk_dx = 0.0;
		double gk_dy = 0.0;
		double gk_dz = 0.0;
		double utm_s = 1.0;
	};

	double gps_degmm_to_degrees(double DDmm_mm);
	double gps_degmm_to_radians(double DDmm_mm);

	WarGrey::SCADA::double3 Degrees_to_XYZ(double latitude, double longitude, double altitude, WarGrey::DTPM::GCSParameter& gcs);
	WarGrey::SCADA::double2 Degrees_to_XY(double latitude, double longitude, double altitude, WarGrey::DTPM::GCSParameter& gcs);

	WarGrey::SCADA::double3 DDmm_mm_to_XYZ(double latitude, double longitude, double altitude, WarGrey::DTPM::GCSParameter& gcs);
	WarGrey::SCADA::double2 DDmm_mm_to_XY(double latitude, double longitude, double altitude, WarGrey::DTPM::GCSParameter& gcs);

	// ECEF: Earth Centered Earth Fixed
	WarGrey::SCADA::double3 WGS84BLH_to_ECEFXYZ(double latitude, double longitude, double altitude, WarGrey::DTPM::GCSParameter& gcs);
	WarGrey::SCADA::double3 ECEFXYZ_to_BEJ54XYZ(double x, double y, double z, WarGrey::DTPM::GCSParameter& gcs);
	WarGrey::SCADA::double3 BEJ54XYZ_to_BEJ54BLH(double x, double y, double z, WarGrey::DTPM::GCSParameter& gcs);
	WarGrey::SCADA::double3 BEJ54BLH_to_GAUSSXYH(double b, double l, double h, WarGrey::DTPM::GCSParameter& gcs);
}
