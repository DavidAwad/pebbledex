/*
 * @Author David Awad
 * Simple Pokedex App for Pebble
 * 
*/ 
#include <pebble.h>
#include <string.h>

#include "windows/pin_window.h"
#include "windows/text_animation_window.h"
#include "windows/progress_bar_window.h"
#include "windows/checkbox_window.h"
#include "windows/pokemon_window.h"

#define NUM_WINDOWS 3

static Window *s_main_window;
static MenuLayer *s_menu_layer;

static uint16_t get_num_rows_callback(MenuLayer *menu_layer, uint16_t section_index, void *context) {
  return NUM_WINDOWS;
}

int rand_rng(int low, int high){
    int ret;
    ret = low + (rand() % (high - low));
    return ret; 
}

static void draw_row_callback(GContext *ctx, const Layer *cell_layer, MenuIndex *cell_index, void *context) {
  switch(cell_index->row) {
    case 0:
      menu_cell_basic_draw(ctx, cell_layer, "Select Pokémon", NULL, NULL);
      break;
    case 1:
      menu_cell_basic_draw(ctx, cell_layer, "Random  Pokémon", NULL, NULL);
      break;
    case 2:
      menu_cell_basic_draw(ctx, cell_layer, "Settings", NULL, NULL);
      break;
    /*
    case 1:
      menu_cell_basic_draw(ctx, cell_layer, "Text Animation", NULL, NULL);
      break;
    case 2:
      menu_cell_basic_draw(ctx, cell_layer, "Progress Bar", NULL, NULL);
      break;
    case 3:
      menu_cell_basic_draw(ctx, cell_layer, "Debug", NULL, NULL);
      break;
      */
    default:
      break;
  }
}

static int16_t get_cell_height_callback(struct MenuLayer *menu_layer, MenuIndex *cell_index, void *context) {
  return PBL_IF_ROUND_ELSE(
    menu_layer_is_index_selected(menu_layer, cell_index) ?
      MENU_CELL_ROUND_FOCUSED_SHORT_CELL_HEIGHT : MENU_CELL_ROUND_UNFOCUSED_TALL_CELL_HEIGHT,
    CHECKBOX_WINDOW_CELL_HEIGHT);
}

static void pin_complete_callback(PIN pin, void *context) {
  // callback function from pin, render pokedex entry with selected pkmn 
  APP_LOG(APP_LOG_LEVEL_INFO, "Pin was %d %d %d", pin.digits[0], pin.digits[1], pin.digits[2]);

  pin_window_pop((PinWindow*)context, true);
  
  int pkmn_number = 100*pin.digits[0] + 10*pin.digits[1] + pin.digits[2]; 
  
  APP_LOG(APP_LOG_LEVEL_INFO, "number was %d", pkmn_number);

  pkmn_window_push(pkmn_number); 
}

static void select_callback(struct MenuLayer *menu_layer, MenuIndex *cell_index, void *context) {
  switch(cell_index->row) {
    case 0: {
        PinWindow *pin_window = pin_window_create((PinWindowCallbacks) {
          .pin_complete = pin_complete_callback
        });
        pin_window_push(pin_window, true);
      }
      break;
    case 1: // debug option in menu
      pkmn_window_push(rand_rng(1, 241)); 
      break;
    case 2: // show some text
      text_animation_window_push();
      break;
    /*
    case 1:
      text_animation_window_push();
      break;
    case 2:
      progress_bar_window_push();
      break;
    case 3: // debug option in menu
      pkmn_window_push(2); // load ivysaur as a shitty debug
      break;
    */
    default:
      break;
  }
}

static void window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);

  s_menu_layer = menu_layer_create(bounds);
  menu_layer_set_click_config_onto_window(s_menu_layer, window);
#if defined(PBL_COLOR)
  menu_layer_set_normal_colors(s_menu_layer, GColorBlack, GColorWhite);
  menu_layer_set_highlight_colors(s_menu_layer, GColorRed, GColorWhite);
#endif
  menu_layer_set_callbacks(s_menu_layer, NULL, (MenuLayerCallbacks) {
      .get_num_rows = get_num_rows_callback,
      .draw_row = draw_row_callback,
      .get_cell_height = get_cell_height_callback,
      .select_click = select_callback,
  });
  layer_add_child(window_layer, menu_layer_get_layer(s_menu_layer));
}

static void window_unload(Window *window) {
  menu_layer_destroy(s_menu_layer);
}

static void init() {
  // Create main Window element and assign to pointer
  s_main_window = window_create();
  // Set handlers to manage the elements inside the Window
  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload
  });
  // Show the Window on the watch, with animated=true
  window_stack_push(s_main_window, true);

}

static void deinit() {
  // Destroy Window
  window_destroy(s_main_window);
}

int main() {
  init();
  app_event_loop();
  deinit();
}
