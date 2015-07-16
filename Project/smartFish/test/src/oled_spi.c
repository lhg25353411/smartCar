#include "oled_spi.h"

//======================================================
// 128X64OLED液晶底层驱动[8X16]字体库
// 设计者: Guokaiyi
// 描 述: [8X16]西文字符的字模数据 (纵向取模,字节倒序)
// !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~
//======================================================
const uchar8 F8X16[]=
{
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// 0
    0x00,0x00,0x00,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x33,0x30,0x00,0x00,0x00,//!1
    0x00,0x10,0x0C,0x06,0x10,0x0C,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//"2
    0x40,0xC0,0x78,0x40,0xC0,0x78,0x40,0x00,0x04,0x3F,0x04,0x04,0x3F,0x04,0x04,0x00,//#3
    0x00,0x70,0x88,0xFC,0x08,0x30,0x00,0x00,0x00,0x18,0x20,0xFF,0x21,0x1E,0x00,0x00,//$4
    0xF0,0x08,0xF0,0x00,0xE0,0x18,0x00,0x00,0x00,0x21,0x1C,0x03,0x1E,0x21,0x1E,0x00,//%5
    0x00,0xF0,0x08,0x88,0x70,0x00,0x00,0x00,0x1E,0x21,0x23,0x24,0x19,0x27,0x21,0x10,//&6
    0x10,0x16,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//'7
    0x00,0x00,0x00,0xE0,0x18,0x04,0x02,0x00,0x00,0x00,0x00,0x07,0x18,0x20,0x40,0x00,//(8
    0x00,0x02,0x04,0x18,0xE0,0x00,0x00,0x00,0x00,0x40,0x20,0x18,0x07,0x00,0x00,0x00,//)9
    0x40,0x40,0x80,0xF0,0x80,0x40,0x40,0x00,0x02,0x02,0x01,0x0F,0x01,0x02,0x02,0x00,//*10
    0x00,0x00,0x00,0xF0,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x1F,0x01,0x01,0x01,0x00,//+11
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xB0,0x70,0x00,0x00,0x00,0x00,0x00,//,12
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,//-13
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x00,0x00,0x00,0x00,0x00,//.14
    0x00,0x00,0x00,0x00,0x80,0x60,0x18,0x04,0x00,0x60,0x18,0x06,0x01,0x00,0x00,0x00,///15
    0x00,0xE0,0x10,0x08,0x08,0x10,0xE0,0x00,0x00,0x0F,0x10,0x20,0x20,0x10,0x0F,0x00,//016
    0x00,0x10,0x10,0xF8,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00,//117
    0x00,0x70,0x08,0x08,0x08,0x88,0x70,0x00,0x00,0x30,0x28,0x24,0x22,0x21,0x30,0x00,//218
    0x00,0x30,0x08,0x88,0x88,0x48,0x30,0x00,0x00,0x18,0x20,0x20,0x20,0x11,0x0E,0x00,//319
    0x00,0x00,0xC0,0x20,0x10,0xF8,0x00,0x00,0x00,0x07,0x04,0x24,0x24,0x3F,0x24,0x00,//420
    0x00,0xF8,0x08,0x88,0x88,0x08,0x08,0x00,0x00,0x19,0x21,0x20,0x20,0x11,0x0E,0x00,//521
    0x00,0xE0,0x10,0x88,0x88,0x18,0x00,0x00,0x00,0x0F,0x11,0x20,0x20,0x11,0x0E,0x00,//622
    0x00,0x38,0x08,0x08,0xC8,0x38,0x08,0x00,0x00,0x00,0x00,0x3F,0x00,0x00,0x00,0x00,//723
    0x00,0x70,0x88,0x08,0x08,0x88,0x70,0x00,0x00,0x1C,0x22,0x21,0x21,0x22,0x1C,0x00,//824
    0x00,0xE0,0x10,0x08,0x08,0x10,0xE0,0x00,0x00,0x00,0x31,0x22,0x22,0x11,0x0F,0x00,//925
    0x00,0x00,0x00,0xC0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x00,0x00,0x00,//:26
    0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x60,0x00,0x00,0x00,0x00,//;27
    0x00,0x00,0x80,0x40,0x20,0x10,0x08,0x00,0x00,0x01,0x02,0x04,0x08,0x10,0x20,0x00,//<28
    0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x00,//=29
    0x00,0x08,0x10,0x20,0x40,0x80,0x00,0x00,0x00,0x20,0x10,0x08,0x04,0x02,0x01,0x00,//>30
    0x00,0x70,0x48,0x08,0x08,0x08,0xF0,0x00,0x00,0x00,0x00,0x30,0x36,0x01,0x00,0x00,//?31
    0xC0,0x30,0xC8,0x28,0xE8,0x10,0xE0,0x00,0x07,0x18,0x27,0x24,0x23,0x14,0x0B,0x00,//@32
    0x00,0x00,0xC0,0x38,0xE0,0x00,0x00,0x00,0x20,0x3C,0x23,0x02,0x02,0x27,0x38,0x20,//A33
    0x08,0xF8,0x88,0x88,0x88,0x70,0x00,0x00,0x20,0x3F,0x20,0x20,0x20,0x11,0x0E,0x00,//B34
    0xC0,0x30,0x08,0x08,0x08,0x08,0x38,0x00,0x07,0x18,0x20,0x20,0x20,0x10,0x08,0x00,//C35
    0x08,0xF8,0x08,0x08,0x08,0x10,0xE0,0x00,0x20,0x3F,0x20,0x20,0x20,0x10,0x0F,0x00,//D36
    0x08,0xF8,0x88,0x88,0xE8,0x08,0x10,0x00,0x20,0x3F,0x20,0x20,0x23,0x20,0x18,0x00,//E37
    0x08,0xF8,0x88,0x88,0xE8,0x08,0x10,0x00,0x20,0x3F,0x20,0x00,0x03,0x00,0x00,0x00,//F38
    0xC0,0x30,0x08,0x08,0x08,0x38,0x00,0x00,0x07,0x18,0x20,0x20,0x22,0x1E,0x02,0x00,//G39
    0x08,0xF8,0x08,0x00,0x00,0x08,0xF8,0x08,0x20,0x3F,0x21,0x01,0x01,0x21,0x3F,0x20,//H40
    0x00,0x08,0x08,0xF8,0x08,0x08,0x00,0x00,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00,//I41
    0x00,0x00,0x08,0x08,0xF8,0x08,0x08,0x00,0xC0,0x80,0x80,0x80,0x7F,0x00,0x00,0x00,//J42
    0x08,0xF8,0x88,0xC0,0x28,0x18,0x08,0x00,0x20,0x3F,0x20,0x01,0x26,0x38,0x20,0x00,//K43
    0x08,0xF8,0x08,0x00,0x00,0x00,0x00,0x00,0x20,0x3F,0x20,0x20,0x20,0x20,0x30,0x00,//L44
    0x08,0xF8,0xF8,0x00,0xF8,0xF8,0x08,0x00,0x20,0x3F,0x00,0x3F,0x00,0x3F,0x20,0x00,//M45
    0x08,0xF8,0x30,0xC0,0x00,0x08,0xF8,0x08,0x20,0x3F,0x20,0x00,0x07,0x18,0x3F,0x00,//N46
    0xE0,0x10,0x08,0x08,0x08,0x10,0xE0,0x00,0x0F,0x10,0x20,0x20,0x20,0x10,0x0F,0x00,//O47
    0x08,0xF8,0x08,0x08,0x08,0x08,0xF0,0x00,0x20,0x3F,0x21,0x01,0x01,0x01,0x00,0x00,//P48
    0xE0,0x10,0x08,0x08,0x08,0x10,0xE0,0x00,0x0F,0x18,0x24,0x24,0x38,0x50,0x4F,0x00,//Q49
    0x08,0xF8,0x88,0x88,0x88,0x88,0x70,0x00,0x20,0x3F,0x20,0x00,0x03,0x0C,0x30,0x20,//R50
    0x00,0x70,0x88,0x08,0x08,0x08,0x38,0x00,0x00,0x38,0x20,0x21,0x21,0x22,0x1C,0x00,//S51
    0x18,0x08,0x08,0xF8,0x08,0x08,0x18,0x00,0x00,0x00,0x20,0x3F,0x20,0x00,0x00,0x00,//T52
    0x08,0xF8,0x08,0x00,0x00,0x08,0xF8,0x08,0x00,0x1F,0x20,0x20,0x20,0x20,0x1F,0x00,//U53
    0x08,0x78,0x88,0x00,0x00,0xC8,0x38,0x08,0x00,0x00,0x07,0x38,0x0E,0x01,0x00,0x00,//V54
    0xF8,0x08,0x00,0xF8,0x00,0x08,0xF8,0x00,0x03,0x3C,0x07,0x00,0x07,0x3C,0x03,0x00,//W55
    0x08,0x18,0x68,0x80,0x80,0x68,0x18,0x08,0x20,0x30,0x2C,0x03,0x03,0x2C,0x30,0x20,//X56
    0x08,0x38,0xC8,0x00,0xC8,0x38,0x08,0x00,0x00,0x00,0x20,0x3F,0x20,0x00,0x00,0x00,//Y57
    0x10,0x08,0x08,0x08,0xC8,0x38,0x08,0x00,0x20,0x38,0x26,0x21,0x20,0x20,0x18,0x00,//Z58
    0x00,0x00,0x00,0xFE,0x02,0x02,0x02,0x00,0x00,0x00,0x00,0x7F,0x40,0x40,0x40,0x00,//[59
    0x00,0x0C,0x30,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x06,0x38,0xC0,0x00,//\60
    0x00,0x02,0x02,0x02,0xFE,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x7F,0x00,0x00,0x00,//]61
    0x00,0x00,0x04,0x02,0x02,0x02,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//^62
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,//_63
    0x00,0x02,0x02,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//`64
    0x00,0x00,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x19,0x24,0x22,0x22,0x22,0x3F,0x20,//a65
    0x08,0xF8,0x00,0x80,0x80,0x00,0x00,0x00,0x00,0x3F,0x11,0x20,0x20,0x11,0x0E,0x00,//b66
    0x00,0x00,0x00,0x80,0x80,0x80,0x00,0x00,0x00,0x0E,0x11,0x20,0x20,0x20,0x11,0x00,//c67
    0x00,0x00,0x00,0x80,0x80,0x88,0xF8,0x00,0x00,0x0E,0x11,0x20,0x20,0x10,0x3F,0x20,//d68
    0x00,0x00,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x1F,0x22,0x22,0x22,0x22,0x13,0x00,//e69
    0x00,0x80,0x80,0xF0,0x88,0x88,0x88,0x18,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00,//f70
    0x00,0x00,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x6B,0x94,0x94,0x94,0x93,0x60,0x00,//g71
    0x08,0xF8,0x00,0x80,0x80,0x80,0x00,0x00,0x20,0x3F,0x21,0x00,0x00,0x20,0x3F,0x20,//h72
    0x00,0x80,0x98,0x98,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00,//i73
    0x00,0x00,0x00,0x80,0x98,0x98,0x00,0x00,0x00,0xC0,0x80,0x80,0x80,0x7F,0x00,0x00,//j74
    0x08,0xF8,0x00,0x00,0x80,0x80,0x80,0x00,0x20,0x3F,0x24,0x02,0x2D,0x30,0x20,0x00,//k75
    0x00,0x08,0x08,0xF8,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00,//l76
    0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x00,0x20,0x3F,0x20,0x00,0x3F,0x20,0x00,0x3F,//m77
    0x80,0x80,0x00,0x80,0x80,0x80,0x00,0x00,0x20,0x3F,0x21,0x00,0x00,0x20,0x3F,0x20,//n78
    0x00,0x00,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x1F,0x20,0x20,0x20,0x20,0x1F,0x00,//o79
    0x80,0x80,0x00,0x80,0x80,0x00,0x00,0x00,0x80,0xFF,0xA1,0x20,0x20,0x11,0x0E,0x00,//p80
    0x00,0x00,0x00,0x80,0x80,0x80,0x80,0x00,0x00,0x0E,0x11,0x20,0x20,0xA0,0xFF,0x80,//q81
    0x80,0x80,0x80,0x00,0x80,0x80,0x80,0x00,0x20,0x20,0x3F,0x21,0x20,0x00,0x01,0x00,//r82
    0x00,0x00,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x33,0x24,0x24,0x24,0x24,0x19,0x00,//s83
    0x00,0x80,0x80,0xE0,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x1F,0x20,0x20,0x00,0x00,//t84
    0x80,0x80,0x00,0x00,0x00,0x80,0x80,0x00,0x00,0x1F,0x20,0x20,0x20,0x10,0x3F,0x20,//u85
    0x80,0x80,0x80,0x00,0x00,0x80,0x80,0x80,0x00,0x01,0x0E,0x30,0x08,0x06,0x01,0x00,//v86
    0x80,0x80,0x00,0x80,0x00,0x80,0x80,0x80,0x0F,0x30,0x0C,0x03,0x0C,0x30,0x0F,0x00,//w87
    0x00,0x80,0x80,0x00,0x80,0x80,0x80,0x00,0x00,0x20,0x31,0x2E,0x0E,0x31,0x20,0x00,//x88
    0x80,0x80,0x80,0x00,0x00,0x80,0x80,0x80,0x80,0x81,0x8E,0x70,0x18,0x06,0x01,0x00,//y89
    0x00,0x80,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x21,0x30,0x2C,0x22,0x21,0x30,0x00,//z90
    0x00,0x00,0x00,0x00,0x80,0x7C,0x02,0x02,0x00,0x00,0x00,0x00,0x00,0x3F,0x40,0x40,//{91
    0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,//|92
    0x00,0x02,0x02,0x7C,0x80,0x00,0x00,0x00,0x00,0x40,0x40,0x3F,0x00,0x00,0x00,0x00,//}93
    0x00,0x06,0x01,0x01,0x02,0x02,0x04,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//~94
};

