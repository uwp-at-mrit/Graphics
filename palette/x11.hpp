#pragma once

#include "palette.hpp"

namespace WarGrey::SCADA {
	private class X11Palette : public WarGrey::SCADA::IPalette {
	public:
		static X11Palette* instance();

	public:
		Platform::String^ name() override;
		unsigned int capacity() override;
		Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^ color_ref(unsigned int i,
			Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^ fallback_color = WarGrey::SCADA::Colours::Foreground) override;

	private:
		virtual ~X11Palette() noexcept {}
		X11Palette() {}
	};
}
