#pragma once

#include "datum/class.hpp"

namespace WarGrey::SCADA {
	typedef Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush Colour;

	private ref class Colours sealed {
	public:
		static Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^ make(double h, double s, double l, double alpha = 1.0);
		static Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^ make(unsigned int r, unsigned int g, unsigned int b, double alpha = 1.0);
		static Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^ make(unsigned int hex, double alpha = 1.0);
		static Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^ make(WarGrey::SCADA::Colour^ src, double alpha = 1.0);
		
		static Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^ contrast(WarGrey::SCADA::Colour^ src);

	public:
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Background);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Foreground);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Highlight);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, GrayText);

	public:
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, AccentDark);

	public:
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Transparent);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, OrangeRed);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Tomato);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, DarkRed);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Red);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Firebrick);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Crimson);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, DeepPink);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Maroon);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, IndianRed);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, MediumVioletRed);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, VioletRed);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, LightCoral);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, HotPink);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, PaleVioletRed);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, LightPink);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, RosyBrown);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Pink);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Orchid);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, LavenderBlush);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Snow);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Chocolate);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, SaddleBrown);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Brown);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, DarkOrange);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Coral);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Sienna);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Orange);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Salmon);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Peru);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, DarkGoldenrod);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Goldenrod);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, SandyBrown);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, LightSalmon);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, DarkSalmon);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Gold);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Yellow);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Olive);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Burlywood);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Tan);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, NavajoWhite);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, PeachPuff);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Khaki);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, DarkKhaki);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Moccasin);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Wheat);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Bisque);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, PaleGoldenrod);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, BlanchedAlmond);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, MediumGoldenrod);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, PapayaWhip);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, MistyRose);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, LemonChiffon);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, AntiqueWhite);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Cornsilk);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, LightGoldenrodYellow);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, OldLace);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Linen);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, LightYellow);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, SeaShell);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Beige);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, FloralWhite);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Ivory);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Green);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, LawnGreen);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Chartreuse);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, GreenYellow);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, YellowGreen);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, MediumForestGreen);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, OliveDrab);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, DarkOliveGreen);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, DarkSeaGreen);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Lime);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, DarkGreen);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, LimeGreen);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, ForestGreen);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, SpringGreen);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, MediumSpringGreen);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, SeaGreen);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, MediumSeaGreen);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Aquamarine);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, LightGreen);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, PaleGreen);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, MediumAquamarine);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Turquoise);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, LightSeaGreen);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, MediumTurquoise);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Honeydew);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, MintCream);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, RoyalBlue);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, DodgerBlue);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, DeepSkyBlue);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, CornflowerBlue);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, SteelBlue);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, LightSkyBlue);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, DarkTurquoise);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Cyan);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Aqua);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, DarkCyan);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Teal);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, SkyBlue);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, CadetBlue);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, DarkSlateGray);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, LightSlateGray);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, SlateGray);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, LightSteelBlue);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, LightBlue);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, PowderBlue);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, PaleTurquoise);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, LightCyan);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, AliceBlue);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Azure);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, MediumBlue);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, DarkBlue);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, MidnightBlue);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Navy);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Blue);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Indigo);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, BlueViolet);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, MediumSlateBlue);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, SlateBlue);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Purple);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, DarkSlateBlue);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, DarkViolet);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, DarkOrchid);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, MediumPurple);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, MediumOrchid);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Magenta);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Fuchsia);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, DarkMagenta);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Violet);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Plum);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Lavender);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Thistle);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, GhostWhite);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, White);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, WhiteSmoke);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Gainsboro);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, LightGray);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Silver);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Gray);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, DarkGray);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, DimGray);
		static_read_only_property(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush^, Black);
	};
}
