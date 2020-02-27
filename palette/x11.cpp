#include "palette/x11.hpp"

using namespace WarGrey::DTPM;
using namespace WarGrey::SCADA;

using namespace Microsoft::Graphics::Canvas::Brushes;

/*************************************************************************************************/
X11Palette* X11Palette::instance() {
	static X11Palette* palette = nullptr;
	
	if (palette == nullptr) {
		palette = new X11Palette();
	}

	return palette;
}

Platform::String^ X11Palette::name() {
	return "X11 Window System Palette";
}

unsigned int X11Palette::capacity() {
	return 143U;
}

CanvasSolidColorBrush^ X11Palette::color_ref(unsigned int idx, CanvasSolidColorBrush^ fallback_color) {
	CanvasSolidColorBrush^ color = fallback_color;

	switch (idx) {
	case 0: color = Colours::OrangeRed; break;
	case 1: color = Colours::Tomato; break;
	case 2: color = Colours::DarkRed; break;
	case 3: color = Colours::Red; break;
	case 4: color = Colours::Firebrick; break;
	case 5: color = Colours::Crimson; break;
	case 6: color = Colours::DeepPink; break;
	case 7: color = Colours::Maroon; break;
	case 8: color = Colours::IndianRed; break;
	case 9: color = Colours::MediumVioletRed; break;
	case 10: color = Colours::VioletRed; break;
	case 11: color = Colours::LightCoral; break;
	case 12: color = Colours::HotPink; break;
	case 13: color = Colours::PaleVioletRed; break;
	case 14: color = Colours::LightPink; break;
	case 15: color = Colours::RosyBrown; break;
	case 16: color = Colours::Pink; break;
	case 17: color = Colours::Orchid; break;
	case 18: color = Colours::LavenderBlush; break;
	case 19: color = Colours::Snow; break;
	case 20: color = Colours::Chocolate; break;
	case 21: color = Colours::SaddleBrown; break;
	case 22: color = Colours::Brown; break;
	case 23: color = Colours::DarkOrange; break;
	case 24: color = Colours::Coral; break;
	case 25: color = Colours::Sienna; break;
	case 26: color = Colours::Orange; break;
	case 27: color = Colours::Salmon; break;
	case 28: color = Colours::Peru; break;
	case 29: color = Colours::DarkGoldenrod; break;
	case 30: color = Colours::Goldenrod; break;
	case 31: color = Colours::SandyBrown; break;
	case 32: color = Colours::LightSalmon; break;
	case 33: color = Colours::DarkSalmon; break;
	case 34: color = Colours::Gold; break;
	case 35: color = Colours::Yellow; break;
	case 36: color = Colours::Olive; break;
	case 37: color = Colours::Burlywood; break;
	case 38: color = Colours::Tan; break;
	case 39: color = Colours::NavajoWhite; break;
	case 40: color = Colours::PeachPuff; break;
	case 41: color = Colours::Khaki; break;
	case 42: color = Colours::DarkKhaki; break;
	case 43: color = Colours::Moccasin; break;
	case 44: color = Colours::Wheat; break;
	case 45: color = Colours::Bisque; break;
	case 46: color = Colours::PaleGoldenrod; break;
	case 47: color = Colours::BlanchedAlmond; break;
	case 48: color = Colours::MediumGoldenrod; break;
	case 49: color = Colours::PapayaWhip; break;
	case 50: color = Colours::MistyRose; break;
	case 51: color = Colours::LemonChiffon; break;
	case 52: color = Colours::AntiqueWhite; break;
	case 53: color = Colours::Cornsilk; break;
	case 54: color = Colours::LightGoldenrodYellow; break;
	case 55: color = Colours::OldLace; break;
	case 56: color = Colours::Linen; break;
	case 57: color = Colours::LightYellow; break;
	case 58: color = Colours::SeaShell; break;
	case 59: color = Colours::Beige; break;
	case 60: color = Colours::FloralWhite; break;
	case 61: color = Colours::Ivory; break;
	case 62: color = Colours::Green; break;
	case 63: color = Colours::LawnGreen; break;
	case 64: color = Colours::Chartreuse; break;
	case 65: color = Colours::GreenYellow; break;
	case 66: color = Colours::YellowGreen; break;
	case 67: color = Colours::MediumForestGreen; break;
	case 68: color = Colours::OliveDrab; break;
	case 69: color = Colours::DarkOliveGreen; break;
	case 70: color = Colours::DarkSeaGreen; break;
	case 71: color = Colours::Lime; break;
	case 72: color = Colours::DarkGreen; break;
	case 73: color = Colours::LimeGreen; break;
	case 74: color = Colours::ForestGreen; break;
	case 75: color = Colours::SpringGreen; break;
	case 76: color = Colours::MediumSpringGreen; break;
	case 77: color = Colours::SeaGreen; break;
	case 78: color = Colours::MediumSeaGreen; break;
	case 79: color = Colours::Aquamarine; break;
	case 80: color = Colours::LightGreen; break;
	case 81: color = Colours::PaleGreen; break;
	case 82: color = Colours::MediumAquamarine; break;
	case 83: color = Colours::Turquoise; break;
	case 84: color = Colours::LightSeaGreen; break;
	case 85: color = Colours::MediumTurquoise; break;
	case 86: color = Colours::Honeydew; break;
	case 87: color = Colours::MintCream; break;
	case 88: color = Colours::RoyalBlue; break;
	case 89: color = Colours::DodgerBlue; break;
	case 90: color = Colours::DeepSkyBlue; break;
	case 91: color = Colours::CornflowerBlue; break;
	case 92: color = Colours::SteelBlue; break;
	case 93: color = Colours::LightSkyBlue; break;
	case 94: color = Colours::DarkTurquoise; break;
	case 95: color = Colours::Cyan; break;
	case 96: color = Colours::Aqua; break;
	case 97: color = Colours::DarkCyan; break;
	case 98: color = Colours::Teal; break;
	case 99: color = Colours::SkyBlue; break;
	case 100: color = Colours::CadetBlue; break;
	case 101: color = Colours::DarkSlateGray; break;
	case 102: color = Colours::LightSlateGray; break;
	case 103: color = Colours::SlateGray; break;
	case 104: color = Colours::LightSteelBlue; break;
	case 105: color = Colours::LightBlue; break;
	case 106: color = Colours::PowderBlue; break;
	case 107: color = Colours::PaleTurquoise; break;
	case 108: color = Colours::LightCyan; break;
	case 109: color = Colours::AliceBlue; break;
	case 110: color = Colours::Azure; break;
	case 111: color = Colours::MediumBlue; break;
	case 112: color = Colours::DarkBlue; break;
	case 113: color = Colours::MidnightBlue; break;
	case 114: color = Colours::Navy; break;
	case 115: color = Colours::Blue; break;
	case 116: color = Colours::Indigo; break;
	case 117: color = Colours::BlueViolet; break;
	case 118: color = Colours::MediumSlateBlue; break;
	case 119: color = Colours::SlateBlue; break;
	case 120: color = Colours::Purple; break;
	case 121: color = Colours::DarkSlateBlue; break;
	case 122: color = Colours::DarkViolet; break;
	case 123: color = Colours::DarkOrchid; break;
	case 124: color = Colours::MediumPurple; break;
	case 125: color = Colours::MediumOrchid; break;
	case 126: color = Colours::Magenta; break;
	case 127: color = Colours::Fuchsia; break;
	case 128: color = Colours::DarkMagenta; break;
	case 129: color = Colours::Violet; break;
	case 130: color = Colours::Plum; break;
	case 131: color = Colours::Lavender; break;
	case 132: color = Colours::Thistle; break;
	case 133: color = Colours::GhostWhite; break;
	case 134: color = Colours::White; break;
	case 135: color = Colours::WhiteSmoke; break;
	case 136: color = Colours::Gainsboro; break;
	case 137: color = Colours::LightGray; break;
	case 138: color = Colours::Silver; break;
	case 139: color = Colours::Gray; break;
	case 140: color = Colours::DarkGray; break;
	case 141: color = Colours::DimGray; break;
	case 142: color = Colours::Black; break;
	}

	return color;
}
