#pragma once

#include <stdarg.h>
#include <stdint.h>

#include "serial/serial.h"

#define MAXRETRY 5


class Tl
{
	public:
		Tl(std::string &port, uint32_t baudrate);
		~Tl();

		bool ReadPacket(int *data);
		
		void tl3_normal_start(void);
		void tl3_stop(void);

	private:
		bool check_PS(void);
		
		void flush();
	    void write(uint8_t data);
	    bool read(uint8_t *byte);

        serial::Serial * port_;

		enum {
				STARTCODE_1 = 0xFF,
				STARTCODE_2 = 0xC0,
				STARTCODE_3 = 0x54,
				STARTCODE_4 = 0x4C,
		};
};

void GetTLAngle(double *tl_angle);
