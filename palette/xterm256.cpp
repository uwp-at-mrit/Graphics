#include "palette/xterm256.hpp"

#include "datum/box.hpp"

using namespace WarGrey::DTPM;
using namespace WarGrey::SCADA;

using namespace Microsoft::Graphics::Canvas::Brushes;

/*************************************************************************************************/
Xterm256Palette* Xterm256Palette::instance() {
	static Xterm256Palette* palette = nullptr;

	if (palette == nullptr) {
		palette = new Xterm256Palette();
	}

	return palette;
}

Platform::String^ Xterm256Palette::name() {
	return "Xterm256 Palette";
}

unsigned int Xterm256Palette::capacity() {
	return 256U;
}

void Xterm256Palette::suggested_cell_layout(unsigned int* column, unsigned int* row) {
	SET_BOX(column, 16U);
	SET_BOX(row, 16U);
}

CanvasSolidColorBrush^ Xterm256Palette::color_ref(unsigned int idx, CanvasSolidColorBrush^ fallback_color) {
	return ((idx < 256U) ? xterms[idx] : fallback_color);
}

Xterm256Palette::Xterm256Palette() {
	this->xterms[0] = Colours::make(0x000000);
	this->xterms[1] = Colours::make(0x800000);
	this->xterms[2] = Colours::make(0x008000);
	this->xterms[3] = Colours::make(0x808000);
	this->xterms[4] = Colours::make(0x000080);
	this->xterms[5] = Colours::make(0x800080);
	this->xterms[6] = Colours::make(0x008080);
	this->xterms[7] = Colours::make(0xc0c0c0);
	this->xterms[8] = Colours::make(0x808080);
	this->xterms[9] = Colours::make(0xff0000);
	this->xterms[10] = Colours::make(0x00ff00);
	this->xterms[11] = Colours::make(0xffff00);
	this->xterms[12] = Colours::make(0x0000ff);
	this->xterms[13] = Colours::make(0xff00ff);
	this->xterms[14] = Colours::make(0x00ffff);
	this->xterms[15] = Colours::make(0xffffff);
	this->xterms[16] = Colours::make(0x000000);
	this->xterms[17] = Colours::make(0x00005f);
	this->xterms[18] = Colours::make(0x000087);
	this->xterms[19] = Colours::make(0x0000af);
	this->xterms[20] = Colours::make(0x0000d7);
	this->xterms[21] = Colours::make(0x0000ff);
	this->xterms[22] = Colours::make(0x005f00);
	this->xterms[23] = Colours::make(0x005f5f);
	this->xterms[24] = Colours::make(0x005f87);
	this->xterms[25] = Colours::make(0x005faf);
	this->xterms[26] = Colours::make(0x005fd7);
	this->xterms[27] = Colours::make(0x005fff);
	this->xterms[28] = Colours::make(0x008700);
	this->xterms[29] = Colours::make(0x00875f);
	this->xterms[30] = Colours::make(0x008787);
	this->xterms[31] = Colours::make(0x0087af);
	this->xterms[32] = Colours::make(0x0087d7);
	this->xterms[33] = Colours::make(0x0087ff);
	this->xterms[34] = Colours::make(0x00af00);
	this->xterms[35] = Colours::make(0x00af5f);
	this->xterms[36] = Colours::make(0x00af87);
	this->xterms[37] = Colours::make(0x00afaf);
	this->xterms[38] = Colours::make(0x00afd7);
	this->xterms[39] = Colours::make(0x00afff);
	this->xterms[40] = Colours::make(0x00d700);
	this->xterms[41] = Colours::make(0x00d75f);
	this->xterms[42] = Colours::make(0x00d787);
	this->xterms[43] = Colours::make(0x00d7af);
	this->xterms[44] = Colours::make(0x00d7d7);
	this->xterms[45] = Colours::make(0x00d7ff);
	this->xterms[46] = Colours::make(0x00ff00);
	this->xterms[47] = Colours::make(0x00ff5f);
	this->xterms[48] = Colours::make(0x00ff87);
	this->xterms[49] = Colours::make(0x00ffaf);
	this->xterms[50] = Colours::make(0x00ffd7);
	this->xterms[51] = Colours::make(0x00ffff);
	this->xterms[52] = Colours::make(0x5f0000);
	this->xterms[53] = Colours::make(0x5f005f);
	this->xterms[54] = Colours::make(0x5f0087);
	this->xterms[55] = Colours::make(0x5f00af);
	this->xterms[56] = Colours::make(0x5f00d7);
	this->xterms[57] = Colours::make(0x5f00ff);
	this->xterms[58] = Colours::make(0x5f5f00);
	this->xterms[59] = Colours::make(0x5f5f5f);
	this->xterms[60] = Colours::make(0x5f5f87);
	this->xterms[61] = Colours::make(0x5f5faf);
	this->xterms[62] = Colours::make(0x5f5fd7);
	this->xterms[63] = Colours::make(0x5f5fff);
	this->xterms[64] = Colours::make(0x5f8700);
	this->xterms[65] = Colours::make(0x5f875f);
	this->xterms[66] = Colours::make(0x5f8787);
	this->xterms[67] = Colours::make(0x5f87af);
	this->xterms[68] = Colours::make(0x5f87d7);
	this->xterms[69] = Colours::make(0x5f87ff);
	this->xterms[70] = Colours::make(0x5faf00);
	this->xterms[71] = Colours::make(0x5faf5f);
	this->xterms[72] = Colours::make(0x5faf87);
	this->xterms[73] = Colours::make(0x5fafaf);
	this->xterms[74] = Colours::make(0x5fafd7);
	this->xterms[75] = Colours::make(0x5fafff);
	this->xterms[76] = Colours::make(0x5fd700);
	this->xterms[77] = Colours::make(0x5fd75f);
	this->xterms[78] = Colours::make(0x5fd787);
	this->xterms[79] = Colours::make(0x5fd7af);
	this->xterms[80] = Colours::make(0x5fd7d7);
	this->xterms[81] = Colours::make(0x5fd7ff);
	this->xterms[82] = Colours::make(0x5fff00);
	this->xterms[83] = Colours::make(0x5fff5f);
	this->xterms[84] = Colours::make(0x5fff87);
	this->xterms[85] = Colours::make(0x5fffaf);
	this->xterms[86] = Colours::make(0x5fffd7);
	this->xterms[87] = Colours::make(0x5fffff);
	this->xterms[88] = Colours::make(0x870000);
	this->xterms[89] = Colours::make(0x87005f);
	this->xterms[90] = Colours::make(0x870087);
	this->xterms[91] = Colours::make(0x8700af);
	this->xterms[92] = Colours::make(0x8700d7);
	this->xterms[93] = Colours::make(0x8700ff);
	this->xterms[94] = Colours::make(0x875f00);
	this->xterms[95] = Colours::make(0x875f5f);
	this->xterms[96] = Colours::make(0x875f87);
	this->xterms[97] = Colours::make(0x875faf);
	this->xterms[98] = Colours::make(0x875fd7);
	this->xterms[99] = Colours::make(0x875fff);
	this->xterms[100] = Colours::make(0x878700);
	this->xterms[101] = Colours::make(0x87875f);
	this->xterms[102] = Colours::make(0x878787);
	this->xterms[103] = Colours::make(0x8787af);
	this->xterms[104] = Colours::make(0x8787d7);
	this->xterms[105] = Colours::make(0x8787ff);
	this->xterms[106] = Colours::make(0x87af00);
	this->xterms[107] = Colours::make(0x87af5f);
	this->xterms[108] = Colours::make(0x87af87);
	this->xterms[109] = Colours::make(0x87afaf);
	this->xterms[110] = Colours::make(0x87afd7);
	this->xterms[111] = Colours::make(0x87afff);
	this->xterms[112] = Colours::make(0x87d700);
	this->xterms[113] = Colours::make(0x87d75f);
	this->xterms[114] = Colours::make(0x87d787);
	this->xterms[115] = Colours::make(0x87d7af);
	this->xterms[116] = Colours::make(0x87d7d7);
	this->xterms[117] = Colours::make(0x87d7ff);
	this->xterms[118] = Colours::make(0x87ff00);
	this->xterms[119] = Colours::make(0x87ff5f);
	this->xterms[120] = Colours::make(0x87ff87);
	this->xterms[121] = Colours::make(0x87ffaf);
	this->xterms[122] = Colours::make(0x87ffd7);
	this->xterms[123] = Colours::make(0x87ffff);
	this->xterms[124] = Colours::make(0xaf0000);
	this->xterms[125] = Colours::make(0xaf005f);
	this->xterms[126] = Colours::make(0xaf0087);
	this->xterms[127] = Colours::make(0xaf00af);
	this->xterms[128] = Colours::make(0xaf00d7);
	this->xterms[129] = Colours::make(0xaf00ff);
	this->xterms[130] = Colours::make(0xaf5f00);
	this->xterms[131] = Colours::make(0xaf5f5f);
	this->xterms[132] = Colours::make(0xaf5f87);
	this->xterms[133] = Colours::make(0xaf5faf);
	this->xterms[134] = Colours::make(0xaf5fd7);
	this->xterms[135] = Colours::make(0xaf5fff);
	this->xterms[136] = Colours::make(0xaf8700);
	this->xterms[137] = Colours::make(0xaf875f);
	this->xterms[138] = Colours::make(0xaf8787);
	this->xterms[139] = Colours::make(0xaf87af);
	this->xterms[140] = Colours::make(0xaf87d7);
	this->xterms[141] = Colours::make(0xaf87ff);
	this->xterms[142] = Colours::make(0xafaf00);
	this->xterms[143] = Colours::make(0xafaf5f);
	this->xterms[144] = Colours::make(0xafaf87);
	this->xterms[145] = Colours::make(0xafafaf);
	this->xterms[146] = Colours::make(0xafafd7);
	this->xterms[147] = Colours::make(0xafafff);
	this->xterms[148] = Colours::make(0xafd700);
	this->xterms[149] = Colours::make(0xafd75f);
	this->xterms[150] = Colours::make(0xafd787);
	this->xterms[151] = Colours::make(0xafd7af);
	this->xterms[152] = Colours::make(0xafd7d7);
	this->xterms[153] = Colours::make(0xafd7ff);
	this->xterms[154] = Colours::make(0xafff00);
	this->xterms[155] = Colours::make(0xafff5f);
	this->xterms[156] = Colours::make(0xafff87);
	this->xterms[157] = Colours::make(0xafffaf);
	this->xterms[158] = Colours::make(0xafffd7);
	this->xterms[159] = Colours::make(0xafffff);
	this->xterms[160] = Colours::make(0xd70000);
	this->xterms[161] = Colours::make(0xd7005f);
	this->xterms[162] = Colours::make(0xd70087);
	this->xterms[163] = Colours::make(0xd700af);
	this->xterms[164] = Colours::make(0xd700d7);
	this->xterms[165] = Colours::make(0xd700ff);
	this->xterms[166] = Colours::make(0xd75f00);
	this->xterms[167] = Colours::make(0xd75f5f);
	this->xterms[168] = Colours::make(0xd75f87);
	this->xterms[169] = Colours::make(0xd75faf);
	this->xterms[170] = Colours::make(0xd75fd7);
	this->xterms[171] = Colours::make(0xd75fff);
	this->xterms[172] = Colours::make(0xd78700);
	this->xterms[173] = Colours::make(0xd7875f);
	this->xterms[174] = Colours::make(0xd78787);
	this->xterms[175] = Colours::make(0xd787af);
	this->xterms[176] = Colours::make(0xd787d7);
	this->xterms[177] = Colours::make(0xd787ff);
	this->xterms[178] = Colours::make(0xd7af00);
	this->xterms[179] = Colours::make(0xd7af5f);
	this->xterms[180] = Colours::make(0xd7af87);
	this->xterms[181] = Colours::make(0xd7afaf);
	this->xterms[182] = Colours::make(0xd7afd7);
	this->xterms[183] = Colours::make(0xd7afff);
	this->xterms[184] = Colours::make(0xd7d700);
	this->xterms[185] = Colours::make(0xd7d75f);
	this->xterms[186] = Colours::make(0xd7d787);
	this->xterms[187] = Colours::make(0xd7d7af);
	this->xterms[188] = Colours::make(0xd7d7d7);
	this->xterms[189] = Colours::make(0xd7d7ff);
	this->xterms[190] = Colours::make(0xd7ff00);
	this->xterms[191] = Colours::make(0xd7ff5f);
	this->xterms[192] = Colours::make(0xd7ff87);
	this->xterms[193] = Colours::make(0xd7ffaf);
	this->xterms[194] = Colours::make(0xd7ffd7);
	this->xterms[195] = Colours::make(0xd7ffff);
	this->xterms[196] = Colours::make(0xff0000);
	this->xterms[197] = Colours::make(0xff005f);
	this->xterms[198] = Colours::make(0xff0087);
	this->xterms[199] = Colours::make(0xff00af);
	this->xterms[200] = Colours::make(0xff00d7);
	this->xterms[201] = Colours::make(0xff00ff);
	this->xterms[202] = Colours::make(0xff5f00);
	this->xterms[203] = Colours::make(0xff5f5f);
	this->xterms[204] = Colours::make(0xff5f87);
	this->xterms[205] = Colours::make(0xff5faf);
	this->xterms[206] = Colours::make(0xff5fd7);
	this->xterms[207] = Colours::make(0xff5fff);
	this->xterms[208] = Colours::make(0xff8700);
	this->xterms[209] = Colours::make(0xff875f);
	this->xterms[210] = Colours::make(0xff8787);
	this->xterms[211] = Colours::make(0xff87af);
	this->xterms[212] = Colours::make(0xff87d7);
	this->xterms[213] = Colours::make(0xff87ff);
	this->xterms[214] = Colours::make(0xffaf00);
	this->xterms[215] = Colours::make(0xffaf5f);
	this->xterms[216] = Colours::make(0xffaf87);
	this->xterms[217] = Colours::make(0xffafaf);
	this->xterms[218] = Colours::make(0xffafd7);
	this->xterms[219] = Colours::make(0xffafff);
	this->xterms[220] = Colours::make(0xffd700);
	this->xterms[221] = Colours::make(0xffd75f);
	this->xterms[222] = Colours::make(0xffd787);
	this->xterms[223] = Colours::make(0xffd7af);
	this->xterms[224] = Colours::make(0xffd7d7);
	this->xterms[225] = Colours::make(0xffd7ff);
	this->xterms[226] = Colours::make(0xffff00);
	this->xterms[227] = Colours::make(0xffff5f);
	this->xterms[228] = Colours::make(0xffff87);
	this->xterms[229] = Colours::make(0xffffaf);
	this->xterms[230] = Colours::make(0xffffd7);
	this->xterms[231] = Colours::make(0xffffff);
	this->xterms[232] = Colours::make(0x080808);
	this->xterms[233] = Colours::make(0x121212);
	this->xterms[234] = Colours::make(0x1c1c1c);
	this->xterms[235] = Colours::make(0x262626);
	this->xterms[236] = Colours::make(0x303030);
	this->xterms[237] = Colours::make(0x3a3a3a);
	this->xterms[238] = Colours::make(0x444444);
	this->xterms[239] = Colours::make(0x4e4e4e);
	this->xterms[240] = Colours::make(0x585858);
	this->xterms[241] = Colours::make(0x626262);
	this->xterms[242] = Colours::make(0x6c6c6c);
	this->xterms[243] = Colours::make(0x767676);
	this->xterms[244] = Colours::make(0x808080);
	this->xterms[245] = Colours::make(0x8a8a8a);
	this->xterms[246] = Colours::make(0x949494);
	this->xterms[247] = Colours::make(0x9e9e9e);
	this->xterms[248] = Colours::make(0xa8a8a8);
	this->xterms[249] = Colours::make(0xb2b2b2);
	this->xterms[250] = Colours::make(0xbcbcbc);
	this->xterms[251] = Colours::make(0xc6c6c6);
	this->xterms[252] = Colours::make(0xd0d0d0);
	this->xterms[253] = Colours::make(0xdadada);
	this->xterms[254] = Colours::make(0xe4e4e4);
	this->xterms[255] = Colours::make(0xeeeeee);
}