void Write_SPI_Command(unsigned char data){
    PDout(6) = 0;
    SPI_ReadWriteByte(HW_SPI0, HW_CTAR0, data, HW_SPI_CS0, kSPI_PCS_ReturnInactive);
}
void Write_SPI_Data(unsigned char data){
    PDout(6) = 1;
    SPI_ReadWriteByte(HW_SPI0, HW_CTAR0, data, HW_SPI_CS0, kSPI_PCS_ReturnInactive);
}
/*****************************************************************************
 函 数 名 : LED_WrDat
 功能描述 : 向OLED写数据
 输入参数 : uchar8 ucData
 输出参数 : NONE
 返 回 值 : NONE
*****************************************************************************/
void LED_WrDat(uchar8 ucData)
{
 Write_SPI_Data(ucData);
}

/*****************************************************************************
 函 数 名 : LED_WrCmd
 功能描述 : 向OLED写命令
 输入参数 : uchar8 ucCmd
 输出参数 : NONE
 返 回 值 : NONE
*****************************************************************************/
void LED_WrCmd(uchar8 ucCmd)
{
   Write_SPI_Command(ucCmd);
}

/*****************************************************************************
 函 数 名 : LED_SetPos
 功能描述 : 设置坐标
 输入参数 : uchar8 ucIdxX
             uchar8 ucIdxY
 输出参数 : NONE
 返 回 值 : NONE
*****************************************************************************/
void LED_SetPos(uchar8 ucIdxX, uchar8 ucIdxY)
{
    if(ucIdxX<132)ucIdxX += 2;
    LED_WrCmd(0xb0 + ucIdxY);
    LED_WrCmd(((ucIdxX & 0xf0) >> 4) | 0x10);
    LED_WrCmd((ucIdxX & 0x0f) | 0x00);
}

