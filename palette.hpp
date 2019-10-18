#pragma once

#include "brushes.hxx"

namespace WarGrey::SCADA {
	private enum class Palette : unsigned int {
		X11, Xterm256
	};

	private class IPalette abstract {
	public:
		virtual Platform::String^ name() = 0;
		virtual unsigned int capacity() = 0;
		virtual Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^ color_ref(unsigned int i,
			Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^ fallback_color = WarGrey::SCADA::Colours::Foreground) = 0;
	};
}
