/**
 * Pokemon information screen
 */
#include "text_animation_window.h"
#include "util.h"

// Pokemon Resource ID's, macros evaluated at compile time. 
static uint8_t PKMN_ICONS[] = {
    0, // RESOURCE_ID_0, TODO MissingNo
    RESOURCE_ID_1,
    RESOURCE_ID_2,
    RESOURCE_ID_3,
    RESOURCE_ID_4,
    RESOURCE_ID_5,
    RESOURCE_ID_6,
    RESOURCE_ID_7,
    RESOURCE_ID_8,
    RESOURCE_ID_9,
    RESOURCE_ID_10,
    RESOURCE_ID_11,
    RESOURCE_ID_12,
    RESOURCE_ID_13,
    RESOURCE_ID_14,
    RESOURCE_ID_15,
    RESOURCE_ID_16,
    RESOURCE_ID_17,
    RESOURCE_ID_18,
    RESOURCE_ID_19,
    RESOURCE_ID_20,
    RESOURCE_ID_21,
    RESOURCE_ID_22,
    RESOURCE_ID_23,
    RESOURCE_ID_24,
    RESOURCE_ID_25,
    RESOURCE_ID_26,
    RESOURCE_ID_27,
    RESOURCE_ID_28,
    RESOURCE_ID_29,
    RESOURCE_ID_30,
    RESOURCE_ID_31,
    RESOURCE_ID_32,
    RESOURCE_ID_33,
    RESOURCE_ID_34,
    RESOURCE_ID_35,
    RESOURCE_ID_36,
    RESOURCE_ID_37,
    RESOURCE_ID_38,
    RESOURCE_ID_39,
    RESOURCE_ID_40,
    RESOURCE_ID_41,
    RESOURCE_ID_42,
    RESOURCE_ID_43,
    RESOURCE_ID_44,
    RESOURCE_ID_45,
    RESOURCE_ID_46,
    RESOURCE_ID_47,
    RESOURCE_ID_48,
    RESOURCE_ID_49,
    RESOURCE_ID_50,
    RESOURCE_ID_51,
    RESOURCE_ID_52,
    RESOURCE_ID_53,
    RESOURCE_ID_54,
    RESOURCE_ID_55,
    RESOURCE_ID_56,
    RESOURCE_ID_57,
    RESOURCE_ID_58,
    RESOURCE_ID_59,
    RESOURCE_ID_60,
    RESOURCE_ID_61,
    RESOURCE_ID_62,
    RESOURCE_ID_63,
    RESOURCE_ID_64,
    RESOURCE_ID_65,
    RESOURCE_ID_66,
    RESOURCE_ID_67,
    RESOURCE_ID_68,
    RESOURCE_ID_69,
    RESOURCE_ID_70,
    RESOURCE_ID_71,
    RESOURCE_ID_72,
    RESOURCE_ID_73,
    RESOURCE_ID_74,
    RESOURCE_ID_75,
    RESOURCE_ID_76,
    RESOURCE_ID_77,
    RESOURCE_ID_78,
    RESOURCE_ID_79,
    RESOURCE_ID_80,
    RESOURCE_ID_81,
    RESOURCE_ID_82,
    RESOURCE_ID_83,
    RESOURCE_ID_84,
    RESOURCE_ID_85,
    RESOURCE_ID_86,
    RESOURCE_ID_87,
    RESOURCE_ID_88,
    RESOURCE_ID_89,
    RESOURCE_ID_90,
    RESOURCE_ID_91,
    RESOURCE_ID_92,
    RESOURCE_ID_93,
    RESOURCE_ID_94,
    RESOURCE_ID_95,
    RESOURCE_ID_96,
    RESOURCE_ID_97,
    RESOURCE_ID_98,
    RESOURCE_ID_99,
    RESOURCE_ID_100,
    RESOURCE_ID_101,
    RESOURCE_ID_102,
    RESOURCE_ID_103,
    RESOURCE_ID_104,
    RESOURCE_ID_105,
    RESOURCE_ID_106,
    RESOURCE_ID_107,
    RESOURCE_ID_108,
    RESOURCE_ID_109,
    RESOURCE_ID_110,
    RESOURCE_ID_111,
    RESOURCE_ID_112,
    RESOURCE_ID_113,
    RESOURCE_ID_114,
    RESOURCE_ID_115,
    RESOURCE_ID_116,
    RESOURCE_ID_117,
    RESOURCE_ID_118,
    RESOURCE_ID_119,
    RESOURCE_ID_120,
    RESOURCE_ID_121,
    RESOURCE_ID_122,
    RESOURCE_ID_123,
    RESOURCE_ID_124,
    RESOURCE_ID_125,
    RESOURCE_ID_126,
    RESOURCE_ID_127,
    RESOURCE_ID_128,
    RESOURCE_ID_129,
    RESOURCE_ID_130,
    RESOURCE_ID_131,
    RESOURCE_ID_132,
    RESOURCE_ID_133,
    RESOURCE_ID_134,
    RESOURCE_ID_135,
    RESOURCE_ID_136,
    RESOURCE_ID_137,
    RESOURCE_ID_138,
    RESOURCE_ID_139,
    RESOURCE_ID_140,
    RESOURCE_ID_141,
    RESOURCE_ID_142,
    RESOURCE_ID_143,
    RESOURCE_ID_144,
    RESOURCE_ID_145,
    RESOURCE_ID_146,
    RESOURCE_ID_147,
    RESOURCE_ID_148,
    RESOURCE_ID_149,
    RESOURCE_ID_150,
    RESOURCE_ID_151
};

