#include "ssh1106.h"

unsigned char frame[1024]; 

Ssh106::Ssh106(uint8_t slave_addresse)
{
    _dev = new I2C(slave_addresse , 1);
    
   
    std::cout << " data 1" <<std::endl;
    SendCommand( SSD1306_DISPLAYOFF);  // Display off
    std::cout << " data 2" <<std::endl;
    SendCommand( SSD1306_MULTIPLEX_RATIO); // Set Multiplex Ratio 
    std::cout << " data 3" <<std::endl;
    SendCommand( 0x3F);                    
    std::cout << " data 4" <<std::endl;
    SendCommand( 0xD3);                     // Set Display Offset
    std::cout << " data 5" <<std::endl;
    SendCommand( 0x00);                     // no Offset
    std::cout << " data 6" <<std::endl;
    SendCommand( 0x40);                    // Set display Start Line
    std::cout << " data 7" <<std::endl;
    SendCommand( 0xA1);  std::cout << " data 8" <<std::endl; // Set Segment Re-Map
    SendCommand( 0xC8);  std::cout << " data 9" <<std::endl;  // Set COM Output Scan Direction
    SendCommand( 0xA6);std::cout << " data 10" <<std::endl;
    SendCommand( 0xD5);std::cout << " data 11" <<std::endl;
    SendCommand( 0x80);std::cout << " data 12" <<std::endl;
    SendCommand( 0xDA);  std::cout << " data 13" <<std::endl;  // Set COM Pins Hardware Configuration
    SendCommand( 0x12);std::cout << " data 14" <<std::endl;
    SendCommand( 0x81);  std::cout << " data 15" <<std::endl;   // Set Contrast Control
    SendCommand( 0x7F);std::cout << " data 16" <<std::endl;
    SendCommand( 0xA5);  std::cout << " data 17" <<std::endl;   // Set Entire Display On/Off
    SendCommand( 0xA6);  std::cout << " data 18" <<std::endl;     // Set Normal/Inverse Display
    //SendCommand( 0xD9);  std::cout << " data 19" <<std::endl;    // Set Pre-Charge Period
   // SendCommand( 0xF1);  std::cout << " data 20" <<std::endl;    // Snternal
    SendCommand(0xDB);  std::cout << " data 21" <<std::endl;    //Set VCOMH Deselect Level
    SendCommand(0x35);  std::cout << " data 22" <<std::endl;    
    SendCommand(0xD5);  std::cout << " data 23" <<std::endl;   // Set Display Clock Divide Ratio\Oscilator Frequency
    SendCommand(0x80);  std::cout << " data 24" <<std::endl;   // the suggested ratio 0x80
    //SendCommand(0x8D);  std::cout << " data 25" <<std::endl;   // Set Charge Pump
    //SendCommand( 0x14);  std::cout << " data 26" <<std::endl;  // Vcc internal
    SendCommand(0x00);  std::cout << " data 27" <<std::endl;   // Set Lower Column Start Address
    SendCommand(0x10);  std::cout << " data 28" <<std::endl;   // Set Higher Column Start Address
    SendCommand(0xB0);  std::cout << " data 29" <<std::endl;   // Set Page Start Address for Page Addressing Mode
    //SendCommand(0x20);  std::cout << " data 30" <<std::endl;   // Set Memory Addressing Mode
    //SendCommand(0x00);   std::cout << " data 31" <<std::endl;
    //SendCommand(0x00);  std::cout << " data 32" <<std::endl;   // Set Column Address (only for horizontal or vertical mode)
    // SendCommand(0x7F);   std::cout << " data 34" <<std::endl;
    //SendCommand(0x22);  std::cout << " data 35" <<std::endl;   // Set Page Address
    // SendCommand(0x00);   std::cout << " data 36" <<std::endl;
    //SendCommand(0x07);   std::cout << " data 37" <<std::endl;
    //SendCommand(0x2E);   std::cout << " data 38" <<std::endl;   // Deactivate Scroll

}




bool Ssh106::SendCommand(uint8_t reg)
{

    __u8 buffer[2] = {SSD1306_CONTROL_REG , reg};
    
    return _dev->Write_Bytes(buffer , 2); 

}




bool Ssh106::SendData(unsigned char data)

{
    __u8 buffer[2] = {SSD1306_DATA_REG ,(__u8) data};

    return _dev->Write_Bytes(buffer , 2);
}



void Ssh106::update_display()
{
    int i;
    for(i = 0; i < 1024; i++)
    
    {
        std :: cout <<" Senddata[" << i <<"]" <<std::endl;
        SendData( frame[i]);
    }
}


void Ssh106::clearDisplay()
{

    int i;
    for(i = 0; i < 1024; i++) {
        frame[i] = 0x00;
    }
  
  std::cout <<"begin update display in clear func" << std::endl;
   update_display();

   std::cout << "end update in clear" << std::endl;

}



void Ssh106::displayOff()
{
      clearDisplay();
      SendCommand(SSD1306_DISPLAYOFF);
}


