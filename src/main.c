#include <pebble.h>
#include <weather_icons2.h>

static Window *s_main_window;
static TextLayer *s_time_layer, *s_date_layer;
static Layer *weather_timeline;

static Layer *s_battery_layer;
static int s_battery_level;

static void weather_update_proc(Layer* layer, GContext* ctx) {
//   graphics_context_set_stroke_color(ctx, GColorBlack);
//   graphics_draw_line(ctx, GPoint(24,90), GPoint(24,168));
  graphics_context_set_fill_color(ctx, GColorDukeBlue);
  graphics_fill_rect(ctx, GRect(0, 0, 144, 90), 0, GCornerNone);
  
  weather forecast[5] = {part_cloudy, part_cloudy, cloudy, rainy, part_cloudy};
  char* text[10] = {"21", "43°", "22", "41°", "23", "39°", "00", "39°", "01", "38°"};
  graphics_draw_weather(ctx, forecast, text);
  
  graphics_context_set_fill_color(ctx, GColorDarkGray);
  graphics_fill_rect(ctx, GRect(0, 158, 144, 10), 0, GCornerNone);
  graphics_context_set_fill_color(ctx, GColorVividCerulean);
  graphics_fill_rect(ctx, GRect(0, 158, 80, 10), 0, GCornerNone);
  graphics_context_set_stroke_width(ctx, 2);
  graphics_context_set_stroke_color(ctx, GColorYellow);
  graphics_draw_line(ctx, GPoint(100,158), GPoint (100,170));
  graphics_context_set_stroke_color(ctx, GColorDukeBlue);
  graphics_draw_line(ctx, GPoint(0,156), GPoint (144,156));
  
  
//   graphics_draw_battery(ctx, 60);
}

static void battery_update_proc(Layer *layer, GContext *ctx) {
  for (int i = 0; i<10; i+=1) {
    graphics_context_set_fill_color(ctx, GColorLightGray);
    graphics_context_set_stroke_color(ctx, GColorLightGray);
    if (100-i*10<=s_battery_level) {
      graphics_fill_rect(ctx, GRect(22 + i*10, 4, 6, 5), 0, GCornerNone);
    } else {
      graphics_draw_rect(ctx, GRect(22 + i*10, 4, 6, 5));
    }
  }
  graphics_fill_rect(ctx, GRect(22 + 90 + 3, 4, 3, 5), 0, GCornerNone);
}

static void battery_callback(BatteryChargeState state) {
  // Record the new battery level
  s_battery_level = state.charge_percent;
  layer_mark_dirty(s_battery_layer);
}

static void update_time() {
  // Get a tm structure
  time_t temp = time(NULL); 
  struct tm *tick_time = localtime(&temp);

  // Write the current hours and minutes into a buffer
  static char s_buffer[8];
  strftime(s_buffer, sizeof(s_buffer), clock_is_24h_style() ? "%H:%M" : "%I:%M", tick_time);

  // Display this time on the TextLayer
  text_layer_set_text(s_time_layer, s_buffer);
  
  
  // Copy date into buffer from tm structure
  static char date_buffer[16];
  strftime(date_buffer, sizeof(date_buffer), "%a %d %b", tick_time);
  
  // Show the date
  text_layer_set_text(s_date_layer, date_buffer);
}

static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
  update_time();
}

static void main_window_load(Window *window) {
  weather_timeline = layer_create(GRect(0, 0, 144, 168));
  layer_set_update_proc(weather_timeline, weather_update_proc);
  layer_add_child(window_get_root_layer(window), weather_timeline);
  
  // Get information about the Window
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);

  // Create the TextLayer with specific bounds
  s_time_layer = text_layer_create(GRect(2, 18, bounds.size.w, 50));

  // Improve the layout to be more like a watchface
  text_layer_set_background_color(s_time_layer, GColorClear);
  text_layer_set_text_color(s_time_layer, GColorWhite);
  text_layer_set_text(s_time_layer, "00:00");
  GFont custom_font_1 = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_BLOCKY_38));
  text_layer_set_font(s_time_layer, custom_font_1);
  text_layer_set_text_alignment(s_time_layer, GTextAlignmentCenter);

  // Add it as a child layer to the Window's root layer
  layer_add_child(window_layer, text_layer_get_layer(s_time_layer));
  
  // Create date TextLayer
  s_date_layer = text_layer_create(GRect(0, 65, 144, 30));
  text_layer_set_text_color(s_date_layer, GColorLightGray);
  text_layer_set_background_color(s_date_layer, GColorClear);
  GFont custom_font_2 = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_BLOCKY_16));
  text_layer_set_font(s_date_layer, custom_font_2);
  text_layer_set_text_alignment(s_date_layer, GTextAlignmentCenter);
  
  // Add to Window
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(s_date_layer));  
  
  
  // Create battery meter Layer
  s_battery_layer = layer_create(GRect(0, 0, 144, 168));
  layer_set_update_proc(s_battery_layer, battery_update_proc);
  
  // Add to Window
  layer_add_child(window_get_root_layer(window), s_battery_layer);
}

static void main_window_unload(Window *window) {
  // Destroy TextLayer
  text_layer_destroy(s_time_layer);
  text_layer_destroy(s_date_layer);
  layer_destroy(s_battery_layer);
  layer_destroy(weather_timeline);
}


static void init() {
  // Create main Window element and assign to pointer
  s_main_window = window_create();

  // Set handlers to manage the elements inside the Window
  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload
  });

  // Show the Window on the watch, with animated=true
  window_stack_push(s_main_window, true);

  // Make sure the time is displayed from the start
  update_time();

  // Register with TickTimerService
  tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);
  
  battery_state_service_subscribe(battery_callback);
  battery_callback(battery_state_service_peek());
}

static void deinit() {
  // Destroy Window
  window_destroy(s_main_window);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}