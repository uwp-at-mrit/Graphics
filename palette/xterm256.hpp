#pragma once

#include "palette.hpp"

namespace WarGrey::SCADA {
	private class Xterm256Palette : public WarGrey::SCADA::IPalette {
	public:
		static Xterm256Palette* instance();
	
	public:
		Platform::String^ name() override;
		unsigned int capacity() override;
		Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^ color_ref(unsigned int i,
			Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^ fallback_color = WarGrey::SCADA::Colours::Foreground) override;

	private:
		virtual ~Xterm256Palette() noexcept {}
		Xterm256Palette();

	private:
		Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^ xterms[256];
	};
}
