#pragma once

#include "brushes.hxx"

namespace WarGrey::SCADA {
	private class IPalette abstract {
	public:
		virtual unsigned int capacity() = 0;
		virtual Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^ color_ref(unsigned int i,
			Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^ fallback_color = WarGrey::SCADA::Colours::Foreground) = 0;
	};

	private class NamedColorPalette : public WarGrey::SCADA::IPalette {
	public:
		static NamedColorPalette* make_instance();

	public:
		unsigned int capacity() override;
		Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^ color_ref(unsigned int i,
			Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^ fallback_color = WarGrey::SCADA::Colours::Foreground) override;

	private:
		virtual ~NamedColorPalette() noexcept {}
		NamedColorPalette() {}
	};

	private class Xterm256Palette : public WarGrey::SCADA::IPalette {
	public:
		static Xterm256Palette* make_instance();
	
	public:
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
