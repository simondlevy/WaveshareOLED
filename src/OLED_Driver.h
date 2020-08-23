#pragma once

#include "SPI.h"

#define SSD1351_CMD_SETCOLUMN       0x15
#define SSD1351_CMD_SETROW          0x75
#define SSD1351_CMD_WRITERAM        0x5C
#define SSD1351_CMD_READRAM         0x5D
#define SSD1351_CMD_SETREMAP        0xA0
#define SSD1351_CMD_STARTLINE       0xA1
#define SSD1351_CMD_DISPLAYOFFSET 	0xA2
#define SSD1351_CMD_DISPLAYALLOFF 	0xA4
#define SSD1351_CMD_DISPLAYALLON  	0xA5
#define SSD1351_CMD_NORMALDISPLAY 	0xA6
#define SSD1351_CMD_INVERTDISPLAY 	0xA7
#define SSD1351_CMD_FUNCTIONSELECT 	0xAB
#define SSD1351_CMD_DISPLAYOFF      0xAE
#define SSD1351_CMD_DISPLAYON     	0xAF
#define SSD1351_CMD_PRECHARGE       0xB1
#define SSD1351_CMD_DISPLAYENHANCE  0xB2
#define SSD1351_CMD_CLOCKDIV        0xB3
#define SSD1351_CMD_SETVSL          0xB4
#define SSD1351_CMD_SETGPIO 		    0xB5
#define SSD1351_CMD_PRECHARGE2      0xB6
#define SSD1351_CMD_SETGRAY         0xB8
#define SSD1351_CMD_USELUT          0xB9
#define SSD1351_CMD_PRECHARGELEVEL 	0xBB
#define SSD1351_CMD_VCOMH           0xBE
#define SSD1351_CMD_CONTRASTABC     0xC1
#define SSD1351_CMD_CONTRASTMASTER  0xC7
#define SSD1351_CMD_MUXRATIO        0xCA
#define SSD1351_CMD_COMMANDLOCK     0xFD
#define SSD1351_CMD_HORIZSCROLL     0x96
#define SSD1351_CMD_STOPSCROLL      0x9E
#define SSD1351_CMD_STARTSCROLL     0x9F

class OLED_Driver {

    public: 

        static const uint16_t BLACK   = 0x0000;
        static const uint16_t BLUE    = 0x001F;
        static const uint16_t RED     = 0xF800;
        static const uint16_t GREEN   = 0x07E0;
        static const uint16_t CYAN    = 0x07FF;
        static const uint16_t MAGENTA = 0xF81F;
        static const uint16_t WHITE   = 0xFFFF;
        static const uint16_t YELLOW  = 0xFFE0;

        static const uint8_t SSD1351_WIDTH   = 128;
        static const uint8_t SSD1351_HEIGHT  = 128;

        OLED_Driver(uint8_t cs_pin, uint8_t rst_pin, uint8_t dc_pin);

        void begin(void);
        void Clear_Screen(void);
        void Fill_Color(uint16_t color);
        void Set_Coordinate(uint16_t x, uint16_t y);

        void Write_text(uint8_t data1);
        void Set_Address(uint8_t column, uint8_t row);

        void Set_Color(uint16_t color);
        void Set_FillColor(uint16_t color);

        void Invert(bool v);
        void Draw_Pixel(int16_t x, int16_t y);

        void Write_Command(uint8_t dat);
        void Write_Data(uint8_t dat);
        void Write_Data(uint8_t* dat_p, int length);

        void Draw_FastHLine(int16_t x, int16_t y, int16_t length);
        void Draw_FastVLine(int16_t x, int16_t y, int16_t length);

        void Display_bmp(void);
        void Display_Interface(void);

    protected:

        uint8_t color_byte[2];
        uint8_t color_fill_byte[2];

    private:  

        uint8_t _cs_pin;
        uint8_t _rst_pin;
        uint8_t _dc_pin;

        void RAM_Address(void);

        void OLED_CS(uint8_t x);
        void OLED_RST(uint8_t x);
        void OLED_DC(uint8_t x);
};
