#include "weather_icons2.h"

#define y_off  3
#define y_off2 6

void graphics_draw_weather(GContext* ctx, weather* forecast, char** text) {
  for (int i = 0; i < 5; i++) {
    weather current = forecast[i];
//     weather next = null;
//     if (i < 5) {
//       next = forecast[i+1];
//     }
    if (current == clear) {
      graphics_context_set_fill_color(ctx, GColorCyan);
    } else if (current == cloudy) {
      graphics_context_set_fill_color(ctx, GColorVividCerulean);
    } else if (current == rainy || current == tstorm) {
      graphics_context_set_fill_color(ctx, GColorVeryLightBlue);
    }
    graphics_context_set_fill_color(ctx, GColorVividCerulean);
    graphics_fill_rect(ctx, GRect(i*29, 85+y_off2, 29, 168), 0, GCornerNone);
    
    if (i<=2) {
      graphics_context_set_fill_color(ctx, GColorDukeBlue);
    } else {
      graphics_context_set_fill_color(ctx, GColorYellow);
    }
    graphics_fill_rect(ctx, GRect(i*29, 85+y_off2-3, 29, 4), 0, GCornerNone);
  }
  graphics_context_set_fill_color(ctx, GColorVividCerulean);
  graphics_fill_rect(ctx, GRect(0, 85+y_off2-5, 2, 9), 0, GCornerNone);
  graphics_fill_rect(ctx, GRect(144-2, 85+y_off2-5, 2, 9), 0, GCornerNone);
  graphics_fill_rect(ctx, GRect(0, 85+y_off2-5, 144, 2), 0, GCornerNone);
  graphics_context_set_stroke_color(ctx, GColorDukeBlue);
  graphics_draw_rect(ctx, GRect(2,85+y_off2-3,140,4));
  
  for (int i = 0; i < 5; i++) {
    weather current = forecast[i];
    weather next = null;
    if (i < 5) {
      next = forecast[i+1];
    }
    
    if (current == cloudy) {
      graphics_draw_cloud(ctx, i, 0, GColorWhite, next);
    } else if (current == rainy || current == tstorm) {
      graphics_draw_cloud(ctx, i, 0, GColorDarkGray, next);
    } else if (current == part_cloudy) {
      graphics_draw_part_cloudy(ctx, i, 0, next);
    }
  }
  
  for (int i = 0; i < 5; i++) {
    weather current = forecast[i];
    weather next = null;
    if (i < 5) {
      next = forecast[i+1];
    }
    
    if (current == cloudy) {
      graphics_draw_cloud(ctx, i, 1, GColorWhite, next);
    } else if (current == rainy) {
      graphics_draw_cloud(ctx, i, 1, GColorDarkGray, next);
      graphics_draw_rain(ctx, i);
    } else if (current == tstorm) {
      graphics_draw_cloud(ctx, i, 1, GColorDarkGray, next);
      graphics_draw_lightning(ctx,i);
    } else if (current == part_cloudy) {
      graphics_draw_part_cloudy(ctx, i, 1, next);
    }
  }
  
  for (int i = 0; i < 5; i++) {
    graphics_draw_wtext(ctx, i, text[i*2], text[i*2 + 1]);
  }
}

void graphics_draw_cloud(GContext * ctx, int pos, int isFront, GColor color, weather next) {
  int start = 29*pos;
  
  if (isFront == 0) {
    graphics_context_set_fill_color(ctx, GColorBlack);
    graphics_context_set_stroke_color(ctx, GColorBlack);
    graphics_fill_circle(ctx, GPoint(start + 7, 102+y_off), 6);
    graphics_fill_circle(ctx, GPoint(start + 14, 99+y_off), 7);
    graphics_fill_circle(ctx, GPoint(start + 22, 103+y_off), 5);
    graphics_draw_line(ctx, GPoint(start + 7, 107+y_off), GPoint(start + 18, 107+y_off));
    graphics_draw_line(ctx, GPoint(start + 7, 108+y_off), GPoint(start + 18, 108+y_off));
    if (next == cloudy || next == rainy || next == tstorm) {
      graphics_fill_circle(ctx, GPoint(start + 30, 101+y_off), 7);
      graphics_draw_line(ctx, GPoint(start + 13, 107+y_off), GPoint(start + 32, 107+y_off));
      graphics_draw_line(ctx, GPoint(start + 13, 108+y_off), GPoint(start + 32, 108+y_off));
    }
  } else {
    graphics_context_set_fill_color(ctx, color);
    graphics_fill_circle(ctx, GPoint(start + 7, 102+y_off), 4);
    graphics_fill_circle(ctx, GPoint(start + 14, 99+y_off), 5);
    graphics_fill_circle(ctx, GPoint(start + 22, 103+y_off), 3);
    graphics_fill_rect(ctx, GRect(start + 7, 101+y_off, 16, 6), 0, GCornerNone);
    
    GColor nextColor = GColorClear;
    if (next == cloudy) {
      nextColor = GColorWhite;
    } else if (next == rainy || next == tstorm) {
      nextColor = GColorDarkGray;
    }
    
    if (!gcolor_equal(nextColor, GColorClear)) {
      if (!gcolor_equal(color, nextColor)) {
        graphics_context_set_fill_color(ctx, GColorLightGray);
      }
      graphics_fill_circle(ctx, GPoint(start + 30, 101+y_off), 5);
      graphics_fill_circle(ctx, GPoint(start + 32, 103+y_off), 3);
      graphics_fill_circle(ctx, GPoint(start + 26, 103+y_off), 3);
      graphics_context_set_fill_color(ctx, color);
      graphics_fill_circle(ctx, GPoint(start + 23, 103+y_off), 3);
    }
  }
}

