// #include "weather_icons.h"


// void graphics_draw_weather(GContext* ctx, weather* forecast) {
//   for (int i = 0; i < 6; i++) {
//     weather current = forecast[i];
// //     weather next = null;
// //     if (i < 5) {
// //       next = forecast[i+1];
// //     }
//     if (current == clear) {
//       graphics_context_set_fill_color(ctx, GColorCyan);
//     } else if (current == cloudy) {
//       graphics_context_set_fill_color(ctx, GColorVividCerulean);
//     } else if (current == rainy || current == tstorm) {
//       graphics_context_set_fill_color(ctx, GColorVeryLightBlue);
//     }
// //     graphics_context_set_fill_color(ctx, GColorCeleste);
//     graphics_fill_rect(ctx, GRect(0 + i*24, 90, 24, 168), 0, GCornerNone);
//   }
  
//   for (int i = 0; i < 6; i++) {
//     weather current = forecast[i];
//     weather next = null;
//     if (i < 5) {
//       next = forecast[i+1];
//     }
    
//     if (current == cloudy) {
//       graphics_draw_cloud(ctx, i, 0, GColorWhite, next);
//     } else if (current == rainy || current == tstorm) {
//       graphics_draw_cloud(ctx, i, 0, GColorDarkGray, next);
//     }
//   }
  
//   for (int i = 0; i < 6; i++) {
//     weather current = forecast[i];
//     weather next = null;
//     if (i < 5) {
//       next = forecast[i+1];
//     }
    
//     if (current == cloudy) {
//       graphics_draw_cloud(ctx, i, 1, GColorWhite, next);
//     } else if (current == rainy) {
//       graphics_draw_cloud(ctx, i, 1, GColorDarkGray, next);
// //       graphics_draw_rain(ctx, i);
//     } else if (current == tstorm) {
//       graphics_draw_cloud(ctx, i, 1, GColorDarkGray, next);
//       graphics_draw_lightning(ctx,i);
//       graphics_draw_rain(ctx, i);
//     }
//   }
// }

// void graphics_draw_cloud(GContext * ctx, int pos, int isFront, GColor color, weather next) {
//   int start = 24*pos;
  
//   if (isFront == 0) {
//     graphics_context_set_fill_color(ctx, GColorBlack);
//     graphics_context_set_stroke_color(ctx, GColorBlack);
//     graphics_fill_circle(ctx, GPoint(start + 6, 101), 5);
//     graphics_fill_circle(ctx, GPoint(start + 13, 98), 6);
//     graphics_fill_circle(ctx, GPoint(start + 19, 102), 4);
//     graphics_draw_line(ctx, GPoint(start + 7, 105), GPoint(start + 18, 105));
//     graphics_draw_line(ctx, GPoint(start + 7, 106), GPoint(start + 18, 106));
//     if (next == cloudy || next == rainy || next == tstorm) {
//       graphics_fill_circle(ctx, GPoint(start + 25, 100), 5);
//       graphics_draw_line(ctx, GPoint(start + 13, 105), GPoint(start + 30, 105));
//       graphics_draw_line(ctx, GPoint(start + 13, 106), GPoint(start + 30, 106));
//     }
//   } else {
//     graphics_context_set_fill_color(ctx, color);
//     graphics_fill_circle(ctx, GPoint(start + 6, 101), 3);
//     graphics_fill_circle(ctx, GPoint(start + 13, 98), 4);
//     graphics_fill_circle(ctx, GPoint(start + 19, 102), 2);
//     graphics_fill_rect(ctx, GRect(start + 7, 102, 11, 3), 0, GCornerNone);
    
//     GColor nextColor = GColorClear;
//     if (next == cloudy) {
//       nextColor = GColorWhite;
//     } else if (next == rainy || next == tstorm) {
//       nextColor = GColorDarkGray;
//     }
    
//     if (!gcolor_equal(nextColor, GColorClear)) {
//       if (!gcolor_equal(color, nextColor)) {
//         graphics_context_set_fill_color(ctx, GColorLightGray);
//       }
//       graphics_fill_circle(ctx, GPoint(start + 25, 100), 3);
//       graphics_fill_circle(ctx, GPoint(start + 28, 101), 3);
//       graphics_fill_circle(ctx, GPoint(start + 22, 102), 2);
//       graphics_context_set_fill_color(ctx, color);
//       graphics_fill_circle(ctx, GPoint(start + 19, 102), 2);
//     }
//   }
// }

// void graphics_draw_rain(GContext * ctx, int pos) {
//   int start = 24*pos;
  
//   graphics_context_set_stroke_color(ctx, GColorDukeBlue);
//   graphics_draw_line(ctx, GPoint(start + 7,106), GPoint(start + 4,112));
//   graphics_draw_line(ctx, GPoint(start + 12,106), GPoint(start + 8,114));
//   graphics_draw_line(ctx, GPoint(start + 17,106), GPoint(start + 14,112));
  
//   graphics_draw_line(ctx, GPoint(start + 6,106), GPoint(start + 3,112));
//   graphics_draw_line(ctx, GPoint(start + 11,106), GPoint(start + 7,114));
//   graphics_draw_line(ctx, GPoint(start + 16,106), GPoint(start + 13,112));
// }

// void graphics_draw_lightning(GContext * ctx, int pos) {
//   int start = 24*pos - 0;
  
//   graphics_context_set_stroke_color(ctx, GColorYellow);
//   for (int i = 0; i < 5; i++) {
//     graphics_draw_line(ctx, GPoint(start + 10 + i,106), GPoint(start + 8 + i,112));
//   }
//   for (int i = 0; i < 4; i++) {
//     graphics_draw_line(ctx, GPoint(start + 12 + i,111), GPoint(start + 8,119));
//   }
  