static char* PKMN_NAMES[] = {
    "MissingNo",
    "bulbasaur", 
    "ivysaur", 
    "venusaur", 
    "charmander", 
    "charmeleon", 
    "charizard", 
    "squirtle", 
    "wartortle", 
    "blastoise",
    "caterpie", 
    "metapod", 
    "butterfree", 
    "weedle", 
    "kakuna", 
    "beedrill", 
    "pidgey", 
    "pidgeotto", 
    "pidgeot", 
    "rattata", 
    "raticate", 
    "spearow", 
    "fearow", 
    "ekans", 
    "arbok", 
    "pikachu", 
    "raichu", 
    "sandshrew", 
    "sandslash", 
    "nidoran", 
    "nidorina", 
    "nidoqueen", 
    "nidoran", 
    "nidorino", 
    "nidoking", 
    "clefairy", 
    "clefable", 
    "vulpix", 
    "ninetales", 
    "jigglypuff", 
    "wigglytuff", 
    "zubat", 
    "golbat", 
    "oddish", 
    "gloom", 
    "vileplume",
    "paras", 
    "parasect", 
    "venonat", 
    "venomoth", 
    "diglett", 
    "dugtrio", 
    "meowth", 
    "persian", 
    "psyduck", 
    "golduck", 
    "mankey", 
    "primeape", 
    "growlithe", 
    "arcanine", 
    "poliwag", 
    "poliwhirl", 
    "poliwrath", 
    "abra", 
    "kadabra",
    "alakazam", 
    "machop", 
    "machoke", 
    "machamp", 
    "bellsprout", 
    "weepinbell", 
    "victreebel", 
    "tentacool", 
    "tentacruel", 
    "geodude", 
    "graveler", 
    "golem", 
    "ponyta", 
    "rapidash", 
    "slowpoke", 
    "slowbro", 
    "magnemite",
    "magneton", 
    "farfetchd", 
    "doduo", 
    "dodrio", 
    "seel", 
    "dewgong", 
    "grimer", 
    "muk", 
    "shellder", 
    "cloyster", 
    "gastly", 
    "haunter", 
    "gengar", 
    "onix", 
    "drowzee", 
    "hypno", 
    "krabby", 
    "kingler", 
    "voltorb", 
    "electrode", 
    "exeggcute", 
    "exeggutor", 
    "cubone", 
    "marowak", 
    "hitmonlee", 
    "hitmonchan", 
    "lickitung", 
    "koffing", 
    "weezing", 
    "rhyhorn", 
    "rhydon", 
    "chansey", 
    "tangela", 
    "kangaskhan", 
    "horsea", 
    "seadra", 
    "goldeen", 
    "seaking", 
    "staryu", 
    "starmie", 
    "mr-mime", 
    "scyther", 
    "jynx", 
    "electabuzz", 
    "magmar", 
    "pinsir", 
    "tauros", 
    "magikarp", 
    "gyarados", 
    "lapras", 
    "ditto", 
    "eevee", 
    "vaporeon", 
    "jolteon", 
    "flareon", 
    "porygon", 
    "omanyte", 
    "omastar", 
    "kabuto", 
    "kabutops", 
    "aerodactyl", 
    "snorlax", 
    "articuno", 
    "zapdos", 
    "moltres", 
    "dratini", 
    "dragonair", 
    "dragonite", 
    "mewtwo", 
    "mew"
};