/*****************************************************************************
 函 数 名 : LED_Fill
 功能描述 : 对全屏写入同一个字符函数
             如 LED_Fill(0x01); 对于某一位0为不亮 1为亮
            ------------------------------------------------------
                                共128列
                  1 1 1
              共 0 0 0
              8 0 0 0
              组 0 ……0 ………… 0
              字 0 0 0
              符 0 0 0
              即 0 0 0
              8 0 0 0
              页 1 1 1
              64 0 0 0
              行 . . .
                  . . ………… .
                  . . .
                  . . .
                  0 0 0
            ------------------------------------------------------
 输入参数 : uchar8 ucData
 输出参数 : NONE
 返 回 值 : NONE
*****************************************************************************/
void LED_Fill(uchar8 ucData)
{
    uchar8 ucPage,ucColumn;

    for(ucPage = 0; ucPage < 8; ucPage++)
    {
        LED_WrCmd(0xb0 + ucPage); //0xb0+0~7表示页0~7
        LED_WrCmd(0x00); //0x00+0~16表示将128列分成16组其地址在某组中的第几列
        LED_WrCmd(0x10); //0x10+0~16表示将128列分成16组其地址所在第几组
        for(ucColumn = 0; ucColumn < 130; ucColumn++)
        {
            LED_WrDat(ucData);
        }
    }
}

