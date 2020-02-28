#pragma once

#include "palette.hpp"

namespace WarGrey::DTPM {
	private class X11Palette : public WarGrey::DTPM::IPalette {
	public:
		static X11Palette* instance();

	public:
		Platform::String^ name() override;
		unsigned int capacity() override;
		Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^ color_ref(unsigned int i,
			Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^ fallback_color = WarGrey::SCADA::Colours::Foreground) override;

	public:
		void suggested_cell_layout(unsigned int* column, unsigned int* row) override;

	private:
		virtual ~X11Palette() noexcept {}
		X11Palette() {}
	};
}