//   graphics_context_set_stroke_color(ctx, GColorBlack);
//   graphics_draw_line(ctx, GPoint(start + 9, 106), GPoint(start + 7, 112));
//   graphics_draw_line(ctx, GPoint(start + 10, 113), GPoint(start + 7, 120));
//   graphics_draw_line(ctx, GPoint(start + 14, 113), GPoint(start + 8, 120));
// }

// // void graphics_draw_weather_cloudy(GContext * ctx, int pos, int isFront, weather next) {
// //   int start = 24*pos;
  
// //   if (isFront == 0) {
// //     graphics_context_set_fill_color(ctx, GColorBlack);
// //     graphics_context_set_stroke_color(ctx, GColorBlack);
// //     graphics_fill_circle(ctx, GPoint(start + 7, 101), 4);
// //     graphics_fill_circle(ctx, GPoint(start + 13, 98), 5);
// //     graphics_fill_circle(ctx, GPoint(start + 18, 102), 3);
// //     graphics_draw_line(ctx, GPoint(start + 7, 105), GPoint(start + 18, 105));
// //     if (next == cloudy || next == rainy) {
// //       graphics_fill_circle(ctx, GPoint(start + 25, 100), 5);
// //       graphics_draw_line(ctx, GPoint(start + 13, 105), GPoint(start + 30, 105));
// //     }
// //   } else {
// //     graphics_context_set_fill_color(ctx, GColorWhite);
// //     graphics_fill_circle(ctx, GPoint(start + 7, 101), 3);
// //     graphics_fill_circle(ctx, GPoint(start + 13, 98), 4);
// //     graphics_fill_circle(ctx, GPoint(start + 18, 102), 2);
// //     graphics_fill_rect(ctx, GRect(start + 7, 102, 11, 3), 0, GCornerNone);
// //     if (next == cloudy) {
// //       graphics_fill_circle(ctx, GPoint(start + 25, 100), 4);
// // //       graphics_context_set_fill_color(ctx, GColorBlue);
// //       graphics_fill_circle(ctx, GPoint(start + 21, 102), 2);
// //       graphics_fill_circle(ctx, GPoint(start + 22, 102), 2);
// //       graphics_fill_circle(ctx, GPoint(start + 28, 101), 3);
// // //       graphics_fill_rect(ctx, GRect(start + 7 + 4, 102, 20, 3), 0, GCornerNone);
// //     } else if (next == rainy) {
// //       graphics_context_set_fill_color(ctx, GColorLightGray);
// //       graphics_fill_circle(ctx, GPoint(start + 25, 100), 4);
// // //       graphics_context_set_fill_color(ctx, GColorBlue);
// //       graphics_context_set_fill_color(ctx, GColorWhite);
// //       graphics_fill_circle(ctx, GPoint(start + 21, 102), 2);
// //       graphics_fill_circle(ctx, GPoint(start + 22, 102), 2);
// //       graphics_context_set_fill_color(ctx, GColorLightGray);
// //       graphics_fill_circle(ctx, GPoint(start + 28, 101), 3);
// //     }
// //   }
// // }

// // void graphics_draw_weather_rainy(GContext* ctx, int pos, int isFront, weather next) {
// //   int start = 24*pos;
  
// //   if (isFront == 0) {
// //     graphics_context_set_fill_color(ctx, GColorBlack);
// //     graphics_context_set_stroke_color(ctx, GColorBlack);
// //     graphics_fill_circle(ctx, GPoint(start + 7, 101), 4);
// //     graphics_fill_circle(ctx, GPoint(start + 13, 98), 5);
// //     graphics_fill_circle(ctx, GPoint(start + 18, 102), 3);
// //     graphics_draw_line(ctx, GPoint(start + 7, 105), GPoint(start + 18, 105));
// //     if (next == cloudy || next == rainy) {
// //       graphics_fill_circle(ctx, GPoint(start + 25, 100), 5);
// //       graphics_draw_line(ctx, GPoint(start + 13, 105), GPoint(start + 30, 105));
// //     }
// //   } else {
// //     graphics_context_set_fill_color(ctx, GColorDarkGray);
// //     graphics_fill_circle(ctx, GPoint(start + 7, 101), 3);
// //     graphics_fill_circle(ctx, GPoint(start + 13, 98), 4);
// //     graphics_fill_circle(ctx, GPoint(start + 18, 102), 2);
// //     graphics_fill_rect(ctx, GRect(start + 7, 102, 11, 3), 0, GCornerNone);
// //     if (next == cloudy) {
// //       graphics_context_set_fill_color(ctx, GColorLightGray);
// //       graphics_fill_circle(ctx, GPoint(start + 25, 100), 4);
// // //       graphics_context_set_fill_color(ctx, GColorBlue);
// //       graphics_context_set_fill_color(ctx, GColorDarkGray);
// //       graphics_fill_circle(ctx, GPoint(start + 21, 102), 2);
// //       graphics_fill_circle(ctx, GPoint(start + 22, 102), 2);
// //       graphics_context_set_fill_color(ctx, GColorWhite);
// //       graphics_fill_circle(ctx, GPoint(start + 28, 101), 3);
// //     } else if (next == rainy) {
// //       graphics_fill_circle(ctx, GPoint(start + 25, 100), 4);
// // //       graphics_context_set_fill_color(ctx, GColorBlue);
// //       graphics_fill_circle(ctx, GPoint(start + 21, 102), 2);
// //       graphics_fill_circle(ctx, GPoint(start + 22, 102), 2);
// //       graphics_fill_circle(ctx, GPoint(start + 28, 101), 3);
// // //       graphics_fill_rect(ctx, GRect(start + 7 + 4, 102, 20, 3), 0, GCornerNone);
// //     }
// //   }
// // }