void SetStartColumn(uchar8 ucData)
{
    LED_WrCmd(0x00+ucData % 16); // Set Lower Column Start Address for Page Addressing Mode
                                   // Default => 0x00
    LED_WrCmd(0x10+ucData / 16); // Set Higher Column Start Address for Page Addressing Mode
                                   // Default => 0x10
}

void SetAddressingMode(uchar8 ucData)
{
    LED_WrCmd(0x20); // Set Memory Addressing Mode
    LED_WrCmd(ucData); // Default => 0x02
                            // 0x00 => Horizontal Addressing Mode
                            // 0x01 => Vertical Addressing Mode
                            // 0x02 => Page Addressing Mode
}

void SetColumnAddress(uchar8 a, uchar8 b)
{
    LED_WrCmd(0x21); // Set Column Address
    LED_WrCmd(a); // Default => 0x00 (Column Start Address)
    LED_WrCmd(b); // Default => 0x7F (Column End Address)
}

void SetPageAddress(uchar8 a, uchar8 b)
{
    LED_WrCmd(0x22); // Set Page Address
    LED_WrCmd(a); // Default => 0x00 (Page Start Address)
    LED_WrCmd(b); // Default => 0x07 (Page End Address)
}

void SetStartLine(uchar8 ucData)
{
    LED_WrCmd(0x40|ucData); // Set Display Start Line
                            // Default => 0x40 (0x00)
}

