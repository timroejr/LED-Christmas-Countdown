//
//  main.cpp
//  ChristmasLED
//
//  Created by Timothy Roe Jr. on 12/19/15.
//  Copyright © 2015 Timothy Roe Jr. All rights reserved.
//

#include <iostream>
#include <unistd.h>
#include <math.h>
#include "led-matrix.h"
#include "threaded-canvas-manipulator.h"
#include "canvas.h"
#include <stdio.h>
#include <string.h>
#include "graphics.h"
#include <getopt.h>
#include <stdlib.h>
#include <fstream>

//#include <Python.h>

using rgb_matrix::GPIO;
using rgb_matrix::RGBMatrix;
using rgb_matrix::Canvas;

using namespace rgb_matrix;
using namespace std;


static void DrawOnCanvas(Canvas *led) {
    
    std::string filename = "countdownToChristmas.py";
    std::string command = "python ";
    command += filename;
    system(command.c_str());
    sleep(1);/*
    const char *bdf_font_file = "fonts/4x6.bdf";
    bdf_font_file = strdup(optarg);
    rgb_matrix::Font font;
    font.LoadFont(bdf_font_file);
    if (!font.LoadFont(bdf_font_file)) {
        fprintf(stderr, "ERROR, Font '%s' not found.\n", bdf_font_file);
    } else {
        printf("Font Found");
    }
    Color color(255, 0, 0);
    rgb_matrix::DrawText(led, font, 1, font.baseline(), color, "Hello");*/
    
    
    int center_x = led->width()/2;
    int width = led->width();
    int height = led->height();
    int x1 = center_x;
    int x2 = center_x;
    int y;
    printf("Top of Tree\n");
    for (y = 0; y < 7; y++) {
        led->SetPixel(x1-1, y, 0, 255, 0);
        led->SetPixel(x2-1, y, 0, 255, 0);
        x1++;
        x2--;
    }
    int x1_1 = 0;
    for (int i = x1-1; i > center_x+2 ; i--) {
        led->SetPixel(i, y, 0, 255, 0);
        x1_1 = i;
    }
    int x2_2 = 0;
    for (int i = x2-1; i < center_x-4; i++) {
        led->SetPixel(i, y, 0, 255, 0);
        x2_2 = i;
    }
    
    printf("Bottom of Tree\n");
    int y2 = 0;
    for (int i = y; i < 18; i++) {
        led->SetPixel(x1_1-1, i, 0, 255, 0);
        led->SetPixel(x2_2+1, i, 0, 255, 0);
        x1_1++;
        x2_2--;
        y2 = i;
    }
    for (int i = x1_1-2; i > center_x+2; i--) {
        led->SetPixel(i, y2, 0, 255, 0);
        x1_1 = i;
    }
    for (int i = x2_2+3; i < center_x-4; i++) {
        led->SetPixel(i, y2, 0, 255, 0);
        x2_2 = i;
    }
    
    printf("Base of Tree\n");
    for (int i = y2; i < 24; i++) {
        led->SetPixel(x1_1, i, 0, 255, 0);
        led->SetPixel(x2_2, i, 0, 255, 0);
        y2 = i;
    }
    
    for (int i = x2_2; i < x1_1; i++) {
        led->SetPixel(i, y2, 0, 255, 0);
    }
    
    led->SetPixel(12, 10, 0, 0, 255);
    led->SetPixel(18, 5, 255, 0, 255);
    led->SetPixel(19, 15, 255, 255, 0);
    led->SetPixel(18, 13, 0, 255, 255);
    led->SetPixel(16, 16, 99, 234, 23);
    led->SetPixel(9, 20, 234, 86, 98);
    led->SetPixel(14, 12, 87, 250, 23);
    led->SetPixel(12, 10, 234, 0, 234);
    led->SetPixel(15, 13, 234, 98, 76);
    
}

static void countdown(Canvas *led) {
    Color color(0, 0, 255);
    const char *bdf = "fonts/4x6.bdf";
    rgb_matrix::Font font;
    if (!font.LoadFont(bdf)) {
        printf("ERROR FONT COULD NOT LOAD");
    }
    char line[1024];
    ifstream readFile;
    readFile.open("Countdown.txt");
    int y = 6;
    if (readFile.is_open()) {
        while (!readFile.eof()) {
            readFile >> line;
            cout << line << endl;
            rgb_matrix::DrawText(led, font, 2, y, color, line);
            y += 6;
        }
    }
}

int main(int argc, char *argv[]) {
    GPIO io;
    if (!io.Init()) {
        return 1;
    }
    
    int rows = 32;
    int chain = 1;
    Canvas *led = new RGBMatrix(&io, rows, chain);
    led->Clear();
    while (true) {
        DrawOnCanvas(led);
        sleep(10);
        led->Clear();
        sleep(1);
        countdown(led);
        sleep(10);
        led->Clear();
    }
    //showTime(led);
    
    printf("Press <RETURN> to Reset Board\n");
    getchar();
    
    led->Clear();
    delete led;
    
    return 0;
}

// -- END CODE --