// Window Variables
static Window *s_window;
static TextLayer *s_text_layer;
static TextLayer *s_name_layer;

// Bitmap Variables
static GBitmapSequence *s_sequence;
static GBitmap *s_bitmap;
static BitmapLayer *s_bitmap_layer;

int pkmn_number; 
uint32_t first_delay_ms = 10;

char *buffer = "123" ; 

static void timer_handler(void *context) {
  uint32_t next_delay; 
  // Advance to the next APNG frame, and get the delay for this frame
  if(gbitmap_sequence_update_bitmap_next_frame(s_sequence, s_bitmap, &next_delay)) {

    // Set the new frame into the BitmapLayer
    bitmap_layer_set_bitmap(s_bitmap_layer, s_bitmap);
    layer_mark_dirty(bitmap_layer_get_layer(s_bitmap_layer));

    // timer for that frame's delay
    app_timer_register(next_delay, timer_handler, NULL);
  }
}

static void animate(){
    // create sequence to display series of frames of an apng
    s_sequence = gbitmap_sequence_create_with_resource(PKMN_ICONS[pkmn_number]);

    // Create blank GBitmap using APNG frame size
    GSize frame_size = gbitmap_sequence_get_bitmap_size(s_sequence);
    s_bitmap = gbitmap_create_blank(frame_size, GBitmapFormat8Bit);

    s_bitmap_layer = bitmap_layer_create(GRect(40, 40, 60, 60));
    bitmap_layer_set_compositing_mode(s_bitmap_layer, GCompOpSet);
    bitmap_layer_set_bitmap(s_bitmap_layer, s_bitmap);

    // add child layer to s_window
    layer_add_child(window_get_root_layer(s_window), bitmap_layer_get_layer(s_bitmap_layer));

	// Schedule a timer to advance the first frame
	app_timer_register(first_delay_ms, timer_handler, NULL);
}

static void window_load(){
  Layer *window_layer = window_get_root_layer(s_window);  
  
  // pkmn number
  s_text_layer = text_layer_create(GRect(10, 10, 40, 40));
  // pkmn name
  s_name_layer = text_layer_create(GRect(20, 100, 100, 40));

  char snum[3];
  itoa(pkmn_number, snum, 10);
  APP_LOG(APP_LOG_LEVEL_INFO, "the integer is %d, str is %s", pkmn_number, snum); 

  text_layer_set_text(s_text_layer, (snprintf(buffer, 4, "%d", pkmn_number) , buffer)  );
  text_layer_set_text_color(s_text_layer, GColorFolly);
  text_layer_set_background_color(s_text_layer, GColorWhite);
  text_layer_set_font(s_text_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  text_layer_set_text_alignment(s_text_layer, GTextAlignmentCenter);
  layer_add_child(window_layer, text_layer_get_layer(s_text_layer));

  text_layer_set_text(s_name_layer, PKMN_NAMES[pkmn_number] );
  text_layer_set_text_color(s_name_layer, GColorFolly);
  text_layer_set_background_color(s_name_layer, GColorWhite);
  text_layer_set_font(s_name_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  text_layer_set_text_alignment(s_name_layer, GTextAlignmentCenter);
  layer_add_child(window_layer, text_layer_get_layer(s_name_layer));
}

static void window_unload(){
    // clear resources
    bitmap_layer_destroy(s_bitmap_layer);
    gbitmap_sequence_destroy(s_sequence);
    gbitmap_destroy(s_bitmap);
    text_layer_destroy(s_text_layer);
    window_destroy(s_window);
    s_window = NULL;
    
}

void pkmn_window_push(int pkmn_num){
  
  pkmn_number = pkmn_num;

  if(!s_window) {
    s_window = window_create();
    window_set_background_color(s_window, GColorWhite);
    window_set_window_handlers(s_window, (WindowHandlers) {
      .load = window_load,
      .unload = window_unload,
    });
  }
  window_stack_push(s_window, true);

  animate(pkmn_number);
}