void SetContrastControl(uchar8 ucData)
{
    LED_WrCmd(0x81); // Set Contrast Control
    LED_WrCmd(ucData); // Default => 0x7F
}

void SetChargePump(uchar8 ucData)
{
    LED_WrCmd(0x8D); // Set Charge Pump
    LED_WrCmd(0x10|ucData); // Default => 0x10
                            // 0x10 (0x00) => Disable Charge Pump
                            // 0x14 (0x04) => Enable Charge Pump
}

void SetSegmentRemap(uchar8 ucData)
{
    LED_WrCmd(0xA0|ucData); // Set Segment Re-Map
                            // Default => 0xA0
                            // 0xA0 (0x00) => Column Address 0 Mapped to SEG0
                            // 0xA1 (0x01) => Column Address 0 Mapped to SEG127
}

void SetEntireDisplay(uchar8 ucData)
{
    LED_WrCmd(0xA4|ucData); // Set Entire Display On / Off
                            // Default => 0xA4
                            // 0xA4 (0x00) => Normal Display
                            // 0xA5 (0x01) => Entire Display On
}

void SetInverseDisplay(uchar8 ucData)
{
    LED_WrCmd(0xA6|ucData); // Set Inverse Display On/Off
                            // Default => 0xA6
                            // 0xA6 (0x00) => Normal Display
                            // 0xA7 (0x01) => Inverse Display On
}

void SetMultiplexRatio(uchar8 ucData)
{
    LED_WrCmd(0xA8); // Set Multiplex Ratio
    LED_WrCmd(ucData); // Default => 0x3F (1/64 Duty)
}

void SetDisplayOnOff(uchar8 ucData)
{
    LED_WrCmd(0xAE|ucData); // Set Display On/Off
                            // Default => 0xAE
                            // 0xAE (0x00) => Display Off
                            // 0xAF (0x01) => Display On
}

void SetStartPage(uchar8 ucData)
{
    LED_WrCmd(0xB0|ucData); // Set Page Start Address for Page Addressing Mode
                            // Default => 0xB0 (0x00)
}

void SetCommonRemap(uchar8 ucData)
{
    LED_WrCmd(0xC0|ucData); // Set COM Output Scan Direction
                            // Default => 0xC0
                            // 0xC0 (0x00) => Scan from COM0 to 63
                            // 0xC8 (0x08) => Scan from COM63 to 0
}

void SetDisplayOffset(uchar8 ucData)
{
    LED_WrCmd(0xD3); // Set Display Offset
    LED_WrCmd(ucData); // Default => 0x00
}

void SetDisplayClock(uchar8 ucData)
{
    LED_WrCmd(0xD5); // Set Display Clock Divide Ratio / Oscillator Frequency
    LED_WrCmd(ucData); // Default => 0x80
                            // D[3:0] => Display Clock Divider
                            // D[7:4] => Oscillator Frequency
}

void SetPrechargePeriod(uchar8 ucData)
{
    LED_WrCmd(0xD9); // Set Pre-Charge Period
    LED_WrCmd(ucData); // Default => 0x22 (2 Display Clocks [Phase 2] / 2 Display Clocks [Phase 1])
                            // D[3:0] => Phase 1 Period in 1~15 Display Clocks
                            // D[7:4] => Phase 2 Period in 1~15 Display Clocks
}

