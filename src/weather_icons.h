// #pragma once

// #include <pebble.h>

// #define wu_api_key "bf04d333c2e0e650"

// typedef enum {
//   null,
//   clear,
//   part_cloudy,
//   cloudy,
//   rainy,
//   tstorm
// } weather;

// // "http://api.wunderground.com/api/bf04d333c2e0e650/hourly/q/GA/Atlanta.json"
// // "http://api.wunderground.com/api/bf04d333c2e0e650/hourly/q/33.7801931,-84.4014109.json"

// void graphics_draw_weather(GContext* ctx, weather* forecast);

// // void graphics_draw_weather_icon(GContext* ctx, int pos, int isFront, weather next);
// // void graphics_draw_weather_cloudy(GContext* ctx, int pos, int isFront, weather next);
// // void graphics_draw_weather_rainy(GContext* ctx, int pos, int isFront, weather next);
// void graphics_draw_cloud(GContext * ctx, int pos, int isFront, GColor color, weather next);
// void graphics_draw_rain(GContext * ctx, int pos);
// void graphics_draw_lightning(GContext * ctx, int pos);