void Ssh106::displayOn()
{
    std::cout << "dispay on begin func" << std::endl;
    SendCommand(SSD1306_DISPLAYON);
    RaspiGpio::milisecondDelay(500);
    std::cout << "begin clear" << std::endl;
    clearDisplay();
}


void Ssh106::draw(int x , int y , const char ascii)
{
unsigned char a[8], b[8];  // init two array with one byte
	unsigned int ascii_index;
	static const uint8_t num_str[95][16] = {
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // sp
    {0x00, 0x00, 0x00, 0x2f, 0x00, 0x00}, // !
    {0x00, 0x00, 0x07, 0x00, 0x07, 0x00}, // "
    {0x00, 0x14, 0x7f, 0x14, 0x7f, 0x14}, // #
    {0x00, 0x24, 0x2a, 0x7f, 0x2a, 0x12}, // $
    {0x00, 0x62, 0x64, 0x08, 0x13, 0x23}, // %
    {0x00, 0x36, 0x49, 0x55, 0x22, 0x50}, // &
    {0x00, 0x00, 0x05, 0x03, 0x00, 0x00}, // '
    {0x00, 0x00, 0x1c, 0x22, 0x41, 0x00}, // (
    {0x00, 0x00, 0x41, 0x22, 0x1c, 0x00}, // )
    {0x00, 0x14, 0x08, 0x3E, 0x08, 0x14}, // *
    {0x00, 0x08, 0x08, 0x3E, 0x08, 0x08}, // +
    {0x00, 0x00, 0x00, 0xA0, 0x60, 0x00}, // ,
    {0x00, 0x08, 0x08, 0x08, 0x08, 0x08}, // -
    {0x00, 0x00, 0x60, 0x60, 0x00, 0x00}, // .
    {0x00, 0x20, 0x10, 0x08, 0x04, 0x02}, // /
    {0x00, 0x3E, 0x51, 0x49, 0x45, 0x3E}, // 0
    {0x00, 0x00, 0x42, 0x7F, 0x40, 0x00}, // 1
    {0x00, 0x42, 0x61, 0x51, 0x49, 0x46}, // 2
    {0x00, 0x21, 0x41, 0x45, 0x4B, 0x31}, // 3
    {0x00, 0x18, 0x14, 0x12, 0x7F, 0x10}, // 4
    {0x00, 0x27, 0x45, 0x45, 0x45, 0x39}, // 5
    {0x00, 0x3C, 0x4A, 0x49, 0x49, 0x30}, // 6
    {0x00, 0x01, 0x71, 0x09, 0x05, 0x03}, // 7
    {0x00, 0x36, 0x49, 0x49, 0x49, 0x36}, // 8
    {0x00, 0x06, 0x49, 0x49, 0x29, 0x1E}, // 9
    {0x00, 0x00, 0x36, 0x36, 0x00, 0x00}, // :
    {0x00, 0x00, 0x56, 0x36, 0x00, 0x00}, // ;
    {0x00, 0x08, 0x14, 0x22, 0x41, 0x00}, // <
    {0x00, 0x14, 0x14, 0x14, 0x14, 0x14}, // =
    {0x00, 0x00, 0x41, 0x22, 0x14, 0x08}, // >
    {0x00, 0x02, 0x01, 0x51, 0x09, 0x06}, // ?
    {0x00, 0x32, 0x49, 0x59, 0x51, 0x3E}, // @
    {0x00, 0x7C, 0x12, 0x11, 0x12, 0x7C}, // A
    {0x00, 0x7F, 0x49, 0x49, 0x49, 0x36}, // B
    {0x00, 0x3E, 0x41, 0x41, 0x41, 0x22}, // C
    {0x00, 0x7F, 0x41, 0x41, 0x22, 0x1C}, // D
    {0x00, 0x7F, 0x49, 0x49, 0x49, 0x41}, // E
    {0x00, 0x7F, 0x09, 0x09, 0x09, 0x01}, // F
    {0x00, 0x3E, 0x41, 0x49, 0x49, 0x7A}, // G
    {0x00, 0x7F, 0x08, 0x08, 0x08, 0x7F}, // H
    {0x00, 0x00, 0x41, 0x7F, 0x41, 0x00}, // I
    {0x00, 0x20, 0x40, 0x41, 0x3F, 0x01}, // J
    {0x00, 0x7F, 0x08, 0x14, 0x22, 0x41}, // K
    {0x00, 0x7F, 0x40, 0x40, 0x40, 0x40}, // L
    {0x00, 0x7F, 0x02, 0x0C, 0x02, 0x7F}, // M
    {0x00, 0x7F, 0x04, 0x08, 0x10, 0x7F}, // N
    {0x00, 0x3E, 0x41, 0x41, 0x41, 0x3E}, // O
    {0x00, 0x7F, 0x09, 0x09, 0x09, 0x06}, // P
    {0x00, 0x3E, 0x41, 0x51, 0x21, 0x5E}, // Q
    {0x00, 0x7F, 0x09, 0x19, 0x29, 0x46}, // R
    {0x00, 0x46, 0x49, 0x49, 0x49, 0x31}, // S
    {0x00, 0x01, 0x01, 0x7F, 0x01, 0x01}, // T
    {0x00, 0x3F, 0x40, 0x40, 0x40, 0x3F}, // U
    {0x00, 0x1F, 0x20, 0x40, 0x20, 0x1F}, // V
    {0x00, 0x3F, 0x40, 0x38, 0x40, 0x3F}, // W
    {0x00, 0x63, 0x14, 0x08, 0x14, 0x63}, // X
    {0x00, 0x07, 0x08, 0x70, 0x08, 0x07}, // Y
    {0x00, 0x61, 0x51, 0x49, 0x45, 0x43}, // Z
    {0x00, 0x00, 0x7F, 0x41, 0x41, 0x00}, // [
    {0x00, 0x55, 0x2A, 0x55, 0x2A, 0x55}, // backslash
    {0x00, 0x00, 0x41, 0x41, 0x7F, 0x00}, // ]
    {0x00, 0x04, 0x02, 0x01, 0x02, 0x04}, // ^
    {0x00, 0x40, 0x40, 0x40, 0x40, 0x40}, // _
    {0x00, 0x00, 0x01, 0x02, 0x04, 0x00}, // '
    {0x00, 0x20, 0x54, 0x54, 0x54, 0x78}, // a
    {0x00, 0x7F, 0x48, 0x44, 0x44, 0x38}, // b
    {0x00, 0x38, 0x44, 0x44, 0x44, 0x20}, // c
    {0x00, 0x38, 0x44, 0x44, 0x48, 0x7F}, // d
    {0x00, 0x38, 0x54, 0x54, 0x54, 0x18}, // e
    {0x00, 0x08, 0x7E, 0x09, 0x01, 0x02}, // f
    {0x00, 0x18, 0xA4, 0xA4, 0xA4, 0x7C}, // g
    {0x00, 0x7F, 0x08, 0x04, 0x04, 0x78}, // h
    {0x00, 0x00, 0x44, 0x7D, 0x40, 0x00}, // i
    {0x00, 0x40, 0x80, 0x84, 0x7D, 0x00}, // j
    {0x00, 0x7F, 0x10, 0x28, 0x44, 0x00}, // k
    {0x00, 0x00, 0x41, 0x7F, 0x40, 0x00}, // l
    {0x00, 0x7C, 0x04, 0x18, 0x04, 0x78}, // m
    {0x00, 0x7C, 0x08, 0x04, 0x04, 0x78}, // n
    {0x00, 0x38, 0x44, 0x44, 0x44, 0x38}, // o
    {0x00, 0xFC, 0x24, 0x24, 0x24, 0x18}, // p
    {0x00, 0x18, 0x24, 0x24, 0x18, 0xFC}, // q
    {0x00, 0x7C, 0x08, 0x04, 0x04, 0x08}, // r
    {0x00, 0x48, 0x54, 0x54, 0x54, 0x20}, // s
    {0x00, 0x04, 0x3F, 0x44, 0x40, 0x20}, // t
    {0x00, 0x3C, 0x40, 0x40, 0x20, 0x7C}, // u
    {0x00, 0x1C, 0x20, 0x40, 0x20, 0x1C}, // v
    {0x00, 0x3C, 0x40, 0x30, 0x40, 0x3C}, // w
    {0x00, 0x44, 0x28, 0x10, 0x28, 0x44}, // x
    {0x00, 0x1C, 0xA0, 0xA0, 0xA0, 0x7C}, // y
    {0x00, 0x44, 0x64, 0x54, 0x4C, 0x44}, // z
    {0x00, 0x00, 0x08, 0x77, 0x41, 0x00}, // {
    {0x00, 0x00, 0x00, 0x63, 0x00, 0x00}, // ¦
    {0x00, 0x00, 0x41, 0x77, 0x08, 0x00}, // }
    {0x00, 0x08, 0x04, 0x08, 0x08, 0x04}, // ~
	};

	ascii_index = (ascii - 32)*6;  // correct ascii offset
	
    
    
    
    memcpy(a, num_str[ascii_index], 8);
	memcpy(b, num_str[ascii_index] + 8, 8);
	memcpy(frame + ((x - 1) * 256) + ((y - 1) * 8), a, 8);
	memcpy(frame + ((x - 1) * 256) + ((y - 1) * 8) + 128, b, 8);

 
}



void Ssh106::draw_line(int x , int y , const char ascii_str[16])
{
    int i;
	for(i = 0; i < strlen(ascii_str); i++){
		draw(x,y++,ascii_str[i]);
	}
}




int main ()

{

    std::cout << " begin Setup" <<std::endl;

    Ssh106 Dispaly(0x3c);
     std::cout << " begin display on" <<std::endl;
     RaspiGpio::milisecondDelay(1000); 
    Dispaly.displayOn();
    RaspiGpio::milisecondDelay(1000); 

    std::cout << "begin trasnmission" << std::endl;

    Dispaly.draw_line(1 , 1 , "hello"); 
    Dispaly.draw_line(2 , 1, "world");
    Dispaly.update_display();
    sleep(20);

    Dispaly.displayOff();
    return 0;

}