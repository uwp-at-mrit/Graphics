#pragma once

namespace WarGrey::SCADA {
	Windows::Foundation::Numerics::float3x2 make_translation_matrix(float x, float y = 0.0F);
	Windows::Foundation::Numerics::float3x2 make_scale_matrix(float sx, float sy = 0.0F);

	Windows::Foundation::Numerics::float3x2 make_rotation_matrix(float radians, float cx, float cy, float tx = 0.0F, float ty = 0.0F);
	Windows::Foundation::Numerics::float3x2 make_rotation_matrix(double degrees, float cx, float cy, float tx = 0.0F, float ty = 0.0F);
}
