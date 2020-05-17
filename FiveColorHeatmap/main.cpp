void createFiveColorHeatmapLut(unsigned char rgb[]) {
	int i;
	//   0:0x0000FF
	for (i = 0; i < 63; i++) {
		rgb[i * 3] = 0;
		rgb[i * 3 + 1] = i * 0xff / 63;
		rgb[i * 3 + 2] = 0xff;
	}
	//  63:0x00FFFF
	for (; i < 127; i++) {
		rgb[i * 3] = 0;
		rgb[i * 3 + 1] = 0xff;
		rgb[i * 3 + 2] = (127 - i) * 0xff / 64;
	}
	// 127:0x00FF00
	for (; i < 191; i++) {
		rgb[i * 3] = (i - 127) * 0xff / 64;
		rgb[i * 3 + 1] = 0xff;
		rgb[i * 3 + 2] = 0;
	}
	// 191:0xFFFF00
	for (; i < 255; i++) {
		rgb[i * 3] = 0xff;
		rgb[i * 3 + 1] = (255 - i) * 0xff / 64;
		rgb[i * 3 + 2] = 0;
	}
	// 255:0xFF0000
	rgb[255 * 3] = 0xff;
	rgb[255 * 3 + 1] = 0;
	rgb[255 * 3 + 2] = 0;
}

int main(int argc, char* argv[]) {
	unsigned char rgb[256 * 3];
	createFiveColorHeatmapLut(rgb);
	return 0;
}