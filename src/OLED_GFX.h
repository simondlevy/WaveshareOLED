/*
   Header code for Waveshare 1.5" RGB OLED display driver graphics

   Copyright (C) Waveshare, Inc / Simon D. Levy 2020

   MIT License
 */

#pragma once

#include "OLED_Driver.h"


class OLED_GFX : public virtual OLED_Driver {

    public:

        typedef enum  {
            FONT_5X8,
            FONT_8X16
        } FONT_SIZE;

        OLED_GFX(uint8_t cs_pin, uint8_t dc_pin, uint8_t rst_pin);

        void Set_Color_And_Write(uint16_t color);

        void Draw_Line(int16_t x0, int16_t y0, int16_t x1, int16_t y1);

        void Draw_Rect(int16_t x, int16_t y, int16_t w, int16_t h);
        void Fill_Rect(uint16_t x, uint16_t y, uint16_t w, uint16_t h);

        void Fill_Circle(int16_t x0, int16_t y0, int16_t r);
        void Draw_Circle(int16_t x0, int16_t y0, int16_t r);

        void Draw_RoundRect(int16_t x, int16_t y, int16_t w, int16_t h, int16_t r);
        void Draw_Triangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2);

        void print_String(uint8_t x, uint8_t y, const char *text, FONT_SIZE size);
        void Display_String_5x8(uint8_t x, uint8_t y, const char *text);
        void Display_String_8x16(uint8_t x, uint8_t y, const char *text);

    private:

        void Write_Line(int16_t x0, int16_t y0, int16_t x1, int16_t y1);

        void FillCircle_Helper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, int16_t delta);
        void DrawCircle_Helper( int16_t x0, int16_t y0, int16_t r, uint8_t corner);

        static void swap(int16_t & a, int16_t & b);

};
