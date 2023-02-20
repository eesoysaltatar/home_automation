#ifndef HW_AVR_HPP
#define HW_AVR_HPP
void LCD5110::_convert_float(char *buf, double num, int width, byte prec)
{
	dtostrf(num, width, prec, buf);
}
#endif
