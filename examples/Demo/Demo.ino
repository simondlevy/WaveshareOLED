/*
   Cool demonstration of the Waveshare 1.5" RGB OLED display

   Copyright (C) Waveshare, Inc / Simon D. Levy 2020

   MIT License
 */

#include "OLED_GFX.h"

// Pins
static const uint8_t CS  = 5;
static const uint8_t RST = 21;
static const uint8_t DC  = 22;

OLED_GFX oled(CS, RST, DC);

static void testlines(void)  
{
    oled.Set_Color(OLED_GFX::RED);
    oled.Clear_Screen();
    for (uint16_t x=0; x <= OLED_GFX::SSD1351_WIDTH - 1; x+=6)  {
        oled.Draw_Line(0, 0, x, OLED_GFX::SSD1351_HEIGHT - 1);
        delay(10);
    }
    for (uint16_t y=0; y < OLED_GFX::SSD1351_HEIGHT - 1; y+=6)  {
        oled.Draw_Line(0, 0, OLED_GFX::SSD1351_WIDTH - 1, y);
        delay(10);
    }

    oled.Set_Color(OLED_GFX::YELLOW);
    oled.Clear_Screen();
    for (uint16_t x=0; x < OLED_GFX::SSD1351_WIDTH - 1; x+=6) {
        oled.Draw_Line(OLED_GFX::SSD1351_WIDTH - 1, 0, x, OLED_GFX::SSD1351_HEIGHT - 1);
        delay(10);
    }
    for (uint16_t y=0; y < OLED_GFX::SSD1351_HEIGHT - 1; y+=6) {
        oled.Draw_Line(OLED_GFX::SSD1351_WIDTH - 1, 0, 0, y);
        delay(10);
    }

    oled.Set_Color(OLED_GFX::BLUE);
    oled.Clear_Screen();
    for (uint16_t x=0; x < OLED_GFX::SSD1351_WIDTH - 1; x+=6) {
        oled.Draw_Line(0, OLED_GFX::SSD1351_HEIGHT - 1, x, 0);
        delay(10);
    }
    for (uint16_t y=0; y < OLED_GFX::SSD1351_HEIGHT - 1; y+=6) {
        oled.Draw_Line(0, OLED_GFX::SSD1351_HEIGHT - 1, OLED_GFX::SSD1351_WIDTH - 1, y);
        delay(10);
    }

    oled.Set_Color(OLED_GFX::GREEN);
    oled.Clear_Screen();
    for (uint16_t x=0; x < OLED_GFX::SSD1351_WIDTH - 1; x+=6) {
        oled.Draw_Line(OLED_GFX::SSD1351_WIDTH - 1, OLED_GFX::SSD1351_HEIGHT - 1, x, 0 );
        delay(10);
    }
    for (uint16_t y=0; y < OLED_GFX::SSD1351_HEIGHT - 1; y+=6) {
        oled.Draw_Line(OLED_GFX::SSD1351_WIDTH - 1, OLED_GFX::SSD1351_HEIGHT - 1, 0, y);
        delay(10);
    }
}

static void lcdTestPattern(void)
{
    uint32_t i,j;
    oled.Set_Coordinate(0, 0);

    for(i=0;i<128;i++)  {
        for(j=0;j<128;j++)  {
            if(i<16)  {
                oled.Set_Color_And_Write(OLED_GFX::RED);
            }
            else if(i<32) {
                oled.Set_Color_And_Write(OLED_GFX::YELLOW);
            }
            else if(i<48) {
                oled.Set_Color_And_Write(OLED_GFX::GREEN);
            }
            else if(i<64) {
                oled.Set_Color_And_Write(OLED_GFX::CYAN);
            }
            else if(i<80) {
                oled.Set_Color_And_Write(OLED_GFX::BLUE);
            }
            else if(i<96) {
                oled.Set_Color_And_Write(OLED_GFX::MAGENTA);
            }
            else if(i<112)  {
                oled.Set_Color_And_Write(OLED_GFX::BLACK);
            }
            else {
                oled.Set_Color_And_Write(OLED_GFX::WHITE);
            }
        }
    }
}