void graphics_draw_rain(GContext * ctx, int pos) {
  int start = 29*pos + 2;
  
  graphics_context_set_stroke_color(ctx, GColorOxfordBlue);
  graphics_draw_line(ctx, GPoint(start + 7,109+y_off), GPoint(start + 4,115+y_off));
  graphics_draw_line(ctx, GPoint(start + 12,109+y_off), GPoint(start + 8,117+y_off));
  graphics_draw_line(ctx, GPoint(start + 17,109+y_off), GPoint(start + 14,115+y_off));
  
  graphics_draw_line(ctx, GPoint(start + 6,109+y_off), GPoint(start + 3,115+y_off));
  graphics_draw_line(ctx, GPoint(start + 11,109+y_off), GPoint(start + 7,117+y_off));
  graphics_draw_line(ctx, GPoint(start + 16,109+y_off), GPoint(start + 13,115+y_off));
}

void graphics_draw_lightning(GContext * ctx, int pos) {
  int start = 29*pos + 2;
  
  graphics_context_set_stroke_color(ctx, GColorYellow);
  for (int i = 0; i < 5; i++) {
    graphics_draw_line(ctx, GPoint(start + 10 + i,109+y_off), GPoint(start + 8 + i,115+y_off));
  }
  for (int i = 0; i < 4; i++) {
    graphics_draw_line(ctx, GPoint(start + 12 + i,114+y_off), GPoint(start + 8,122+y_off));
  }
  
  graphics_context_set_stroke_color(ctx, GColorBlack);
  graphics_draw_line(ctx, GPoint(start + 9, 109+y_off), GPoint(start + 7, 115+y_off));
  graphics_draw_line(ctx, GPoint(start + 15, 109+y_off), GPoint(start + 13, 113+y_off));
  graphics_draw_line(ctx, GPoint(start + 10, 116+y_off), GPoint(start + 7, 123+y_off));
  graphics_draw_line(ctx, GPoint(start + 16, 114+y_off), GPoint(start + 8, 123+y_off));
}

void graphics_draw_part_cloudy(GContext * ctx, int pos, int isFront, weather next) {
  int start = 29*pos;
  
  if (isFront == 0) {
    graphics_context_set_fill_color(ctx, GColorBlack);
    graphics_fill_circle(ctx, GPoint(start + 7, 104+y_off), 4);
    graphics_fill_circle(ctx, GPoint(start + 11, 105+y_off), 3);
    
    graphics_fill_circle(ctx, GPoint(start + 19, 96+y_off), 4);
    graphics_fill_circle(ctx, GPoint(start + 23, 97+y_off), 3);
    
    if (next == part_cloudy) {
      if (pos%2 == 0) {
        graphics_fill_circle(ctx, GPoint(start + 27, 97+y_off), 3);
      } else {
        graphics_fill_circle(ctx, GPoint(start + 31, 103+y_off), 5);
      }
    }
  } else {
    graphics_context_set_fill_color(ctx, GColorWhite);
    graphics_fill_circle(ctx, GPoint(start + 7, 104+y_off), 2);
    graphics_fill_circle(ctx, GPoint(start + 11, 105+y_off), 1);
    graphics_fill_circle(ctx, GPoint(start + 9, 105+y_off), 1);
    
    graphics_fill_circle(ctx, GPoint(start + 19, 96+y_off), 2);
    graphics_fill_circle(ctx, GPoint(start + 23, 97+y_off), 1);
    graphics_fill_circle(ctx, GPoint(start + 21, 97+y_off), 1);
    
    if (next == part_cloudy) {
      if (pos%2 == 0) {
        graphics_fill_circle(ctx, GPoint(start + 27, 97+y_off), 1);
        graphics_fill_circle(ctx, GPoint(start + 26, 97+y_off), 1);
      } else {
        graphics_fill_circle(ctx, GPoint(start + 31, 103+y_off), 3);
        graphics_fill_circle(ctx, GPoint(start + 33, 104+y_off), 2);
      }
    }
  }
}

void graphics_draw_wtext(GContext* ctx, int pos, char* time, char* temp) {
  int start = 29*pos;
  
  GFont custom_font_3 = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_BLOCKY_11));
  //GFont custom_font_4 = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_BLOCKY_08));
  graphics_context_set_text_color(ctx, GColorBlack);
  graphics_draw_text(ctx, temp, custom_font_3, GRect(start+2, 124, 29, 15), GTextOverflowModeWordWrap, GTextAlignmentCenter, NULL);
  graphics_draw_text(ctx, time, custom_font_3, GRect(start+2, 140, 29, 15), GTextOverflowModeWordWrap, GTextAlignmentCenter, NULL);
}

// void graphics_draw_battery(GContext* ctx, int percent) {
//   for (int i = 0; i<10; i+=1) {
//     graphics_context_set_fill_color(ctx, GColorLightGray);
//     graphics_context_set_stroke_color(ctx, GColorLightGray);
//     if (100-i*10<=percent) {
//       graphics_fill_rect(ctx, GRect(22 + i*10, 4, 6, 5), 0, GCornerNone);
//     } else {
//       graphics_draw_rect(ctx, GRect(22 + i*10, 4, 6, 5));
//     }
//   }
//   graphics_fill_rect(ctx, GRect(22 + 90 + 3, 4, 3, 5), 0, GCornerNone);
// }