#include "mbed.h"
#include "uLCD_4DGL.h"

uLCD_4DGL uLCD(p9,p10,p11);

int main() {
    
    int x;
    int y;
    int radius;
    int vx;
    
    //Set out UART baudrate to somehting reasonable
    uLCD.baudrate(921600);
    
    //Change background color (must be caclled before cls)
    uLCD.background_color(WHITE);
    
    //Clear screen with background color
    uLCD.cls();
    
    //Change background color of text
    uLCD.textbackground_color(WHITE);
    
    //Make some colorful text
    uLCD.locate(4,1);  //Move cursor
    uLCD.color(BLUE);
    //uLCD.printf("I\n");
    uLCD.locate(2,3);  //Move cursor
    uLCD.text_width(2);  //2x normal size
    uLCD.text_height(2); //2x normal size
    //uLCD.color(RED);  //Change text color
    uLCD.printf("BATMAN!");
    uLCD.text_width(1);  //Normal size
    uLCD.text_height(1); //Move cursor
    uLCD.locate(3,6); //Move cursor
    uLCD.color(BLACK); //Change text color
    //uLCD.printf("of my new LCD");
    
    // Initial parameters for the circle
    x=50;
    y=100;
    radius=4;
    vx=1;
    
    //Make a ball bounce back and forth
    while (1) {
        
        // Draw a dark green
        uLCD.filled_circle(x,y,radius, 0x008000);
        
        // Bounce off the edges
        if ((x <= radius + 1) || (x >= 126 -radius)) {
            vx = -1 * vx;
        }
        
        //Wait before erasing old circlce
        wait(0.1); //In seconds
        
        // Erase old circle
        uLCD.filled_circle(x,y,radius,WHITE);
        
        // Move circle
        x = x + vx;
    }
}
        
    
    