static void testfastlines(void) 
{
    oled.Set_Color(OLED_GFX::WHITE);
    oled.Clear_Screen();

    for (uint16_t y=0; y < OLED_GFX::SSD1351_WIDTH - 1; y+=5) {
        oled.Draw_FastHLine(0, y, OLED_GFX::SSD1351_WIDTH - 1);
        delay(10);
    }
    for (uint16_t x=0; x < OLED_GFX::SSD1351_HEIGHT - 1; x+=5) {
        oled.Draw_FastVLine(x, 0, OLED_GFX::SSD1351_HEIGHT - 1);
        delay(10);
    }
}

void testdrawrects(void)  
{
    oled.Clear_Screen();
    for (uint16_t x=0; x < OLED_GFX::SSD1351_HEIGHT - 1; x+=6)  {
        oled.Draw_Rect((OLED_GFX::SSD1351_WIDTH-1)/2 - x/2, (OLED_GFX::SSD1351_HEIGHT-1)/2 - x/2 , x, x);
        delay(10);
    }
}

static void testfillrects(uint16_t color1, uint16_t color2) 
{
    uint16_t x = OLED_GFX::SSD1351_HEIGHT - 1;
    oled.Clear_Screen();
    oled.Set_Color(color1);
    oled.Set_FillColor(color2);
    for(; x > 6; x-=6)  {
        oled.Fill_Rect((OLED_GFX::SSD1351_WIDTH-1)/2 - x/2, (OLED_GFX::SSD1351_HEIGHT-1)/2 - x/2 , x, x);
        oled.Draw_Rect((OLED_GFX::SSD1351_WIDTH-1)/2 - x/2, (OLED_GFX::SSD1351_HEIGHT-1)/2 - x/2 , x, x);
    }
}

static void testfillcircles(uint8_t radius, uint16_t color)
{ 
    oled.Set_Color(color);

    oled.Fill_Circle(64, 64, radius);
}


static void testdrawcircles(uint16_t color)  
{
    uint8_t r = 0;
    oled.Set_Color(color);

    for (; r < OLED_GFX::SSD1351_WIDTH/2; r+=4)  {
        oled.Draw_Circle(64, 64, r);
        delay(10);
    }
}

static void testroundrects(void) 
{
    int color = 100;
    int x = 0, y = 0;
    int w = OLED_GFX::SSD1351_WIDTH - 1, h = OLED_GFX::SSD1351_HEIGHT - 1;

    oled.Clear_Screen();

    for(int i = 0 ; i <= 20; i++) {

        oled.Draw_RoundRect(x, y, w, h, 5);
        x += 2;
        y += 3;
        w -= 4;
        h -= 6;
        color += 1100;
        oled.Set_Color(color);
    }
}

static void testtriangles(void)  
{
    oled.Clear_Screen();
    int color = 0xF800;
    int t;
    int w = OLED_GFX::SSD1351_WIDTH/2;
    int x = OLED_GFX::SSD1351_HEIGHT-1;
    int y = 0;
    int z = OLED_GFX::SSD1351_WIDTH;
    for(t = 0 ; t <= 15; t+=1) {
        oled.Draw_Triangle(w, y, y, x, z, x);
        x-=4;
        y+=4;
        z-=4;
        color+=100;
        oled.Set_Color(color);
    }
}

void setup(void)  
{
    oled.begin();

    oled.Display_Interface();
    delay(3000);

    oled.Clear_Screen();

    oled.Set_Color(OLED_GFX::BLUE);
    oled.print_String(20, 50, "Hello WaveShare !", OLED_GFX::FONT_5X8);
    delay(2000);
    oled.Clear_Screen();

    oled.Set_Color(OLED_GFX::WHITE);
    oled.Draw_Pixel(50,50);
    delay(1000);

    lcdTestPattern();
    delay(1000);

    testlines();
    delay(1000);

    testfastlines();
    delay(1000);

    testdrawrects();
    delay(1000);

    testfillrects(OLED_GFX::BLUE,OLED_GFX::YELLOW);
    delay(1000);


    oled.Clear_Screen();
    testfillcircles(63, OLED_GFX::BLUE);
    delay(500);
    testdrawcircles(OLED_GFX::WHITE);
    delay(1000);

    testroundrects();
    delay(1000);

    testtriangles();
    delay(1000);
}


void loop(void) 
{

}