void SetCommonConfig(uchar8 ucData)
{
    LED_WrCmd(0xDA); // Set COM Pins Hardware Configuration
    LED_WrCmd(0x02|ucData); // Default => 0x12 (0x10)
                            // Alternative COM Pin Configuration
                            // Disable COM Left/Right Re-Map
}

void SetVCOMH(uchar8 ucData)
{
    LED_WrCmd(0xDB); // Set VCOMH Deselect Level
    LED_WrCmd(ucData); // Default => 0x20 (0.77*VCC)
}

void SetNop(void)
{
    LED_WrCmd(0xE3); // Command for No Operation
}

/*****************************************************************************
 函 数 名 : LED_P8x16Str
 功能描述 : 写入一组8x16标准ASCII字符串
 输入参数 : UCHAR8 ucIdxX 为显示的横坐标0~120
             UCHAR8 ucIdxY 为页范围0～3
             UCHAR8 ucDataStr[] 要显示的字符串
 输出参数 : NONE
 返 回 值 : NONE
*****************************************************************************/
void LED_P8x16Str(uchar8 ucIdxX, uchar8 ucIdxY, uchar8 ucDataStr[])
{
    uchar8 i, j, ucDataTmp;

    ucIdxY <<= 1;

    for (j = 0; ucDataStr[j] != '\0'; j++)
    {
        ucDataTmp = ucDataStr[j] - 32;
        if(ucIdxX > 120)
        {
            ucIdxX = 0;
            ucIdxY += 2;
        }
        LED_SetPos(ucIdxX, ucIdxY);

        for(i = 0; i < 8; i++)
        {
            LED_WrDat(F8X16[(ucDataTmp << 4) + i]);
        }

        LED_SetPos(ucIdxX, ucIdxY + 1);

        for(i = 0; i < 8; i++)
        {
            LED_WrDat(F8X16[(ucDataTmp << 4) + i + 8]);
        }
        ucIdxX += 8;

    }

    return;
}

/*****************************************************************************
 函 数 名 : LED_Init
 功能描述 : OLED初始化
 输入参数 : void
 输出参数 : NONE
 返 回 值 : NONE
*****************************************************************************/
void initOLED(void)
{
    for(int i = 1;i <= 6; i++)
        GPIO_QuickInit(HW_GPIOD, i, kGPIO_Mode_OPP);

    SPI_QuickInit(SPI0_SCK_PD01_SOUT_PD02_SIN_PD03, kSPI_CPOL0_CPHA0, 8*1000*1000);

    PDout(5) = 0;
    DelayMs(1);
    PDout(5) = 1;
    //Reset and Wait

    SetDisplayOnOff(0x00); // Display Off (0x00/0x01)
    SetDisplayClock(0x80); // Set Clock as 100 Frames/Sec
    SetMultiplexRatio(0x3F); // 1/64 Duty (0x0F~0x3F)
    SetDisplayOffset(0x00); // Shift Mapping RAM Counter (0x00~0x3F)
    SetStartLine(0x00); // Set Mapping RAM Display Start Line (0x00~0x3F)
    SetChargePump(0x04); // Enable Embedded DC/DC Converter (0x00/0x04)
    SetAddressingMode(0x02); // Set Page Addressing Mode (0x00/0x01/0x02)
    SetSegmentRemap(0x01); // Set SEG/Column Mapping 0x00左右反置 0x01正常
    SetCommonRemap(0x08); // Set COM/Row Scan Direction 0x00上下反置 0x08正常
    SetCommonConfig(0x10); // Set Sequential Configuration (0x00/0x10)
    SetContrastControl(0xCF); // Set SEG Output Current
    SetPrechargePeriod(0xF1); // Set Pre-Charge as 15 Clocks & Discharge as 1 Clock
    SetVCOMH(0x40); // Set VCOM Deselect Level
    SetEntireDisplay(0x00); // Disable Entire Display On (0x00/0x01)
    SetInverseDisplay(0x00); // Disable Inverse Display On (0x00/0x01)
    SetDisplayOnOff(0x01); // Display On (0x00/0x01)
    LED_Fill(0x00); // 初始清屏
    LED_SetPos(0,0);

    printf("OLED init OK\r\n");
    return;
}

